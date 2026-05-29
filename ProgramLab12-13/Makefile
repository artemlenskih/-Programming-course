.PHONY: clean all

CC = gcc
CFLAGS = -Wall -I./include
TARGET = main_exe
SOURCE_DIR = src/
LIB_NAME = libLab12-13.so

all: $(TARGET)

$(TARGET): mainLab12.o $(LIB_NAME)
	$(CC) mainLab12.o -o $(TARGET) -L. -lLab12-13 -Wl,-rpath,.
	
mainLab12.o: $(SOURCE_DIR)/mainLab12.c
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/mainLab12.c -o mainLab12.o

Lab12_100.o: $(SOURCE_DIR)/Lab12_100.c
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/Lab12_100.c -o Lab12_100.o -fPIC

$(LIB_NAME): Lab12_100.o
	$(CC) --shared Lab12_100.o -o $(LIB_NAME)

clean:
	rm -rf *.o *.so *.a $(TARGET)