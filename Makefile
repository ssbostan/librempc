# libreMPC is Multiple Precision Arithmetic.
# Copyright (c) 2014 Saeid Bostandoust <ssbostan@gmail.com>

LIBDIR=/usr/lib
LIB64DIR=/usr/lib64
INCLUDEDIR=/usr/include
CC=gcc
CFLAGS=-Wall
CXXFLAGS=-fPIC -c
LDFLAGS=-shared
SONAME=libmpc.so

$(SONAME): mpc.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $?

mpc.o: mpc.c
	$(CC) $(CFLAGS) $(CXXFLAGS) -o $@ $?

.PHONY: install
install:
	cp $(SONAME) $(LIBDIR)
	[ -d $(LIB64DIR) ] && ln -s $(LIBDIR)/$(SONAME) $(LIB64DIR)/$(SONAME)
	cp mpc.h $(INCLUDEDIR)

.PHONY: uninstall
uninstall:
	[ -d $(LIB64DIR) ] && rm -f $(LIB64DIR)/$(SONAME)
	rm -f $(LIBDIR)/$(SONAME)
	rm -f $(INCLUDEDIR)/mpc.h

.PHONY: clean
clean:
	rm -f $(SONAME) mpc.o
