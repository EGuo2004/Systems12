all: twelve

twelve: main.o
	gcc main.o -o twelve
	
main.o: main.c
	gcc -c main.c
	
run:
	./twelve
