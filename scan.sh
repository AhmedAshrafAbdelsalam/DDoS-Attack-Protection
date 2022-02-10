#!bin/bash
sudo -kSs << EOF
$1
timeout 5s tcpdump icmp[0] == 8 > outputDDOS.txt
EOF
