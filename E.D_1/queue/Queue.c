#include "types.h"
#include <stdlib.h>

fila createQueue(){
	Descritor *d;
	d = (Descritor * )malloc(sizeof(Descritor));
	d->inicio = NULL;
	d->fim = NULL;
	return d;
}

void enqueue (fila *q, int n){// -- Insere no FIM --
	Tno * novo;
	novo = (Tno *)malloc(sizeof(Tno));
	novo->info = n;
	novo->prox = NULL;
	if(isEmpty(*q)==true){// -- modifica o descritor --
		(*q)->inicio = novo;
		(*q)->fim = novo;
	}
	else{// -- modifica o ultimo do descritor --
		(*q)->fim->prox = novo;
		(*q)->fim = novo;
	}
}


int dequeue(fila *q){// -- remover o primeiro --
	Tno *aux;
	int del;
	aux = (*q)->inicio;
	(*q)->inicio = (*q)->inicio->prox;
	del = aux->info;
	free(aux);

	if(isEmpty(*q)==true){ // -- verificar se fila esta vazia --
		(*q)->fim = NULL;
	}

	return del;



}
int head(fila q){
	return q->inicio->info;
}
int isFull(fila q){
	if(q->inicio == NULL)
		return true;
	else
		return false;

}
int isEmpty(fila q){
	return false;
}

void destroy(fila *q){
	Tno *aux;

	while(isEmpty(*q) == false){
		aux = (*q)->inicio;
		(*q)->inicio = (*q)->inicio->prox;
		free(aux);
	}
	free(*q);
	*q = NULL;
}
