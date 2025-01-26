CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
SRC = src/main.c src/jogo.c src/tabuleiro.c src/util.c
OBJ = $(SRC:.c=.o)
TARGET = batalha_naval

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
