

# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
OPT = -g -DDEBUG
# wersja zoptymalizowana do mierzenia czasu
# OPT = -O3

# pliki naglowkowe
#INC = -I../pomiar_czasu

# biblioteki
#LIB = -L../pomiar_czasu -lm

# zaleznosci i komendy
moj_program: pub_sym_1.o
	$(LOADER) $(OPT)  pub_sym_1.o -o moj_program $(LIB) -lpthread

# jak uzyskac plik moj_program.o ?



pub_sym_1.o: pub_sym_1.c
	$(CCOMP) -c $(OPT) pub_sym_1.c 

clean:
	rm -f *.o
