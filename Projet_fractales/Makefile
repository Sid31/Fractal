# RAPPEL : 
# $^ : liste des dependances 
# $@ : cible
# $< : Premiere dependance

#Repertoires
srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savedir = ./save/
texdir = ./Latex/

#Variables
CC = gcc -Wall #compilation
CP = cp -u
RM = rm -i -f #suppresion
SRC = $(wildcard $(srcdir)*.c) #fichiers sources situées dans le dossier srcdir
# HEAD = $(#wildcard *.h)
OBJ = $(subst $(srcdir), $(bindir),$(SRC:.c=.o)) #reprise de la commande SRC en remplacant le dossier srcdir par bindir et les .c en .o
#OBJ = $(SRC:.c=.o) 
PROG = $(bindir)fractale #executable
TEX = $(wildcard $(texdir)*.tex)
GTEX = *.log *.aux *.toc


all : $(PROG)

$(PROG) : $(OBJ)
	$(CC) `sdl-config --libs` $^ -o $@ 

$(bindir)%.o : $(srcdir)%.c
	$(CC) `sdl-config --cflags` -c $< -o $@

clean :
	$(RM) $(bindir)*.o $(PROG) *~ *# $(GTEX)

latex : $(TEX)
	pdflatex $^

