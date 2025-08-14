<img width="121" height="519" alt="bootloader drawio" src="https://github.com/user-attachments/assets/2a6fdc8e-c05c-40dd-b02f-ac0ad4bc7b89" />
The bootloader Employed by MazeOS is "CortusBootManager"(CBM).

The flow breakdown is as follows

Step 1: The Origin

BIOS loads Cortus at 0x7C00 and loads it into physical memory address
0x0000:0x7C00  (linear address 0x7C00)  
CPU starts executing CBM in Real Mode.

Step 2: Registers & Segments Setup

CPU uses segemented addressing in real mode
Cortus sets up segement registers(CS, DS, ES, SS).

Step 3: Stack Initialization

Bootloader initializes stack around 0x7000 (or nearby safe low-memory)
Loads SS and SP registers for stable push/pop operations
Protects against crashes during boot code execution.

Step 4: Kernel Loading

Uses BIOS interrupt int 0x13 to read disk sectors
Loads MazeOS kernel binary into memory (usually above 0x1000 or at 0x100000 — 1MB mark)
Prepares kernel for execution.

Step 5: Jump to Kernel Entry Point

Cortus sets CPU state for kernel
Jumps to the kernel’s start address, handing over full control to MazeOS



To get this running on your system (arch based distros)
1. sudo pacman -S qemu-full qemu-emulators-full virt-manager virt-viewer dnsmasq vde2 bridge-utils openbsd-netcat libvirt
2. sudo systemctl enable libvirtd
3. sudo systemctl start --now libvirtd
4. sudo usermod -aG libvirt $(whoami)
5. newgrp libvirt
6. sudo EDITOR=nano virsh net-edit default
7. sudo systemctl restart libvirtd
8. sudo virsh net-start default
9. sudo virsh net-autostart default
10. qemu-system-x86_64 --version
11. sudo virsh net-list --all
12. virt-manage
