all: menu.o index_first_negative.o index_last_negative.o sum_between_negative.o
	gcc -o menu menu.o index_first_negative.o index_last_negative.o sum_between_negative.o
menu.o: menu.c index_first_negative.h index_last_negative.h sum_between_negative.h
	gcc -c menu.c
index_first_negative.o: index_first_negative.h index_first_negative.c
	gcc -c index_first_negative.c
index_last_negative.o: index_last_negative.h index_last_negative.c
	gcc -c index_last_negative.c
sum_between_negative.o: sum_between_negative.h sum_between_negative.c
	gcc -c sum_between_negative.c
