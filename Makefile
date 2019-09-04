# 0MQ Example Makefile

CC=gcc
OUTPUTDIR=bin
CFLAGS=-lzmq

version:
	$(CC) -o $(OUTPUTDIR)/version examples/version.c $(CFLAGS)
