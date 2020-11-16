#include<stdio.h>
#include<stdlib.h>
#include<string.h>

list *CriaLista();          //DONE
nodo *CriaNodo();           //DONE
void pop();                 //DONE
void push();                //DONE
void InserirList();         //DONE
void ImprimirList();        //DONE
void ImprimirListBusca();   //DONE
void DeletarList();         //DONE
void Ordenar();             //DONE
void allDell();             //DONE
nodo *buscar();             //DONE

list *CriaLista(){
    //testa se a lista foi criada mais de uma vez, ou se houve erro ao allocar
    //cria lista, inicio e fim apontam para NULL
    if(list){
        printf("\nERRO\n");
        exit(1);
    }
    list = (list*)malloc(sizeof(list));
    if(!list){
        printf("\nERRO\n");
        exit(-1);
    }
    list->ini = NULL;
    list->ult = NULL;
    return list;
}

nodo *CriaNodo(){
    //cria um novo nodo, testa se há erro no alloc
    //prox e anterior apontam para NULL, preenche lista com nome e telefone
    //retorna o nodo com a lista
    nodo *nNodo;
    nNodo = (nodo*)malloc(sizeof(nodo));
    if(!nNodo){
        printf("\nERRO\n");
        exit(-1);
    }
    nNodo->prox = NULL;
    nNodo->ant = NULL;
    printf("\nDigite um nome: ");
    scanf("%s", nNodo->info.nome);
    printf("\nDigite o telefone");
    scanf("%d", &nNodo->info.telefone);

    return nNodo;
}

void InserirList(){
    //insere uma info na ultima iteração da lista, percorre a lista até achar o ultimo
    nodo *nNodo = CriaNodo();
    nodo *ajuda = list->ini;
    nodo *ajudaAnt = ajuda;
    (aux->Npessoas)++;

    if(list->ini == NULL){
        list->ini = nNodo;
        list->ult = list->ini;
    }else{
        list->ult = list->ini;
        while(ajuda->prox){
            ajuda = ajuda->prox;
            ajuda->ant = ajudaAnt;
            ajudaAnt = ajudaAnt->prox;
            list->ult = list->ult->prox;
        }
        ajuda->prox = nNodo;
        ajuda = ajuda->prox;
        ajuda->ant = ajudaAnt;
        list->ult = list->ult->prox;

    }
}

void Ordenar(){
    //utiliza bubble sort para ordenar por nome
    if(!list){
        printf("\nVAZIO\n");
        return;
    }
    nodo *i, *j;
    for(i = list->ini->prox; i; i = i->prox){
        for(j = list->ini; j != list->ult; j = j->prox){
            if(strcmp(j->info.nome, j->prox->info.nome) > 0){
                aux->agendaAux = j->info;
                j->info = j->prox->info;
                j->prox->info = aux->agendaAux;
            }
        }
    }
}

void ImprimirList(){
    //itera pela lista imprimindo todos
    if(!list){
        printf("\nERRO\n");
        return;
    }
    Ordenar();
    push();
    pop();
}

void push(){
    pbuffer = realloc(pbuffer, sizeof(var) + sizeof(agenda) * aux->Npessoas);
    nodo *ajuda = list->ini;
    aux = pbuffer;

    aux->i = aux->Npessoas - 1;
    while(ajuda){
        *(agenda*)(pbuffer + sizeof(var) + sizeof(agenda) * aux->i) = ajuda->info;
        (aux->i)--;
        ajuda = ajuda->prox;
    }
}

void pop(){
    agenda *agenda = pbuffer +sizeof(var) + sizeof(agenda) * (aux->Npessoas - 1);
    aux->i = aux->Npessoas;
    while(aux->Npessoas){
        printf("\nNome: %s, Telefone: %d\n", agenda->nome, agenda->telefone);
        (aux->Npessoas)--;
        agenda--;
        pbuffer = realloc(pbuffer, sizeof(var) + sizeof(agenda) * aux->Npessoas);
        aux = pbuffer;
        agenda = pbuffer + sizeof(var) + sizeof(agenda) * (aux->Npessoas-1);
    }
    aux->Npessoas = aux->i;
}

nodo *buscar(){
    //itera a função retornando um nome que a flag procura
    nodo *ajuda = list->ini;
    printf("Digite um nome: ");
    scanf("%s", aux->comp);
    while(ajuda && strcmp(aux->nome, ajuda->info->nome) != 0){
        ajuda = ajuda->prox;
    }
    if(!ajuda){
        printf("\nVAZIO\n");
        return NULL;
    }else{
        return ajuda;
    }
}

void ImprimirListBusca(){
    //utiliza a função busca para encontrar e imprimir uma info
    nodo *ajuda = buscar();
    if(ajuda){
        printf("\nNome: %s, Telefone: %d\n", ajuda->info.nome, ajuda->info.telefone)
    }else{
        printf("\nERRO\n");
        return;
    }
}

void DeletarList(){
    //utiliza a função buscar para encontrar um elemento que de match com a flag, itera pela lista e então libera essa info
    nodo *delel = buscar();
    if(!delel){
        printf("\nERRO\n");
        return;
    }
    nodo *ajuda = list->ini;
    if(aux->Npessoas == 1){
        free(list->ini);
        list->ini = list->ult = NULL;
    }else if(!delel->ant && delel->prox){
        list->ini = list->ini->prox;
        list->ini->ant = NULL;
        free(delel);
    }else if(!delel->prox){
        list->ult = list->ult->ant;
        ajuda = delel->ant;
        ajuda->prox = NULL;
        free(delel);
    }else{
        ajuda = delel->ant;
        ajuda->prox = delel->prox;
        ajuda->prox->ant = ajuda;
        free(delel);
    }
    (aux->Npessoas)--;
}

void allDell(){
    //libera primeiro da lista, case haja mais de um elemento itera pela lista liberando o anterior
    list *ajuda = list;
    if(!ajuda->ini->prox && ajuda->ini){
        free(ajuda->ini);
    }else{
        while(ajuda->ini && (ajuda->ini != ajuda->ult)){
            free(ajuda->ini->ant);
            ajuda->ini = ajuda->ini->prox;
        }
        free(ajuda->ini);
    }
    free(ajuda);
}