@echo off
set dir_path=E:\\Free\\STM32F10X_Demo_VSCode
set board_cfg=%dir_path%\\Debug\\board\\stm32f103c8_blue_pill.cfg
set image=%dir_path%\\Obj\\STM32F10X.hex

openocd -s %dir_path% -f %board_cfg% -c ^
"init;halt;reset halt;flash write_image erase %image%;reset;shutdown;"
@echo on