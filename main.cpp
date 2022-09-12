#include <iostream>
#include "memory.h"
#include "CPU.h"

int main() {
	Memory mem;
	CPU cpu;

	cpu.power_up(mem);
}