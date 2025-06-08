
APP = test-app
obj-m = cdev_driver.o
cdev_driver-objs := main.o


CC = gcc
KERNEL_DIR = /usr/src/linux-headers-$(shell uname -r)
PWD = $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	$(CC) -o $(APP) $(APP).c

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	$(RM) $(APP)
