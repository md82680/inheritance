CC = clang
CFLAGS = -g -Wall -Werror -Wextra
LDLIBS = -lcs50

# List all your programs here
PROGRAMS = hello scores scrabble

all: $(PROGRAMS)

inheritance: inheritance.c
	$(CC) $(CFLAGS) -o inheritance inheritance.c $(LDLIBS)

clean:
	rm -f $(PROGRAMS)
	rm -f *.o filter core