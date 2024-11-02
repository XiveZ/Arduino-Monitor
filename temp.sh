#!/bin/bash
stty -F /dev/ttyUSB0 ispeed 2000000 ospeed 2000000 -ignpar cs8 -cstopb -echo -hupcl nl
while true
do
 echo `nvidia-smi --query-gpu=temperature.gpu,memory.used,power.draw --format csv | tail -1; sensors | grep Core | awk {'print $3'} | sort -n | tail -1 `> /dev/ttyUSB0
 sleep 2
done