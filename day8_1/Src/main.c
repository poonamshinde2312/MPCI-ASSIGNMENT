/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "eeprom.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32] = "";
	SystemInit();
	EEPROM_Init();
	UartInit(9600);
	//EEPROM_Write(0x0000, (uint8_t*)"GOD BLESS YOU!\r\n", 16);
	//EEPROM_Read(0x0000, (uint8_t*)str, 16);

	int choice;
		UartPuts("Enter your choice\r\n0. Exit\r\n1. to write a string into EEPROM at address 0x0000. On\r\n2. to Read 32 bytes from address 0x0000.\r\n");


		//UartGets(str);
		//sscanf(str, "%d", &choice);


	while(1){
			UartGets(str);
			sscanf(str, "%d", &choice);

			switch(choice){
			      default :
			    	   return 0;
		         case 1:
		        	 EEPROM_Write(0x0000, (uint8_t*)"GOD bless you!\r\n", 32);
		    	   break;

		         case 2:
		        	 EEPROM_Read(0x0000, (uint8_t*)str, 32);
                     UartPuts(str);
                     break;

		       }
        	}
	return 0;
}







