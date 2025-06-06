
APP = test-app
obj-m += base-driver.o


CC = gcc
KERNEL_DIR = /usr/src/linux-headers-$(shell uname -r)
CUR_DIR = $(shell pwd)

all:
	make -C $(KERNEL_DIR) M=$(CUR_DIR) modules
	$(CC) -o $(APP) $(APP).c

clean:
	make -C $(KERNEL_DIR) M=$(CUR_DIR) clean
	$(RM) $(APP)
