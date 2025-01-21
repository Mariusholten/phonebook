CC = gcc
CFLAGS = -Wall -Wextra

phonebook.exe: phonebook.o contact.o
	$(CC) -o phonebook.exe phonebook.o contact.o

phonebook.o: phonebook.c contact.h
	$(CC) $(CFLAGS) -c phonebook.c

contact.o: contact.c contact.h
	$(CC) $(CFLAGS) -c contact.c

clean:
	del *.o phonebook.exe

run:
	.\phonebook