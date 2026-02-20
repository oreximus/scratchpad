Here's a refined, comprehensive prompt you can give to an AI coding agent:

---

## Prompt for AI Coding Agent

**Project:** Ad Landing Page Generator — Full-Stack Next.js Web Application

---

### Overview

Build a production-ready Next.js web application that allows users to generate cloned Ad Landing Pages from various design references. The app takes multiple input types, uses AI to analyze and generate a high-fidelity HTML/CSS/JS landing page, renders it in a live preview with inline editing capabilities, and exports the final result.

---

### Tech Stack & Configuration

- **Framework:** Next.js 14+ (App Router)
- **Language:** TypeScript
- **Styling:** Tailwind CSS + design tokens from `design-tokens.json` (wire this into `tailwind.config.ts` for colors, typography, spacing)
- **Database:** PostgreSQL via `pg` or `drizzle-orm` — use SSL with cert from `config/ca.pem`
- **AI:** OpenAI API (GPT-4o with vision) — all keys from `.env.local`
- **File Handling:** `pdf-parse` for PDFs, `axios`/`cheerio` for URL scraping, Figma REST API for Figma URLs
- **Export:** `jszip` to bundle HTML/CSS/JS for download
- **Preview:** sandboxed `<iframe>` with `srcdoc`
- **State:** Zustand or React Context for editor state

Read ALL configuration from `.env.local`. Never hardcode secrets. SSL cert path is `config/ca.pem` — load it via `fs.readFileSync` in database config.

---

### Database Schema (PostgreSQL)

Create and auto-migrate these tables on startup:

```sql
-- Projects table
CREATE TABLE IF NOT EXISTS projects (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  name TEXT NOT NULL,
  status TEXT DEFAULT 'draft', -- draft | generating | ready | exported
  created_at TIMESTAMPTZ DEFAULT NOW(),
  updated_at TIMESTAMPTZ DEFAULT NOW()
);

-- Input references per project
CREATE TABLE IF NOT EXISTS project_inputs (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  project_id UUID REFERENCES projects(id) ON DELETE CASCADE,
  type TEXT NOT NULL, -- url | figma | pdf | brief
  raw_value TEXT,      -- URL string or text brief
  file_path TEXT,      -- for uploaded PDFs
  extracted_content TEXT, -- AI-parsed/scraped content
  created_at TIMESTAMPTZ DEFAULT NOW()
);

-- Generated pages per project (versioned)
CREATE TABLE IF NOT EXISTS generated_pages (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  project_id UUID REFERENCES projects(id) ON DELETE CASCADE,
  version INTEGER DEFAULT 1,
  html TEXT NOT NULL,
  css TEXT,
  js TEXT,
  metadata JSONB,      -- fonts, colors, components used
  is_active BOOLEAN DEFAULT TRUE,
  created_at TIMESTAMPTZ DEFAULT NOW()
);

-- Edit history
CREATE TABLE IF NOT EXISTS edit_history (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  page_id UUID REFERENCES generated_pages(id) ON DELETE CASCADE,
  diff JSONB,           -- what changed
  snapshot_html TEXT,
  created_at TIMESTAMPTZ DEFAULT NOW()
);
```

---

### Application Pages & Routes

#### 1. `/` — Dashboard

- List all projects with status badges, timestamps, thumbnails (iframe screenshot)
- "New Project" CTA button
- Search and filter by status

#### 2. `/projects/new` — Input Collection

A multi-step form (stepper UI) with these input methods:

**Step 1 — Add References (support all of the following):**

- **URL input:** Enter any website URL → scrape with `cheerio` (colors, fonts, layout structure, hero text, CTAs)
- **Figma URL:** Detect `figma.com` URLs → call Figma REST API (`/v1/files/:key`) using `FIGMA_ACCESS_TOKEN` from `.env.local` → extract component tree, colors, text styles
- **PDF Upload:** Upload design doc/brief PDF → parse with `pdf-parse` → extract text content
- **Text Brief:** Free-text product brief textarea
- Support adding multiple references of mixed types

**Step 2 — Project Settings:**

- Project name
- Target industry/niche (dropdown)
- Desired tone (Professional / Playful / Minimal / Bold)
- Primary CTA text
- Brand colors override (optional color pickers)

**Step 3 — Generate**

- Show summary of all inputs
- "Generate Landing Page" button

#### 3. `/projects/[id]/generate` — Generation & Preview (Core Feature)

**Generation Pipeline (API Route: `POST /api/projects/[id]/generate`):**

1. Aggregate all extracted content from inputs
2. Build a structured prompt for GPT-4o that includes:
   - All scraped/extracted design context
   - Design token constraints (load `design-tokens.json` server-side)
   - Instruction to output a **single self-contained HTML file** with embedded CSS + JS
   - Must include these high-impact sections: Hero, Features/Benefits, Social Proof/Testimonials, CTA Section, Footer
   - Output format: JSON `{ html: string, css: string, js: string, metadata: { colors: [], fonts: [], components: [] } }`
3. Stream the response using OpenAI streaming (show live generation progress to user)
4. Save result to `generated_pages` table
5. Return the complete page code

**Preview Panel:**

- Render generated HTML in a sandboxed `<iframe srcdoc={...}>`
- Toggle between Desktop (100%) / Tablet (768px) / Mobile (375px) viewport widths
- Toolbar with: Undo, Redo, Regenerate, Export buttons

**Inline Editor (Right Panel — split layout):**

