# Linux Technical Practical - June 18, 2025

## Overview
**Course**: Linux System Administration  
**Date**: June 18, 2025  
**Topic**: Pattern Matching and Text Processing with grep  
**Duration**: 2 Hours

## Objectives
- [x] Understanding the grep command and its purpose
- [x] Learning various grep options and patterns
- [x] Practical usage of grep in system administration
- [x] Working with regular expressions in grep

## Prerequisites
- grep package installed on your Linux system
- Basic understanding of Stream Processing (STDIN, STDOUT and STDERR)
- System requirements (Basic System with 2GB RAM and 5-10GB of space)
- Basic knowledge of command line interface

## Practical Environment Setup
```bash
# System Information
OS Version: Kali 6.12.25-1kali1 (2025-04-30) x86_64 GNU/Linux
Kernel: #1 SMP PREEMPT_DYNAMIC Kali 6.12.25-1kali1 (2025-04-30)
Shell: zsh
```

## Commands & Concepts Covered

### 1. grep (Global Regular Expression Print)
```bash
# Basic Command syntax
grep [options] pattern [file...]

# Example usage
grep root /etc/passwd
```

**Purpose**: grep searches for patterns in text files or command output. It's essential for filtering and searching through text data.

**Key Options**:
- `-i`: Case insensitive search
- `-v`: Invert match (show lines that don't match)
- `-r` or `-R`: Recursive search in directories
- `-n`: Show line numbers
- `-w`: Match whole words only
- `-c`: Count matching lines
- `-E`: Extended regular expressions (same as egrep)
- `-F`: Fixed strings (same as fgrep)
- `-l`: Show only filenames with matches
- `-h`: Don't prefix filenames in output

**Common Use Cases**:
1. Searching for specific text in files
2. Filtering command output
3. System log analysis
4. Finding patterns across multiple files
5. Text processing in scripts

## Practical Exercises

### Exercise 1: Basic grep Usage
**Objective**: Learn fundamental grep operations

**Steps**:
1. Basic pattern search in a file
   ```bash
   grep root /etc/passwd
   ```

2. Using grep with pipe (|)
   ```bash
   cat /etc/passwd | grep root
   ```

3. Searching in multiple files
   ```bash
   grep root /etc/passwd /etc/shadow
   ```

### Exercise 2: Advanced grep Options
**Objective**: Master various grep options and patterns

1. Case-insensitive search
   ```bash
   grep -i root /etc/passwd
   ```

2. Search with spaces in pattern
   ```bash
   grep "Session Started" /var/log/messages
   ```

3. Multiple pattern matching
   ```bash
   grep -E "(root|daemon)" /var/log/messages
   ```

4. Nested grep commands
   ```bash
   grep root /var/log/messages | grep "login"
   ```

### Exercise 3: Regular Expressions with grep
**Objective**: Understanding regex patterns in grep

1. Pattern exclusion
   ```bash
   grep root /var/log/messages | grep -vE "(error|failed)"
   ```

2. Matching with dot (.)
   ```bash
   grep "root\." /var/log/messages
   ```

3. End of line matching
   ```bash
   grep "root$" /var/log/messages
   ```

4. Start of line matching
   ```bash
   grep "^#" /etc/ssh/sshd_config
   ```

## Best Practices
1. Always use quotes around patterns containing spaces or special characters
2. Use `-r` carefully in large directory structures
3. Combine with other commands (like wc, sort, uniq) for powerful text processing
4. Use `-l` to find files first, then search within specific files
5. Add context to matches using `-A`, `-B`, or `-C` options when needed

## Common Mistakes to Avoid
- Not escaping special characters in patterns
- Forgetting to use quotes around patterns with spaces
- Using grep recursively without proper path specification
- Not considering case sensitivity in searches
- Overlooking regular expression syntax differences

## Additional Resources
- `man grep` - Complete grep manual
- [GNU Grep Manual](https://www.gnu.org/software/grep/manual/grep.html)
- [Regular Expression Testing Tools](https://regex101.com)

## Notes & Observations
- grep is case-sensitive by default
- Regular expressions are powerful but need careful syntax
- Combining grep with other commands enhances its utility
- Performance can be affected when searching large files

## References
1. [GNU Grep Documentation](https://www.gnu.org/software/grep/)
2. [Linux Documentation Project](https://tldp.org/)
3. [Regular Expression Guide](https://www.regular-expressions.info/)

---
*Last Updated: June 18, 2025*

