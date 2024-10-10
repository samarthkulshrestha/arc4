all: arc4 ex

ex: ex.o arc4.o
	gcc arc4.o ex.o -o ex -Wall -O2

ex.o: ex.c
	gcc -c -O2 -Wall ex.c

arc4: arc4.o
	gcc arc4.o -o arc4.so -O2 -Wall -fPIC -shared -ldl -D_GNU_SOURCE

arc4.o: arc4.c
	gcc -c -O2 -Wall arc4.c

clean:
	rm -f *.o *.so ex
