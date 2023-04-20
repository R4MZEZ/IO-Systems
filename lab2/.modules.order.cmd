cmd_/home/roman/IO-Systems/lab2/modules.order := {   echo /home/roman/IO-Systems/lab2/lab2.ko; :; } | awk '!x[$$0]++' - > /home/roman/IO-Systems/lab2/modules.order
