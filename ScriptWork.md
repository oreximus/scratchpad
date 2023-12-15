# Script Work

## To Achieve

- creating an script which takes input, of sevices and applications names and tell us the Available Vulnerabilities for it!

### Tools and Applications:

- we are getting output from :

1. pyexploitdb

**code**:
```
from pyExploitDb import PyExploitDb

pEdb = PyExploitDb()
pEdb.debug = False
pEdb.openFile()
results = pEdb.searchCve("CVE-2019-0211")
print(results)
```
**sample output**:
```
Pulling exploit-database updates...
Updating db...
Refreshing EDBID-CVE mapping. This may take a long time.
Loading database...
CVE-2019-0211
{'id': '46676', 'file': 'exploits/linux/local/46676.php', 'description': "Apache 2.4.17 < 2.4.38 - 'apache2ctl graceful' 'logrotate' Local Privilege Escalation", 'date': '2019-04-08', 'author': 'cfreal', 'type': 'local', 'platform': 'linux', 'port': '', 'date_updated': '2019-04-08', 'verified': '0', 'codes': 'CVE-2019-0211', 'tags': '', 'aliases': '', 'app_url': '', 'src_url': 'https://github.com/cfreal/exploits/blob/ba026fae59974037d744a90cef09224f751bc3e4/CVE-2019-0211-apache/cfreal-carpediem.php'}
```

2. vulners.com API

**command used**:
```
curl -XPOST https://vulners.com/api/v3/burp/softwareapi/ -H  'Content-Type: application/json' -d '{                             ✔  .env  
"software": "apache",
"version": "2.4.29",
"type": "software",
"maxVulnerabilities": 10,
"apiKey": "UBKV0D5ABB8MAOK3C6TOC1M25E6E87HAHK1OBXSBLYLTKBI4VVZ50Y6B527XRZOQ"
}'
```

