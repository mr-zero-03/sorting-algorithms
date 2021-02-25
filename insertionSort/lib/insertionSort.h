int array[100];
int sizeArray = 0;

bool isEmptyArray(){	//(Empty==True; No empty==False)
	return sizeArray==0;
}

void printfArray(){
	if(isEmptyArray()){
		printf("Array vacio, no se puede imprimir :c\n");
	}else{
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


//Insertion Sort----------------------------------------------------

void insertionSort(int option){
	for(int i=1; i<sizeArray; i++){
	  int temp = array[i];										//We use temp to don't lose the value of array[i]
		int j = i-1;													  //We assign j the value i-1 to make j the value behind i

		if(option==1){				//*FROM THE LOWEST TO THE HIGHEST
			while((j >= 0) && (array[j] > temp)){	//j can't be < 0 because it would be outside of the array size
				array[j+1] = array[j];							//We use [j+1] and not [i] because the [i] position don't change, but j does
				j--;																//We subtract 1 from j until j == -1, or until array[j] don't be > temp
			}
		} else if (option==2){	//*FROM THE HIGHEST TO THE LOWEST
			while((j >= 0) && (array[j] < temp)){
				array[j+1] = array[j];
				j--;
			}
		}
		array[j+1] = temp;			//As j == -1, or, in general, j is 1 number less than the number we need,
	}													//we incremented 1 and assign temp (the initial value of array[i])
	printf("\nArray ordenado satisfactoriamente");
}


//SortMenu-----------------------------------------------
void sortMenu(){
	if ( isEmptyArray() ){
		printf("Array vacío, no se puede organizar :c");
	} else {
		int option=0;
		printf("1. De menor a mayor\n");
		printf("2. De mayor a menor\n");
		printf("Opción:");
		scanf("%i", &option);

		switch(option){
			case 1: case 2:
				insertionSort(option);
			break;
			default:
				printf("Opción inválida");
		}
	}
}
