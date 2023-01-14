### VARIABLES ###
 
CC = gcc
CFLAGS = -lgraph -ansi -Wall 
EXE = paires
OFILES = menu.o paires.o timer_fin.o jeu.o grille.o 
 
### BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}
 
### REGLES OPTIONNELLES ###
 
clean :
	-rm -f ${OFILES}

run : but
	./${EXE}

mrproper : clean but
 
### BUTS FACTICES ###
 
.PHONY : but clean mrproper run
 
### FIN ###
