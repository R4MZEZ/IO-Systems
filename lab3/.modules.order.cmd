cmd_/home/roman/IO-Systems/lab3/modules.order := {   echo /home/roman/IO-Systems/lab3/virt_net_if.ko; :; } | awk '!x[$$0]++' - > /home/roman/IO-Systems/lab3/modules.order
