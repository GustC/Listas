#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void Preencher(int x[]);
void Inverter(int x[]);
void Exibir(int x[]);

int main(){
	int vetInicial[TAM];
	Preencher(vetInicial);
	Inverter(vetInicial);
	Exibir(vetInicial);
}

void Preencher(int x[]){
	int cont;
	printf("Preencha o vetor\n");
	for(cont = 0;cont<TAM;cont++){
		printf("Digite o valor da posisao %i :",cont+1);
		scanf("%i",&x[cont]);
		printf("\n");
	}
}

void Inverter(int x[]){
	int cont, fim = TAM - 1,aux,aux2;
	for(cont = 0;cont<TAM;cont++){
		if(cont == fim || cont>fim)// cont = fim : significa tamanho impar || cont > fim : significa tamanho par
			break;
		aux2 = x[fim];
		aux = x[cont];
		x[cont] = aux2;
		x[fim] = aux;
		fim --;
	}
}

void Exibir(int x[]){
	int cont;
	for(cont = 0;cont < TAM;cont++){
		printf("[%i] = %i\n",cont+1,x[cont]);
	}
	system("pause");
}