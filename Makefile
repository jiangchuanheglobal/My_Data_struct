SRC = main.c heap.c

main: $(SRC)
	cc -g -o main $(SRC)

.PHONY: clean

clean:
	rm main
	rm -r
