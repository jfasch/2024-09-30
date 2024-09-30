all: hello-world hello-suesser
clean:
	rm libcompany.a hello-suesser hello-world *.o

# <COMPANY VALUE>
greet.o: greet.c
	gcc -c -o greet.o greet.c

bye.o:  bye.c
	gcc -c -o bye.o bye.c

libcompany.a: greet.o bye.o
	ar cr libcompany.a greet.o bye.o
# </COMPANY VALUE>

hello-world.o: hello-world.c
	gcc -c -o hello-world.o hello-world.c

hello-suesser.o: hello-suesser.c
	gcc -c -o hello-suesser.o hello-suesser.c

hello-world: hello-world.o libcompany.a
	gcc -o hello-world hello-world.o libcompany.a

hello-suesser: hello-suesser.o libcompany.a
	gcc -o hello-suesser hello-suesser.o libcompany.a
