
# Introduction

The base linux driver.


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
$ sudo insmod base-driver.ko
$ sudo dmesg -c
[ 2400.711325] base_driver: Create device driver successful.
[ 2425.314983] base_driver: Write hello world.
```

- See module:

```bash
$ lsmod | grep base
base_driver            16384  0
```

- Test app:

```bash
$ sudo ./test-app
Read from kernel: Aello world.
```

- Uninstall driver and see kernel log:

```bash
$ sudo rmmod base_driver
$ sudo dmesg -c
[ 2498.949272] base_driver: Uninstalled.
```


# License

GPL-2.0 License.
