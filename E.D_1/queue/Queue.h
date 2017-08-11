#include "types.h"


void enqueue (fila *q, int n);
int dequeue(fila *q);
int head(fila q);
int isFull(fila q);
int isEmpty(fila q);

void destroy(fila *q);
fila createQueue();