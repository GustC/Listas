#include <stdio.h>
#include <stdlib.h>

#define TAM 10

float Media(float vet[]);
void Proximo(float vet[],float media);

int main(){
	float vet[TAM],media;
	media = Media(vet);
	Proximo(vet,media);	
	return 0;
}

float Media(float x[]){
	int cont;
	float soma=0;
	printf("Digite %i Valores\n",TAM);
	for(cont = 0 ; cont < TAM ; cont++){
		scanf("%f",&x[cont]);
		soma += x[cont];
	}
	return soma/cont;
}

void Proximo(float vet[],float media){
	int cont;
	float prox ,valorProximo;
	long sub = vet[0] - media;	
	prox = abs(sub);
	valorProximo = vet[0];
	for(cont = 1 ; cont < TAM ; cont++){
		sub = vet[cont] - media;
		if(abs(sub)<prox){
			prox = sub;
			valorProximo = vet[cont];
		}
	}
	printf("O valor mais proximo da media %.2f e  : %.2f\n",media,valorProximo);
	system("Pause");
}