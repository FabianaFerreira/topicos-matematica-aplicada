#  Fabiana Ferreira Fonseca
#  Universidade Federal do Rio de Janeiro
#  DRE: 115037241

# the compiler
CC = g++
CFLAGS  = -Wall

OBJFILES = functions.o ClasseCalculadora.o ed1.o
TARGET = ed1.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
