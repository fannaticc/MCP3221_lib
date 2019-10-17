/* 
 * File:   main.c
 * Author: raphael.pereira
 *
 * Created on 28 de Junho de 2018, 10:17
 */
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "my_delays.h"
#include "hd44780.h"
#include "my_i2c.h"
#include "mcp3221.h"

void main(void)
{
    unsigned int read_adc;
    unsigned char aux[20];
    
    OSCCON = 0b01110010;

    ADCON1 = 0b00001111; // Set all pins in digital mode.
    CMCON = 0b00000111; // Disable all comparators.

    TRISB = 0b11000000;
    TRISC = 0b00011000;
    
    Lcd_Init();                // Start LCD
    Lcd_Command(LCD_CLEAR);
    Lcd_Command(LCD_CURSOR_OFF);
    
    I2C_Close(); // Close the  I2C Bus.
    //I2C_Init(49); // I2C 100kHz, 20MHz-CRYSTAL.
    I2C_Init(19); // I2C 100kHz, 8MHz-CRYSTAL.
    //I2C_Init(9); // I2C 100kHz, 4MHz-CRYSTAL.
    
    Lcd_Text(1, 1, "ADC:");
    
    MCP3221_Init(MCP3221_ADR_A0); // Just do the first conversion.
    
    while(1)
    {
        read_adc = MCP3221_Read(MCP3221_ADR_A0);
        sprintf(aux, "%4d", read_adc);
        Lcd_Text(1, 5, aux);
    }
}

