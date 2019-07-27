/*
 * Project: I2C-Debugger
 * Description:  Main code for I2C slave for r-90 debug code
 * Author:  JJ Fenstermaker
 * Date: 7/23/19
 */
#define pragma once
#define DEBUGGER_SLAVE_ADDRESS       0x99
#define XMIT_ADDRESS                 0x99 
#define RECEIVER_ADRRESS             0x9A
#define I2C_DEBUGGER                 1234
#define I2C_RECEIVER                 5678
#define VERSION                      "0.0.01"

// Function Definitions
void setup(void);
void loop(void);
