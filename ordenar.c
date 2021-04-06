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

int main(int argc, char *argv[]){
	int n, i, buscar, pos;
	int *tam;
	time_t inicial, final;
	FILE *fp;

	printf("¿Cuántos números desea generar?\n");
	printf("n = ");
	scanf(" %i", &n);
	tam = calloc(n, sizeof(int));
	if(tam == NULL){
		printf("Error, no hay memoria disponible\n");
		exit(1);
	}
	int numeros[n];
	fp = fopen("aleatrios.txt", "w");
	if(fp == NULL){
		printf("ERROR: Archivo (aleatorios.txt) no disponible\n");
		exit(1);
	}
	srand(time(0));
	printf("+++++Lista generada+++++\n");
	for(i = 0; i < n; i++){
		numeros[i] = rand() % (MAX + 1 - MIN) + MIN;
		printf("%i\n", numeros[i]);
		fprintf(fp, "%i\n", numeros[i]);
	}
	printf("++++++++++++++++++++++++\n");
	fclose(fp);
	printf("Archivo de numeros aleatorios escrito\n");
	inicial = time(0);
	quickSort(numeros, n);
	//TODO Agregar iteraciones?
	final = time(0) - inicial;
	printf("++++Lista Ordenada+++++\n");
	for(i = 0; i < n; i++){
		printf("%i\n", numeros[i]);
	}
	printf("+++++++++++++++++++++++\n");
	printf("Tiempo transcurrido para ordenar: %ld segundos\n", final);
	printf("Número a buscar: ");
	scanf(" %i", &buscar);
	pos = busquedaBinaria(buscar, numeros, n);
	if(pos >= 0){
		printf("El número %i esta en la posición %i\n", buscar, pos);
	}else{
		printf("El número %i no esta en la lista\n", buscar);
	}

	return 0;
}
