
# Introduction

The simple linux driver.


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
$ sudo insmod hello-driver.ko
$ sudo dmesg -c
[ 4380.261921] hello_driver: module license 'GPL-2.0' taints kernel.
[ 4380.261929] Disabling lock debugging due to kernel taint
[ 4380.263826] Kernel: hello init.
```

- See module:

```bash
$ lsmod | grep hello
hello_driver           16384  0
```

- Uninstall driver and see kernel log:

```bash
$ sudo rmmod hello_driver
$ sudo dmesg -c
[ 4949.313959] Kernel: hello exit.
```


# License

GPL-2.0 License.
