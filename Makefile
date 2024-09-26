# Variables
CC = gcc
CFLAGS = -Wall -I./include -I./lib/include    # Include both global and lib-specific headers
LDFLAGS =
SRC_DIR = src
LIB_SRC_DIR = lib/src
OBJ_DIR = obj

# Source and object files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/read_file.c $(LIB_SRC_DIR)/remove_blank_space.c
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/read_file.o $(OBJ_DIR)/remove_blank_space.o

# Executable name
EXEC = program

# Default target
all: $(EXEC)

# Build the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./include/*.h
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile library source files into object files
$(OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c ./lib/include/*.h
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build files
clean:
	if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	if exist $(EXEC) del $(EXEC)

# Phony target so clean doesn't conflict with a file named 'clean'
.PHONY: clean
