CC=gcc
CFLAGS=-Wall -I $(INC_PATH)

OBJECTS=(wildcard *.o)

SRC_PATH=src
INC_PATH=include
OBJ_PATH=obj
BIN_PATH=bin
#VPATH=bin:src:include:obj
vpath %.c ./src
vpath %.h ./include
vpath %.o ./obj

main:	main.o grille.o interaction.o serie.o image.o
	$(CC) $(CFLAGS) -o $@ obj/main.o obj/interaction.o obj/serie.o obj/grille.o obj/image.o -lncurses
	mv main bin/.
grille.o: grille.c grille.h  
	$(CC) -c $(CFLAGS) $<
	mv grille.o obj/.
serie.o: serie.c grille.h 
	$(CC) -c $(CFLAGS) $<
	mv serie.o obj/.
image.o: image.c image.h
	$(CC) -c $(CFLAGS) $<
	mv image.o obj/.
interaction.o: interaction.c grille.h interaction.h 
	$(CC) -c $(CFLAGS) $< 
	mv interaction.o obj/.
main.o: main.c grille.h 
	$(CC) -c $(CFLAGS) $<
	mv main.o obj/.
maindb: base.h grille.h interaction.h grille.c main.c serie.c interaction.c
	$(CC) $(CFLAGS) -g src/main.c src/grille.c src/serie.c src/interaction.c -o $@ -lncurses
	mv maindb bin/.
clean: 
	rm -f *.o 
	rm -f *~
