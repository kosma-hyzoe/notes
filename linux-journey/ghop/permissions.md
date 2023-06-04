# Permissions

## General

* umask 021 - new files start with 756 (sic!)

* d/-/. - dir/regular file/script

* r - readable
* w - writeable
* x - executable
* s - SUID, get permissions of the file creator when run

* chown kosma foo.txt - modify user ownership
* chgrp gang foo.txt - modify group ownership
* chown kosma:gang foo.txt - both at the same time

## chmod

* chmod u+x foo.sh - add exec permissions on the user bit
* chmod u-rw foo.sh - remove read and write perms
* 4/2/1 - read, write, exec
* chmod u+s/chomd 4755 - append SUID perms
* chmod g+s/chmod 2755 - append SGID perms

## SUID / GUID

* SUID - get file owner and exec permissions when running a file.
  * `chmod u+s` / `chmod 4755` -> `-rwsr-x-r-x`
  * capital `S` means there are no execute permissions.
* GUID: `chmod g+s` / `chmod 2555` -> `-rwxr-sr-x`

## Process permissions

* effective user ID - takes SUIDs and GUIDs into account
* real user ID - actual user-who-runs ID
* saved user ID - switch between effective and real user ID

## Sticky bit

* `drwxrwxrwxt` - the `t` means only owner and root can delete the file.
* `chmod +t mydir` / `chmod 1755 mydir`
