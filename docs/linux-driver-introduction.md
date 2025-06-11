
# Linux driver folder introductions

# accel

- 硬件加速子系统: CXL 接口驱动优化内存访问、GPU 或专用 AI 芯片可加速模型训练。


# accessibility

- 无障碍技术驱动: 如屏幕阅读器、盲文显示器、语音合成器。


# acpi

-  ACPI标准驱动: 电源管理、硬件配置、热插拔支持等。


# amba

- 高级微控制器总线: 负责连接处理器、外设和内存控制器等组件。


# android

- Android OS定制的驱动: Binder 驱动。


# ata

- SATA/PATA 硬盘: AHCI 驱动、传统 IDE 控制器。


# atm

- ATM(异步传输模式)网络驱动: ATM 网卡驱动、协议栈。


# auxdisplay

- 辅助显示设备驱动: 除主显示屏之外的附加显示模块，与字符型显示设备、图形化小屏等硬件交互。


# base

- 设备模型核心: platform/bus/class/devres 等基础设施实现。


# bcma

- Broadcom 专有总线架构: 如 Wi-Fi、蓝牙与主机系统的通信。


# block

- 块设备核心: 调度器、驱动框架 (如 loop 虚拟设备)。


# bluetooth

- 蓝牙协议栈: HCI 驱动 (USB/UART)、协议层 (L2CAP/SCO)。


# bus

- 总线驱动: 通用总线驱动(如 PCIe、USB、I2C)、虚拟总线驱动(如 virtio-net、virtio-blk)。


# cache

- CPU缓存驱动: 缓存管理、硬件一致性协议以及缓存监控。


# cdrom

- 光驱驱动: 如 CD-R/RW、DVD±R/RW 和多媒体播放功能。


# cdx

- CDX 总线: 专为AMD/Xilinx Versal SoC 设计，实现 FPGA 动态分区设备 (如加速器 IP)的 自动发现、枚举和驱动加载，无需重启系统。


# char

- 字符设备驱动: 以字节为单位进行数据传输，适合连续数据流设备。


# clk

- 时钟框架: 通用时钟接口 (CCF)实现与各 SoC 时钟驱动。


# clocksource

-  时钟源驱动: 硬件时钟源驱动、虚拟时钟源驱动。


# comedi

- 数据采集与控制设备驱动: 旨在为科研、工业控制和测试测量领域提供统一的硬件抽象层 (HAL)，支持多种 DAQ 设备 (如数据采集卡、数字 I/O 模块、运动控制器)。


# connector

- 进程间通信 (IPC)和事件通知机制驱动: 它提供了一种轻量级的内核-用户空间通信方式，允许内核模块向用户空间程序发送异步事件通知 (如硬件状态变化、系统事件)。


# counter

- 硬件计数器驱动: 硬件计数器是 CPU 或协处理器中集成的性能监控单元，用于统计指令执行、缓存命中、分支预测等底层事件，广泛用于性能分析、调试和优化。


# cpufreq

- CPU 频率调整驱动: 多种架构的 CPU 频率调整驱动和通用框架，节能和性能优化。


# cpuidle

- CPU 空闲状态驱动: 多种架构的 CPU 空闲状态驱动和通用框架，节能优化。


# crypto

- 密码学功能: 对称加密、非对称加密、哈希函数等。


# cxl

- Compute Express Link驱动: CXL 是一种新兴的高性能互联协议，旨在突破传统 PCIe 总线的限制，提供低延迟、高带宽的内存语义通信，支持异构计算 (如 CPU、GPU、FPGA 协同)和内存扩展 (如持久内存、池化内存)。


# dax

- DAX(Direct Access)技术驱动: DAX 是一种允许文件系统直接访问持久内存 (PMEM，Persistent Memory)的技术，无需通过传统的页缓存 (Page Cache)，从而显著降低延迟并提高性能。drivers/dax 目录提供 DAX 核心框架、设备驱动和用户空间接口，确保持久内存设备在 Linux 系统中的高效运行。


# dca

- DCA(Direct Cache Access)技术驱动: DCA 是一种允许硬件设备 (如网卡、存储控制器)直接访问 CPU 缓存的技术，旨在减少数据在内存和缓存之间的传输延迟，从而提升系统性能。drivers/dca 目录提供 DCA 核心框架、设备驱动和用户空间接口，确保支持 DCA 的硬件设备在 Linux 系统中的高效运行。


# devfreq

