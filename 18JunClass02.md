# Windows User Management - Technical Practical

## Overview
**Course**: Windows Server Administration  
**Date**: June 18, 2025  
**Topic**: Local User Management and Access Control  
**Duration**: 2 Hours

## Objectives
- [x] Understanding Windows user account types and security contexts
- [x] Managing local users, groups, and built-in accounts
- [x] Configuring user permissions and access rights
- [x] Implementing user security policies
- [x] Understanding service accounts and system contexts

## Prerequisites
- Windows Server 2022/2025 or Windows 10/11 Pro/Enterprise
- Administrative access to the system
- Basic understanding of Windows security concepts
- Computer Management console access

## Environment Setup
```powershell
# System Information
OS: Windows Server 2022/Windows 10/11 Pro
Computer Management: Local Users and Groups enabled
Administrative Tools: Accessible
Security Settings: Configurable
```

## Concepts & Tools Covered

### 1. Local Users and Groups Management
```powershell
# Access Path
Computer Management > System Tools > Local Users and Groups

# PowerShell Alternative
Get-LocalUser    # List local users
Get-LocalGroup   # List local groups
```

**Purpose**: Manage local user accounts, groups, and their security settings on Windows systems.

**Key Management Tools**:
- Computer Management Console
- Local Security Policy
- User Account Control (UAC)
- PowerShell User Management Cmdlets
- Local Group Policy Editor (gpedit.msc)
- Security Configuration Manager

**Common Tasks**:
1. User account creation and modification
2. Group membership management
3. Password policy enforcement
4. Security permissions configuration
5. Service account management

## Windows Account Types in Detail

### 1. Built-in Administrator Account

**Characteristics**:
- Account SID ends in 500
- Cannot be deleted (only disabled)
- Not affected by UAC by default
- Has complete system access

**Capabilities**:
- Full system control
- Access to all files and resources
- Can manage all other accounts
- Bypass most security restrictions

**Security Considerations**:
- Should be renamed and disabled when not needed
- Access should be heavily audited
- Password should be complex and frequently changed
- Use separate admin accounts for daily admin tasks

### 2. Regular Administrator Accounts

**Capabilities**:
- Create, modify, and delete user accounts
- Install and uninstall software
- Make system-wide changes
- Access all files and folders
- Modify system settings
- Run elevated processes
- Change security policies
- Manage local groups and permissions

**Limitations**:
- Subject to UAC prompts
- Can be restricted by group policy
- Auditable actions

**Best Practices**:
- Use standard account for daily tasks
- Only elevate to admin when necessary
- Implement strong password policies
- Regular security audits
- Enable UAC notifications

### 3. Power Users

**Capabilities**:
- Install some applications (user-specific)
- Modify their own account settings
- Access most system tools
- Create and modify local files
- Limited system modifications

**Cannot**:
- Create new user accounts
- Modify other user accounts
- Access protected system files
- Make system-wide changes
- Modify system security settings

**Use Cases**:
- Development environments
- Technical users
- Application testing
- Limited administrative tasks

### 4. Standard Users

**Capabilities**:
- Use installed applications
- Modify their own user settings
- Change their own password
- Access their own files
- View system settings

**Cannot**:
- Install most applications
- Modify other accounts
- Change system settings
- Access protected files
- Create new users
- Modify security settings

**Recommended for**:
- Daily computer use
- Regular employees
- General purpose computing
- Enhanced security

### 5. Guest Account

**Characteristics**:
- Disabled by default
- Limited access rights
- No password required
- Temporary profile

**Capabilities**:
- Basic system access
- Use installed applications
- Temporary file storage

**Security Considerations**:
- Should remain disabled in most cases
- No persistent storage
- Cannot install software
- Limited network access

### 6. Service Accounts

#### Local Service Account
**Characteristics**:
- Minimal privileges
- Acts as computer on local system
- Anonymous network access

#### Network Service Account
**Characteristics**:
- More privileges than Local Service
- Authenticates as computer account on network
- Used for network services

#### System Account
**Characteristics**:
- Highest level of privileges
- Used by Windows OS
- Full system access
- Should not be used for regular services

## Practical Exercises

### Exercise 1: Managing Built-in Accounts
**Objective**: Secure built-in administrator and guest accounts

**Steps**:
1. Access Local Users and Groups
   ```powershell
   compmgmt.msc
   ```

2. Secure Built-in Administrator
   ```powershell
   # Rename Administrator account
   Rename-LocalUser -Name "Administrator" -NewName "Admin-Secure"
   
   # Disable account when not needed
   Disable-LocalUser -Name "Admin-Secure"
   ```

