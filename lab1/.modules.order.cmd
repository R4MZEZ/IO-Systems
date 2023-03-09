cmd_/home/roman/IO-Systems/lab1/modules.order := {   echo /home/roman/IO-Systems/lab1/ch_drv.ko; :; } | awk '!x[$$0]++' - > /home/roman/IO-Systems/lab1/modules.order
