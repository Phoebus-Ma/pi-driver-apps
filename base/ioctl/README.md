
# Introduction

The ioctl linux driver.


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
$ sudo insmod ioctl_driver.ko
$ sudo dmesg -c
[ 7491.099906] ioctl_driver: Create device driver successful.
```

- See module:

```bash
$ lsmod | grep ioctl
ioctl_driver           16384  0
```

- Test app:

```bash
$ sudo ./test-app
Reset random sucessfully.
Set random sucessfully.
Device ID: 0x12345678.
value: 200.
The a + b = 3.
```

- See driver information:

```bash
$ sudo dmesg -c
[ 7571.445766] ioctl_driver: Random reset: 0x1010.
[ 7571.445885] ioctl_driver: random number: 13579.
[ 7571.445915] ioctl_driver: HELLO_IOCEXCHANGE value * 2 = 200.
```

- Uninstall driver and see kernel log:

```bash
$ sudo rmmod ioctl_driver
$ sudo dmesg -c
[ 7639.604811] ioctl_driver: Uninstalled.
```


# License

GPL-2.0 License.
