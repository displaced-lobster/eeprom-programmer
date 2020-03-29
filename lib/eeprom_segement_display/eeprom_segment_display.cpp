#include "eeprom_segment_display.h"

void program_hex_digits() {
  // 4-bit hex decoder for common cathode 7-segment display
  byte data[] = { 0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b, 0x77, 0x1f, 0x4e, 0x3d, 0x4f, 0x47 };

  for (unsigned int address = 0; address < sizeof(data); address++) {
    write_EEPROM(address, data[address]);

    if (address % 64 == 0) {
      Serial.print(".");
    }
  }
}


void program_decimal_digits() {
  byte digits[] = { 0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b };

  for (int value = 0; value <= 255; value++) {
    write_EEPROM(value, digits[value % 10]);
    write_EEPROM(value + 256, digits[(value / 10) % 10]);
    write_EEPROM(value + 512, digits[(value / 100) % 10]);
    write_EEPROM(value + 768, 0);

    if (value % 15 == 0) {
      Serial.print(".");
    }
  }

  for (int value = -128; value <= 127; value++) {
    write_EEPROM((byte) value + 1024, digits[abs(value) % 10]);
    write_EEPROM((byte) value + 1280, digits[abs(value / 10) % 10]);
    write_EEPROM((byte) value + 1536, digits[abs(value / 100) % 10]);

    if (value < 0) {
      write_EEPROM((byte) value + 1792, 0x01);
    } else {
      write_EEPROM((byte) value + 1792, 0);
    }

    if (value % 15 == 0) {
      Serial.print(".");
    }
  }
}
