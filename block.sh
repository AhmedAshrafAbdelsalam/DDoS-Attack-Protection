#!bin/bash
sudo -kSs << EOF
$2
iptables -I INPUT -s $1 -j DROP
EOF