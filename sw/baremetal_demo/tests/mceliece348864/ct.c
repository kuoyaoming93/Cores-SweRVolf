#include "crypto_kem.h"
#include <stdint.h>

unsigned char ct[128] __attribute__((section(".data"))) = {0xDE, 0xF6, 0x19, 0x08, 0xA7, 0x0A, 0x30, 0x99, 0xE4, 0x5B, 0x4D, 0x5D, 0x91, 0x95, 0x7A, 0xDE, 0x70, 0xF5, 0x71, 0xD2, 0x10, 0xD5, 0x25, 0xD6, 0x55, 0xDB, 0x72, 0x94, 0x51, 0x5F, 0x91, 0xD9, 0x77, 0x95, 0xF2, 0x35, 0x36, 0x15, 0xBC, 0x7C, 0xDF, 0x13, 0x50, 0x21, 0x81, 0xE5, 0xBC, 0xC8, 0xC9, 0xAB, 0xFE, 0xF3, 0x18, 0x19, 0xD6, 0x6D, 0xD2, 0x76, 0x03, 0x63, 0x69, 0x4F, 0x78, 0x96, 0x02, 0x26, 0x4A, 0x3E, 0x24, 0x44, 0x56, 0x81, 0xA0, 0x18, 0x3C, 0xE3, 0x43, 0xA2, 0x26, 0x4F, 0xDF, 0xF9, 0x6C, 0x82, 0xAB, 0x31, 0x8A, 0xE8, 0x88, 0xD1, 0x05, 0xD5, 0x2D, 0x59, 0xBC, 0x1B, 0xB2, 0xA4, 0x4D, 0xB7, 0xA3, 0xCF, 0x1F, 0xBF, 0xFF, 0xEB, 0x7E, 0x06, 0x25, 0x70, 0x1D, 0x97, 0xB7, 0x86, 0x38, 0xE8, 0xEC, 0xC3, 0xE9, 0x1F, 0xEF, 0x73, 0x27, 0xCD, 0x11, 0x83, 0x97, 0xC0};