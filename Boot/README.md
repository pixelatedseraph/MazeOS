# MazeOS Bootloader: CortusBootManager (CBM)

**CortusBootManager (CBM)** is the bootloader for **MazeOS**, responsible for initializing the CPU, setting up memory, and loading the kernel.

---

## Boot Flow Overview

### Step 1: Power Up
- System powers on and CPU begins execution at **`0x7C00`**.  
- Bootloader (**CortusBootManager**) is loaded into memory.  
- CPU is in **Real Mode (16-bit)**.

### Step 2: BIOS Initialization
- BIOS performs **POST (Power-On Self Test)** to check CPU, memory, and hardware.  
- Initializes hardware for booting.  
- Prepares system to load the bootloader.

### Step 3: CortusBootManager Execution
- CBM executes from `0x7C00`.  
- Uses BIOS interrupts to load kernel from disk.  
- Performs early system checks and memory layout setup.  
- Acts as a bridge between **16-bit BIOS** and **32-bit kernel**.

### Step 4: Stack & Segment Setup
- Initializes stack at a safe low-memory address (e.g., `0x7000`).  
- Loads segment registers for stable memory access:  
  - `CS`, `DS`, `ES`, `SS`  
- Protects against crashes during boot code execution.

### Step 5: Kernel Loading
- Uses BIOS interrupt **`int 0x13`** to read disk sectors.  
- Loads MazeOS kernel binary into memory:  
  - Usually above `0x1000`  
  - Often at `0x100000` (1MB mark) for protected mode  
- Prepares kernel for execution.

### Step 6: Switch to Protected Mode
- MazeOS kernel sets up **Global Descriptor Table (GDT)**.  
- Enables **32-bit protected mode** on the CPU.  
- Prepares CPU registers and memory for full kernel execution.

### Step 7: Jump to Kernel Entry Point
- CBM or early kernel sets CPU state for kernel execution.  
- Jumps to the kernel’s **entry point**, handing full control to MazeOS.  
- Kernel begins initializing subsystems (memory, interrupts, scheduler, etc.).

## Visual Flow

<img width="121" height="519" alt="BootloaderProcess1 drawio" src="https://github.com/user-attachments/assets/a944e258-9a9f-4e65-9eff-f8ad14e7c773" />


##  Running MazeOS (Arch-based Distros)

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
