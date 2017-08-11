#include <stdio.h>
#include <stdlib.h>
/*1 - Faça um programa que, dados dois vetores inteiros de 20 posições, efetue as respectivas operações indicadas por um
outro vetor de 20 posições de caracteres também fornecido pelo usuário, contendo as quatro operações aritméticas em
qualquer combinação, armazenando os resultados em um quarto vetor e apresentando na saída padrão quais as
operações realizadas, os operandos envolvidos e os resultados*/
#define TAM 3

void Operacao(char vetOp[],int vetA[],int vetB[],int vetResp[]);
void Preencher(int x[]);
void PreencherOp(char VetOp[]);
void Resultado(char Op,int A,int B,int Resp);

int main(){
	int vetA[TAM],vetB[TAM],vetResp[TAM];
	char vetOp[TAM];
	printf("Preechendo o vetor A !\n");
	Preencher(vetA);	
	printf("Preechendo o vetor B !\n");
	Preencher(vetB);
	printf("Preechendo o vetor de Operacoes !\n");
	fflush(stdin);
	PreencherOp(vetOp);
	Operacao(vetOp,vetA,vetB,vetResp);
	system("pause");
	return 0;
}

void Operacao(char vetOp[],int vetA[],int vetB[],int vetResp[]){
	int cont;
	for(cont = 0; cont < TAM; cont++){
		if(vetOp[cont] == '+')
			vetResp[cont] = vetA[cont] + vetB[cont];
		else if(vetOp[cont] == '-')
			vetResp[cont] = vetA[cont] - vetB[cont];		
		else if(vetOp[cont] == '*')
			vetResp[cont] = vetA[cont] * vetB[cont];
		else if(vetA[cont]>vetB[cont])
			vetResp[cont] = vetA[cont]/vetB[cont]; 
		else
			vetResp[cont] = vetB[cont]/vetA[cont]; 
		Resultado(vetOp[cont],vetA[cont],vetB[cont],vetResp[cont]);
	}
}

void Resultado(char Op,int A,int B,int Resp){	
	printf("%i %c %i = %i\n",A,Op,B,Resp);
}

void Preencher(int x[]){
	int cont ;
	printf("Preechendo o vetor\n");
	for(cont = 0 ; cont < TAM ; cont++){
		printf("Digite o valor da posisao %i :",cont+1);
		scanf("%i",&x[cont]);
	}
	system("cls");
}

void PreencherOp(char x[]){
	int cont ;
	char aux;
	printf("Operadores \n + = Adicao\n - = Subitracao\n * = Multiplicacao\n / = Divisao\n\n");
	for(cont = 0 ; cont < TAM ; cont++){
		do{
			printf("Digite o operador da posisao %i :",cont+1);
			scanf("%c",&aux);fflush(stdin);
			if((aux != '-')&&(aux != '/')&&(aux != '+')&&(aux != '*'))
				printf(" Operador Invalido !!");
		}while((aux != '-')&&(aux != '/')&&(aux != '+')&&(aux != '*'));
		x[cont]=aux;
	}
	system("cls");
}