# Embedded programming

* newlib

## Examining binaries

* `hd`
* `readelf`
	* -h - header
	* -s - section
	* -n - notes
	* alternatively `elfutils`
* `objdump` - elf and object files
* `arm-none-eabi*`
	* nm
	* size

## Compiling


```
arm-none-eabi-gcc --specs=nosys.specs main.c -o ehelloWorld
arm-none-eabi-objcopy -O binary -S ehelloWorld ehelloWorld.bin

arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=soft -g -O0 -Wextra -Warray-bounds -DSTM32F401xE -Iinclude -Iinclude/core -Wall -fcommon -fdata-sections -ffunction-sections --specs=nosys.specs -Tsrc/STM32F401RETx_FLASH.ld -lnosys -Wl,-Map=build/main.map,--cref,--gc-sections src/main.c -o build/main.elf
arm-none-eabi-objcopy -O binary -S build/main.elf build/main.bin
```

## Makefile

```

