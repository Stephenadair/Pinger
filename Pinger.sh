#!/bin/bash


log_file="/home/stephen/Documents/Pinger/Log.txt"

> "$log_file"

for i in {11..25}; do 
    if ping -c 1 -W 1 192.168.1.$i >> "$log_file" 2>&1;
    then 
        echo "Pinged cybernet $i" | tee -a "$log_file"
    else 
        echo "error" | tee -a "$log_file"
    fi
done