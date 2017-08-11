#include <stdio.h>
#include "Types.h"

Queue initialize (void);
void enqueue (Queue q, int num);
int dequeue (Queue q);
int head (Queue q);
int isEmpty (Queue q);
int isFull (Queue q);
void destroy (Queue q);