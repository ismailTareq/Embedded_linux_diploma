obj-m += gpio_driver.o
gpio_driver-objs := ioctl.o file-operation.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
