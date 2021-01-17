CC=gcc
FLAGS= -Wall -g

all:  mainTrie.o trie.o frequency

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c  trie.c

frequency: mainTrie.o trie.o 
	$(CC) $(FLAGS) mainTrie.o trie.o -o frequency

mainTrie.o: mainTrie.c trie.h
	$(CC) $(FLAGS) -c  mainTrie.c


.PHONY: clean all 

clean:
	rm -f *.o frequency