3. Configure Guest Account
   ```powershell
   # Ensure Guest account is disabled
   Disable-LocalUser -Name "Guest"
   ```

### Exercise 2: Creating Administrative Users
**Objective**: Create and configure administrative accounts properly

**Steps**:
1. Create Admin Account
   ```powershell
   New-LocalUser -Name "AdminUser" -FullName "Administrative User" -Description "Controlled Admin Account"
   Add-LocalGroupMember -Group "Administrators" -Member "AdminUser"
   ```

2. Configure UAC Settings
   ```powershell
   # Access UAC Settings
   UserAccountControlSettings.exe
   ```

### Exercise 3: Service Account Management
**Objective**: Create and configure service accounts

**Steps**:
1. Create Service Account
   ```powershell
   New-LocalUser -Name "SvcAcct" `
       -Description "Service Account" `
       -PasswordNeverExpires $true `
       -UserMayNotChangePassword $true
   ```

2. Configure Service Account Rights
   ```powershell
   # Using Local Security Policy
   secpol.msc
   ```

## Best Practices
1. Always use least-privilege principle
2. Create separate admin accounts for administrative tasks
3. Disable built-in Administrator when possible
4. Never use System account for services
5. Regularly audit user accounts and groups
6. Implement strong password policies
7. Enable account lockout policies
8. Regular security reviews
9. Document all privileged accounts
10. Use service accounts only for services

## Common Mistakes to Avoid
- Using built-in Administrator for daily tasks
- Enabling Guest account unnecessarily
- Weak service account passwords
- Overuse of administrative privileges
- Disabled UAC
- Improper permission inheritance
- Unmonitored privileged accounts
- Using System account for services
- Not documenting admin accounts
- Neglecting regular account audits

## Additional Resources
- [Windows Security Documentation](https://docs.microsoft.com/en-us/windows-server/security/security-and-assurance)
- [User Account Management Guide](https://docs.microsoft.com/en-us/windows/security/identity-protection/access-control/managing-user-accounts)
- [Service Account Documentation](https://docs.microsoft.com/en-us/windows/security/identity-protection/access-control/service-accounts)

## Notes & Observations
- UAC prompts indicate elevated privileges needed
- Service accounts require special attention
- Built-in accounts need careful management
- Regular maintenance ensures security
- Document all account modifications
- Monitor privileged account usage

## Quick Reference: Account Type Comparison

| Feature/Capability                | Built-in Admin | Regular Admin | Power User | Standard User | Guest | Service Account |
|----------------------------------|----------------|---------------|------------|---------------|-------|-----------------|
| Create User Accounts             | ✓             | ✓            | ✗          | ✗             | ✗     | ✗               |
| Install System-wide Apps         | ✓             | ✓            | Limited    | ✗             | ✗     | ✗               |
| Modify System Settings           | ✓             | ✓            | Limited    | ✗             | ✗     | Context-specific |
| Change Own Password             | ✓             | ✓            | ✓          | ✓             | ✗     | ✗               |
| Access All Files                | ✓             | ✓            | Limited    | Own Only      | Limited| Context-specific |
| Run as Administrator            | Always         | ✓            | Limited    | ✗             | ✗     | Context-specific |
| Modify Security Settings        | ✓             | ✓            | ✗          | ✗             | ✗     | ✗               |
| Use Installed Applications      | ✓             | ✓            | ✓          | ✓             | ✓     | Context-specific |
| View System Settings           | ✓             | ✓            | ✓          | ✓             | Limited| Context-specific |
| Create Local Groups            | ✓             | ✓            | ✗          | ✗             | ✗     | ✗               |
| Bypass UAC                     | Default       | ✗            | ✗          | ✗             | ✗     | Context-specific |
| Network Access                 | Full          | Full         | Limited    | Limited        | Limited| Context-specific |
| Run Services                   | ✓             | ✓            | Limited    | ✗             | ✗     | ✓               |

## References
1. [Microsoft Windows Server Documentation](https://docs.microsoft.com/en-us/windows-server/)
2. [Windows Security Best Practices](https://docs.microsoft.com/en-us/windows/security/threat-protection/security-policy-settings/security-policy-settings)
3. [User Account Control Documentation](https://docs.microsoft.com/en-us/windows/security/identity-protection/user-account-control/user-account-control-overview)
4. [Service Account Security](https://docs.microsoft.com/en-us/windows-server/security/windows-services/service-accounts)

---
*Last Updated: June 18, 2025*
