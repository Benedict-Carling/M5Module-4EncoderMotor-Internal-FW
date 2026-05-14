// M2 stub: the original M5 flash.c writes the EEPROM-emulation parameter
// store and the OTA receive buffer to addresses near the top of F030's
// 64 KB flash (PAGE63 = 0x0800FC00). On F103RB (128 KB flash, 1 KB pages)
// those constants are still in-range, but using them blindly risks
// overwriting application code. M5+ will pick a safe F103-specific
// region (e.g. last 2 KB of the 128 KB block) and re-enable real
// HAL flash writes.
//
// For M2 the goal is just to compile clean and let the rest of the
// firmware link. All public functions here are no-ops that report
// success; nothing is ever written to flash.
//
// Public entry points kept identical to the original signatures so
// callers in i2c_ex.c (Write_Code) and any future caller of
// writeMessageToFlash / readPackedMessageFromFlash continue to link.

#include "flash.h"

bool writeMessageToFlash(uint8_t *buff, uint16_t length)
{
    (void)buff;
    (void)length;
    // M2 stub: pretend the write succeeded.
    return true;
}

uint16_t readPackedMessageFromFlash(uint8_t *buff, uint16_t length)
{
    (void)buff;
    (void)length;
    // M2 stub: report "no stored message" so callers fall back to
    // their compiled-in defaults.
    return 0;
}

bool Write_Code(void)
{
    // M2 stub: the OTA "write a page of new firmware" path. Disabled
    // for safety — we don't want a stray I2C 0xE0 sequence to brick
    // the F103 by stomping on its own code. Returns true so the
    // caller in i2c_ex.c exits its `while(!Write_Code());` loop.
    return true;
}