- 动态设备频率调节驱动: DVFS 是一种通过动态调整硬件设备 (如 CPU、GPU、内存控制器)的工作频率和电压，以优化性能与功耗平衡的技术。devfreq 目录提供统一的框架、设备驱动和用户空间接口，支持多种硬件设备的智能调频。


# dio

- DIO(Digital Input/Output)设备驱动: DIO 设备是一种用于数字信号输入/输出的硬件接口，广泛应用于工业控制、自动化测试、嵌入式系统等领域，支持传感器数据采集、执行器控制和数字通信。drivers/dio 目录提供 DIO 设备抽象层、驱动模型和用户空间接口，确保 DIO 设备在 Linux 系统中的高效运行。


# dma

- DMA 引擎框架与控制器驱动 (如 dmaengine)。


# dma-buf

- 跨设备共享内存驱动: DMA-BUF 是一种允许不同硬件设备 (如 GPU、摄像头、显示控制器)直接访问同一块物理内存的技术，旨在减少数据拷贝、降低延迟并提升系统性能。dma-buf 目录提供统一的内存共享接口、设备驱动支持和用户空间工具，确保多设备协同工作的高效性。


# dpll

- DPLL(Digital Phase-Locked Loop，数字锁相环) 硬件核心驱动: DPLL 是一种关键的时钟管理组件，广泛用于同步处理器、外设和总线时钟，确保系统时钟的稳定性和准确性。drivers/dpll 目录提供 DPLL 核心框架、设备驱动和配置接口，支持多种硬件平台的时钟同步需求。


# edac

- 硬件错误检测与纠正驱动: EDAC 技术通过监控内存、CPU 缓存等硬件组件的错误 (如位翻转、ECC 错误)，确保系统稳定性和数据完整性，广泛应用于服务器、存储系统和工业控制领域。drivers/edac 目录提供 EDAC 核心逻辑、设备驱动和用户空间接口，支持多种硬件平台的错误管理需求。


# eisa

- EISA(Extended Industry Standard Architecture)总线驱动: EISA 总线是一种早期计算机扩展总线标准，广泛用于 1980-1990 年代的 IBM PC 兼容机，支持多设备并行连接和即插即用 (PnP)功能。drivers/eisa 目录提供 EISA 总线控制器驱动、设备枚举逻辑和用户空间接口，确保 EISA 设备在 Linux 系统中的兼容性和基本功能。


# extcon

- 外部连接器(External Connector)事件驱动: 外部连接器 (如 USB-C、HDMI、耳机插孔)广泛用于检测设备插入/拔出、模式切换 (如 USB-C 显示端口模式)和电源状态变化，是移动设备、嵌入式系统和工业控制领域的关键组件。extcon 目录提供统一的连接器管理接口、设备驱动支持和用户空间工具，确保多设备协同工作的实时性和可靠性。


# firewire

- FireWire (IEEE 1394)高速串行总线驱动: FireWire 是一种由苹果公司开发的高速数据传输标准，广泛用于音频/视频设备、存储设备和外设连接，支持热插拔、等时同步传输和低延迟通信。firewire 目录提供 FireWire 协议栈、设备驱动和用户空间接口，确保 FireWire 设备在 Linux 系统中的兼容性和高性能。


# firmware

- 固件加载框架 (如 UEFI、DMI、Devicetree 支持)。


# fpga

- FPGA(现场可编程门阵列)驱动: FPGA 是一种可编程逻辑器件，允许用户通过硬件描述语言(如 Verilog、VHDL)动态配置其逻辑功能，广泛应用于数据中心加速、嵌入式系统、航空航天等领域。fpga 目录提供 FPGA 配置管理、部分重配置和电源管理接口，支持多种 FPGA 平台(如 Xilinx、Intel/Altera、Lattice)。


# fsi

- FSI(Frame Signal Interface)总线协议驱动: FSI 是一种由 IBM 开发的芯片间通信接口，广泛用于 Power 架构处理器 (如 POWER7、POWER8、POWER9)中，实现处理器核心与内存控制器、I/O 控制器等组件的高速、低延迟通信。fsi 目录提供 FSI 主机控制器驱动、设备枚举逻辑和用户空间接口，确保 FSI 设备在 Linux 系统中的兼容性和高性能。


# gnss

