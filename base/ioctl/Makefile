
APP = test-app
obj-m = ioctl_driver.o
ioctl_driver-objs := main.o calculate.o


CC = gcc
KERNEL_DIR = /usr/src/linux-headers-$(shell uname -r)
PWD = $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	$(CC) -o $(APP) $(APP).c

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	$(RM) $(APP)
