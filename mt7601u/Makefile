obj-m += mt7601u.o
mt7601u-y := main.o dma.o core.o mac.o mcu.o phy.o eeprom.o init.o usb.o tx.o debugfs.o util.o trace.o
ccflags-y := -I$(src)

#mt7601u-y := main.o dma.o core.o mac.o mcu.o phy.o eeprom.o init.o usb.o tx.o debugfs.o util.o trace.o
KDIR ?= /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