**output**:
```
{
  "result": "OK",
  "data": {
    "search": [
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "17C6AD2A-8469-56C8-BBBE-1764D0DF1680",
        "doc_type": "bulletin",
        "_source": {
          "id": "17C6AD2A-8469-56C8-BBBE-1764D0DF1680",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# Rapid Reset Client\n\nRapid Reset Client is a tool for testing m...",
          "published": "2023-10-13T23:55:32",
          "modified": "2023-12-14T01:19:11",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:46:24",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "17C6AD2A-8469-56C8-BBBE-1764D0DF1680"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "5A864BCC-B490-5532-83AB-2E4109BB3C31",
        "doc_type": "bulletin",
        "_source": {
          "id": "5A864BCC-B490-5532-83AB-2E4109BB3C31",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# CVE-2023-44487-\n----------------------------------------------...",
          "published": "2023-12-11T23:12:03",
          "modified": "2023-12-11T23:13:25",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:38:00",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "5A864BCC-B490-5532-83AB-2E4109BB3C31"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "9814661A-35A4-5DB7-BB25-A1040F365C81",
        "doc_type": "bulletin",
        "_source": {
          "id": "9814661A-35A4-5DB7-BB25-A1040F365C81",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# HTTP/2 Rapid Reset: CVE-2023-44487\n\n## Description\n\nThis repos...",
          "published": "2023-10-11T01:59:47",
          "modified": "2023-12-14T15:05:49",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:47:15",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "9814661A-35A4-5DB7-BB25-A1040F365C81"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "A820A056-9F91-5059-B0BC-8D92C7A31A52",
        "doc_type": "bulletin",
        "_source": {
          "id": "A820A056-9F91-5059-B0BC-8D92C7A31A52",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# Golang CVE-2023-44487 testing\n\nThis repository contains testin...",
          "published": "2023-10-25T09:11:46",
          "modified": "2023-10-26T15:03:08",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:43:36",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "A820A056-9F91-5059-B0BC-8D92C7A31A52"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "B0208442-6E17-5772-B12D-B5BE30FA5540",
        "doc_type": "bulletin",
        "_source": {
          "id": "B0208442-6E17-5772-B12D-B5BE30FA5540",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# CVE-2023-44487\nBasic vulnerability scanning to see if web serv...",
          "published": "2023-10-10T14:20:42",
          "modified": "2023-12-14T15:26:10",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:47:17",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "B0208442-6E17-5772-B12D-B5BE30FA5540"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "BD3652A9-D066-57BA-9943-4E34970463B9",
        "doc_type": "bulletin",
        "_source": {
          "id": "BD3652A9-D066-57BA-9943-4E34970463B9",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# CVE-2023-44487 and http2-rst-stream-attacker\n\n## CVE-2023-4448...",
          "published": "2023-11-08T20:56:22",
          "modified": "2023-12-06T21:53:51",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:40:23",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "BD3652A9-D066-57BA-9943-4E34970463B9"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "C9A1C0C1-B6E3-5955-A4F1-DEA0E505B14B",
        "doc_type": "bulletin",
        "_source": {
          "id": "C9A1C0C1-B6E3-5955-A4F1-DEA0E505B14B",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# HTTP/2 Rapid Reset Client (C#)\n\nThe HTTP/2 Rapid Reset Client,...",
          "published": "2023-11-24T18:26:36",
          "modified": "2023-12-12T14:49:12",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:39:29",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "C9A1C0C1-B6E3-5955-A4F1-DEA0E505B14B"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "DB6E1BBD-08B1-574D-A351-7D6BB9898A4A",
        "doc_type": "bulletin",
        "_source": {
          "id": "DB6E1BBD-08B1-574D-A351-7D6BB9898A4A",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# CVE-2023-44487 (HTTP/2 Rapid Reset)\r\nThere are some examples i...",
          "published": "2023-11-10T08:38:51",
          "modified": "2023-11-23T20:35:44",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:41:21",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "DB6E1BBD-08B1-574D-A351-7D6BB9898A4A"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "E5C174E5-D6E8-56E0-8403-D287DE52EB3F",
        "doc_type": "bulletin",
        "_source": {
          "id": "E5C174E5-D6E8-56E0-8403-D287DE52EB3F",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# HTTP2 Rapid Reset Attack: CVE-2023-44487\nQuick exploit to test...",
          "published": "2023-10-16T11:07:50",
          "modified": "2023-12-10T09:24:06",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:46:00",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "E5C174E5-D6E8-56E0-8403-D287DE52EB3F"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "F7F6E599-CEF4-5E03-8E10-FE18C4101E38",
        "doc_type": "bulletin",
        "_source": {
          "id": "F7F6E599-CEF4-5E03-8E10-FE18C4101E38",
          "type": "githubexploit",
          "bulletinFamily": "exploit",
          "title": "Exploit for Uncontrolled Resource Consumption in Ietf Http",
          "description": "# HTTP/2 Rapid Reset Client (C#)\n\nThe HTTP/2 Rapid Reset Client,...",
          "published": "2023-11-24T18:26:36",
          "modified": "2023-12-12T14:49:12",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            }
          },
          "href": "",
          "cvelist": [
            "CVE-2023-44487"
          ],
          "lastseen": "2023-12-14T16:39:30",
          "privateArea": 1
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "F7F6E599-CEF4-5E03-8E10-FE18C4101E38"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "OSV:BIT-2023-31122",
        "doc_type": "bulletin",
        "_source": {
          "id": "OSV:BIT-2023-31122",
          "type": "osv",
          "bulletinFamily": "software",
          "title": "BIT-2023-31122",
          "description": "Out-of-bounds Read vulnerability in mod_macro of Apache HTTP Server.This issue affects Apache HTTP Server: through 2.4.57.",
          "published": "2023-10-29T07:16:56",
          "modified": "2023-10-29T07:42:36",
          "cvss": {
            "score": 6.4,
            "vector": "AV:N/AC:L/Au:N/C:P/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:P/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "PARTIAL",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 6.4
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 4.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:H/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "HIGH",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 9.1,
              "baseSeverity": "CRITICAL"
            },
            "exploitabilityScore": 3.9,
            "impactScore": 5.2
          },
          "href": "https://osv.dev/vulnerability/BIT-2023-31122",
          "cvelist": [
            "CVE-2023-31122"
          ],
          "lastseen": "2023-10-30T15:06:11",
          "affectedSoftware": [
            {
              "version": "2.4.57",
              "operator": "lt",
              "name": "apache"
            }
          ]
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "OSV:BIT-2023-31122"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "OSV:BIT-2023-43622",
        "doc_type": "bulletin",
        "_source": {
          "id": "OSV:BIT-2023-43622",
          "type": "osv",
          "bulletinFamily": "software",
          "title": "BIT-2023-43622",
          "description": "An attacker, opening a HTTP/2 connection with an initial window size of 0, was able to block handling of that connection indefinitely in Apache HTTP Server. This could be used to exhaust worker resources in the server, similar to the well known \"slow loris\" attack pattern.This has been fixed in version 2.4.58, so that such connection are terminated properly after the configured connection timeout.This issue affects Apache HTTP Server: from 2.4.55 through 2.4.57.Users are recommended to upgrade to version 2.4.58, which fixes the issue.",
          "published": "2023-11-02T07:16:32",
          "modified": "2023-11-02T07:42:39",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            },
            "exploitabilityScore": 3.9,
            "impactScore": 3.6
          },
          "href": "https://osv.dev/vulnerability/BIT-2023-43622",
          "cvelist": [
            "CVE-2023-43622"
          ],
          "lastseen": "2023-11-02T15:20:14",
          "affectedSoftware": [
            {
              "version": "2.4.55",
              "operator": "ge",
              "name": "apache"
            },
            {
              "version": "2.4.58",
              "operator": "lt",
              "name": "apache"
            }
          ]
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "OSV:BIT-2023-43622"
      },
      {
        "index": "es6_bulletins_bulletin_v2",
        "id": "OSV:BIT-2023-45802",
        "doc_type": "bulletin",
        "_source": {
          "id": "OSV:BIT-2023-45802",
          "type": "osv",
          "bulletinFamily": "software",
          "title": "BIT-2023-45802",
          "description": "When a HTTP/2 stream was reset (RST frame) by a client, there was a time window were the request's memory resources were not reclaimed immediately. Instead, de-allocation was deferred to connection close. A client could send new requests and resets, keeping the connection busy and open and causing the memory footprint to keep on growing. On connection close, all resources were reclaimed, but the process might run out of memory before that.This was found by the reporter during testing of CVE-2023-44487 (HTTP/2 Rapid Reset Exploit) with their own test client. During \"normal\" HTTP/2 use, the probability to hit this bug is very low. The kept memory would not become noticeable before the connection closes or times out.Users are recommended to upgrade to version 2.4.58, which fixes the issue.",
          "published": "2023-11-02T07:16:21",
          "modified": "2023-11-02T07:42:39",
          "cvss": {
            "score": 5.0,
            "vector": "AV:N/AC:L/Au:N/C:N/I:N/A:P"
          },
          "cvss2": {
            "cvssV2": {
              "version": "2.0",
              "vectorString": "AV:N/AC:L/Au:N/C:N/I:N/A:P",
              "accessVector": "NETWORK",
              "accessComplexity": "LOW",
              "authentication": "NONE",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "PARTIAL",
              "baseScore": 5.0
            },
            "severity": "MEDIUM",
            "exploitabilityScore": 10.0,
            "impactScore": 2.9,
            "acInsufInfo": false,
            "obtainAllPrivilege": false,
            "obtainUserPrivilege": false,
            "obtainOtherPrivilege": false,
            "userInteractionRequired": false
          },
          "cvss3": {
            "cvssV3": {
              "version": "3.1",
              "vectorString": "CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:N/I:N/A:H",
              "attackVector": "NETWORK",
              "attackComplexity": "LOW",
              "privilegesRequired": "NONE",
              "userInteraction": "NONE",
              "scope": "UNCHANGED",
              "confidentialityImpact": "NONE",
              "integrityImpact": "NONE",
              "availabilityImpact": "HIGH",
              "baseScore": 7.5,
              "baseSeverity": "HIGH"
            },
            "exploitabilityScore": 3.9,
            "impactScore": 3.6
          },
          "href": "https://osv.dev/vulnerability/BIT-2023-45802",
          "cvelist": [
            "CVE-2023-44487",
            "CVE-2023-45802"
          ],
          "lastseen": "2023-11-02T15:22:34",
          "affectedSoftware": [
            {
              "version": "2.4.58",
              "operator": "lt",
              "name": "apache"
            }
          ]
        },
        "found": true,
        "_index": "es6_bulletins_bulletin_v2",
        "_type": "bulletin",
        "_id": "OSV:BIT-2023-45802"
      }
    ],
    "total": 13,
    "total_by_family": {
      "exploit": 10,
      "software": 3
    }
  }
}
```

