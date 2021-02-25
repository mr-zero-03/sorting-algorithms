//Divide: Divide the n-parts array into two smaller sub-arrays.
//Conquer: Recursively sorts the sub-arrays.

int array[100];
int sizeArray = 0;

bool isEmptyArray(){	//(Empty==True; No empty==False)
	return sizeArray==0;
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

//QuickSort--------------------------------------------------------

    //Swap two positions of any array
void swap( int arraySwap[], int pos1, int pos2 ) {
 	int temp = arraySwap[pos1];
  	arraySwap[pos1] = arraySwap[pos2];
  	arraySwap[pos2] = temp;
}

		//Divide and Conquer
int sort( int quickArray[], int minPos, int maxPos, int option){	//Gets the index and order with it the rest of the numbers

	char stop;

	int pivotValue = quickArray[maxPos];				//The pivotValue is the last number in the array
	int pivotIndex = minPos;

	if(verboseOn){
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n*SORTING:*\n");
		printf("\nI'm going to get the pivotValue and compare it with the rest of the numbers\n");
		printf("Analizing from minPos(%i) to maxPos(%i) and my pivotValue is (%i)\n\n\n", minPos, maxPos, pivotValue);
	}


  for ( int i = minPos; i < maxPos; i++ ){
	  if ( option == 1 ) {			//*FROM THE LOWEST TO THE HIGHEST
	    if ( quickArray[i] < pivotValue ) {

			  if(verboseOn){
					printf("quickArray[%i] (%i) is less than the pivotValue (%i)\n", i, quickArray[i], pivotValue );
					printf("Swapping the pivotIndex = %i, with the pos of i = %i\n", pivotIndex, i );
					printf("pivotIndex++\n");
					scanf( "%c", &stop );
				}

	      swap ( quickArray, pivotIndex, i );
	      pivotIndex++;
      }

  	} else {				//*FROM THE HIGHEST TO THE LOWEST

			if ( quickArray[i] > pivotValue ) {

				if(verboseOn){
					printf("quickArray[%i] (%i) is greater than the pivotValue (%i)\n", i, quickArray[i], pivotValue );
					printf("Swapping the pivotIndex pos = %i, with the pos of i = %i\n", pivotIndex, i );
					printf("pivotIndex++\n");
					scanf( "%c", &stop );
				}

	      swap ( quickArray, pivotIndex, i );
	      pivotIndex++;
		  }
		}
	}


	if(verboseOn){
	  if ( pivotIndex == minPos ) {
			if ( option == 1 ){
				printf("The pivot is the less number in this array\n\n");
			} else {
				printf("The pivot is the greater number in this array\n\n");
			}
		}

		printf("Swapping the pivotIndex pos = %i, with the pivotPos (maxPos) = %i\n", pivotIndex, maxPos);
		printf("Returning the pivotIndex value (%i)\n", pivotIndex);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		scanf( "%c", &stop );
	}

	swap ( quickArray, pivotIndex, maxPos );

  return pivotIndex;
}

			//quickSort
void quickSort ( int quickArray[], int minPos, int maxPos, int direction, int option ) {

	if(verboseOn) {
    if ( direction == 0 ) {
  	  printf("\nI got no direction, I'm the main array\n");
  	} else {
			if ( direction == 1 ){
  		  printf("\n\nI'm the left division\n");
  		} else if ( direction == 2 ) {
  		  printf("\n\nI'm the right division\n");
  		}

			printf("Join again to sort\n");
		}
		printfArray();
	}


	if ( minPos < maxPos ){

    int pivotPos = sort ( quickArray, minPos, maxPos, option );			//Gets the pivotPos


		if(verboseOn) {
			char stop;

			printf("\nMy pivot is [%i] %i\n\n", pivotPos, array[pivotPos] );

			printf("Numbers that are less than the pivot (Left side): \n");
			printf("From minPos (%i) to pivotPos - 1 (%i)\n", minPos, ( pivotPos - 1 ) );	//Goes to the left side of the array
			for(int i=minPos; i<=( pivotPos - 1 ); i++){					//Prints the left side of the array
				printf("[%i] %i. ", i, array[i]);
			}

			printf("\nNumbers that are greater than or equal to the pivot (Right side): \n");
			printf("From pivotPos + 1 (%i) to maxPos (%i)\n", (pivotPos + 1), maxPos);	//Goes to the right side of the array
			for(int i=(pivotPos + 1); i<=maxPos; i++){					//Prints the right side of the array
				printf("[%i] %i. ", i, array[i]);
			}

			printf("\n\nPress ENTER to Continue...");
			scanf( "%c", &stop );
			printf("\n--------------------------------------------------------------------------");
		}


		//Join at the left side of the array
   	if ( minPos < ( pivotPos - 1 ) ) { quickSort( quickArray, minPos, ( pivotPos - 1 ), 1, option ); }	//The purpose of the "if" is to analyze to
		//Join at the right side of the array									//don't rejoin at the mergeSort function
    if ( ( pivotPos + 1 ) < maxPos ) { quickSort( quickArray, ( pivotPos + 1 ), maxPos, 2, option ); }	//when it's unnecessary (when minPos==maxPos)

  }
}


void preQuickSort ( int option ){
	quickSort ( array, 0, sizeArray - 1, 0, option );	//Send the first parameters to sort
	printf("\n\nArray ordenado satisfactoriamente");
}

//SortMenu-----------------------------------------------
void sortMenu(){
	if( isEmptyArray() ){
		printf("Array vacio, no se puede organizar :c");
	} else {
		char stop;
		int option = 0;

		printf("1. De menor a mayor\n");
		printf("2. De mayor a menor\n");
		printf("Opción:");
		scanf("%i", &option);

		scanf("%c", &stop);

		switch(option){
			case 1: case 2:
				preQuickSort(option);
			break;
			default:
				printf("Opción inválida");
		}
	}
}
