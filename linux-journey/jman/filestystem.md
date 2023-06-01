#  Filesystem

* `/etc` - core system configuration directory
* `/lib` - libs that bins use
* `/media` - attachment point for removable media
* `/mnt` - temporarilt mounted filesystems
* `/opt` - optional app software packages (TODO ?)
* `/sbin` - essential system binaries
* `/run` - info about running system since last boot
* `/srv` - site specific data served by the system (TODO ?)
* `/usr` - user installed software and utils
* `/var` - "variable directory", system logging, user tracking, caches,
  stuff subject to change.

## Filesystem types

* Linux always uses Virtual File System (VFS) abstraction layer.
* Journaling: before copy/write operations, journal/log the operation (TODO in
  in then the system can recover from here, right?) and log it's completion.
* `df -T`

## Disk anatomy

* `sudo parted -l` - show partition data

* boot block - for booting the filesystem
* super block - info about the filesystem
* inode table - database
* data blocks - data

## Partition table types

MBR:

* Traditional partition table, was used as the standard
* Can have primary, extended, and logical partitions
* MBR has a limit of four primary partitions
Additional partitions can be made by making a primary partition into an extended
partition (there can only be one extended partition on a disk). Then inside the
extended partition you add logical partitions. The logical partitions are used
just like any other partition. Silly I know. Supports disks up to 2 terabytes

GPT:

* GUID Partition Table (GPT) is becoming the new standard for disk partitioning
* Has only one type of partition and you can make many of them
* Each partition has a globally unique ID (GUID)
* Used mostly in conjunction with UEFI based booting (we'll get into details in another course)

## Disk partitioning

```bash
sudo parted
(parted) select /dev/sdb2
(parted) print
mkpart primary 123 4567
```

