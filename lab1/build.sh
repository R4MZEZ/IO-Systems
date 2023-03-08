rmmod ch_drv
make clean
make
insmod ch_drv.ko
#echo "1 2 3 4 5 6 7" > /dev/var4
#cat /proc/var4
#dmesg | tail -20