Build a component-aware editor. After generation, parse the HTML to identify editable sections and expose:

- **Text Editor:** Click any text element in preview → highlight it → edit in sidebar input field → changes reflect live in iframe
- **Color Editor:** Show extracted color palette → click to change any color → update all instances in HTML
- **Image Swap:** Click image placeholders → upload or enter URL → swap src
- **Section Visibility:** Toggle show/hide for each major section
- **Component Library:** Drag pre-built component variants (different hero layouts, CTA styles, testimonial cards) to replace sections

Implement editing via `postMessage` to the iframe + maintaining a `document.innerHTML` state that updates on every change. Save diffs to `edit_history`.

#### 4. `/projects/[id]/export` — Export

**API Route: `GET /api/projects/[id]/export`**

- Fetch active `generated_pages` record
- Create ZIP using `jszip`:
  - `index.html` (complete self-contained file)
  - `styles.css` (extracted CSS)
  - `script.js` (extracted JS)
  - `README.md` (component map, fonts used, edit instructions)
- Stream ZIP as download with `Content-Disposition: attachment`

Also offer:

- **Copy HTML** button (clipboard)
- **Preview in new tab** button

---

### API Routes Summary

```
POST   /api/projects                    → create project
GET    /api/projects                    → list projects
GET    /api/projects/[id]               → get project + inputs + active page
DELETE /api/projects/[id]               → delete project

POST   /api/projects/[id]/inputs        → add input reference
POST   /api/projects/[id]/inputs/scrape → scrape URL and return extracted data
POST   /api/projects/[id]/inputs/figma  → fetch Figma file data
POST   /api/projects/[id]/inputs/pdf    → upload + parse PDF

POST   /api/projects/[id]/generate      → run AI generation pipeline (streaming)
POST   /api/projects/[id]/regenerate    → regenerate with modified prompt

PUT    /api/projects/[id]/pages/[pageId]  → save edits to page HTML
POST   /api/projects/[id]/pages/[pageId]/history → save edit snapshot

GET    /api/projects/[id]/export        → download ZIP
```

---

### UI/UX Design Requirements

- Apply ALL values from `design-tokens.json` — map colors, font families, font sizes, spacing scale, border radius, shadow tokens into Tailwind config and CSS variables
- Dark sidebar editor panel, light main canvas area
- Split-pane layout on the editor page: 60% preview iframe | 40% editor controls
- Smooth transitions on all panel interactions
- Loading skeleton states during generation
- Real-time streaming progress indicator (token-by-token or section-by-section)
- Toast notifications for save/export/error states
- Responsive dashboard (collapses to single column on mobile)

---

### Environment Variables (from `.env.local`)

The app must read and use all of the following (do not define defaults for secrets):

```
OPENAI_API_KEY
OPENAI_MODEL          # e.g. gpt-4o
FIGMA_ACCESS_TOKEN
DATABASE_URL          # PostgreSQL connection string
DB_SSL_CERT_PATH      # path to config/ca.pem
NEXT_PUBLIC_APP_URL
```

---

### File Structure

```
/
├── app/
│   ├── page.tsx                        # Dashboard
│   ├── projects/
│   │   ├── new/page.tsx               # Multi-step input form
│   │   └── [id]/
│   │       ├── page.tsx               # Redirect to generate
│   │       ├── generate/page.tsx      # Preview + Editor
│   │       └── export/page.tsx        # Export page
│   └── api/
│       └── projects/...              # All API routes
├── components/
│   ├── editor/
│   │   ├── PreviewFrame.tsx           # iframe renderer
│   │   ├── EditorPanel.tsx            # right panel controls
│   │   ├── TextEditor.tsx
│   │   ├── ColorPicker.tsx
│   │   ├── ComponentLibrary.tsx
│   │   └── SectionToggle.tsx
│   ├── inputs/
│   │   ├── UrlInput.tsx
│   │   ├── FigmaInput.tsx
│   │   ├── PdfUpload.tsx
│   │   └── BriefInput.tsx
│   └── ui/                            # shared UI primitives
├── lib/
│   ├── db.ts                          # PostgreSQL client with SSL
│   ├── openai.ts                      # OpenAI client + prompt builder
│   ├── scraper.ts                     # URL scraping logic
│   ├── figma.ts                       # Figma API client
│   ├── pdf-parser.ts                  # PDF extraction
│   ├── prompt-builder.ts              # Aggregates inputs → GPT prompt
│   └── design-tokens.ts              # Loads design-tokens.json
├── config/
│   └── ca.pem                         # PostgreSQL SSL cert
├── design-tokens.json
├── .env.local
├── tailwind.config.ts                 # Wired to design-tokens.json
└── middleware.ts                      # Auth guard if needed
```

---

### Additional Requirements

- All database queries must use parameterized queries (no raw string interpolation)
- PDF uploads stored in `/tmp` or `/public/uploads` with unique filenames
- Figma integration must gracefully handle invalid/expired tokens with user-facing error
- The iframe preview must be sandboxed: `sandbox="allow-scripts allow-same-origin"`
- Generated HTML must be valid, self-contained, and render without any external dependencies unless they're CDN links (Google Fonts, etc.)
- All edit operations must be debounced (300ms) before hitting save API
- Export ZIP filename format: `{project-name}-landing-page-{date}.zip`
- Add a "Version History" drawer showing past generated versions with restore capability

---

This is a complete, working production application. Implement all features fully — no placeholder TODOs, no mock data, no stub functions.
