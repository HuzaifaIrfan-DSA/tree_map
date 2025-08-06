# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -MMD -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
TARGET = main

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# Default target
all: $(TARGET)

# Link final binary
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Compile .c to .o in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
