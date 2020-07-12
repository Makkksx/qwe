objects = menu.o index_first_negative.o index_last_negative.o multi_between_negative.o multi_before_and_after_negative.o
all: $(objects)
	gcc -o menu $(objects)
menu.o: index_first_negative.h index_last_negative.h multi_between_negative.h multi_before_and_after_negative.h
	gcc -c menu.c
index_first_negative.o: index_first_negative.h index_first_negative.c
	gcc -c index_first_negative.c
index_last_negative.o: index_last_negative.h index_last_negative.c
	gcc -c index_last_negative.c
multi_between_negative.o: multi_between_negative.h index_first_negative.h index_last_negative.h multi_between_negative.c
	gcc -c multi_between_negative.c
multi_before_and_after_negative.o: multi_before_and_after_negative.h index_first_negative.h index_last_negative.h multi_before_and_after_negative.c
	gcc -c multi_before_and_after_negative.c