- GNSS(Global Navigation Satellite System，全球导航卫星系统): GNSS 设备 (如 GPS、北斗、GLONASS 接收器)通过接收卫星信号实现定位、导航和授时 (PNT)功能，广泛应用于移动设备、车载系统、无人机和工业控制领域。gnss 目录提供 GNSS 设备抽象层、协议解析和用户空间接口，确保 GNSS 设备在 Linux 系统中的兼容性和高性能。


# gpio

- GPIO 控制器驱动 (如 gpio-mxc.c)与核心库。


# gpu

- GPU 驱动 (Intel i915、AMD amdgpu、Nouveau)。


# greybus

- Greybus 协议驱动: Greybus 是一种由 Google 开发的通信协议，旨在实现模块化设备 (如 Project Ara 模块化手机)中各模块 (如摄像头、显示屏、传感器)与主机 (如应用处理器)之间的高效、低延迟通信。greybus 目录提供 Greybus 协议栈、设备抽象层和驱动模型，支持模块化设备的动态热插拔、电源管理和数据传输。


# hid

- HID 设备 (人机接口): USB HID 核心、特殊设备 (如绘图板、传感器)。


# hsi

- HSI(High-Speed Synchronous Serial Interface，高速同步串行接口)协议驱动: HSI 是一种由诺基亚开发的串行通信协议，最初用于移动设备 (如智能手机、平板电脑)中处理器与调制解调器 (Modem)之间的高速数据传输，支持全双工通信和低延迟控制。hsi 目录提供 HSI 协议栈、设备抽象层和驱动模型，支持多种 HSI 控制器 (如高通 MSM、三星 Exynos)。


# hte

- HTE(HyperTransport Extension)总线驱动: HTE 是 HyperTransport 总线的扩展协议，由 AMD 开发，旨在实现芯片间的高速、低延迟通信，广泛应用于数据中心服务器、高性能计算 (HPC)和嵌入式系统。hte 目录提供 HTE 主机控制器驱动、设备枚举逻辑和用户空间接口，确保 HTE 设备在 Linux 系统中的兼容性和高性能。


# hv

- Hyper-V 虚拟化平台驱动: Hyper-V 是微软开发的虚拟化技术，广泛用于 Windows 服务器和桌面系统，支持客户机操作系统 (如 Linux)在 Hyper-V 主机上高效运行。hv 目录提供 Hyper-V 虚拟化设备驱动、集成服务 (Integration Services)和性能优化接口，确保 Linux 虚拟机在 Hyper-V 环境中的兼容性和高性能。


# hwmon

- 硬件监控传感器 (电压/温度/风扇转速)。


# hwspinlock

- 硬件自旋锁驱动: 硬件自旋锁是一种低延迟、高效率的同步机制，广泛用于多核处理器、实时系统 (如 RTOS)和嵌入式设备中，确保对共享资源 (如内存、外设)的独占访问。hwspinlock 目录提供硬件自旋锁的抽象层、设备驱动和用户空间接口，支持多种硬件平台 (如 ARM、PowerPC、RISC-V)。


# hwtracing

- 硬件追踪驱动: 硬件追踪是一种通过专用硬件模块 (如跟踪宏单元、性能监测单元)实时捕获和分析系统行为 (如指令执行、中断处理、内存访问)的技术，广泛用于性能调优、故障排查和安全审计。hwtracing 目录提供硬件追踪框架、设备抽象层和用户空间接口，支持多种硬件平台 (如 ARM、Intel、RISC-V)和追踪技术 (如 CoreSight、ETM、PTM)。


# i2c

- I2C 子系统: 核心、算法、适配器驱动 (如 i2c-designware)。


# i3c

- 改进型内部集成电路总线协议驱动: I3C 是 I2C 总线的继任者，由 MIPI 联盟开发，旨在提供更高速度、更低功耗和更灵活的传感器集成方案，广泛用于移动设备、物联网 (IoT)和汽车电子领域。包含 I3C 核心框架、设备驱动和用户空间接口，为多传感器融合和低功耗设计提供高效通信支持。


# idle

- CPU 空闲状态核心驱动: 提供 cpuidle 框架和空闲状态治理器，支持动态调整 CPU 频率、电压和核心状态，优化系统能效。


# iio

- 工业输入/输出设备驱动: IIO 子系统旨在为传感器、模数转换器 (ADC)、数模转换器 (DAC)、加速度计、陀螺仪等工业级设备提供统一的接口和抽象层，广泛用于物联网 (IoT)、工业自动化、医疗设备和消费电子等领域。


# infiniband

