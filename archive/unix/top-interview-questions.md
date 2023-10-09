# Top Interview Questions

Most of these commands are from 
["Top 10 Linux Job Interview Questions" @ YT](https://www.youtube.com/watch?v=l0QGLMwR-lY)

## Basics

* `uname` - print system info
  * -a - all
  * -r - kernel release
  * -v - kernel version

* `ipconfig`/`ip addr show` - show ip

## Disk usage

* `df -ah` - show disk use
* `du -sh mydir` - total file/dir space use

## Processes

* `service udev start/status/start` - service management, non-systemd distros
* `systemctl status/start/stop gdm` - stop/start GUI session
* `telinit 3/5` - stop/start GUI session (non-systemd?)
* `ps aux | grep nginx` - show processes (?) 

## Ports

* `netstat -tulpn` - show open ports

## Mounting

`mount /dev/sda2 /mnt`
`mount` - check existing mounts
`/etc/fstab` - drives mounted at boot

