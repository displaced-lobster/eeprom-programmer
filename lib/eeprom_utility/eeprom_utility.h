#include "Arduino.h"

#define SHIFT_DATA 10
#define SHIFT_CLOCK 16
#define SHIFT_LATCH 14

#define EEPROM_D0 2
#define EEPROM_D7 9

#define WRITE_ENABLE 15

void set_address(int address, bool output_enable);

byte read_EEPROM(int address);

void write_EEPROM(int address, byte data);

void print_contents();

void erase_EEPROM();
