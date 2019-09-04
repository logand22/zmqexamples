# 0MQ Example Makefile

CC=gcc
OUTPUTDIR=bin
CFLAGS=-lzmq

version:
	$(CC) -o $(OUTPUTDIR)/version examples/version.c $(CFLAGS)

helloworld: 
	$(CC) -o $(OUTPUTDIR)/hserver examples/hello_server.c examples/zhelpers.h $(CFLAGS)
	$(CC) -o $(OUTPUTDIR)/hclient examples/hello_client.c examples/zhelpers.h $(CFLAGS)