- InfiniBand 架构驱动: InfiniBand 是一种高性能、低延迟的网络通信技术，广泛用于数据中心、高性能计算 (HPC)和存储区域网络 (SAN)，支持远程直接内存访问 (RDMA)和内核旁路 (Kernel Bypass)特性。提供 InfiniBand 核心框架、设备驱动和用户空间接口，为集群计算、分布式存储和 AI 训练等场景提供高效的网络互联能力。


# input

输入设备核心

- keyboard: 键盘驱动 (PS/2、USB)。
- mouse: 鼠标/触摸板驱动。
- touchscreen: 触摸屏驱动 (电阻/电容式)。
- joystick: 游戏手柄/摇杆驱动。


# interconnect

- 设备间互联机制驱动: 支持硬件设备间的高效通信与数据传输。linux/drivers/interconnect 是 Linux 内核中支持复杂硬件互联的关键组件，通过抽象底层协议、优化资源管理，为多设备协同工作提供高效、稳定的通信框架。


# iommu

- IOMMU (Input/Output Memory Management Unit，输入输出内存管理单元) 硬件驱动: OMMU 是现代计算机系统中用于增强设备直接内存访问 (DMA)安全性、支持虚拟化及优化性能的关键组件。linux/drivers/iommu 是 Linux 内核中保障系统安全、提升 I/O 性能的关键模块。


# ipack

- IPACK (Industry Pack)总线及设备驱动: IPACK 是一种模块化硬件标准，常见于工业控制、数据采集和嵌入式系统，支持通过载板 (Carrier)和模块 (Module)的组合实现灵活配置。linux/drivers/ipack 是 Linux 内核中支持工业模块化硬件的关键组件，通过抽象 IPACK 总线与设备细节，为工业控制、嵌入式系统等场景提供高效、可靠的硬件访问接口。


# irqchip

- 中断控制器驱动 (如 GIC、APIC、硬件级中断管理)。


# isdn

- ISDN (Integrated Services Digital Network，综合业务数字网)设备及协议驱动: ISDN 是一种早期数字通信技术，曾广泛用于电话、传真、数据传输等场景。提供对 ISDN 硬件设备(如 ISDN 网卡、调制解调器)、实现 ISDN 协议栈(如 LAPD、Q.921/Q.931)、桥接 ISDN 设备与上层网络协议(如 TCP/IP)。


# leds

- LED子系统: 提供统一的 LED 控制框架和设备驱动，支持通过 GPIO、PWM、I2C/SPI 等接口驱动 LED，并集成到内核的电源管理和用户空间接口中。


# macintosh

- 苹果 Macintosh 计算机特有硬件驱动: 由于 Macintosh 硬件设计具有独特性 (如电源管理、热键、专用外设等)，该目录提供了对这类设备的定制化支持。提供对 Macintosh 专用硬件、电源管理、睡眠/唤醒逻辑、特有的外设接口的支持。


# mailbox

- Mailbox 硬件机制驱动: Mailbox 是一种常见的进程间通信 (IPC)机制，广泛用于嵌入式系统、多核处理器或异构计算平台，实现不同硬件模块或软件组件间的消息传递。提供对 Mailbox 硬件的驱动支持、抽象 Mailbox 硬件细节、支持多核处理器间的通信 (如 ARM big.LITTLE 架构)、芯片间 (SoC-to-SoC)或设备间 (如 CPU 与 DSP)的协同工作。


# mcb

- MCB (Memory Controller Block，内存控制器块)硬件驱动: MCB 是某些嵌入式系统或专用硬件平台中用于管理内存访问、优化性能或实现特定内存操作的关键组件。提供对 MCB 硬件的驱动支持、抽象 MCB 的硬件细节、可能支持内存保护、地址转换、缓存一致性管理等功能。


# md

- 软件 RAID 实现 (如 RAID0/1/5/10)。


# media

- 多媒体框架: V4L2 核心、摄像头/视频采集卡驱动 (如 uvcvideo)。


# memory

- 内存设备驱动: 包括 RAM (随机存取存储器)、ROM (只读存储器)、闪存 (Flash Memory)等。提供统一的内存设备管理框架和设备驱动，支持动态内存分配、错误校正和持久化存储，广泛应用于服务器、嵌入式系统、移动设备和存储系统。


# memstick

- Memory Stick 存储设备及其协议驱动: Memory Stick 是索尼公司开发的一种可移动存储介质，曾广泛用于数码相机、PDA、便携式音乐播放器等设备。提供对 Memory Stick 设备、协议、桥接 Memory Stick 设备与上层文件系统 (如 VFAT、exFAT)，实现数据的存储与访问。


