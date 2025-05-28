CC = gcc

SRC_DIR = ./src
BUILD_DIR = ./build

$(BUILD_DIR)/lamp:$(SRC_DIR)/main.c
	$(CC) $(SRC_DIR)/main.c $(SRC_DIR)/signin/signin.c -o $(BUILD_DIR)/lamp
