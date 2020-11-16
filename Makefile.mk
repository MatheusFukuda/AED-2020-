ifeq ($(OS), Windows_NT)
TARGET=program.exe
else
TARGET=program
endif

SRC=$(wildcard *.c)
H_SRC=$(wildcard *.h)
OBJ=$(SRC:.c=.o)
CC=gcc

all: $(TARGET) clear
$(TARGET): $(OBJ)
	$(CC) $^ -o $@
%.o: %.c %.h
	$(CC) -c $< -o $@


ifeq ($(OS), Windows_NT)	#se SO for windows comando para windows de delet
clear:						#se SO for para Linux, comando delet para Linux
	-@del /f /a *.o
else
clear:
	-@rm -rvf *.o
endif
