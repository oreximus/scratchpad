## Web Application Testing:

1. Enumeration: NMAP

   - `NMAP`: network scanners, for scanning entire network or single IP address.
   - `Gobuster`: directory scanning tool, for fuzzing/scanning presented directories in the target HOST.
   - `Burpsuite`: tools for intercepting website traffic to test and assesment the website requests.
   - `FFUF`: fuzzing subdomains, directories, etc stuffs in the website or target HOST. written in the GO language, so it
     is very fast at scanning, as compared to gobuster, feroxbuster, etc.
   - `SQLMap`: for indentifying any SQL related vulnerabilities (bugs related to SQL), and runs only in URL where any SQL
     query is going on.
   - `WPSCAN`: for scanning wordpress website and returns any error or bugs present in the website.

2. Scanning: Here we perform related stuffs, directory scanning, subdomain scanning, network scanning, etc. Tools: ffuf,
   gobuster, etc.
3. Exploitation: Here attackers try to take advatage of the presented vulnerabilities in the Systems.
4. Access Maintained: Installing the backdoors at the server-side for reconnecting easily, or maintaining the session without
   getting caught by the organization.

## Common Attacks in Website Applications:

1. SQL injection: SQL related vulnerabilities, can be indentified from the PATH(URL) where SQL queries are happening.
2. XSS (cross site scripting): being able execute code from any input box or input method at UI side(client-side)
3. XXE (XML External Entity): Problems in XML, that can lead to sensitive information leakage!
4. SSRF (Server Side Request Forgery):
5. SSTI (Server Side Template Injection):
6. LFI (Local File Inclusion): Being able to see the files contents of the server or HOST.
7. Path traversal Vulnerabily: Being able to list the directories and files of the server.

## Common Commands for Tools:

### FFUF:

- scanning `subdomains` of the target HOST.

```
ffuf -w /path/to/your/wordlist.txt -u [FUZZ.google.com] -of html -o [OUTPUT_FILE]
```

### Gobuster:

- scanning the `directories` of the target HOST.

```
gobuster dir -u [URL] -w PATH_TO_THE_WORDLIST
```

### WPSCAN:

```
wpscan [website-url]
```

### SQLMAP

```
sqlmap -u "http://example.com/vuln.php?id=1" --dbms="MySQL" --level=5 --risk=3 --dump
```
