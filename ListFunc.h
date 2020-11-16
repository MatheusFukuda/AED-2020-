#ifndef _LISTFUNCTION_H            //guarda cabeçalho, impedem inclusões cíclicas
#define _LISTFUNCTION_H

void Insere();
void Imprimir();
void Buscar();
void Deletar();
list *CriaLista();
nodo *CriaNodo();
void pop();
void push();
void InserirList();
void ImprimirList();
void ImprimirListBusca();
void DeletarList();
void Ordenar();
void allDell();
nodo *buscar();

extern void *pbuffer;
extern var *aux;
extern agenda *aponta;
extern agenda *apontaaux;
extern list lista;

#endif
