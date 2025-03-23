CC= gcc
CFLAGS= -Wall -Wextra -std=c99

dashboard: dashboard.o DB_impl.o DB.o
	$(CC) $(CFLAGS) -o dashboard $^

dashboard.o: dashboard.c DB_impl.h DB.h
	$(CC) $(CFLAGS) -c dashboard.c

DB_impl.o: DB_impl.c DB_impl.h DB.h
	$(CC) $(CFLAGS) -c DB_impl.c

DB.o: DB.c DB.h
	$(CC) $(CFLAGS) -c DB.c

clean:
	rm -f *.o dashboard

run: dashboard
	./dashboard dataset/PicnicTableSmall.csv

leaks:
	leaks --atExit -- ./dashboard dataset/PicnicTableSmall.csv

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./dashboard dataset/PicnicTableSmall.csv