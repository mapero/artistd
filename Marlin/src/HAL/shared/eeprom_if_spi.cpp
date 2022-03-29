/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * Platform-independent Arduino functions for SPI EEPROM.
 * Enable USE_SHARED_EEPROM if not supplied by the framework.
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(SPI_EEPROM)

#include "eeprom_if.h"
#include "../../libs/W25Qxx.h" //TWINKIEXLII

void eeprom_init() {
  W25QXX.init(SPI_QUARTER_SPEED);
}

#if ENABLED(USE_SHARED_EEPROM)

#define CMD_WREN  6   // WREN
#define CMD_READ  2   // WRITE
#define CMD_WRITE 2   // WRITE

#ifndef EEPROM_WRITE_DELAY
  #define EEPROM_WRITE_DELAY    7
#endif



uint8_t eeprom_read_byte(uint8_t *pos) {
  uint8_t v;
  W25QXX.SPI_FLASH_BufferRead((uint8_t *)&v,(uint32_t)pos,1);
  return v; 
}

void eeprom_write_byte(uint8_t *pos, uint8_t value) {
  W25QXX.SPI_FLASH_BufferWrite((uint8_t *)&value,(uint32_t)pos,1);
}

#endif // USE_SHARED_EEPROM
#endif // I2C_EEPROM
