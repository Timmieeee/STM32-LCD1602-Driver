This is a library for STM32 to drive an LCD1602 screen based on HAL and the instruction set provided by LCD1602. Using this library, commands and datas can be written to LCD1602 to control its display content, as well as CGRAM and DDRAM, without direct bit flow control. All the functions defined in this library are detailed annotated. This library does not include instructions to read contents from LCD1602, and an example is provided to illustrate the usage of this library, in which STM32f103c8t6 drives LCD1602A to display the pseudonym of HATSUNE MIKU.

Advice on how to use this library:
1. Use STM32CubeMX to new a project and generate codes. 11 GPIO output pins are needed as the signal RS, RW, EN, DB0~DB7.
2. Copy "lcd1602driver.h" to the project path Core/Inc, "lcd1602driver.c" to the project path Core/Src.
3. Modify the pins assignment section from line 7 to line 30 in "lcd1602driver.h", which are defined in step 1.

I may add more detailed functions in the library sooner or later, as preparations for hardware course design.