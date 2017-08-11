#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void Preencher(int x[]);
int Encontrar(int x[],int nun);
void Exibir(int x[]);

int main(){
	int Numeros[TAM],aux,resp;
	Preencher(Numeros);
	printf("Digite o valor que deseja encontrar : ");
	scanf("%i",&aux);
	resp = Encontrar(Numeros,aux);
	if(resp != -1)
		printf("%i esta localizado na posisao %i\n",aux,resp+1);
	else
		printf("Valor não encontrado!");
	system("pause");
	return 0;
}

void Preencher(int x[]){
	int cont;
	printf("Preenchendo o vetor!\n");
	for(cont = 0; cont < TAM; cont++){
		printf("Valor da posisao %i:",cont+1);
		scanf("%i",&x[cont]);		
	}
	Exibir(x);
}

void Exibir(int x[]){
	int cont;
	printf("Vetor Numeros :");
	for(cont = 0;cont<TAM;cont++){
		printf("%i, ",x[cont]);
	}
	printf("\n");
}

int Encontrar(int x[],int nun){
	int cont,menor=x[0],maior=x[0],posMenor=0,posMaior=0,pos=-1;
	for(cont = 0;cont < TAM;cont++){
		if((pos == -1)&&(x[cont] == nun)){
			pos = cont;
		}
		else if(x[cont]<menor){
			menor = x[cont];
			posMenor = cont;
		}
		else if(x[cont]> maior){
			maior = x[cont];
			posMaior = cont;
		}	
	}
	printf("%i e o menor valor encontrado e sua posisao e %i\n",menor,posMenor+1);
	printf("%i e o maior valor encontrado e sua posisao e %i\n",maior,posMaior+1);
	return pos;
}