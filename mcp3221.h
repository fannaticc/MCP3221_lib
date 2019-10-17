/* 
 * File:   mcp3221.h
 * Author: raphael.pereira
 *
 * Created on 28 de Junho de 2018, 10:15
 */

#ifndef MCP3221_H
#define	MCP3221_H

#define MCP3221_ADR_A0 0x90
#define MCP3221_ADR_A1 0x92
#define MCP3221_ADR_A2 0x94
#define MCP3221_ADR_A3 0x96
#define MCP3221_ADR_A4 0x98
#define MCP3221_ADR_A5 0x9A
#define MCP3221_ADR_A6 0x9C
#define MCP3221_ADR_A7 0x9E

unsigned char value_lo = 0;
unsigned char value_hi = 0;

void MCP3221_Init(unsigned char mcp3221_adr);
unsigned int MCP3221_Read(unsigned char mcp3221_adr);

#endif	/* MCP3221_H */

