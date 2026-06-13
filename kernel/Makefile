CXXFLAGS = -m32 -std=c++23  -ffreestanding -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASMFLAGS = --32
LD       = i386-elf-ld
LDFLAGS  = -melf_i386 
LIBGCC := $(shell i386-elf-gcc -print-libgcc-file-name)
objects = loader.o gdt.o kernel.o vga.o string.o

%.o: %.cxx
	i386-elf-g++ $(CXXFLAGS) -c -o $@ -v $<

%.o: %.s
	as $(ASMFLAGS) -o $@ $<

#mkern.bin: linker.ld $(objects)
#	$(LD) $(LDFLAGS) -T $< -o $@ $(objects)

mkern.bin: linker.ld $(objects)
	i386-elf-ld \
		-melf_i386 \
		-T linker.ld \
		-o $@ \
		$(objects) \
		$(LIBGCC)


install: mkern.bin
	sudo cp $< /boot/mkern.bin