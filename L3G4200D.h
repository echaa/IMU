/* L3G4200D.h
 * Last modified Jan 16, 2016
 */


#ifndef L3G4200D_H
#define L3G4200D_H

#include "i2c_functions.h"
#include "Wire.h"

#define kFilterFactor 0.1f
#define EnableFiltering true

#define L3G4200D_Address 105 // SDO pin to PWR
// #define L3G4200D_Address 104 // SDO pin to GND

// Define Register Addressses
#define L3G4200D_CTRL_REG1     0x20
#define L3G4200D_CTRL_REG2     0x21
#define L3G4200D_CTRL_REG3     0x22
#define L3G4200D_CTRL_REG4     0x23
#define L3G4200D_CTRL_REG5     0x24
#define L3G4200D_REFERENCE     0x25
#define L3G4200D_OUT_TEMP      0x26
#define L3G4200D_STATUS_REG    0x27

#define L3G4200D_OUT_X_L       0x28
#define L3G4200D_OUT_X_H       0x29
#define L3G4200D_OUT_Y_L       0x2A
#define L3G4200D_OUT_Y_H       0x2B
#define L3G4200D_OUT_Z_L       0x2C
#define L3G4200D_OUT_Z_H       0x2D

#define L3G4200D_FIFO_CTRL_REG 0x2E
#define L3G4200D_FIFO_SRC_REG  0x2F

/* INTERRUPT REGISTERS
#define L3G4200D_INT1_CFG      0x30
#define L3G4200D_INT1_SRC      0x31
#define L3G4200D_INT1_THS_XH   0x32
#define L3G4200D_INT1_THS_XL   0x33
#define L3G4200D_INT1_THS_YH   0x34
#define L3G4200D_INT1_THS_YL   0x35
#define L3G4200D_INT1_THS_ZH   0x36
#define L3G4200D_INT1_THS_ZL   0x37
#define L3G4200D_INT1_DURATION 0x38
*/

// define datasheet constants

const float So_250 = 8.75f, // Sensitivity in mdps/digit(millidegrees per sec)
            So_500 = 17.50f,
            So_2000 = 70.0f;

const float DV_off_250 = 10.0f, // Zero-Rate offset
            DV_off_500 = 15.0f,
            DV_off_2000 = 75.0f;

class L3G4200D
{
public:
    float x, y, z, temperature;
    float scaleFactor = 0.0f;

    void updateValues();
    void updateTemperature();
    float filterValue(float currentInput, float newInput);

    void startUp(int sensitivity); // Used in place of constructor
    L3G4200D();
};
#endif // L3G4200D_H
