#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/bubbleSort.h"

void menu(){
  int option=0;
  do{
		printf("\n-------------------------------\n");
		printf("    BUBBLE SORT :D (Sorting Algorithm)\n");
		printf("1. Llenar o sobreescribir el array\n");			//Fill array
		printf("2. Imprimir el contenido del array\n");			//Printf array
		printf("3. Organizar el array\n");				        //Sort array
		printf("4. Salir\n");					                //Leave
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
		if ( (option != 1) && (option != 2) ) {
		  printf("\n");
	  }
	} while(option != 4);
}

int main(){
  menu();

	return 0;
}
