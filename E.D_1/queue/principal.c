#include "Queue.h"
#include <stdio.h>

int main(){
	fila Fila;
	int nun;
	char op;

	Fila = createQueue();

	do{
		printf("1 - Enfileirar\n2 - Desenfileirar\n"
			"3 - Ver inicio\n4 - Sair\n"
			"Digite a opcao : ");
		op = getchar();fflush(stdin);
		switch (op)
		{
		case '1':
			if(isFull(Fila) == false){
				printf("Informe o valor : ");
				scanf("%i",&nun);
				enqueue(&Fila,nun);
			}
			else{
				printf("Fila cheia!\n");
			}
			break;
		case '2':
			if(isEmpty(Fila) == false){
				nun = dequeue(&Fila);
				printf("Valor desenfileirado : %i",nun);
			}
			else
				printf("Fila vazia!\n");
			break;
		case '3':
			if(isEmpty(Fila) == false){
				nun = head(Fila);
				printf("Valor do primeiro : %i",nun);
			}
			else
				printf("Fila vazia!\n");
			break;
		}
	}while(op!='4');

	return 0;
}