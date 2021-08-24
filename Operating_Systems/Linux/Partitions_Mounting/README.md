**Disk Partition**
- [Why](#why)
- [Primary, Extended Partitions](#pe)
- **Types of Linux Partitions**
  - [Data Partition](#dp)
  - [Swap Partition](#sp)
- **Disk Partitioning Schemes**
  - [MBR(Master Boot Record)](#mbr)
  - [GPT(GUID Partition Table)](#gpt)
- **Partitioning**
  - **Using parted**
    - [100MB MBR partition](#100m)
    - [100MB GPT Partition](#100g)
    - [500MB SWAP](#500s)
  - **Using fdisk or gdisk**
    - [MBR Partition](#mbr)
    - [GPT Partition](#gpt)
- **LVM**
  - [Terms: Physical Volume, Logical Volume, Volume Group](#te)
  - [Creating Logical Volume](#cre)
- **Others**
  - [1. Combine 2 linux partitions to Create Volume Group(test-vg) & create Logical-Volume arya(512MB) mount on /start](#o1)
  - [2. Existing Logical-Volume (loans=256MB). Increase It to 768MB. Mount at /finance/loans](#o2)
  - [3. Logical-volume(/dev/finance/loans=768MB), Reduce to 256MB, Again resize to 768MB. Without Loss of data](#o3)
  - [4. Make Volume-Group(oracleVG having each physicalExtentSize=8MB), (Logical Volume red_lv will have 100 extents), red_lv is ext3 formatted](#o4)
- [Creating Bootable USB](#creu)
- [Mounting USB Device](#mou)


## Disk Partition
Dividing hard drive into multiple logical storage units called partitions. Disk is partitioned at time of OS installation or later whenever we need to extend/create a partition(using fdisk)
<a name=why></a>
#### Why
- Limit available space to applications or users. 
- Create a separate area for memory swapping.  
- Data security in case of disaster, In case of accident, only the data in the partition that got the hit will be damaged.
```c
Hard Disk: /dev/sda or /dev/sdb or /dev/sdc or /dev/hda        
Floppy Disk: /dev/fd0 or /dev/fd1 or /dev/fd2 ..        
CDROM: /dev/sdc0 or /dev/sdc1        
Virtual Machine partions: /dev/vda1 or /dev/vda2

Partition Type Numbers?
ext2/ext3/ext4 (Linux Partitions),
Swap(82), 
Data(83), 
FAT/VFAT(For Windows Data), 
JFS/NFS/FATxx(New Reiser File System).
```
<a name=pe></a>
#### Primary, Extended Partitions? 
A MBR-partitioned disk, create 3 primary partitions and 1 extended partition. Extended partition serves as a container within which we can create multiple logical partitions. 

## Types of Linux Partitions
<a name=dp></a>
### A. Data Partition
This contains all data, also contains root partition(data for system to run at startup).

**Root Partition(100-150MB)**:  
- This is indicated by /. 
- Contains system configuration files, most basic commands and server programs, system libraries, some temporary space and the home directory of admin user.

<a name=sp></a>
### B. Swap Partition
This partition is used when RAM fills up and more space is needed, unused/inactive pages are moved to Swap Space(swapped out).Now active pages of other process may reside on RAM.
- Types of swap spaces
  - _1. Swap Partition:_ described above
  - _2. Swap File:_ Specially configured file as a swap file using mkswap.

**RAM + Swap Space acts as Virtual Memory.**


## Disk Partitioning Schemes
<a name=mbr></a>
### A. MBR(Master Boot Record)
Used since 1982 but obsoleted by GPT. Disadvantages: 
- _1._ Only 4 Default Partitions(Max 2TiB) can be created, 5th(onwards) should be extended partition, Max 15 partitions can be created only.
- _2._ Because physical disks are getting larger, and SAN-based volumes even larger than that, the 2 TiB disk and partition size limit of the MBR partitioning scheme is no longer a theoretical limit, but rather a real-world problem.

<a name=gpt></a>
### B. GPT(GUID Partition Table)
Used by newer system running UFEI(Unified Extensible Firmware Interface). Advantages:
_1._ Provides max of 128 partitions.
_2._ Partition sizes can be max upto 8 Zebi Bytes.
_3._ Also, A GPT uses a globally unique identifier (GUID) to identify each disk and partition

## Partitioning(using parted)
### Using parted
<a name=100m></a>
#### 100MB MBR partition
```c
# parted /dev/vda mklabel msdos                   //a. Create disk label
# parted /dev/vda       	    		                //b. Create partition
(parted) ?    
(parted) mkpart
Partition type?  primary/extended? primary
File system type?  [ext2]? xfs                                            
Start? 1001MB                  //Start point of new sector on the disk.
End? 1101MB   			    //Size of partition created = Start - End.
# udevadm settle    //create device file under the /dev directory
# ls -ltr /dev    
    -See new /dev/vda4 is created
# mkfs.xfs /dev/vdb4                            //c. Create file system
# df -T                                     //Check file system type
# lsblk --fs
# /etc/fstab			                              //d. Mount File system. Know UUID using  'lsblk --fs'
UUID=7a20....   /test  xfs   defaults   0 0
# findmnt --verify
# reboot
# df   								                          //f. Verify its mounted on /test
```

<a name=100g></a>
#### 100MB GPT Partition
```c
Everything else is same
(parted) mkpart
Partition name?  []? usersdata       
//Just name need to be provided for partition
```

<a name=500s></a>
#### 500MB SWAP
```c
parted -> udevadm -> mkswap -> swapon ->
 (lsblk --fs)
# parted /dev/vdb 
(parted) mkpart type linux-swap 
start? 1001MB 
end? 1501MB
# udevadm settle
# mkswap /dev/vdb2
# swapon /dev/vdb2
# lsblk --fs /dev/vdb2
# vim /etc/fstab
    UUID=<> swap swap defaults 0 0 
```

### Using fdisk or gdisk
<a name=mbr></a>
#### MBR Partition
```c
Only 4 Default Partitions can be created, 5th(onwards) should be extended partition.
# fdisk  -l        //fdisk(Format Disk): fdisk is used to create/delete/resize/format partitions. To list partitions.
# fdisk    /dev/vda
        Command: n    //New Partition
        Select (default p):   p    //Primary Partition
        Partition Number: 1
        First Sector(default:2048):    <enter>
        Last sector    +size{k,M,G}:    +512M
        Partition 1 of type Linux and size 512M is set
        command:    t    //type    [82: Swap]
        command:    p    //Print    
        Device Boot     Start         End      Blocks   Id  System
        /dev/sda1         2048     6293503     3145728   83  Linux
        command: w //Write    |    d //delete
$  partprobe
//Format the Partition
//Normal Partition
$ mkfs    -t    <file-system-type>    /dev/vda1 
//Swap Space
$ mkswap  /dev/vda1        //applies Swap Signature to device 
$ swapon  -a    //Activate formatted Swap Space
$ swapon -s    //Check Swap partitons
$ lsblk    //Will not tell Part is swap or not, use blkid
//Mount the Partition
$ vim  /etc/fstab   			     OR       		 $ mount  /dev/vda1  /share
    //See linux-command page for <dump> <fsck> options
    <partition    OR device-file>  						       <mnt-point>	 <fs-type>  <mnt-options>  <dump> <fsck>
    UUID=7a20315d-ed8b-4e75-a5b6-24ff9e1f9838   		/share  	 	 xfs    	      defaults 	    0         2
    UUID=d00554b7-dfac-4034-bdd1-37b896023f2c    	 swap    		 swap    		defaults         0    	0
    UUID=af30cbb0-3866-466a-825a-58889a49ef33          swap    		 swap    		  pri=1           0    	0    //PRIORITY=1
$ mount  -a
$ reboot
$ mount | grep ^/
    /dev/vda1 on / type xfs (rw,relatime,seclabel,attr2,inode64,noquota)
    /dev/vdb1 on /share type xfs (rw,relatime,seclabel,attr2,inode64,noquota)            <== vdb1 mounted on /share 
```

<a name=gpt></a>
#### GPT Partition
```c
 $ gdisk    /dev/vdb
    Command (? for help): n   	     //new partition
    Partition number (1-128, default 1): 1
    First sector (34-20971486, default = 2048) or {+-}size{KMGTP}: 2048
    Last sector (2048-20971486, default = 20971486) or {+-}size{KMGTP}: 1050623 
    Hex code or GUID (L to show codes, Enter = 8300): 8e00 
    Command (? for help): w   						     //Save Partition table changes
     Do you want to proceed? (Y/N): y
$ partprobe /dev/vdb 
```

## LVM (Logical Volume Manager)
- LVM provides a methods to allocate/extend logical parititons on Hard-Disk(without complete erase/rewrite) to form larger/smaller Virtual Partitions
- For Example: 2 or more Physical Drives (Separate Hard Disks) can be combined to form single virtual Hard disk. 
<a name=te></a>
### Terms
#### Physical Volume
- This can be Hard-Disks/Partitions. This labels partition as LVM and adds header that stores configuration data. Command used: pvcreate; pvremove
- Each PV is composed of a sequence of chunks called physical extents (PEs). PEs can be same or different sizes. Default size of PE is 4MB, But custom sized physical extents can also be created. Commands: vgcreate;vgremove

#### volume Group
This is combination/summation of Physical volumes prepared using "pvcreate". 

#### Logical Volume
- Storage devices for: Applications, users. These are collection of logical extents(LE) which maps to PE(1 LE can map to more than 1 PE). 
- LVs can be used as raw block devices just like disk partitions: creating mountable file systems on them, or using them as swap storage.
```c
  		             |Log Vol-1|                 |Log Vol-2|
                                                  |          
      | Volume Group-1 |                                             | Volume Group-2 |
           |                                                               |
     --------------------                                          ------------------------
    |        |                |                                                               
| PE1 | PE2 | PE3 | PE4 | Hard Disk-1/Physical Volume(PV)       | PE1 | PE2 | PE3 | PE4 | Hard Disk-2/Physical Volume(PV)
```

<img src=lvm.png width=500>

<a name=cre></a>
### Creating Logical Volume
```c
///////////1. Disk Partition    //Create a Disk partition/Space using fdisk. Type = 8e (LVM)///////////////
Method-1:    Reserve some free Space while installing Linux    //Preferred
    While Selecting Disk > Select (I will configure Partitioning) > Done
    Create Partitions automatically > Take 10 GB for /.
    See Available Space = 40.68GB
# lsblk
    NAME                                     MAJ:MIN RM  SIZE RO TYPE MOUNTPOINT
    sda                                            8:0    0  100G  0 disk 
    ├─sda1                                     8:1    0    1G  0 part /boot
    ├─sda2                                     8:2    0 58.3G  0 part 
    │ ├─rhel_vm249--232-root 253:0        0  9.3G  0 lvm  /
    │ ├─rhel_vm249--232-swap 253:1      0  7.9G  0 lvm  [SWAP]
    │ └─rhel_vm249--232-home 253:2     0 41.1G  0 lvm  /home        <<41GB at home
# lsblk; fdisk /dev/sda
    p(print the partition table)    >    n(add a new partition)  Give Size    > t=8e(LVM)//Type    >    w(write table to disk and exit)    > /dev/sda3
# partprobe /dev/sda3

Method-2:    Already installed OS, with All space occupied by /
# lsblk 
NAME        MAJ:MIN RM  SIZE   RO TYPE MOUNTPOINT
vda                  252:0    0   15G      0 disk 
├─vda1           252:1    0  200M     0 part /boot
├─vda2           252:2    0 1000M    0 part [SWAP]
└─vda3           252:3    0 13.8G     0 part 
  ├─myvg-rootvol 253:0   0 13.3G 0 lvm  /        <<<See 13.3GB allocated to /
  └─myvg-homevol 253:1 0 500M  0 lvm  /home
# fdisk -l
   Device Boot      Start         End      Blocks   Id  System
/dev/sda1   *        2048     2099199     1048576   83  Linux
/dev/sda2         2099200    62914559    30407680   8e  Linux LVM
# fdisk /dev/sda2
    p(print the partition table)    >    n(add a new partition)  Give Size    > t=8e(LVM)//Type    >    w(write table to disk and exit)
Issue-1: No free sectors available.
    Root-Cause: There is no free space on Disk, all space is allocated to /
# partprobe


///////////////////2. Make this disk partition as Logical Volume.    pvcreate, vgcreate, lvcreate//////////////////
# lsblk; pvcreate /dev/sda3; pvscan; pvdisplay
# vgcreate test-vg /dev/sda3; vgscan; vgdisplay                    //-c: Clustered support. -y:Take input as yes
# lvcreate  -n arya  -L 512M  test-vg; lvscan; lvdisplay        //-n:name    -L:size-in-bytes    -l:number-of-physical-extents-to-allocate    name-of-volume-group-from-which LV needs to be created


///////////////////3. Format this LVM in desired file system type => gfs, xfs, ext3 etc////////////
# mkfs  -t xfs  /dev/mapper/test--vg-arya
```

### Others
<a name=o1></a>
#### 1. Combine 2 linux partitions to Create Volume Group(test-vg) & create Logical-Volume arya(512MB) mount on /start
```c
# fdisk    -l
# fdisk    /dev/vdb        //Create 2 partitions    /vdb1 /vdb2
    type: 8e    //LVM
# partprobe
# pvcreate  /dev/vdb1  /dev/vdb2;    pvdisplay            
# vgcreate  test-vg  /dev/vdb1  /dev/vdb2;    vgdisplay   //vgcreate  -s <size-o-physical-extent>  <name>
# lvcreate   -n arya   -L 512M  test-vg;    lvdisplay        //lvcreate  -n <name>  -L <size-in-bytes>   -l <number-of-physical-extents-to-allocate>   <name-of-volume-group-from-which LV needs to be created>
# mkfs  -t xfs  /dev/mapper/test--vg-arya        //Build file system
# lsblk;  blkid
    UUID="........"
# vim  /etc/fstab
    UUID=....    /start    xfs    defaults    0    0
# mount -a
```

<a name=o2></a>
#### 2. Existing Logical-Volume (loans=256MB). Increase It to 768MB. Mount at /finance/loans
```c
# lvdisplay  /dev/finance/loans
    ....    //Size of Logical Volume
# fdisk /dev/vdb
    ....    //Created    /dev/vdb3
# pvcreate  /dev/vdb3
# vgextend    finance    /dev/vdb3
# lvextend    -n /dev/finance/loans    -L 768M    
# xfs_growfs    /finance/loans        //For creating we use mkfs
```

<a name=o3></a>
#### 3. Logical-volume(/dev/finance/loans=768MB), Reduce to 256MB, Again resize to 768MB. Without Loss of data
```c
# lvdisplay    /dev/finance/loans
# cp    /finance/loans/*    /home/Desktop        <============Without Loss of data
# lvreduce    -n /dev/finance/loans    -L 256M    
# lvextend    -n /dev/finance/loans    -L 768M   
```

<a name=o4></a>
#### 4. Make Volume-Group(oracleVG having each physicalExtentSize=8MB), (Logical Volume red_lv will have 100 extents), red_lv is ext3 formatted.
```c
# fdisk  /dev/vdb    [Get vdb1 of 1GB]
# pvcreate /dev/vdb1
# vgcreate  oracleVG  /dev/vdb1  -s 8M;    vgdisplay
# lvcreate -n red_lv1  -l 100  oracleVG;    lvcreate
# mkfs  -t ext3  /dev/mapper/oracle_red_lv
```

<a name=creu></a>
## [Creating Bootable USB](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/installation_guide/sect-making-usb-media?extIdCarryOver=true&sc_cid=701f2000001Css5AAC)
```c
Step-1. A log detailing all recent events will be displayed. At the bottom of this log, you will see a set of messages caused 
by the USB flash drive you just connected. Note the name of the connected device - in the above example, it is sdb
-> Insert USB.    # lsblk;    lsusb;    dmesg 

Step-2.  Make sure that the device is not mounted. If the command displays no output, you can proceed with the next step. 
if the command does provide output, it means that the device was automatically mounted and you must unmount it before proceeding.
# findmnt /dev/sdb

Step-3. Umount if mounted.
# findmnt /dev/sdb
    TARGET   SOURCE   FSTYPE  OPTIONS    
    /mnt/iso /dev/sdb iso9660 ro,relatime
# umount /mnt/iso

Step-4: Use the dd command to write the installation ISO image directly to the USB device. 
Replace /image_directory/image.iso with the full path to the ISO image file you downloaded, device with the device name 
as reported by the dmesg command earlier, and blocksize with a reasonable block size (for example, 512k) to speed up the writing process. 
    # dd if=/image_directory/image.iso of=/dev/device bs=blocksize
    # dd if=/home/testuser/Downloads/rhel-server-7-x86_64-boot.iso of=/dev/sdb bs=512k
    
Step-5: Wait for dd to finish writing the image to the device.    
```    

<a name=mou></a>
## Mounting USB Device
```c
Step-1. Detect USB device. Look for your USB drive based on its size and filesystem. Once ready, take a note of the block device name of the partition you intent to mount.
# fdisk -l 
# gparted

Step-2: Create mount point and mount
# mkdir /root/test-mount
# mount /dev/sdb /root/test-mount
Issue-1:  mount: /dev/sdb is write-protected, mounting read-only.mount: wrong fs type, bad option, bad superblock on /dev/sdb,
Resolution:  
```
