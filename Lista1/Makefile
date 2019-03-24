# the compiler
CC = g++
CFLAGS  = -Wall

OBJFILES = ClasseEquacaoSegundoGrau.o lista1.o
TARGET = lista1.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
