#  Fabiana Ferreira Fonseca
#  Universidade Federal do Rio de Janeiro
#  DRE: 115037241

CC = g++
CFLAGS  = -Wall -std=c++11
OBJFILES = functions.o Pino.o Pilha.o MatrixList.o lista4.o
TARGET = lista4.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
