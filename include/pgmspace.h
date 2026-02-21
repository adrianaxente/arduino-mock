#ifndef PGM_MOCK_H
#define PGM_MOCK_H

#include <stdint.h>

// Mock the PROGMEM keyword to do nothing
#define PROGMEM 

// Mock pgm_read functions to simply return the value at the address
#define pgm_read_byte(addr)  (*(const uint8_t*)(addr))
#define pgm_read_word(addr)  (*(const uint16_t*)(addr))
#define pgm_read_dword(addr) (*(const uint32_t*)(addr))

// Mock the F() macro for strings
// Handle F macro redefinition
#ifdef F
  #undef F
#endif
#define F(str) (str)

#endif