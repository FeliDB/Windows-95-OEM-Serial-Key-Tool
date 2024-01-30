# Makefile

CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -Iinclude
CXXFLAGS := -Wall -Wextra -Iinclude

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.c $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS)))

TARGET := ./bin/keygen95

.PHONY: all clean

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	@mkdir -p $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) $(TARGET)
