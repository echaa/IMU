/*  i2c_functions.cpp
 *  Last modified: Jan 14, 2016
 */

#include "i2c_functions.h"

void writeRegister(int i2c_Address, byte registerAddress, byte value)
{
    Wire.beginTransmission(i2c_Address);
    Wire.write(registerAddress);
    Wire.write(value);
    Wire.endTransmission();
}

int readRegister(int i2c_Address, byte registerAddress)
{
    int temp = 0;

    Wire.beginTransmission(i2c_Address);
    Wire.write(registerAddress);
    Wire.endTransmission();

    Wire.requestFrom(i2c_Address, 1);

    while(!Wire.available())
    {
        // Wait for data to be sent
    }

    temp = Wire.read();
    return temp;
}
