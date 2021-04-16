#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file funciones.c
 * @brief Esta función hace el ordenamiento por método de quicksort al arreglo de números aleatorios.
 * @author Fernando Yedra
 * @date 15/04/2021
 * @param arr[]	Es el arreglo que se va a ordenar.
 * @param n	Es el tamaño del arreglo.
 * @return void
 */

void quickSort(int arr[], int n){
	int i = 0, j = (n - 1), temp, x = arr[j/2];

	do{
		while(arr[i] < x){
			i++;
		}
		while(arr[j] > x){
			j--;
		}
		if(i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}else{
			if(i > j){
				break;
			}
		}
	}while(++i <= --j);
	if(j > 0){
		quickSort(arr, j+1);
	}
	if(i < (n-1)){
		quickSort(arr+1, n-1);
	}

	return;
}

/**
 * @brief Esta función busca el número que provee el usuario en el arreglo ordenado.
 * @author Fernando Yedra
 * @date 15/04/2021
 * @param x	Es el número que el usuario se manda a buscar.
 * @param arr[]	Es el arreglo de números ordenado.
 * @param n	Es el namaño del arreglo.
 * @return der	Es la posición en la que se encuentra el número si no se encuentra este vale -1.
 */

int busquedaBinaria(int x, int arr[], int n){
	int medio, izq, der;

	izq = 0;
	der = n - 1;
	if(arr[izq] == x){
		der = izq;
    	}else{
        	while(der - izq > 1){
			medio = (izq + der)/2;
            		if(x <= arr[medio]){
                		der = medio;
            		}else{
                		izq = medio;
            		}
        	}
    	}
    	if(x != arr[der]){
        	der = -1;
    	}

    	return der;
}

/**
 * @brief Esta función se encarga de buscar y eliminar los números repetidos en el arreglo
 *        desordenado.
 * @author Fernando Yedra
 * @param arr[]	Es el arreglo de los números desordenados.
 * @param n	Es el tamaño del arreglo.
 * @return n	Es el tamaño del arreglo despues de eliminar los números repetidos.
 */

int quitarRep(int arr[], int n){
	int i, j , k;

	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(arr[i] == arr[j]){
				printf("Numero %i repetido, quitando del arreglo\n", arr[i]);
				for(k = j; k < n; k++){
					arr[k] = arr[k + 1];
				}
				n--;
				j--;
			}
		}
	}

	return n;
}
