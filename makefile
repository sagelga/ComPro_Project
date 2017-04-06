EXEC = Click-to-run-POS

$(EXEC): main.c main.h inventory.c sales.c customer.c purchase.c transaction.c promotion.c settings.c report.c decorate.c
	gcc -o $(EXEC) main.c inventory.c sales.c customer.c purchase.c transaction.c promotion.c settings.c report.c decorate.c -std=c99 -I.

clean:
	rm -f $(EXEC)
