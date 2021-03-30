/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "def.h"
#define MAX 1000
#define MIN 0

int main(int argc, char *argv[]){
	int n, i, numero;
	FILE *fp;

	printf("¿Cuántos números desea generar?\n");
	printf("n = ");
	scanf(" %i", &n);
	fp = fopen("aleatrios.txt", "w");
	if(fp == NULL){
		printf("ERROR: Archivo (aleatorios.txt) no disponible\n");
		exit(1);
	}
	srand(time(0));
	for(i = 0; i < n; i++){
		fprintf(fp, "%i\n", rand() % (MAX + 1 - MIN) + MIN);
	}
	fclose(fp);
	printf("Archivo de numeros aleatorios escrito\n");
	//TODO El resto del progema

	return 0;
}
