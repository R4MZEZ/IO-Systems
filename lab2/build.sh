rmmod ch_drv
make clean
make
insmod ch_drv.ko
fdisk -l
mkdir /mnt/vramdisk1
mkdir /mnt/vramdisk2
mkdir /mnt/vramdisk3
mkfs.vfat /dev/vramdisk1
mkfs.vfat /dev/vramdisk2
mkfs.vfat /dev/vramdisk3
mount /dev/vramdisk1 /mnt/vramdisk1
mount /dev/vramdisk2 /mnt/vramdisk2
mount /dev/vramdisk3 /mnt/vramdisk3

