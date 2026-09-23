CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = db_generator

SRC = src/main.c src/generator.c src/exporter.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
