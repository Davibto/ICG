all:	casa.exe

clean:
	rm casa.o casa.exe

casa.exe:	casa.o
	g++ -g	-o	casa	casa.o	-lglut	-lGLU	-lGL

casa.o:
	g++	-c	-g	-lglut	-lGLU	-lGL	casa.cpp 