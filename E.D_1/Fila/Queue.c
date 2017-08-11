#include <stdlib.h>
#include "Types.h"

Queue initialize (void){
	TDesc *aux;
	aux = (TDesc *) malloc(sizeof(TDesc));
	aux->prim = NULL;
	aux->ult = NULL;
	return aux;
}

void enqueue (Queue q, int num){
	NoQueue *novo;

	novo = (NoQueue *) malloc (sizeof(NoQueue));
	novo->info = num;
	novo->prox = NULL;

	q->ult = novo;
	if(q->prim == NULL)
		q->prim = novo;
}

int dequeue (Queue q){
	NoQueue *aux;
	int n;

	aux = q->prim;
	q->prim = q->prim->prox;
	n = aux->info;
	free(aux);

	return n;
}

int head (Queue q){
	return q->prim->info;
}

int isEmpty (Queue q){
	if (q->prim == NULL)
		return true;
	else
		return false;
}

int isFull (Queue q){
	return false;
}

void destroy (Queue q){
	NoQueue *aux;

	while(q->prim != NULL){
		aux = q->prim;
		q->prim = q->prim->prox;
		free(aux);
	}
	free(q);
}




