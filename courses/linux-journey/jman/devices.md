# Devices

* `udev` - automatically creates device files on connect/disconnect
* `udevadm info --query=all --name=/dev/sda`
* `lspci`, `lsusb`, `lspci` (SCSI)
## Device types

* c - character
* b - block
* p, pipe - two or more procs communicating, send output to other process
* s, socket - like pipe but can communicate with many processes

* major number - device driver id
* minor number - unique device id

## Device names

* SCSI ("scuzzy") - Small Computer System Interface
    * prefixed by `sd` (SCSI disk)
    * `/dev/sda`, `/dev/sdb` - first and second disk
* PATA - on older devices. `/dev/hda`

## sysfs

* `/dev` - for device management. `/sys` - for detailed info and management
*

## `dd`

* `dd if=/home/pete/backup.img of=/dev/sdb bs=1024` will copy until the end of
* file or until `count=${n}` bytes where copied. `bs=1M` for 1 megabyte.
