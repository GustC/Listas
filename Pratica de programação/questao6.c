#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 12

void Preencher(float x[]);
void Verificar(float x[]);
char *NomeMes(int nun);

int main(){
	float Temperaturas[TAM];
	Preencher(Temperaturas);
	Verificar(Temperaturas);
	return 0;
}

void Preencher(float x[]){
	int cont;
	printf("Preenchendo a temperatura dos meses!\n");
	for(cont = 0;cont < TAM ; cont ++){
		printf("Digite a temperatura do mes %i :",cont+1);
		scanf("%f",&x[cont]);
	}
	system("cls");
}

void Verificar(float x[]){
	int cont,mesMenor,mesMaior;
	char mes[20];
	float maior=x[0],menor=x[0];
	mesMaior = 0;
	mesMenor = 0;
	for(cont = 1;cont < TAM ; cont ++){
		if(x[cont]<menor){
			menor = x[cont];
			mesMenor = cont;
		}
		else if(x[cont]>maior){
			maior = x[cont];
			mesMaior = cont;
		}			
	}	
	strcpy(mes,NomeMes(mesMenor+1));
	printf("Mes de menor temperatura e : %s\n",mes);
	
	strcpy(mes,NomeMes(mesMaior+1));
	printf("Mes de maior temperatura e : %s\n",mes);

	system("pause");
}

char *NomeMes(int nun){
	if(nun == 1)
		return "Janeiro";
	else if(nun == 2)
		return "Fevereiro";
	else if(nun == 3)
		return "Março";
	else if(nun == 4)
		return "Abril";
	else if(nun == 5)
		return "Maio";
	else if(nun == 6)
		return "Junho";
	else if(nun == 7)
		return "Julho";
	else if(nun == 8)
		return "Agosto";
	else if(nun == 9)
		return "Setembro";
	else if(nun == 10)
		return "Outubro";
	else if(nun == 11)
		return "Novembro";
	else
		return "Dezembro";
}