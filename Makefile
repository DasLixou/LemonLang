ifeq ($(OS),Windows_NT)
SHELL := powershell.exe
.SHELLFLAGS := -NoProfile -Command
endif

CC := gcc

exec = lemonc.exe
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -fPIC -std=c99

$(exec): $(objects)
	$(CC) $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	$(CC) -c $(flags) $< -o $@

clean:
	rm src/*.o