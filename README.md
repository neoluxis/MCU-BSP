# Board Support Package (BSP) of Neolux Lee

## Abstract

In this repo are board support packages by Neolux Lee for MCU, including Standard Library and HAL Library. 

## Supported MCU

- STM32 F103 RCT6: 小鲨鱼开发板
- STM32 F103 VET6: 野火指南者开发板

## Directory Structure

The directories and functions are like this: 

`/`: Root directory of the repo
- `F103RC`: For STM32 F103 RC series MCU
	- `Blueprints`: 图纸
		- `(上一版)MINI-STM32 硬件图纸`
		- `(新版)MINI-STM32 硬件图纸`
		- `(上一版)MINI-STM32--原理图.pdf`
		- `(新版)MINI-STM32--原理图.pdf`
	- `HAL`: STM32 F103 RC HAL library support
		- `KEY`: Hardware/KEY
		  - `key.c`
		  - `key.h`
		- `LED`: Hardware/LED
		  - `led.c`
		  - `led.h`
	- `STD`: STM32 F103 RC STD library support
- `F103VE`: For STM32 F103 VE series MCU
	- `Blueprints`: 图纸
	  - `野火_指南者原理图_2020-05-06.pdf`
	- `HAL`: STM32 F103 VE HAL library support
	  - `KEY`: Hardware/KEY
	    - `key.c`
	    - `key.h`
	  - `LED`: [Hardware/LED](./F103VE/HAL/LED/led.md)
	    - `led.c`
	    - `led.h`
	- `STD`: STM32 F103 VE STD library support
