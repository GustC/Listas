#include <stdio.h>
#include <stdlib.h>

#define TAM 2

void IniciarVetor(int vetCodigo[],int vetEstoque[]);
void CompraProduto(int vetCodigo[],int vetEstoque[]);
int verificarCodigoProduto(int vetCodigo[],int codigo);// --== Retorna a posisao do codigo do produto se existir, se não retorna -1

int main(){
	int Codigos[TAM],Estoque[TAM];
	int codigCliente;

	IniciarVetor(Codigos,Estoque);

	do{
		system("cls");
		printf("Digite o codigo do Cliente : ");
		scanf("%i",&codigCliente);
		if(codigCliente != 0)
			CompraProduto(Codigos,Estoque);
	}while(codigCliente!=0);
	return 0;
}

void IniciarVetor(int vetCodigo[],int vetEstoque[]){
	int cont;
	printf("Preenchendo os vetores Produto e Estoque\n");
	for(cont=0;cont<TAM;cont++){
		printf("Digite o codigo do produto %i : ",cont+1);
		scanf("%i",&vetCodigo[cont]);		
		printf("Digite o estoque do produto %i : ",cont+1);
		scanf("%i",&vetEstoque[cont]);
	}
}

void CompraProduto(int vetCodigo[],int vetEstoque[]){
	int codigoAux,posisaoCodigo;
	int qtdAux;
	do{// --== Validar o codigo produto ==--
		printf("Digite o codigo do produto : ");
		scanf("%i",&codigoAux);
		posisaoCodigo = verificarCodigoProduto(vetCodigo,codigoAux);// --== Retorna a posisao onde o codigo se encontra | se n existir retorna -1 ==--
		if(posisaoCodigo == -1)
			printf("\nCodigo do produto nao encontrado!\n");
	}while(posisaoCodigo == -1);
	do{// --== Validar a quantidade desejada ==--
		printf("Digite a quantidade desejada : ");
		scanf("%i",&qtdAux);
		if(qtdAux > vetEstoque[posisaoCodigo])
			printf("\nNão tem estoque suficiente dessa mercadoria\n");
	}while(qtdAux > vetEstoque[posisaoCodigo]);
	vetEstoque[posisaoCodigo] = vetEstoque[posisaoCodigo] - qtdAux;
	printf("Pedido atendido. Obrigado e volte sempre!");
}

int verificarCodigoProduto(int vetCodigo[],int codigo){
	int pos;
	for(pos = 0; pos<TAM;pos++){
		if(vetCodigo[pos]==codigo)
			return pos;// --== Posisao onde se encontra o codigo ==--
	}
	return -1;// --== Não encontrar ==--
}