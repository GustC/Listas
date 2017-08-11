#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Jogar();
void InformarErro(int numero, int resp);
void InformarAcerto(int tentativas);

int main(){
	char resp;
	do{
		system("cls");
		printf("1 - Jogar\n2 - Sair\nDigite sua opcao : ");
		scanf("%c",&resp);fflush(stdin);
		while((resp!='1')&&(resp!='2')){
			printf("Opcao invalida!\nDigite corretamente : ");
			scanf("%c",&resp);fflush(stdin);
		}
		if(resp == '1')
			Jogar();
	}while(resp != '2');
	return 0;
}

void Jogar(){
	int tentativas=0;
	int numero,resp;
	srand((unsigned) time(NULL));
	numero = rand() % 101;
	printf("Um valor foi gerado entre 0 e 100, tente adivinhar :");
	do{	
		tentativas++;
		scanf("%i",&resp);
		while(resp<0 ||resp>100){
			printf("Valor invalido!\nDigite um valor entre 0 e 100 : ");
			scanf("%i",&resp);
		}
		if(resp == numero)
			break;
		else{
			InformarErro(numero, resp);
		}
	}while(resp != numero);

	InformarAcerto(tentativas);
}

void InformarErro(int numero, int resp){
	printf("Errou!\n");
	if(resp < numero){// numero = valor gerado | resp = numero digitado
		printf("O valor gerado e maior que o seu valor digitado!\n");
	}
	else
		printf("O valor gerado e menor que o seu valor digitado!\n");
}

void InformarAcerto(int tentativas){
	printf("Voce Acertou !!\n");
	printf("Voce utilizou %i tentativas.",tentativas);
	system("pause");
}