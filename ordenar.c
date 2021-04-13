/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "def.h"
#define MAX 1000
#define MIN 0

void quickSort(int arr[], int n);
int busquedaBinaria(int x, int arr[], int n);
int quitarRep(int arr[], int n);

int main(int argc, char *argv[]){
	int n, i, buscar, pos;
	int *numeros;
	time_t inicial, final;
	FILE *fp;

	argv[2] = (argv[1] == NULL) ? NULL : argv[2];
	printf("¿Cuántos números desea generar?\n");
	printf("n = ");
	scanf(" %i", &n);
	numeros = (int *)malloc(n * sizeof(int));
	if (numeros == NULL){
		printf("ERROR: no hay memoria disponible\n");
		exit(1);
	}
	fp = fopen((argv[1]!=NULL) ? argv[1] : "aleatorios.txt", "w");
	if(fp == NULL){
		printf("ERROR: Archivo (%s) no disponible\n", argv[1]);
		exit(1);
	}
	srand(time(0));
	printf("+++++Lista generada+++++\n");
	for(i = 0; i < n; i++){
		numeros[i] = rand() % (MAX + 1 - MIN) + MIN;
		printf("%i\n", numeros[i]);
	}
	n = quitarRep(numeros, n);
	for(i = 0; i < n; i++){
		fprintf(fp, "%i)\t%i\n", i, numeros[i]);
	}
	printf("++++++++++++++++++++++++\n");
	fclose(fp);
	printf("Archivo de numeros aleatorios escrito\n");
	inicial = time(0);
	quickSort(numeros, n);
	final = time(0) - inicial;
	printf("++++Lista Ordenada+++++\n");
	for(i = 0; i < n; i++){
		printf("%i)\t%i\n", i, numeros[i]);
	}
	printf("+++++++++++++++++++++++\n");
	printf("Tiempo transcurrido para ordenar: %ld segundos\n", final);
	printf("Número a buscar: ");
	scanf(" %i", &buscar);
	inicial = time(0);
	pos = busquedaBinaria(buscar, numeros, n);
	final = time(0) - inicial;
	if(pos >= 0){
		printf("El número %i esta en la posición %i\n", buscar, pos);
	}else{
		printf("El número %i no esta en la lista\n", buscar);
	}
	printf("Tiempo transcurrido para ordenar: %ld segundos\n", final);
	fp = fopen((argv[2]!=NULL) ? argv[2] : "ordenados.txt", "w");
	if(fp == NULL){
		printf("ERROR: Archivo %s no disponible\n", argv[2]);
		exit(1);
	}
	for(i = 0; i < n; i++){
		fprintf(fp, "%i)\t%i\n", i, numeros[i]);
	}
	printf("Archivo de números ordenados escrito\n");
	fclose(fp);

	return 0;
}
