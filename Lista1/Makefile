# the compiler
CC = g++
CFLAGS  = -Wall

OBJFILES = ClasseEquacaoSegundoGrau.o exercicios1.o
TARGET = exercicios1

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
