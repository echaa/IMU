/* l3g4200d.cpp
 * Last modified Jan 16, 2016
 */

#include "L3G4200D.h"

void L3G4200D::updateValues()
{
    byte xMSB = readRegister(L3G4200D_Address, L3G4200D_OUT_X_H);
    byte xLSB = readRegister(L3G4200D_Address, L3G4200D_OUT_X_L);
    float xVal = scaleFactor * ((xMSB << 8) | xLSB);

    byte yMSB = readRegister(L3G4200D_Address, L3G4200D_OUT_Y_H);
    byte yLSB = readRegister(L3G4200D_Address, L3G4200D_OUT_Y_L);
    float yVal = scaleFactor * ((yMSB << 8) | yLSB);

    byte zMSB = readRegister(L3G4200D_Address, L3G4200D_OUT_Z_H);
    byte zLSB = readRegister(L3G4200D_Address, L3G4200D_OUT_Z_L);
    float zVal = scaleFactor * ((zMSB << 8) | zLSB);

#if EnableFiltering
    x = filterValue(x, xVal);
    y = filterValue(y, yVal);
    z = filterValue(z, zVal);
#else
    x = xVal;
    y = yVal;
    z = zVal;
#endif // EnableFiltering
}

void L3G4200D::updateTemperature()
{
    byte temp = readRegister(L3G4200D_Address, L3G4200D_OUT_TEMP);
    temperature = float(temp);
}

float L3G4200D::filterValue(float currentInput, float newInput)
{
    return (newInput * kFilterFactor) + (currentInput * ( 1 - kFilterFactor));
}

void L3G4200D::startUp(int sensitivity)
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    temperature = 0.0f;
    // Enable x, y, z, and turn off power down
    writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG1, 0b00001111);

    // Leave high pass filter off
    writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG2, 0b00000000);

    // CTRL_REG 3 controls interrupts; leave them all off
    writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG3, 0b00000000);

    switch(sensitivity)
    {
        case 250:
            writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG4, 0b00000000);
            scaleFactor = So_250/1000.0f; // Convert from millidegrees/sec to deg/sec
            break;

       case 500:
            writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG4, 0b00010000);
            scaleFactor = So_500/1000.0f;
            break;

       case 2000:
            writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG4, 0b00110000);
            scaleFactor = So_2000/1000.0f;
            break;
    }

    writeRegister(L3G4200D_Address, L3G4200D_CTRL_REG5, 0b00000000);
}

L3G4200D::L3G4200D()
{
    // nothing here: use startUp() instead
}
