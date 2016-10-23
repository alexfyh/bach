all: baash.o
	 gcc baash.o -o baash

baash.o: baash.c
		 gcc -c baash.c -o baash.o

clean: 
	  rm baash.o baash
