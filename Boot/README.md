# MazeOS Bootloader: CortusBootManager (CBM)

**CortusBootManager (CBM)** is the bootloader for **MazeOS**, responsible for initializing the CPU, setting up memory, and loading the kernel.

---

## Boot Flow Overview

### Step 1: The Origin
- BIOS loads Cortus at `0x7C00` (physical memory: `0x0000:0x7C00`, linear: `0x7C00`)  
- CPU starts executing CBM in **Real Mode**.

### Step 2: Registers & Segments Setup
- CPU uses **segmented addressing** in real mode.  
- Cortus sets up segment registers:
  - `CS`, `DS`, `ES`, `SS`

### Step 3: Stack Initialization
- Initializes stack near `0x7000` (safe low memory)  
- Loads `SS` and `SP` registers for stable push/pop  
- Protects against crashes during boot code execution

### Step 4: Kernel Loading
- Uses BIOS interrupt `int 0x13` to read disk sectors  
- Loads MazeOS kernel binary:
  - Usually above `0x1000`  
  - Or at `0x100000` (1MB mark)  
- Prepares kernel for execution

### Step 5: Jump to Kernel Entry Point
- Cortus sets CPU state for kernel  
- Jumps to the kernel’s start address, handing full control to MazeOS

---

## 💻 Running MazeOS on Arch-based Distros

```bash
# Install required packages
sudo pacman -S qemu-full qemu-emulators-full virt-manager virt-viewer dnsmasq vde2 bridge-utils openbsd-netcat libvirt

# Enable and start libvirtd
sudo systemctl enable libvirtd
sudo systemctl start --now libvirtd

# Add current user to libvirt group
sudo usermod -aG libvirt $(whoami)
newgrp libvirt

# Edit default network config
sudo EDITOR=nano virsh net-edit default

# Restart libvirtd and start default network
sudo systemctl restart libvirtd
sudo virsh net-start default
sudo virsh net-autostart default

# Verify QEMU installation
qemu-system-x86_64 --version

# List all networks
sudo virsh net-list --all

# Launch GUI manager
virt-manager
