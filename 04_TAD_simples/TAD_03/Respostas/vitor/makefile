all: locadora

locadora: main.o locadora.o filme.o
	gcc -o locadora main.o locadora.o filme.o -Wall -g

main.o: main.c locadora.h
	gcc -o main.o main.c -c -Wall -g

locadora.o:	locadora.c filme.o locadora.h
	gcc -o locadora.o locadora.c -c -Wall -g

filme.o: filme.c filme.h
	gcc -o filme.o filme.c -c -Wall -g

clear:
	rm *.o locadora