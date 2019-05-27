obj-m+=amit_driver.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules 
	$(CC) user_space_handler.c -o handler
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm handler
