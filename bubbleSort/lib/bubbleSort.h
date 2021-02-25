int array[100];
int sizeArray = 0;

bool isEmptyArray(){	//(Empty==True; No empty==False)
	return sizeArray == 0;
}

void printfArray(){
	if ( isEmptyArray() ) {
		printf("Array vacío, no se puede imprimir :c\n");
	} else {
		for(int i=0; i<sizeArray; i++){
			printf("Array[%i] = %i\n", i, array[i]);
		}
	}
}

void getArray(){

	int sizeArrayTemp = 0;
	printf("Digite el tamaño de su array (debe ser menor a 100): ");
	scanf("%i", &sizeArrayTemp);
	if ( (sizeArrayTemp >= 100) || (sizeArrayTemp <= 0) ) {
	  printf("Error, tamaño de array invalido\n");

	} else {

		sizeArray = sizeArrayTemp;
		for(int i=0; i < sizeArray; i++){
		  printf("Digite el valor de la posición %i en su array: ", i);
	    scanf("%i", &array[i]);
	  }
		printf("\n");
		printfArray();

  }
}

//BubbleSort-------------------------------------

void bubbleSort(int option){
  int cases=1;
  while(cases != 0){		//-Enter in the while loop
    cases=0;						//-Cases = 0 for the loop end

		for(int i=0; i<sizeArray-1; i++){		//If we compare i with sizeArray it will exceed the size of the array, then it
      if(option==1){										//would be compared to an empty space (a 0). So we compare i with sizeArray-1.
        if(array[i+1] < array[i]){   //*FROM THE LOWEST TO THE HIGHEST
          int temp = array[i];
          array[i] = array[i+1];
				  array[i+1] = temp;
				  cases++;			//-If there is a case then Cases!=0, and repeat the while loop	until there are not cases
        }
      }else{
        if(array[i+1] > array[i]){   //*FROM THE HIGHEST TO THE LOWEST
          int temp = array[i];
			  	array[i] = array[i+1];
			  	array[i+1] = temp;
			  	cases++;
        }
      }
	  }
  }
	printf("\nArray ordenado satisfactoriamente");
}

//SortMenu-----------------------------------------------
void sortMenu(){
	if(isEmptyArray()){
		printf("Array vacío, no se puede organizar :c");
	}else{
		int option=0;
		printf("1. De menor a mayor\n");
		printf("2. De mayor a menor\n");
		printf("Opción:");
		scanf("%i", &option);

		switch(option){
			case 1: case 2:
				bubbleSort(option);
			break;
			default:
				printf("Opción inválida");
		}
	}
}
