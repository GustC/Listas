#include <stdio.h>
#include <stdlib.h>

#define TAM 2


int verificar(int vet[]);// --== Retorna 1 se possuir uma poltrona disponivel | 0 quando nao possuir vaga ==--
int verificarOnibus(int vetCorredor[],int vetJanela[]);// --== Retorna 1 quando possuir vaga no onibus | 0 onibus lotado ==--
void menu(int vetCorredor[],int vetJanela[]);
void iniciarVetor(int vet[]);// --== Inicia o vetor com as poltronas livres ==--
void MostrarPosisoes(int vet[]);// --== Exibe as posisoes disponiveis , do vetor passado(janela ou corredor) ==-- 
int ValidarPosisao(int vet[],int pos);// --== Retorna -1 se a posisao estiver livre | 1 se a posisao estiver preenchida ==--

int main(){
	int Corredor[TAM],Janela[TAM];
	iniciarVetor(Corredor);
	iniciarVetor(Janela);
	menu(Corredor,Janela);
	return 0;
}

void iniciarVetor(int vet[]){
	int cont;
	for(cont=0;cont<TAM;cont++){
		vet[cont] = 0;
	}
}

void menu(int vetCorredor[],int vetJanela[]){
	int vagaJanela,vagaCorredor,vagaOnibus,posisao;
	int resp3;
	char resp,resp2;
	do{
		fflush(stdin);
		system("cls");
		printf("1 - Comprar de poltronas\n2 - Sair\nDigite sua opcao : ");
		scanf("%c",&resp);fflush(stdin);
		vagaJanela = verificar(vetJanela);
		vagaCorredor = verificar(vetCorredor);
		vagaOnibus = verificarOnibus(vetCorredor,vetJanela);
		if(vagaOnibus == 0)// --== 1º verifica se exite vaga no onibus ==--
			printf("Nao ha vagas no Onibus!\n");
		else{// --== Se houver , verifica se exite vaga na janela ou no corredor ==--
			if(vagaJanela == 0)
				printf("Nao ha vagas na Janela!\n");
			if(vagaCorredor == 0)
				printf("Nao ha vagas na Corredor!\n");
		}
		if(vagaOnibus == 0 && resp == '1'){// --== Entra somente se houver vaga no onibus ==--
			do{
				printf("\nInforme onde deseja a poltrona \n"
					"1 - Janela\n2 - Corredor\nInforme sua opcao :");
				scanf("%c",&resp2);fflush(stdin);
				if(resp2!='1' && resp2 != '2')
					printf("Opcao invalida!\n");				
			}while(resp2!='1' && resp2 != '2');
			if(resp2 == '1')
				MostrarPosisoes(vetJanela);
			else
				MostrarPosisoes(vetCorredor);
			printf("\nInforme sua posisao : ");

			if(resp2 == '1'){
				do{
					scanf("%i",&posisao);
					resp3 = ValidarPosisao(vetJanela,posisao-1);
					if(resp3 == 1)
						printf("Posisao ja preenchida!\nDigite uma posisao valida: ");
				}while(resp3!=-1);
				vetJanela[posisao-1] = 1;
			}
			else{
				do{
					scanf("%i",&posisao);
					resp3 = ValidarPosisao(vetCorredor,posisao-1);
					if(resp3 == 1)
						printf("Posisao ja preenchida!\nDigite uma posisao valida: ");
				}while(resp3!=-1);
				vetCorredor[posisao-1] = 1;
			}
		}
	}while(resp!='2');
}

int verificar(int vet[]){
	int cont,flag=0;
	for(cont = 0; cont <TAM ; cont++){
		if(vet[cont]==0)
			flag = 1;// --== vaga disponivel ==--
	}
	return flag;
}
int verificarOnibus(int vetCorredor[],int vetJanela[]){
	int cont,flag=0;
	for(cont = 0; cont <TAM ; cont++){
		if(vetCorredor[cont]==0)
			flag = 1;// --== vaga disponivel ==--
	}
	for(cont = 0; cont <TAM ; cont++){
		if(vetJanela[cont]==0)
			flag = 1;// --== vaga disponivel ==--
	}
	return flag;
}

void MostrarPosisoes(int vet[]){
	int cont;
	printf("\nPosisoes disponiveis, sao : ");
	for(cont = 0; cont <TAM ; cont++){
		if(vet[cont]==0)
			printf("%i ",cont+1);// --== vaga disponivel ==--
	}
}

int ValidarPosisao(int vet[],int pos){
	int flag=-1;
	if(vet[pos]==1)
		flag = 1;
	return flag;
}
