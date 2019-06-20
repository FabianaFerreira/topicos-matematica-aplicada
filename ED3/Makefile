#  Fabiana Ferreira Fonseca
#  Universidade Federal do Rio de Janeiro
#  DRE: 115037241

# the compiler
CC = g++
CFLAGS  = -Wall -std=c++11
OBJFILES = functions.o Matrix.o SquareMatrix.o DiagonalMatrix.o UpperTriangularMatrix.o LowerTriangularMatrix.o MatrixList.o ed3.o
# OBJFILES = functions.o Matrix.o teste.o

TARGET = ed3.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
