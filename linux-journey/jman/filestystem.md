#  Filesystem

## General

* `mkfs -t ext4 /dev/sdb2` - only use on partitions with no existing fs
* `mount -t ext4 /dev/sdb2 /mymountpoint`
* `unmount /mymountpoint` or `/unmount /dev/sdb2`
* can use the `UUID=` arg instead of path
* `blkid` - display block device UUID
* auto mount by adding file to `/etc/fstab` (pronounced "eff es tab")
* `man fstab`
* `du -h` - show disk usage
* `df` - how much *disk* is *free*
* `fsck /dev/sda` - check and try to repair the filesystem

## Dir structure

* `/etc` - core system configuration directory
* `/lib` - libs that bins use
* `/media` - attachment point for removable media
* `/mnt` - temporarilt mounted filesystems
* `/opt` - optional, self-contained app software packages
* `/sbin` - essential system binaries (root only)
* `/run` - info about running system since last boot
* `/srv` - site specific data served by the system (on servers
* `/usr` - user installed software and utils. "non-essential"
    * `/usr/local/bin` - self-compiled bins or not a part of package manager
* `/var` - "variable directory", system logging, user tracking, caches,
  stuff subject to change.
  `/tmp` - NON-PERSISTENT BETWEEN REBOOTS!

## Filesystem types

* Linux always uses Virtual File System (VFS) abstraction layer.
* Journaling: before copy/write operations, journal/log the operation
* and log it's completion for easy recovery points.
* `df -T`

## Disk anatomy

* `sudo parted -l` - bhow partition data

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

## Disk partitioning (using `parted`)

* select /dev/sdb2
* print
* `mkpart primary 123 4567` / `mkpart ${type} ${start} ${end}`

## Swap

* `mkswap /deb/sdb2`
* `swapon /deb/sdb2`
* add to `/etc/fstab`
* `swapoff /deb/sdb2`


## Inodes (Index nodes)

An inode table is a database that manages the files on a filestystem. `df -i`
Allocated automatically on fs creation. "Out of indode space" errrors may occur,
though not very often.

* File type - regular file, directory, character device, etc
* Owner
* Group
* Access permissions
* Timestamps
    * mtime (time of last file modification)
    * ctime (time of last attribute change), atime (time of last access)
* Number of hardlinks to the file
* Size of the file
* Number of blocks allocated to the file
* Pointers to the data blocks of the file - most important!

 Inodes point to the actual data blocks of your files. In a typical filesystem
 (not all work the same), each inode contains 15 pointers, the first 12 pointers
 point directly to the data blocks. Pointers 13-15 point to a block
 containing pointers to more blocks.

 * Hardlinks create another files with a link (pointer?) to the same inode.
