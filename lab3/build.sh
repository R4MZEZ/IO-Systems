make clean
make
rmmod virt_net_if.ko
insmod virt_net_if.ko
#echo -n "hello" | nc -u -w1 192.168.0.100 12345
#cat /proc/virt_net_if
