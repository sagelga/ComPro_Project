EXEC = Click-to-run-POS

$(EXEC): main.h authenticate.c category.c customer.c decorate.c inventory.c main.c personnel.c pos.c promotion.c purchase.c report.c sales.c settings.c support.c systemcall.c transaction.c
	gcc -o $(EXEC) authenticate.c category.c customer.c decorate.c inventory.c main.c personnel.c pos.c promotion.c purchase.c report.c sales.c settings.c support.c systemcall.c transaction.c -std=c99 -I.

clean:
	rm -f $(EXEC)
