#IDIR =../include
CC=gcc
CFLAGS=#-I$(IDIR)

ODIR=../obj
LDIR=../lib

_DEPS = archiver.h
DEPS = #$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = archiver.o zip.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

archiver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./$(ODIR)/*.o ./*~ ./core ./$(IDIR)/*~ 
