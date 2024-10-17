GCC = gcc
FLAGS = -c

PROGRAMAS: principalLab 

principalLab:
	$(GCC) $(FLAGS) funciones.c
	$(GCC) $@.c funciones.o -o $@
	$(RM) *.o

clear:
	$(RM) *.o principalLab
