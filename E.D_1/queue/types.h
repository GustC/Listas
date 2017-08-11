
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

#ifndef QUEUE
#define QUEUE
typedef struct NO{
	struct NO *prox;
	int info;
}Tno;

typedef struct descritor{
	Tno *inicio,*fim;
}Descritor;

typedef Descritor *fila;
#endif