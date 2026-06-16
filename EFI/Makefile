.POSIX:
.PHONY: all clean run

SOURCE := efi_main.c
OBJ := $(SOURCE:.c=.o)
DEPENDS := $(OBJ:.o=.d)

ESP_DIR := esp/EFI/BOOT
TARGET := $(ESP_DIR)/BOOTX64.EFI

CC := clang

CFLAGS := \
	-target x86_64-unknown-windows \
	-std=c23 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-mno-red-zone \
	-MMD \
	-ffreestanding \
	-fshort-wchar \
	-nostdlib

LDFLAGS := \
	-fuse-ld=lld-link \
	-Wl,-subsystem:efi_application \
	-Wl,-entry:efi_main

all: $(TARGET)

$(ESP_DIR):
	mkdir -p $@

$(TARGET): $(OBJ) | $(ESP_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

run: $(TARGET)
run: $(TARGET)
	qemu-system-x86_64 \
		-m 512M \
		-serial stdio \
		-drive if=pflash,format=raw,readonly=on,file=/usr/share/edk2/x64/OVMF_CODE.4m.fd \
		-drive if=pflash,format=raw,file=OVMF_VARS.4m.fd \
		-drive format=raw,file=fat:rw:esp

-include $(DEPENDS)

clean:
	rm -rf esp *.o *.d