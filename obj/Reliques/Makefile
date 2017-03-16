
CC=g++
CFLAGS=-W -Wall -ansi -pedantic -lstdc++
sourcedir = scr
libesdir = lib
objdir = obj/Debug
sources = Bateau.cpp Allegro.cpp Casetouche.cpp Cuirasse.cpp Destroyer.cpp Fusee.cpp Menu.cpp Objet.cpp Partie.cpp Sousmarin.cpp
libes = Bateau.h Allegro.h Casetouche.h Cuirasse.h Destroyer.h Fusee.h Menu.h Objet.h Partie.h Sousmarin.h
objets = $(sourcedir)/$(sources:.cpp=.o)
%: %.o
	$(CC) -o $@ -c $< $(CFLAGS)


jeux: $(objdir)/$(objets)

###

codesource.pdf: $(sourcedir)/$(sources) main.cpp $(libesdir)/$(libes) Makefile
	a2ps -o - $^ | ps2pdf - @<

clean:
	rm -f *~ *.o *.bak

mrproper: clean
	rm -f jeux

depend:
	makedepend $(sourcedir)/$(sources) $(sourcedir)/main.cpp
