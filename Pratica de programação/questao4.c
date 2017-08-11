#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void Preencher(int x[]);
void Intercalar(int a[],int b[],int c[]);
void Exibir(int x[]);

int main(){
	int A[TAM],B[TAM],C[TAM*2];
	printf("Preenchendo o vetor A!\n");
	Preencher(A);
	printf("Preenchendo o vetor B!\n");
	Preencher(B);
	Intercalar(A,B,C);
	Exibir(C);
	return 0;
}

void Preencher(int x[]){
	int cont;
	for(cont = 0;cont < TAM ; cont ++){
		printf("Digite o valor da posisao %i :",cont+1);
		scanf("%i",&x[cont]);
	}
	system("cls");
}

void Intercalar(int a[],int b[],int c[]){
	int cont, cont2;
	for(cont = 0,cont2 = 0 ; cont2<(TAM*2) ; cont++, cont2++){
		c[cont2] = a[cont];
		cont2++;
		c[cont2] = b[cont];
	}
}

void Exibir(int x[]){
	int cont;
	printf("Vetor Intercalado :");
	for(cont = 0;cont < TAM*2 ; cont ++){
		printf("%i ",x[cont]);
	}
	printf("\n");
	system("pause");
}