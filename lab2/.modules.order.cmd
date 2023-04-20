cmd_/home/mike/IO-Systems/lab2/modules.order := {   echo /home/mike/IO-Systems/lab2/lab2.ko; :; } | awk '!x[$$0]++' - > /home/mike/IO-Systems/lab2/modules.order
