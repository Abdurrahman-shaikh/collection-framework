# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source directory
SRC_DIR = src

# Include directory
INC_DIR = include

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c) main.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXECUTABLE = my_program

# Compilation rule
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -I$(INC_DIR) $^ -o $@

# Object files compilation rule
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean rule
clean:
	rm -f $(SRC_DIR)/*.o $(EXECUTABLE)

