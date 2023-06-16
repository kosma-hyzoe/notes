all : 
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
obj-m = brdx.o
clean:
	rm -rf *.o *.ko *.mod.c .an* .lab* .tmp_versions test-all Module.symvers *.mod modules.order
