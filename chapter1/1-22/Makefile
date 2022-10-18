CC=gcc
CFLAGS=-std=c99 -Wall
BIN=foldlines
INPUT=input
OUT=out

$(BIN): foldlines.c
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS += -g
debug: $(BIN)

release: CFLAGS += -O2
release: $(BIN)

test: $(BIN)
	./$(BIN) < $(INPUT) > $(OUT)

clean:
	rm $(BIN) 
