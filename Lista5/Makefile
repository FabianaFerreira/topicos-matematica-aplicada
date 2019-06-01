#  Fabiana Ferreira Fonseca
#  Universidade Federal do Rio de Janeiro
#  DRE: 115037241

# the compiler
CC = g++
CFLAGS  = -Wall

OBJFILES1 = Aluno.o Lista.o functions.o lista5q1.o

OBJFILES2 = Aluno.o Lista.o sortRules.o functions.o lista5q2.o

TARGET1 = lista5q1.exe

TARGET2 = lista5q2.exe

all: $(TARGET1) $(TARGET2)

q1: $(OBJFILES1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJFILES1)

q2: $(OBJFILES2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJFILES2)

clean:
	rm -f $(OBJFILES1) $(OBJFILES2) $(TARGET1) $(TARGET2) *~
