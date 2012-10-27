all: queuetest tnodetest randtree

queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -c queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

tnodetest: tnodetest.o tnode.o
	gcc -g tnodetest.o tnode.o -o tnodetest

tnode.o: tnode.c tnode.h
	gcc -g -c tnode.c

tnodetest.o: tnodetest.c tnode.h
	gcc -g -c tnodetest.c

randtree: randtree.o tnode.o
	gcc -g randtree.o tnode.o -o randtree

docs: 
	doxygen
	chmod go+r html/*
	cp -p html/* ~/public_html/assig5

clean:
	rm -f *~
	rm -f *.o
	rm -f queuetest
	rm -f tnodetest
	rm -f randtree