3. searchsploit/offline exploitdb

**command**:

```
searchsploit apache 2.4.29
```

**output**

```
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                                                                                                                    |  Path
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- ---------------------------------
Apache + PHP < 5.3.12 / < 5.4.2 - cgi-bin Remote Code Execution                                                                                                                   | php/remote/29290.c
Apache + PHP < 5.3.12 / < 5.4.2 - Remote Code Execution + Scanner                                                                                                                 | php/remote/29316.py
Apache 2.4.17 < 2.4.38 - 'apache2ctl graceful' 'logrotate' Local Privilege Escalation                                                                                             | linux/local/46676.php
Apache CXF < 2.5.10/2.6.7/2.7.4 - Denial of Service                                                                                                                               | multiple/dos/26710.txt
Apache mod_ssl < 2.8.7 OpenSSL - 'OpenFuck.c' Remote Buffer Overflow                                                                                                              | unix/remote/21671.c
Apache mod_ssl < 2.8.7 OpenSSL - 'OpenFuckV2.c' Remote Buffer Overflow (1)                                                                                                        | unix/remote/764.c
Apache mod_ssl < 2.8.7 OpenSSL - 'OpenFuckV2.c' Remote Buffer Overflow (2)                                                                                                        | unix/remote/47080.c
Apache OpenMeetings 1.9.x < 3.1.0 - '.ZIP' File Directory Traversal                                                                                                               | linux/webapps/39642.txt
Apache Tomcat < 5.5.17 - Remote Directory Listing                                                                                                                                 | multiple/remote/2061.txt
Apache Tomcat < 6.0.18 - 'utf8' Directory Traversal                                                                                                                               | unix/remote/14489.c
Apache Tomcat < 6.0.18 - 'utf8' Directory Traversal (PoC)                                                                                                                         | multiple/remote/6229.txt
Apache Tomcat < 9.0.1 (Beta) / < 8.5.23 / < 8.0.47 / < 7.0.8 - JSP Upload Bypass / Remote Code Execution (1)                                                                      | windows/webapps/42953.txt
Apache Tomcat < 9.0.1 (Beta) / < 8.5.23 / < 8.0.47 / < 7.0.8 - JSP Upload Bypass / Remote Code Execution (2)                                                                      | jsp/webapps/42966.py
Apache Xerces-C XML Parser < 3.1.2 - Denial of Service (PoC)                                                                                                                      | linux/dos/36906.txt
Webfroot Shoutbox < 2.32 (Apache) - Local File Inclusion / Remote Code Execution                                                                                                  | linux/remote/34.pl
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
```

