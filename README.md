# STM32 GCC 编译模版

## 作者 ———— Ertuil

## 介绍
这里是我在Mac环境上使用 gcc-arm-none-eabi编译时候，使用的模版。其中包含了一个makefile，可以编译、烧写stm32程序。
有三个框架分别支持：stm32F103R8T6、stm32F407ZET6以及stm32F103R8T6带DSP库。
全部在Mac OS10.13 上测试通过，理论上linux也能使用。

## 目录介绍

基本与原子的目录相同：

1. USER/ 用户文件（建议代码放在此处）、stm32fxxx_conf、stmfxxx_it、stmfxxx等
2. BUILD/ 编译时产生文件
3. CORE/ arm 内核文件
4. FWLIB/ stm32 标准库文件
5. SYSTEM/ 原子提供的一部分.c .h 文件
6. HARDWARE/ 硬件相关的代码文件（建议硬件代码放在此处）
7. makefile makefile文件，需要根据自己情况配置配置。

## 使用和Makefile文件配置

### 需要安装的软件等
1. Unix、Linux上编译stm32文件，需要安装arm-none-eabi-gcc库。具体方法不再赘述。
2. 我使用st-link-v2下载代码至单片机。需要安装st-link的命令行工具

### Makefile文件配置

我这里使用的 Makefile 文件大体上是由 Stm32Cube自动生成的文件修改而成。常用的需要修改配置的的地方如下：

1. TARGET： 输出文件名
2. DEBUG： 时候开启debug
3. OPT： 优化等级
4. BUILD_DIR： 编译文件存放位置，默认build
5. BINPATH： gcc-arm-none-eabi/bin的位置
6. C_INCLUDES： C头文件位置

**注意** 

1. 对于不同型号的单片机，可能需要替换STM32F103R8Tx_FLASH.ld、startup_stm32f103xb.s两个.ld、.s文件为自己单片机对应型号的文件。
对应的makefile变量为：ASM_SOURCES和LDSCRIPT

2. 如果引入库，则适量修改即可。

### Make命令：

1. make： 编译所有文件，生成.bin,.elf二进制文件
2. make flash：使用st-flash命令把.bin 下载到单片机0x8000000处，（使用openocd等工具时需要自行修改命令）
3. make clean：删除所有编译生成的文件。

## 关于调试：

使用 arm-none-eabi-gdb和 st-utils 配合使用可以很方便的进行调试。st-utils打开调试服务器，gdb连接服务器来调试。
