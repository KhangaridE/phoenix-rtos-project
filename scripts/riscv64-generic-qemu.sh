#!/bin/bash
#
# Shell script for running Phoenix-RTOS on QEMU (riscv64-generic-qemu)
#
# Copyright 2021 Phoenix Systems
# Author: Lukasz Kosinski
#

REGEX="version ([0-9]+)\.([0-9]+)"
OPTIMG=""

# Determine QEMU version
[[ $(qemu-system-riscv64 --version) =~ $REGEX ]]
MAJOR="${BASH_REMATCH[1]}"
MINOR="${BASH_REMATCH[2]}"

# Select QEMU option for passing kernel image
if [[ "$MAJOR" -gt 4 || ( "$MAJOR" -eq 4 && "$MINOR" -ge 1 ) ]]; then
	OPTIMG="-bios"
else
	OPTIMG="-kernel"
fi

exec qemu-system-riscv64 \
	-smp 1 \
	-machine virt \
	"$OPTIMG" "$(dirname "${BASH_SOURCE[0]}")/../_boot/riscv64-generic-qemu/phoenix.osbi" \
	-nographic \
	-drive file="$(dirname "${BASH_SOURCE[0]}")/../_boot/riscv64-generic-qemu/rootfs.disk",format=raw,cache=unsafe,if=none,id=vblk0 \
	-device virtio-blk-device,drive=vblk0 \
	-device loader,file="$(dirname "${BASH_SOURCE[0]}")/../_boot/riscv64-generic-qemu/phoenix.disk",addr=0x20000000
