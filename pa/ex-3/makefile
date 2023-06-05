CC = g++
CFLAGS = -std=c++20 -Wall

BIN_DIR = bin
TARGET = $(BIN_DIR)/main

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.cpp
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR)

run: $(TARGET)
	$(TARGET)