# message

- 消息传递接口硬件及协议驱动: 这类驱动通常涉及设备间通过共享内存、中断或专用总线进行数据交换，常见于嵌入式系统、工业控制或高性能计算场景。


# mfd

- 多功能设备 (Multi-Function Device, MFD)驱动: MFD 设备通常集成多种功能模块 (如 ADC、DAC、GPIO、PWM、RTC 等)，常见于嵌入式系统、片上系统 (SoC)或工业控制领域。


# misc

- 杂项驱动: 无法归类的独立设备 (如 eeprom、ibmvmc 虚拟管理)。


# mmc

- SD/MMC 存储: 核心、主机控制器驱动 (如 sdhci)、eMMC 协议。


# most

- MOST (Media Oriented Systems Transport)总线协议驱动: MOST 是一种专为汽车多媒体和通信系统设计的高速串行总线标准，广泛用于车载信息娱乐系统、导航、语音通信等场景。


# mtd

- 存储技术设备 (Memory Technology Device, MTD)驱动: MTD 子系统提供了一套统一的框架，用于管理各种非易失性存储器 (如 NOR Flash、NAND Flash、ROM 等)，常见于嵌入式系统、移动设备和存储解决方案中。


# mux

- 多路复用器 (Multiplexer)硬件驱动: 多路复用器是一种常见的硬件组件，用于在多个信号或数据流之间动态切换，常见于嵌入式系统、通信设备和复杂 SoC (片上系统)中。


# net

- ethernet: 有线网卡驱动 (Intel e1000、Realtek r8169)。
- wireless: - 无线网络: Wi-Fi 驱动 (如 ath9k、iwlwifi)、MAC80211 框架。
- phy: 网络 PHY 芯片驱动 (如 Marvell 88E1111)。


# nfc

- 近场通信驱动: NFC 是一种短距离无线通信技术，允许设备在几厘米范围内交换数据，广泛用于移动支付、门禁控制、数据传输等场景。


# ntb

- 非透明桥 (Non-Transparent Bridge, NTB)硬件驱动: NTB 是一种特殊的 PCI Express (PCIe)设备，用于在两个独立的 PCIe 域之间建立通信通道，常见于高性能计算 (HPC)、数据中心互连或嵌入式系统中。


# nubus

- NuBus 架构设备驱动: NuBus 是一种由苹果公司开发的 32 位总线架构，曾用于早期的 Macintosh 计算机 (如 Macintosh II、Quadra 系列)，用于连接扩展卡 (如显卡、网卡、硬盘控制器)与主板。


# nvdimm

- 非易失性内存 (如 NVDIMM、PMEM)驱动。


# nvme

- NVMe SSD 驱动 (高性能 PCIe SSD 标准)。


# nvmem

- 非易失性存储器驱动: NVMEM 设备能够在断电后保留数据，广泛用于存储系统配置、校准数据、安全密钥和固件镜像等关键信息。drivers/nvmem 目录提供统一的 NVMEM 设备抽象层、设备驱动和用户空间接口，支持多种非易失性存储技术(如 EEPROM、Flash、FRAM、NVRAM)。


# of

- 设备树 (OF)核心: 节点解析、属性处理、动态设备树操作。


# opp

- 操作性能点 (Operating Performance Points, OPP)框架驱动: OPP 框架用于管理设备的性能状态 (如电压、频率)，常见于需要动态调整功耗和性能的场景 (如移动设备、嵌入式系统)。


# parisc

- HP PA-RISC 架构硬件驱动: PA-RISC (Precision Architecture Reduced Instruction Set Computer)是惠普公司开发的精简指令集计算机架构，曾用于 HP 9000 系列服务器和工作站。


# parport

- 并行端口 (Parallel Port)硬件驱动: 并行端口是一种经典的计算机接口，曾广泛用于连接打印机、扫描仪、外部存储设备等。


# pci

- PCI(e) 子系统: 主机桥驱动、端点驱动、热插拔管理。


# pcmcia

- PCMCIA (Personal Computer Memory Card International Association)CardBus设备驱动: PCMCIA/CardBus 是一种曾广泛用于笔记本电脑的扩展卡标准，用于连接网络适配器、调制解调器、存储设备等外设。


# peci

