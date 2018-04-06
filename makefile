CC=gcc
CFLAGS=-g -Wall -std=c11
LIBS=
TAR=prog

OUT=textfiles
PTXT=p_*.txt
CTXT=c_*.txt

.PHONY: default all clean

default: $(TAR)
all: default cleanobj

OBJ=$(patsubst %.c, %.o, $(wildcard *.c))
HEADERS=$(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TAR) $(OBJ)

$(TAR): $(OBJ)
	$(CC) $(OBJ) -Wall -o $@ $(LIBS)

clean:
	-rm -f *.o
	-rm -f $(TAR)
	-rm -f $(OUT)/$(PTXT) $(OUT)/$(CTXT)

rebuild: clean all

cleanobj:
	-rm -f *.o

cleanout:
	-rm -f $(OUT)/$(PTXT) $(OUT)/$(CTXT)