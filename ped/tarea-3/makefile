CC = g++
CFLAGS = -std=c++20 -Wall

BIN_DIR = bin
TARGET = $(BIN_DIR)/main

.PHONY: all clean run force_build

all: $(TARGET)

$(TARGET): Source.cpp
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR)

force_build:
	@$(MAKE) clean
	@$(MAKE) all

run: force_build
	./$(TARGET)
