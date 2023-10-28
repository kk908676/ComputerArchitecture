.PHONY: clean

include /home/an/rv32emu/mk/toolchain.mk

ASFLAGS = -march=rv32i_zicsr -mabi=ilp32
SOURCE = main.o

	
%.o: %.s
	$(CROSS_COMPILE)as -R $(ASFLAGS) -o $@ $<

all: main.elf

main.elf: $(SOURCE)
	$(CROSS_COMPILE)ld -o $@ -T main.ld $(LDFLAGS) $<

clean:
	$(RM) main.elf main.o 
