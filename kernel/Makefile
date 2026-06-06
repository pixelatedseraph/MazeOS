CXXFLAGS = -m32 -std=c++23 -ffreestanding -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASMFLAGS = --32
LD       = i386-elf-ld
LDFLAGS  = -melf_i386

objects = loader.o kernel.o

%.o: %.cxx
	i386-elf-g++ $(CXXFLAGS) -c -o $@ -v $<

%.o: %.s
	as $(ASMFLAGS) -o $@ $<

mkern.bin: linker.ld $(objects)
	$(LD) $(LDFLAGS) -T $< -o $@ $(objects)

install: mkern.bin
	sudo cp $< /boot/mkern.bin