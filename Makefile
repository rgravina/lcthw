all:
	gcc -std=c11 -Wall ex17.c -o ex17
	gcc -std=c11 -Wall ex18.c -o ex18
clean:
	rm -f ex17 ex18
