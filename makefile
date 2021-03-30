ordenar.exe: ordenar.o
	gcc ordenar.o -o ordenar.exe

ordenar.o: ordenar.c
	gcc -c ordenar.c
