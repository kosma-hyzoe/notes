# SSH

* `ssh-copy-id -i ~/.ssh/id_rsa.pub root@serv.local`
* `ssh-agent; ssh-add ~/.ssh/id_rsa ` - add key password to memory
* `systemctl restart sshd`
* `journalctl -fu ssh`
* `/var/log/auth.log`
* Consider using non-default ports
