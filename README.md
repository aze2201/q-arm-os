# Dummy Operating System ARM Cortex M arch

`Embed Bin ( ELF ( boot (kernel entrypoint) ) )`

## installing tool chain
1. `wget https://download.iopsys.eu/iopsys/toolchain/arm-2011.09-69-arm-none-eabi-i686-pc-linux-gnu.tar.bz2`
2. `bzcat arm-2011.09-69-arm-none-eabi-i686-pc-linux-gnu.tar.bz2 > arm-none-eabi.tar`
3. `tar xvf arm-none-eabi.tar`

## compiling source code

1. `arm-2011.09/bin/arm-none-eabi-as  -g boot.s -o boot.o `
2. `arm-2011.09/bin/arm-none-eabi-gcc -c  -g kernel.c -o kernel.o`
3. `arm-2011.09/bin/arm-none-eabi-ld -T linker.ld kernel.o boot.o -o q-arm-os.elf`
4. `arm-2011.09/bin/arm-none-eabi-objcopy -O binary q-arm-os.elf q-arm-os.bin`

## start OS with QEMU

```
$ qemu-system-arm -M versatilepb -m 128M -nographic -kernel miniOS-arm.bin
Hello baby ARM by Fariz!

```
### note

* dummy interrupts
* on Memory
* no NAND or MMC controller


# Author

Name:  Fariz Muradov
email: aze2201@gmail.com
