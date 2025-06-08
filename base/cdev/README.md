
# Introduction

The cdev linux driver.


# Platform

Test on Ubuntu 22.04.


# Install

```bash
$ sudo apt update
$ sudo apt install build-essential flex bc gawk texinfo file libssl-dev libncurses-dev
$ sudo apt install linux-headers-$(uname -r)
```


# Usage

- Build and clear kernel log:

```bash
$ sudo dmesg -c
$ make
```

- Install driver and see kernel log:

```bash
$ sudo insmod cdev_driver.ko
$ sudo dmesg -c
[  730.698607] cdev_driver driver installed.
```

- See module:

```bash
$ lsmod | grep cdev
cdev_driver            16384  0
```

- Test app:

```bash
$ sudo ./test-app
Read from kernel 1: 0xab.
Read from kernel 2: 0x56.
```

- See driver information:

```bash
$ sudo dmesg -c
[  778.850524] cdev_driver: Write 0x56.
```

- Uninstall driver and see kernel log:

```bash
$ sudo rmmod cdev_driver
$ sudo dmesg -c
[  890.593141] cdev_driver unistalled.
```


# License

GPL-2.0 License.
