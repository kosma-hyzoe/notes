# User management

* `su` - substitute user, by default root
* `visudo` - edit `/etc/sudoers`
* `useradd`/`userdel`
* `passwd joe` - change password for joe

## /etc/passwd

Fields:
* x - password in shadow
* '*' -  no login access
* ' ' - no password
* user ID
* group ID 
* GECOS field - comments, comma delimited
* home dir
* user shell

## /etc/shadow

Fields:
* username
* encrypted password
* date of password change
* min/max password age
* password warning period 
* password inactivity warning (still allowed to login after expiration)

