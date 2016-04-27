#!/bin/bash


# First command line argument is the check-prefix for FileCheck:
VAR1=$(cat - | sed "s|.*$|// "$1": &|" )
# Replace hex numbers (typically addresses) with patterns that FileCheck can match:
VAR2=$(echo "$VAR1" | sed "s|0x[0-9a-f]\+|0x{{\[0-9a-f\]+}}|g")
# Replace line numbers with patterns:
VAR3=$(echo "$VAR2" | sed "s|line:[0-9]\+:[0-9]\+|line:{{\[0-9\]+}}:{{\[0-9]+}}|g")
# Replace column numbers wiht patterns:
VAR4=$(echo "$VAR3" | sed "s|col:[0-9]\+|col:{{\[0-9\]+}}|g")

echo "$VAR4"

