/* 
 * File:   mcp3221.c
 * Author: raphael.pereira
 *
 * Created on 28 de Junho de 2018, 10:15
 */

#include "mcp3221.h"
#include "my_i2c.h"
#include "config.h"

void MCP3221_Init(unsigned char mcp3221_adr)
{
    unsigned char temp;
    
    temp = MCP3221_Read(mcp3221_adr);
}

unsigned int MCP3221_Read(unsigned char mcp3221_adr)
{
    // reads data from the sensor and stores them in temporary variables that
    // are then accessed via public variables
    I2C_Start();
    I2C_WriteByte(mcp3221_adr); // Send the ADR to the talk device.
    I2C_RepeatedStart();
    I2C_WriteByte(mcp3221_adr + 1); // Send the ADR to the talk device.
    value_hi = I2C_ReadByte(1); // Read the data
    value_lo = I2C_ReadByte(0); // Read the data
    I2C_Stop();
    
    return (((unsigned int)value_hi) << 8) | (value_lo);
}
