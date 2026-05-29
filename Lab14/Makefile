.PHONY: clean all

CC = gcc
CFLAGS = -Wall -I./include
TARGET = main_exe
SOURCE_DIR = src/
LIB_NAME = libLab14.so

all: $(TARGET)

$(TARGET): Lab14.o $(LIB_NAME)
	$(CC) Lab14.o -o $(TARGET) -L. -lLab14 -Wl,-rpath,.
	
Lab14.o: $(SOURCE_DIR)/Lab14.c
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/Lab14.c -o Lab14.o

Lab14F.o: $(SOURCE_DIR)/Lab14F.c
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/Lab14F.c -o Lab14F.o -fPIC

$(LIB_NAME): Lab14F.o
	$(CC) --shared Lab14F.o -o $(LIB_NAME)

clean:
	rm -rf *.o *.so *.a $(TARGET)