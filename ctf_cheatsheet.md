# Tools and Commands Cheatsheet for CTFs


## Enumeration:

### NMAP Commands:

- for TCP Port Scanning in Aggressive Mode with Script and Version scanning:
```
nmap -sV -sC -A $IP -p- -vv -oN tools/nmap/nmap_tcp_agressive.txt
```

- for UDP Port Scanning in Aggressive Mode with Script and Version scanning:
```
nmap -sU -sV -sC -A $IP -p- -vv -oN tools/nmap/nmap_tcp_agressive.txt
```

### Rustscan Commands:

- simple TCP rustscan with NMAP options:

```
rustscan -a $IP -- -sV -sV -Pn -oN tools/nmap/nmap.txt -vv
```

### Feroxbuster Commands:

- feroxbuster command to scan directory of target with -x php,txt,html

```
mkdir -p tools/feroxbuster/ && feroxbuster -u http://planning.htb/ -x php,txt,html --no-recursion -vv -o tools/feroxbuster/output.txt
```

## Linux Basic Shell Commands:

### find Commands:

- finding files or any search pattern with combining find and grep together:

```
find /home -type f -exec grep -H "search_pattern" {} + 2>/dev/null
```

