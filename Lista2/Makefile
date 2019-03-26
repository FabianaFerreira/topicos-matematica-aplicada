# the compiler
CC = g++
CFLAGS  = -Wall

OBJFILES = functions.o lista2.o
TARGET = lista2.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
