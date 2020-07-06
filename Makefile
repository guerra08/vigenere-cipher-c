CC := gcc

vigenere: main.c
	$(CC) $^ -o $@

clean: vigenere
	rm $^