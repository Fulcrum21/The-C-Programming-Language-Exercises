CC=gcc
CFLAGS=-std=c99 -Wall
BIN=rmcom
INPUT=input
OUT=out
SRC=rmcom.c

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

debug:clean
debug: CFLAGS += -g
debug: $(BIN)

release: clean
release: CFLAGS += -O2
release: $(BIN)

test: $(BIN)
	./$(BIN) < $(INPUT) > $(OUT)

clean:
	rm $(BIN) 
