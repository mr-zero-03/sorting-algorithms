#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//To explain the process of merging
bool verboseOn = false; //To turn on the verbose mode send the parameter --verbose or -v when you are compiling (./mergeSort --verbose)

#include "lib/mergeSort.h"

void menu(){
	int option=0;
  do{
		printf("\n-------------------------------\n");
		printf("    MERGE SORT :D (Sorting Algorithm)\n");
		printf("1. Llenar o sobreescribir el array\n");			//Fill array
		printf("2. Imprimir el contenido del array\n");			//Printf array
		printf("3. Organizar el array\n");				          //Sort array
		printf("4. Salir\n");						                    //Leave
		printf("-------------------------------\n");
		printf("Digite su opcion:");
		scanf("%i", &option);
		printf("\n");

		switch(option){
			case 1:
				getArray();
			break;
			case 2:
				printfArray();
			break;
			case 3:
				sortMenu();
			break;
			case 4:
			  printf("Gracias por usar :D");
			break;
			default:
				printf("Opcion invalida");
		}
		if ((option != 1) && (option != 2)) {
			printf("\n");
		}
	} while (option != 4);
}

int main (int argc, char *argv[]){
    		//To explain the process of merging
	if(argc == 2){          		     //If the user passes two parameters (the first is the execution of the program)
		char verbose [7];
		strcpy ( verbose, argv[1] );   //Copy the parameter in a string

    for(int i = 0; verbose[i]; i++){
      verbose[i] = tolower(verbose[i]);    //Making with the string an insensitive case to avoid errors
    }

		if ( (strcmp(verbose, "--verbose") == 0) || (strcmp(verbose, "-v") == 0) ) {
  		printf("\nVERBOSE MODE ON\n");       //Compares the string to verify the parameter and turns on the verbose mode
  		verboseOn = true;
    }
	}

	menu();

  return 0;
}
