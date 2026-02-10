# Notes related to Spring Internship Project in 2026

# **1-WEEK PROJECT SCHEDULE - COMPACT VIEW**

---

## **GRAPHIC DESIGNER**

| Day | Tasks | Deliverables |
|-----|-------|--------------|
| **1-2** | Design System in Figma | Colors, Typography, Components Library |
| **3-4** | Admin Dashboard Mockups | 6 screens (Dashboard, Drafts, Detail, Published, Analytics, Settings) |
| **5** | Email Templates | 4 HTML templates (Draft Ready, Published, Weekly Report, Alerts) |
| **6** | Article Layouts | Public article page (desktop + mobile) |
| **7** | Export & Documentation | SVG assets, Developer handoff docs, Figma Dev Mode setup |

---

## **FRONTEND DEVELOPERS**

| Day | Tasks | Deliverables |
|-----|-------|--------------|
| **1** | Project Setup | Next.js 14 + Tailwind + shadcn/ui, folder structure, config files |
| **2** | Types & API Layer | TypeScript interfaces, API client, React Query hooks |
| **3** | Layout Components | Sidebar, Header, Dashboard Layout |
| **4** | Drafts Module | Draft List, Draft Card, Filters, Pagination |
| **5** | Draft Detail & Approval | Full draft preview, approval/reject actions, source verification panel |
| **6** | Analytics Dashboard | Stats cards, performance charts (Recharts) |
| **7** | Testing & Polish | Unit tests, error handling, responsive checks, deployment prep |

---

## **BACKEND DEVELOPERS**

| Day | Tasks | Deliverables |
|-----|-------|--------------|
| **1** | Project Setup | Express + TypeScript, folder structure, env config |
| **2** | Database Models | Topic, Draft, Article, Analytics schemas with Mongoose |
| **3** | Claude Service | Article generation, topic validation, research functions |
| **4** | Job Queues | Bull jobs: topic discovery, content generation, analytics |
| **5** | API Routes | REST endpoints for drafts, articles, analytics, auth |
| **6** | Content Pipeline | Full auto-generation flow: discover → validate → research → generate → draft |
| **7** | Testing & Security | Unit tests, error handling, rate limiting, API documentation |

---

## **INTEGRATION POINTS**

### **End of Week Checklist:**

✅ **Designer → Frontend:**
- Figma files shared
- Assets exported to `/public`
- Design tokens documented

✅ **Backend → Frontend:**
- API endpoints documented (Postman/Swagger)
- Sample responses provided
- WebSocket events defined (if needed)

✅ **Full Stack:**
- Environment variables aligned
- CORS configured
- Authentication flow working
- First draft can be generated and approved end-to-end

---

## **WEEK TIMELINE OVERVIEW**

```
Mon-Tue:  Setup & Foundation (all teams)
Wed-Thu:  Core Features (UI screens, API routes, models)
Fri:      Integration (connect frontend to backend)
Sat:      Polish & Testing
Sun:      Documentation & Deployment prep
```

---

## **CRITICAL PATH**

**Must be done in order:**
1. Day 1-2: All teams complete setup
2. Day 3: Backend models + Frontend types aligned
3. Day 4: Backend APIs ready for frontend integration
4. Day 5: Frontend calls backend successfully
5. Day 6-7: End-to-end testing

---

## **MINIMAL VIABLE PRODUCT (MVP)**

By end of week, you should have:
- ✅ One category (Fintech) working
- ✅ Topic discovery running (manual trigger)
- ✅ Draft generation working
- ✅ Admin can view/approve/publish drafts
- ✅ Basic analytics tracking
- ✅ Email notifications working

**Future weeks:** Add more categories, auto-scheduling, advanced analytics, image generation optimization.