- PECI (Platform Environment Control Interface)协议驱动: PECI 是一种由英特尔开发的低速串行总线协议，主要用于监控和管理服务器、数据中心等环境中的硬件健康状态 (如温度、电压、风扇转速)。


# perf

- 性能监控与调试 (Performance Monitoring and Debugging)驱动: 它提供对硬件性能计数器 (如 CPU 周期、缓存命中率、分支预测错误)的访问，并支持内核调试和性能分析工具 (如 perf 工具)。


# phy

- PHY (Physical Layer)设备驱动: PHY 设备是网络接口 (如以太网、USB、SATA)中的物理层组件，负责将数字信号转换为适合在物理介质 (如双绞线、光纤)上传输的模拟信号。


# pinctrl

- 引脚控制子系统: GPIO 复用、电气属性配置 (关键外设初始化依赖)。


# platform

- 平台设备驱动: 与 SoC 紧密绑定的外设 (如片上 ADC、PWM)。


# pmdomain

- 电源管理域 (Power Management Domains)驱动: 电源管理域是一种将硬件设备或组件分组以便统一管理电源状态 (如上电、断电、休眠)的机制，旨在优化系统能效和响应速度。


# pnp

- 即插即用 (Plug-and-Play, PnP)设备驱动: PnP 技术允许操作系统自动检测和配置硬件设备，无需用户手动设置 IRQ (中断请求)、I/O 端口或 DMA (直接内存访问)通道等资源。


# power

- 电源管理: 休眠/唤醒框架、电池驱动 (power_supply)。


# powercap

- 功率限制 (Power Capping)驱动: 功率限制技术允许操作系统动态调整硬件设备的功耗上限，以平衡性能与能效，尤其在数据中心、笔记本电脑等需要精细化电源管理的场景中至关重要。


# pps

- PPS (Pulse Per Second)信号驱动: PPS 是一种高精度时间同步信号，通常由 GPS 接收器、原子钟或其他高精度时钟源生成，用于同步计算机系统的时钟，确保时间精度达到微秒甚至纳秒级。


# ps3

- 索尼 PlayStation 3 (PS3)游戏主机特定硬件或功能的驱动: 由于 PS3 的硬件架构 (如 Cell 处理器、RSX 显卡)与通用计算机存在显著差异，该目录包含了一系列定制化驱动，以支持 PS3 在 Linux 操作系统下的运行。


# ptp

- PTP (Precision Time Protocol，精确时间协议)驱动: PTP 是一种高精度时间同步协议，通常用于需要纳秒级时间精度的场景，如电信网络、金融交易、工业自动化和科学实验。


# pwm

- 脉宽调制驱动: PWM 是一种通过调整信号占空比来控制设备的技术，广泛应用于电机控制、LED 调光、电源管理等领域。


# rapidio

- RapidIO 互联技术驱动: RapidIO 是一种高性能、低延迟的串行互联技术，广泛应用于嵌入式系统、通信设备和高性能计算领域，用于实现处理器、内存、外设之间的高速数据传输。


# ras

- RAS (Reliability, Availability, and Serviceability，可靠性、可用性和可维护性)驱动: RAS 技术旨在提高系统的容错能力、故障诊断效率和可维护性，尤其在数据中心、服务器和关键任务系统中至关重要。


# regulator

- 电源管理框架: 电压/电流调节器 (如 LDO、Buck)驱动。


# remoteproc

- 远程处理器 (Remote Processor)驱动: 远程处理器通常指与主处理器 (如 CPU)物理分离但通过高速接口 (如 PCIe、UART、SPI)连接的协处理器，例如 DSP (数字信号处理器)、FPGA (现场可编程门阵列)、GPU 或专用加速器。


# reset

- 硬件复位信号驱动: 复位信号是硬件设计中用于初始化、重启或恢复设备至已知状态的关键机制，广泛用于嵌入式系统、SoC (系统级芯片)和外设控制器。


# rpmsg

- RPMsg (Remote Processor Messaging，远程处理器消息传递)协议驱动: RPMsg 是一种轻量级、高效的通信协议，用于在主处理器 (如 CPU)与远程处理器 (如 DSP、FPGA、协处理器)之间传递消息和数据，常见于异构多核系统和嵌入式设备中。


# rtc

- 实时时钟 (RTC)芯片驱动。


# s390

