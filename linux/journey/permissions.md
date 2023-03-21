# Permissions

## General

* umask 021 - new files start with 756 (sic!)

* d/-/. - dir/regular file/script
* current user, group, everyone (else?)

* r - readable
* w - writeable
* x - executable
* s - SUID, get permissions of the file creator when run

* chown kosma foo.txt - modify user ownership
* chgrp gang foo.txt - modify user ownership
* chown kosma:gang foo.txt - both at the same time 

## chmod 

* chmod u+x foo.sh - add exec permissions on the user bit
* chmod u-rw foo.sh - remove read and write perms
* 4/2/1 - read, write, exec
* chmod u+s/chomd 4755 - append SUID perms
* chmod g+s/chmod 2755 - append SGID perms

## UIDs

* effective user ID (of the file/process that was run )
* real user ID (of the user that launched the process)

## Note

* continue on 7. of chapter Permissions!
