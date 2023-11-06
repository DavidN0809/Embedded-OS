#!/bin/sh

DEVICE="vpb_uart"

MODDIR="."
PERM=666

insmod ${MODDIR}/${DEVICE}.ko
MAJOR=`awk "\\$2==\"${DEVICE}\" {print \\$1}" /proc/devices`
mknod /dev/${DEVICE} c $MAJOR 0
chmod $PERM /dev/${DEVICE}
