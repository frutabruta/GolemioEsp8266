// This is the 'classic' fixed-space bitmap font for Adafruit_GFX since 1.0.
// See gfxfont.h for newer custom bitmap font info.

#ifndef FONT5X7_H
#define FONT5X7_H

#ifdef __AVR__
 #include <avr/io.h>
 #include <avr/pgmspace.h>
#elif defined(ESP8266)
 #include <pgmspace.h>
#else
 #define PROGMEM
#endif

// Standard ASCII 5x7 font

static const unsigned char font[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
	0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
	0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
	0x18, 0x3C, 0x7E, 0x3C, 0x18,
	0x1C, 0x57, 0x7D, 0x57, 0x1C,
	0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
	0x00, 0x18, 0x3C, 0x18, 0x00,
	0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
	0x00, 0x18, 0x24, 0x18, 0x00,
	0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
	0x30, 0x48, 0x3A, 0x06, 0x0E,
	0x26, 0x29, 0x79, 0x29, 0x26,
	0x40, 0x7F, 0x05, 0x05, 0x07,
	0x40, 0x7F, 0x05, 0x25, 0x3F,
	0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
	0x7F, 0x3E, 0x1C, 0x1C, 0x08,
	0x08, 0x1C, 0x1C, 0x3E, 0x7F,
	0x14, 0x22, 0x7F, 0x22, 0x14,
	0x5F, 0x5F, 0x00, 0x5F, 0x5F,
	0x06, 0x09, 0x7F, 0x01, 0x7F,
	0x00, 0x66, 0x89, 0x95, 0x6A,
	0x60, 0x60, 0x60, 0x60, 0x60,
	0x94, 0xA2, 0xFF, 0xA2, 0x94,
	0x08, 0x04, 0x7E, 0x04, 0x08,
	0x10, 0x20, 0x7E, 0x20, 0x10,
	0x08, 0x08, 0x2A, 0x1C, 0x08,
	0x08, 0x1C, 0x2A, 0x08, 0x08,
	0x1E, 0x10, 0x10, 0x10, 0x10,
	0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
	0x30, 0x38, 0x3E, 0x38, 0x30,
	0x06, 0x0E, 0x3E, 0x0E, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x5F, 0x00, 0x00,
	0x00, 0x07, 0x00, 0x07, 0x00,
	0x14, 0x7F, 0x14, 0x7F, 0x14,
	0x24, 0x2A, 0x7F, 0x2A, 0x12,
	0x23, 0x13, 0x08, 0x64, 0x62,
	0x36, 0x49, 0x56, 0x20, 0x50,
	0x00, 0x08, 0x07, 0x03, 0x00,
	0x00, 0x1C, 0x22, 0x41, 0x00,
	0x00, 0x41, 0x22, 0x1C, 0x00,
	0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
	0x08, 0x08, 0x3E, 0x08, 0x08,
	0x00, 0x80, 0x70, 0x30, 0x00,
	0x08, 0x08, 0x08, 0x08, 0x08,
	0x00, 0x00, 0x60, 0x60, 0x00,
	0x20, 0x10, 0x08, 0x04, 0x02,
	0x3E, 0x51, 0x49, 0x45, 0x3E,
	0x00, 0x42, 0x7F, 0x40, 0x00,
	0x72, 0x49, 0x49, 0x49, 0x46,
	0x21, 0x41, 0x49, 0x4D, 0x33,
	0x18, 0x14, 0x12, 0x7F, 0x10,
	0x27, 0x45, 0x45, 0x45, 0x39,
	0x3C, 0x4A, 0x49, 0x49, 0x31,
	0x41, 0x21, 0x11, 0x09, 0x07,
	0x36, 0x49, 0x49, 0x49, 0x36,
	0x46, 0x49, 0x49, 0x29, 0x1E,
	0x00, 0x00, 0x14, 0x00, 0x00,
	0x00, 0x40, 0x34, 0x00, 0x00,
	0x00, 0x08, 0x14, 0x22, 0x41,
	0x14, 0x14, 0x14, 0x14, 0x14,
	0x00, 0x41, 0x22, 0x14, 0x08,
	0x02, 0x01, 0x59, 0x09, 0x06,
	0x3E, 0x41, 0x5D, 0x59, 0x4E,
	0x7C, 0x12, 0x11, 0x12, 0x7C,
	0x7F, 0x49, 0x49, 0x49, 0x36,
	0x3E, 0x41, 0x41, 0x41, 0x22,
	0x7F, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x49, 0x49, 0x49, 0x41,
	0x7F, 0x09, 0x09, 0x09, 0x01,
	0x3E, 0x41, 0x41, 0x51, 0x73,
	0x7F, 0x08, 0x08, 0x08, 0x7F,
	0x00, 0x41, 0x7F, 0x41, 0x00,
	0x20, 0x40, 0x41, 0x3F, 0x01,
	0x7F, 0x08, 0x14, 0x22, 0x41,
	0x7F, 0x40, 0x40, 0x40, 0x40,
	0x7F, 0x02, 0x1C, 0x02, 0x7F,
	0x7F, 0x04, 0x08, 0x10, 0x7F,
	0x3E, 0x41, 0x41, 0x41, 0x3E,
	0x7F, 0x09, 0x09, 0x09, 0x06,
	0x3E, 0x41, 0x51, 0x21, 0x5E,
	0x7F, 0x09, 0x19, 0x29, 0x46,
	0x26, 0x49, 0x49, 0x49, 0x32,
	0x03, 0x01, 0x7F, 0x01, 0x03,
	0x3F, 0x40, 0x40, 0x40, 0x3F,
	0x1F, 0x20, 0x40, 0x20, 0x1F,
	0x3F, 0x40, 0x38, 0x40, 0x3F,
	0x63, 0x14, 0x08, 0x14, 0x63,
	0x03, 0x04, 0x78, 0x04, 0x03,
	0x61, 0x59, 0x49, 0x4D, 0x43,
	0x00, 0x7F, 0x41, 0x41, 0x41,
	0x02, 0x04, 0x08, 0x10, 0x20,
	0x00, 0x41, 0x41, 0x41, 0x7F,
	0x04, 0x02, 0x01, 0x02, 0x04,
	0x40, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x03, 0x07, 0x08, 0x00,
	0x20, 0x54, 0x54, 0x78, 0x40,
	0x7F, 0x28, 0x44, 0x44, 0x38,
	0x38, 0x44, 0x44, 0x44, 0x28,
	0x38, 0x44, 0x44, 0x28, 0x7F,
	0x38, 0x54, 0x54, 0x54, 0x18,
	0x00, 0x08, 0x7E, 0x09, 0x02,
	0x18, 0xA4, 0xA4, 0x9C, 0x78,
	0x7F, 0x08, 0x04, 0x04, 0x78,
	0x00, 0x44, 0x7D, 0x40, 0x00,
	0x20, 0x40, 0x40, 0x3D, 0x00,
	0x7F, 0x10, 0x28, 0x44, 0x00,
	0x00, 0x41, 0x7F, 0x40, 0x00,
	0x7C, 0x04, 0x78, 0x04, 0x78,
	0x7C, 0x08, 0x04, 0x04, 0x78,
	0x38, 0x44, 0x44, 0x44, 0x38,
	0xFC, 0x18, 0x24, 0x24, 0x18,
	0x18, 0x24, 0x24, 0x18, 0xFC,
	0x7C, 0x08, 0x04, 0x04, 0x08,
	0x48, 0x54, 0x54, 0x54, 0x24,
	0x04, 0x04, 0x3F, 0x44, 0x24,
	0x3C, 0x40, 0x40, 0x20, 0x7C,
	0x1C, 0x20, 0x40, 0x20, 0x1C,
	0x3C, 0x40, 0x30, 0x40, 0x3C,
	0x44, 0x28, 0x10, 0x28, 0x44,
	0x4C, 0x90, 0x90, 0x90, 0x7C,
	0x44, 0x64, 0x54, 0x4C, 0x44,
	0x00, 0x08, 0x36, 0x41, 0x00,
	0x00, 0x00, 0x77, 0x00, 0x00,
	0x00, 0x41, 0x36, 0x08, 0x00,
	0x02, 0x01, 0x02, 0x04, 0x02,
	0x3C, 0x26, 0x23, 0x26, 0x3C,
	0x1E, 0xA1, 0xA1, 0x61, 0x12,
	0x3A, 0x40, 0x40, 0x20, 0x7A,
	0x38, 0x54, 0x54, 0x55, 0x59,
	0x21, 0x55, 0x55, 0x79, 0x41,
	0x22, 0x54, 0x54, 0x78, 0x42, // a-umlaut
	0x21, 0x55, 0x54, 0x78, 0x40,
	0x20, 0x54, 0x55, 0x79, 0x40,
	0x0C, 0x1E, 0x52, 0x72, 0x12,
	0x39, 0x55, 0x55, 0x55, 0x59,
	0x39, 0x54, 0x54, 0x54, 0x59,
	0x39, 0x55, 0x54, 0x54, 0x58,
	0x00, 0x00, 0x45, 0x7C, 0x41,
	0x00, 0x02, 0x45, 0x7D, 0x42,
	0x00, 0x01, 0x45, 0x7C, 0x40,
	0x7D, 0x12, 0x11, 0x12, 0x7D, // A-umlaut
	0xF0, 0x28, 0x25, 0x28, 0xF0,
	0x7C, 0x54, 0x55, 0x45, 0x00,
	0x20, 0x54, 0x54, 0x7C, 0x54,
	0x7C, 0x0A, 0x09, 0x7F, 0x49,
	0x32, 0x49, 0x49, 0x49, 0x32,
	0x3A, 0x44, 0x44, 0x44, 0x3A, // o-umlaut
	0x32, 0x4A, 0x48, 0x48, 0x30,
	0x3A, 0x41, 0x41, 0x21, 0x7A,
	0x3A, 0x42, 0x40, 0x20, 0x78,
	0x00, 0x9D, 0xA0, 0xA0, 0x7D,
	0x3D, 0x42, 0x42, 0x42, 0x3D, // O-umlaut
	0x3D, 0x40, 0x40, 0x40, 0x3D,
	0x3C, 0x24, 0xFF, 0x24, 0x24,
	0x48, 0x7E, 0x49, 0x43, 0x66,
	0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
	0xFF, 0x09, 0x29, 0xF6, 0x20,
	0xC0, 0x88, 0x7E, 0x09, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x3C, 0x0A, 0x09, 0xCA, 0xBC,
	0x00, 0x01, 0x02, 0x02, 0x01,
	0x10, 0x7F, 0x44, 0x42, 0x40,
	0x24, 0x18, 0x18, 0x24, 0x00,
	0x7F, 0x40, 0x42, 0x41, 0x40,
	0x48, 0x54, 0x56, 0x55, 0x24,
	0x00, 0x66, 0x89, 0x95, 0x6A,
	0x00, 0x01, 0x00, 0x01, 0x00,
	0x48, 0x55, 0x56, 0x55, 0x24,
	0x24, 0x2A, 0xAA, 0xEA, 0x12,
	0x0C, 0x05, 0x7E, 0x05, 0x0C,
	0x44, 0x64, 0x56, 0x4D, 0x44,
	0x00, 0x00, 0x7B, 0x00, 0x00,
	0x44, 0x65, 0x56, 0x4D, 0x44,
	0x44, 0x64, 0x55, 0x4C, 0x44,
	0x00, 0x02, 0x05, 0x02, 0x00, // #176 (25% block) missing in old code
	0x10, 0x2A, 0xEA, 0xBC, 0x20, // 50% block
	0x00, 0x00, 0xC0, 0x80, 0x00, // 75% block
	0x10, 0x49, 0x7F, 0x44, 0x02,
	0x00, 0x00, 0x02, 0x01, 0x00,
	0x00, 0x41, 0x7F, 0x40, 0x03,
	0x48, 0x54, 0x56, 0x55, 0x24,
	0x00, 0x01, 0x02, 0x01, 0x00,
	0x00, 0x00, 0x80, 0xC0, 0x00,
	0x48, 0x55, 0x56, 0x55, 0x24,
	0x24, 0x2A, 0xAA, 0xEA, 0x12,
	0x04, 0x04, 0x3F, 0x44, 0x23,
	0x44, 0x64, 0x56, 0x4D, 0x44,
	0x00, 0x02, 0x01, 0x02, 0x01,
	0x44, 0x65, 0x56, 0x4D, 0x44,
	0x44, 0x64, 0x55, 0x4C, 0x44,
	0x7C, 0x14, 0x16, 0x35, 0x48,
	0x70, 0x28, 0x24, 0x2A, 0x71,
	0x70, 0x2A, 0x29, 0x29, 0x72,
	0x70, 0x29, 0x2A, 0x2A, 0x71,
	0x70, 0x29, 0x24, 0x29, 0x70,
	0x7F, 0x40, 0x42, 0x41, 0x40,
	0x38, 0x44, 0x46, 0x45, 0x28,
	0x1E, 0xA1, 0xA1, 0x61, 0x12,
	0x38, 0x45, 0x46, 0x45, 0x28,
	0x7C, 0x54, 0x56, 0x55, 0x44,
	0x3E, 0x2A, 0xAA, 0xEA, 0x22,
	0x7C, 0x55, 0x54, 0x55, 0x44,
	0x7C, 0x55, 0x56, 0x55, 0x44,
	0x00, 0x44, 0x7E, 0x45, 0x00,
	0x00, 0x4A, 0x79, 0x4A, 0x00,
	0x7C, 0x45, 0x46, 0x45, 0x38,
	0x04, 0x7F, 0x45, 0x41, 0x3E,
	0x7C, 0x08, 0x12, 0x21, 0x7C,
	0x7C, 0x09, 0x12, 0x21, 0x7C,
	0x38, 0x44, 0x46, 0x45, 0x38,
	0x38, 0x46, 0x45, 0x45, 0x3A,
	0x3A, 0x45, 0x44, 0x46, 0x39,
	0x38, 0x45, 0x44, 0x45, 0x38,
	0x00, 0x28, 0x10, 0x28, 0x00,
	0x7C, 0x15, 0x16, 0x35, 0x48,
	0x3C, 0x41, 0x42, 0x41, 0x3C,
	0x3C, 0x40, 0x42, 0x41, 0x3C,
	0x3A, 0x41, 0x40, 0x42, 0x39,
	0x3C, 0x41, 0x40, 0x41, 0x3C,
	0x0C, 0x10, 0x62, 0x11, 0x0C,
	0x03, 0x01, 0xBF, 0xC1, 0x03,
	0xFC, 0x4A, 0x49, 0x36, 0x00,
	0x7C, 0x08, 0x06, 0x05, 0x08,
	0x20, 0x54, 0x56, 0x79, 0x40, // sharp-s or beta
	0x20, 0x56, 0x55, 0x7A, 0x40,
	0x20, 0x55, 0x56, 0x7A, 0x41,
	0x20, 0x55, 0x54, 0x79, 0x40,
	0x00, 0x41, 0x7F, 0x42, 0x01,
	0x38, 0x44, 0x46, 0x45, 0x28,
	0x18, 0x3C, 0xA4, 0xE4, 0x24,
	0x38, 0x45, 0x46, 0x45, 0x28,
	0x38, 0x54, 0x56, 0x55, 0x18,
	0x1C, 0x2A, 0xEA, 0xAA, 0x0C,
	0x38, 0x55, 0x54, 0x55, 0x18,
	0x38, 0x55, 0x56, 0x55, 0x18,
	0x00, 0x48, 0x7A, 0x41, 0x00,
	0x00, 0x4A, 0x79, 0x42, 0x00,
	0x30, 0x48, 0x7F, 0x40, 0x03,
	0x30, 0x48, 0x4A, 0x7F, 0x42,
	0x7C, 0x08, 0x06, 0x05, 0x78,
	0x7C, 0x09, 0x06, 0x05, 0x78,
	0x38, 0x44, 0x46, 0x45, 0x38,
	0x38, 0x46, 0x45, 0x45, 0x3A,
	0x3A, 0x45, 0x44, 0x46, 0x39,
	0x38, 0x45, 0x44, 0x45, 0x38,
	0x08, 0x08, 0x6B, 0x6B, 0x08,
	0x7C, 0x09, 0x06, 0x05, 0x08,
	0x3C, 0x42, 0x45, 0x22, 0x7C,
	0x3C, 0x40, 0x42, 0x21, 0x7C,
	0x3A, 0x41, 0x40, 0x22, 0x79,
	0x3C, 0x41, 0x40, 0x21, 0x7C,
	0x4C, 0x90, 0x92, 0x91, 0x7C,
	0x02, 0x02, 0x1F, 0xA2, 0xD2,
	0x00, 0x00, 0x01, 0x00, 0x00  // #255 NBSP
};
#endif // FONT5X7_H
