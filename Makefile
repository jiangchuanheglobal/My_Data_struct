SRC = main.c deque.c

main: $(SRC)
	cc -g -o main $(SRC)

.PHONY: clean

clean:
	rm main
