#Make file for Assignment

a = main.c
b = functions.c
c = assignment_3.h

assignment3: $(a) $(b) $(c)
	gcc -Wall -ggdb -o assignment $(a) $(b)
	./assignment

clean:
	rm *# *~ assignment
