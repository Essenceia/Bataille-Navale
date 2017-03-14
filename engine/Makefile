IDIR =/include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
#LDIR =../lib

LIBS=-lm

_DEPS = Bateau.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Bateau.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) #$(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
