EXEC = Click-to-run-POS

$(EXEC): main.c main.h
	gcc -o $(EXEC) main.c -std=c99 -I.

clean:
	rm -f $(EXEC)
