CC = gcc
CFLAGS = -std=c99
OBJECTS = authenticate.o category.o customer.o decorate.o inventory.o main.o personnel.o pos.o promotion.o purchase.o report.o sales.o settings.o support.o systemcall.o transaction.o
EXEC = Click-to-run-POS

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC) -lm

authenticate.o: authenticate.c main.h
	$(CC) $(CFLAGS) -c authenticate.c

category.o: category.c main.h
	$(CC) $(CFLAGS) -c category.c

customer.o: customer.c main.h
	$(CC) $(CFLAGS) -c customer.c

decorate.o: decorate.c main.h
	$(CC) $(CFLAGS) -c decorate.c

inventory.o: inventory.c main.h
	$(CC) $(CFLAGS) -c inventory.c

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

personnel.o: personnel.c main.h
	$(CC) $(CFLAGS) -c personnel.c

pos.o: pos.c main.h
	$(CC) $(CFLAGS) -c pos.c

promotion.o: promotion.c main.h
	$(CC) $(CFLAGS) -c promotion.c

purchase.o: purchase.c main.h
	$(CC) $(CFLAGS) -c purchase.c

report.o: report.c main.h
	$(CC) $(CFLAGS) -c report.c

sales.o: sales.c main.h
	$(CC) $(CFLAGS) -c sales.c

settings.o: settings.c main.h
	$(CC) $(CFLAGS) -c settings.c

support.o: support.c main.h
	$(CC) $(CFLAGS) -c support.c

systemcall.o: systemcall.c main.h
	$(CC) $(CFLAGS) -c systemcall.c

transaction.o: transaction.c main.h
	$(CC) $(CFLAGS) -c transaction.c

.PHONY : clean

clean:
	-rm $(EXEC) *.o

clear:
	-rm $(EXEC) *.o

run:
	./$(EXEC)

