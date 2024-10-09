all: arc4 ex

ex: examples/ex.o src/arc4.o
	gcc src/arc4.o examples/ex.o -o examples/ex -Wall -O2

ex.o: examples/ex.c
	gcc -c -O2 -Wall examples/ex.c

arc4: src/arc4.o
	gcc src/arc4.o -o src/arc4.so -O2 -Wall -fPIC -shared -ldl -D_GNU_SOURCE

arc4.o: src/arc4.c
	gcc -c -O2 -Wall src/arc4.c

clean:
	rm -f src/*.o src/*.so examples/*.o examples/ex
