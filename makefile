#En este archivo se encuentran las instrucciones de compilacion doble para make

ordenar.exe: ordenar.o funciones.o
	gcc ordenar.o funciones.o -o ordenar.exe

ordenar.o: ordenar.c
	gcc -c ordenar.c

funciones.o: funciones.c
	gcc -c funciones.c
