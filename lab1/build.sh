INPUT="1 2 3 4 5 6"
EXPECTATION="buf: 42  "

rmmod ch_drv
make clean
make
insmod ch_drv.ko

echo "$INPUT" > /dev/var4 
ACTUAL=$(cat /proc/var4)
if [[ "$EXPECTATION" = "$ACTUAL" ]]; then 
echo "Test is OK"
else
echo "Test is failed" >&2
fi
