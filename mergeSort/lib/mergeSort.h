//Divide: Divide the n-parts array into two n/2-parts subarrays
//Conquer: Sort the two subarrays recursively using MergeSort
//Combine: Join the two subarrays to make the sorted array

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


//MergeSort------------------------------------------------------

		//Combine the arrays
void merge ( int mergeArray[], int minPos, int midPos, int maxPos, int option ) {
	char stop;

	//Start to merge the array
  if(verboseOn) { printf( "\n\n--Merging using the positions minPos(%i), midPos(%i), maxPos(%i)--\n", minPos, midPos, maxPos ); }

	int sizeArrayLeft = midPos-minPos+1;
	int sizeArrayRight = maxPos-midPos;
	int mergeArrayLeft[sizeArrayLeft], mergeArrayRight[sizeArrayRight];  	//Two temporal subarrays to contain the two parts of the array that will be combined

	for(int i=0; i<sizeArrayLeft; i++){					//The arrays recive their parts
		mergeArrayLeft[i] = mergeArray[minPos+i];
	}

	for(int i=0; i<sizeArrayRight; i++){
		mergeArrayRight[i] = mergeArray[midPos+1+i];
	}

  if(verboseOn) {
	 	printf("\nmergeArrayLeft: ");
  	for ( int i = 0; i < sizeArrayLeft; i++ ) {
	  	printf("[%i] %i. ", i, mergeArrayLeft[i]);
		}

  	printf( "\nmergeArrayRight: " );
  	for ( int i = 0; i < sizeArrayRight; i++ ) {
		  printf("[%i] %i. ", i, mergeArrayRight[i]);
	  }
  }


  int i = 0, j = 0;				//i == left; j == right

	for ( int k = minPos; k <= maxPos; k++ ) {	//Going through the main array from minPos to maxPos

	  if ( i == sizeArrayLeft ) {
			for (; j < sizeArrayRight; j++) {
				mergeArray[k] = mergeArrayRight[j];
				k++;
		  }
		} else if ( j == sizeArrayRight ) {
			for (; i < sizeArrayLeft; i++){
				mergeArray[k] = mergeArrayLeft[i];
				k++;
			}
		}

		else if ( option == 1 ) {	//*FROM THE LOWEST TO THE HIGHEST
			if ( ( mergeArrayLeft[i] <= mergeArrayRight[j] ) ) {

        if(verboseOn) { printf("\nmergeArray[%i] = mergeArrayLeft[%i] (%i)", k, i, mergeArrayLeft[i]); }

      	mergeArray[k] = mergeArrayLeft[i];		//Assign the value at the main array
				i++;

	  	} else if ( ( mergeArrayLeft[i] > mergeArrayRight[j] ) ) {

        if(verboseOn) { printf("\nmergeArray[%i] = mergeArrayRight[%i] (%i)", k, j, mergeArrayRight[j]); }

				mergeArray[k] = mergeArrayRight[j];		//Assign the value at the main array
				j++;
		  }

		} else {	                //*FROM THE HIGHEST TO THE LOWEST
			if ( ( mergeArrayLeft[i] >= mergeArrayRight[j] ) ) {

				if(verboseOn) { printf("\nmergeArray[%i] = mergeArrayLeft[%i] (%i)", k, i, mergeArrayLeft[i]); }

				mergeArray[k] = mergeArrayLeft[i];		//Assign the value at the main array
				i++;

			} else if ( ( mergeArrayLeft[i] < mergeArrayRight[j] ) ) {

				if(verboseOn) { printf("\nmergeArray[%i] = mergeArrayRight[%i] (%i)", k, j, mergeArrayRight[j]); }

				mergeArray[k] = mergeArrayRight[j];		//Assign the value at the main array
				j++;
			}
		}
	}

	if(verboseOn) {
    printf("\n");

  	for ( int i = minPos; i <= maxPos; i++ ) {
  		printf( "[%i] %i. ", i, mergeArray[i] );
  	}

		printf("\n\nPress ENTER to Continue...");
		scanf( "%c", &stop );
		printf("\n--------------------------------------------------------------------------");
  }
}

							//Divides the array
void mergeSort(int mergeArray[], int minPos, int maxPos, int direction, int option){		//Was maked to analyze the function operation
	char stop;
	int midPos = 0;

  if(verboseOn) {
    if ( direction == 0 ) {
  	  printf("\nI got no direction, I'm the main array\n");
  		printfArray();
  	} else if ( direction == 1 ){
  		printf("\n\nI'm the left division\n");
  	} else if ( direction == 2 ) {
  		printf("\n\nI'm the right division\n");
  	}

  	printf("\n*I'm going to analyze from minPos(%i) to maxPos(%i):*\n", minPos, maxPos);
  }

	if(minPos < maxPos){					//Join and divides the array in two parts
		midPos = (minPos+maxPos) / 2;			//Get the value of the half

		// Divide and Conquer
		if(verboseOn) {
      printf("\nI'm going to Divide and Conquer:\n");

  		printf("Left side from minPos(%i) to midPos(%i)\n", minPos, midPos);		//Goes to the left side of the array
  		for(int i=minPos; i<=midPos; i++){						//Prints the left side of the array
  			printf("[%i] %i. ", i, array[i]);
  		}

			printf("\nRight side from midPos+1(%i) to maxPos(%i)\n", (midPos + 1), maxPos);	//Goes to the right side of the array
			for(int i=(midPos + 1); i<=maxPos; i++){					//Prints the right side of the array
				printf("[%i] %i. ", i, array[i]);
			}

    	printf("\n\nI'm going to merge the array with the positions minPos(%i), midPos(%i), maxPos(%i)\n", minPos, midPos, maxPos );

		  printf("\n\nPress ENTER to Continue...");
		  scanf( "%c", &stop );
      printf("\n--------------------------------------------------------------------------");
  	}

		//Makes the division at the left side of the array
    if(minPos < midPos) { mergeSort( mergeArray, minPos, midPos, 1, option );}	//The purpose of the "if" is to analyze to don't rejoin at the
		//Makes the division at the right side of the array				//mergeSort function when it's unnecessary (when minPos==maxPos)
   	if((midPos + 1) < maxPos) { mergeSort( mergeArray, (midPos + 1), maxPos, 2, option);}


		merge(mergeArray, minPos, midPos, maxPos, option);				//Combine (start to merge the array)
  }
}

void preMergeSort( int option ){					//Send the first parameters to sort
	mergeSort(array, 0, sizeArray-1, 0, option);
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
				preMergeSort(option);
			break;
			default:
				printf("Opción inválida");
		}
	}
}
