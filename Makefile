.c.o:   $*.h
	g++ -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	trabalho

trabalho:  trabalho.o funcoes.o winGL.o
	g++ -o $@ $^ -lglut -lGL -lGLU

clean:
	rm *.o *.*~ *~ trabalho
