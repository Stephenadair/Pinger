#!/bin/bash

if ["ping -c 1 192.168.1.20"]
then 
    echo "Pinged cybernet 10"
else 
        echo "error"
fi