/**
 * @file
 * @brief
 * @author
 * @date
 * @param
 * @return
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