- IBM S/390 和 zSeries 架构驱动: S/390/zSeries 是 IBM 的高端服务器架构，广泛用于企业级计算、大型数据库、事务处理和高性能计算 (HPC)场景。drivers/s390 目录提供针对 S/390 硬件特性的驱动支持，包括通道子系统、加密硬件、网络设备和存储控制器，确保 Linux 在 IBM 大型机上的高效运行。


# sbus

- SPARC SBus 架构驱动: SBus 是 SPARC 架构中使用的总线标准，广泛用于 Sun Microsystems 的 SPARC 工作站和服务器。drivers/sbus 目录提供针对 SBus 硬件特性的驱动支持，包括 SBus 控制器、外设适配器和专用硬件模块，确保 Linux 在 SPARC 平台上的高效运行。


# scsi

- SCSI 子系统: 核心、HBA 驱动 (如 SAS/NVMe)、磁盘/磁带设备驱动。


# sh

- SuperH (SH)架构驱动: SuperH 是由 Hitachi (现 Renesas)开发的 32/64 位 RISC 架构，广泛用于嵌入式系统、消费电子和汽车电子领域。drivers/sh 目录提供针对 SuperH 硬件特性的驱动支持，包括片上系统 (SoC)外设、总线控制器和专用硬件模块，确保 Linux 在 SuperH 平台上的高效运行。


# siox

- SIOX架构驱动: SIOX 是一种新兴的 I/O 扩展技术，旨在通过标准化接口和协议，提升数据中心、高性能计算 (HPC)和存储系统的 I/O 性能与可扩展性。drivers/siox 目录提供 SIOX 框架、设备驱动和用户空间接口，支持多种 I/O 设备 (如网络适配器、存储控制器、加速卡)的统一管理和动态配置。


# slimbus

- SLIMbus驱动: SLIMbus 是一种低功耗、高速率的芯片间通信总线，广泛用于移动设备、嵌入式系统和物联网 (IoT)领域，支持音频编解码器、传感器、电源管理芯片等外设的互联。drivers/slimbus 目录提供 SLIMbus 核心框架、设备驱动和用户空间接口，确保 SLIMbus 设备在 Linux 系统中的高效运行。


# soc

SoC 厂商特定代码。

- qcom: Qualcomm 芯片支持。
- mediatek: MediaTek 芯片支持。
- samsung: Samsung Exynos 驱动。
- xilinx: Xilinx FPGA 相关驱动。


# sound

- 音频子系统 (ALSA)

## core

- ALSA 核心框架。


## pci

- PCI 声卡驱动 (如 hda)。


## soc

- SoC 集成音频编解码器 (如 Qualcomm/Wi-Fi 音频)。


# soundwire

- SoundWire 音频接口驱动: SoundWire 是 MIPI 联盟定义的一种低功耗、高性能音频传输协议，旨在替代传统 I2S/PCM 接口，广泛用于移动设备、嵌入式系统和音频配件。


# spi

- SPI 子系统: 核心、控制器驱动 (如 spi-imx)、协议驱动 (如 Flash)。


# spmi

- SPMI驱动: SPMI 是一种用于移动设备和嵌入式系统的电源管理接口标准，由 MIPI 联盟制定，旨在实现芯片间电源管理信号的标准化通信。drivers/spmi 目录提供 SPMI 核心框架、设备驱动和用户空间接口，支持多种电源管理芯片 (如 PMIC、电压调节器)的集成与控制。


# ssb

- SSB驱动: SSB 是一种用于芯片间通信的高速总线标准，广泛用于嵌入式系统、网络设备和多媒体处理器，支持低延迟、高带宽的数据传输。drivers/ssb 目录提供 SSB 核心框架、设备驱动和用户空间接口，确保 SSB 设备在 Linux 系统中的高效运行。


# staging

- 过渡代码区: 尚未稳定的驱动 (如新 Wi-Fi 芯片、实验性功能)，慎用！


# target

- SCSI 目标驱动 (用于存储网络，如 iSCSI、FC)。


# tc

- TC (Traffic Control，流量控制)驱动: TC 是一种网络流量管理技术，通过队列调度、速率限制和优先级标记等手段，优化网络性能、保障服务质量 (QoS)和实现流量整形。tc 目录提供 TC 核心框架、设备抽象层和用户空间接口，支持多种网络设备 (如以太网、无线网卡)和流量控制算法 (如 HTB、HFSC)。


# tee

