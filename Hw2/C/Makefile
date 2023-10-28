.PHONY: clean

include /home/an/rv32emu/mk/toolchain.mk

ASFLAGS = -march=rv32i_zicsr -mabi=ilp32
SOURCE = main.o initial.o getcycles.o

VAR = -O0
CC = riscv-none-elf-gcc

%.o: %.c
	$(CC) $(ASFLAGS) $(VAR) -c -o $@ $<
	
%.o: %.s
	$(CC) $(ASFLAGS) -c -o $@ $<

all: main.elf

main.elf: $(SOURCE)
	$(CC) -o $@ $(SOURCE)

clean:
	$(RM) main.elf main.o initial.o getcycles.o
