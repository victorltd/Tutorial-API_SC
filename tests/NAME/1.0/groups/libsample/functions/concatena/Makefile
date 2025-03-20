INSTALL_PREFIX ?= /home/victor/Documentos/UFPE/UFPE/api-sanity-checker/Tutorial-API_SC

CC       = gcc
CFLAGS   = -Wall
INCLUDES = -I"$(INSTALL_PREFIX)"
LIBS     = -L"$(INSTALL_PREFIX)" -lsample

all: test

test: test.c
	$(CC) $(CFLAGS) $(INCLUDES) test.c -o test $(LIBS)

clean:
	rm -f test test.o
