CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = main
SRC = main.c stack_ops.c command_handler.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)
	mv $(TARGET) ../

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ) ../$(TARGET)

.PHONY: all clean
