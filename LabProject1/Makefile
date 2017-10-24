all: Sosa-Isaias-PMS

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

Sosa-Isaias-PMS: Sosa-Isaias-PMS.o
		   cc -o $@ $^

BSTree.o: Sosa-Isaias-PMS.c BSTree.h
	cc -c $(CFLAGS)

Sosa-Isaias-PMS.o: Sosa-Isaias-PMS.c BSTree.h
	       cc -c $(CFLAGS) Sosa-Isaias-PMS.c

clean:
	rm -f *.o Sosa-Isaias-PMS

demo: Sosa-Isaias-PMS
	 ./Sosa-Isaias-PMS

