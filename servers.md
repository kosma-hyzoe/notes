## Mounting SMB as CIFS

```
# in fstab
//192.168.x.x/public /mnt/public cifs username=guest,password=foobar,uid=1000,gid=1000,file_mode=0660`
# in cli
sudo mount -t cifs //192.168.x.x/public /mnt/public -o username=guest
```
Alternatively, `noperm` can be used instead of `uid`, `gid` and `file_mode`
