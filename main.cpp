#include <iostream>
#include "memory.h"
#include "CPU.h"

int main() {
	Memory mem;
	CPU cpu;

	cpu.power_up(&mem);
	//start - inline program
	mem.set_memory(mem, 0xFFFC, 0xA9);
	mem.set_memory(mem, 0xFFFD, 0x42);
	//end - inline program

	cpu.execute(2);


}