- TEE (Trusted Execution Environment，可信执行环境)驱动: TEE 是一种与富执行环境 (REE，如 Linux 操作系统)隔离的安全计算环境，广泛用于保护敏感操作 (如加密、生物识别、数字版权管理)。tee 目录提供 TEE 客户端驱动、安全通信接口和用户空间库，确保 TEE 在 Linux 系统中的兼容性和安全性。


# thermal

- 温度监控与调控: 传感器驱动、冷却策略 (如风扇控制)。


# thunderbolt

- Thunderbolt/USB4 总线支持。


# tty

- 终端设备核心驱动: TTY (Teletypewriter)是 Unix/Linux 系统中历史最悠久的子系统之一，负责处理字符设备的输入/输出 (I/O)，支持物理终端 (如串口、USB 串口)、虚拟终端 (如 Linux 控制台)和伪终端 (如 SSH 会话、Xterm)。


# ufs

- UFS (Universal Flash Storage，通用闪存存储)驱动: UFS 是一种高性能、低功耗的闪存存储接口标准，广泛用于移动设备 (如智能手机、平板电脑)和嵌入式系统中，提供高速数据传输和可靠存储。ufs 目录提供 UFS 主机控制器驱动、设备枚举逻辑和用户空间接口，确保 UFS 设备在 Linux 系统中的兼容性和高性能。


# uio

- UIO (Userspace I/O，用户空间 I/O)驱动: UIO 是一种允许用户空间程序直接访问硬件设备 (如 FPGA、网络接口卡)的框架，旨在简化内核驱动开发并提升灵活性。uio 目录提供 UIO 核心框架、设备抽象层和用户空间接口，支持多种硬件平台 (如 x86、ARM、PowerPC)和设备类型 (如 PCIe、USB)。


# usb

- USB 全栈支持: 主机控制器 (xhci/ehci)、设备驱动 (storage/net)。


# vdpa

- vDPA (virtual Data Path Acceleration，虚拟数据路径加速)驱动: vDPA 是一种通过硬件卸载 (如网络、存储 I/O)提升虚拟机 (VM)和容器性能的技术，广泛用于云计算、数据中心和虚拟化环境，实现高效资源利用和低延迟 I/O。vdpa 目录提供 vDPA 核心框架、设备抽象层和用户空间接口，支持多种硬件平台 (如 Intel、Mellanox、NVIDIA)和虚拟化方案 (如 KVM、QEMU)。


# vfio

- VFIO (Virtual Function I/O，虚拟功能 I/O)驱动: VFIO 是一种安全的用户空间驱动框架，允许用户空间程序直接访问和管理 I/O 设备 (如 PCIe、USB 设备)，无需编写复杂内核驱动。vfio 目录提供 VFIO 核心框架、设备抽象层和用户空间接口，支持多种虚拟化场景 (如 KVM、QEMU)和硬件平台 (如 x86、ARM、PowerPC)。


# vhost

- vhost (Virtual Host)驱动: vhost (Virtual Host)是一种通过内核与用户空间协作优化虚拟化 I/O 性能的技术，广泛用于云计算、网络功能虚拟化 (NFV)和高性能计算 (HPC)场景，实现低延迟、高吞吐的 I/O 处理。vhost 目录提供 vhost 核心框架、设备抽象层和用户空间接口，支持多种虚拟化方案 (如 KVM、QEMU)和硬件平台 (如 x86、ARM)。


# video

- 显示和帧缓冲驱动: 负责管理图形硬件的底层输出(如显示器、控制台等)，主要包含: 帧缓冲设备(Framebuffer)、显示硬件控制(驱动显示器/LCD面板、背光亮度调节)、内核启动界面，现已被DRM/KMS等现代驱动取代。


# virt

- 虚拟化驱动 (如 KVM 设备直通、VirtIO 后端)。


# virtio

- Virtio 虚拟化接口驱动: Virtio 是一种半虚拟化技术，旨在优化虚拟机 (VM)与 Hypervisor 之间的 I/O 性能，通过定义标准化的设备接口 (如网络、块设备、balloon 内存)减少虚拟化开销。


# w1

- 1-Wire 总线驱动: 只有一根数据线的低速串行通信协议。


# watchdog

- 看门狗定时器驱动。


# xen

- Xen 虚拟化环境驱动: 实现 Linux 内核与 Xen Hypervisor 的深度集成，优化虚拟化性能并支持高级功能 (如实时迁移、设备直通)。


# zorro

- Zorro 总线驱动: Zorro 总线是 Amiga 计算机中用于连接扩展卡 (如显卡、声卡、网络卡)的总线标准。
