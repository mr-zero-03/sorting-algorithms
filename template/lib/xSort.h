int array[100];
int sizeArray = 0;

bool isEmptyArray(){	//(Empty==True; No empty==False)
	return sizeArray == 0;
}

void printfArray(){
  if(isEmptyArray()){
		printf("Array vacío, no se puede imprimir :c\n");
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


//Sort---------------------------------------------------------------

/*Here you write your cool sorting algorithm*/
void xSort(int option){
	printf("\nMe da pereza organizar el array, hagalo usted mismo, vago\n");
	printf("La opción del usuario fue %i", option);
}

//SortMenu-----------------------------------------------
void sortMenu(){
	if( isEmptyArray() ){
		printf("Array vacio, no se puede organizar :c");
	} else {
		char stop;
		int option = 0;

		printf("1. De menor a mayor\n");	//If user option is 1 is from lowest to highest
		printf("2. De mayor a menor\n");	//If user option is 2 is from highest to lowest
		printf("Opción:");
		scanf("%i", &option);

		scanf("%c", &stop);

		switch(option){
			case 1: case 2:
				/*Here you call your sorting function and send it the var option as a parameter*/
				xSort(option);
			break;
			default:
				printf("Opción inválida");
		}
	}
}
