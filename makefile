run : test_tunes
	./test_tunes

test_tunes : main.c tunes.o
	gcc -o test_tunes main.c

tunes.o : tunes.h
	gcc -c tunes.h
