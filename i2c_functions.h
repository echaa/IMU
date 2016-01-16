/*  i2c_functions.h
 *  Last modified: Jan 16, 2016
 */

#ifndef I2C_FUNCTIONS_H
#define I2C_FUNCTIONS_H

#include "Wire.h"
#define byte uint8_t

void writeRegister(int i2c_Address, byte registerAddress, byte value);

int readRegister(int i2c_Address, byte registerAddress);

#endif // I2C_FUNCTIONS_H
