#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char nome[20];
    int telefone;
}Agenda;

typedef struct var{
    int i, Npessoas, op, op2, j, compint;
    char comp[20];
    Agenda agendaAux;
}Var;

typedef struct nodo{
    Agenda info;
    struct nodo *prox;
    struct nodo *ant;
}Nodo;

typedef struct list{
    Nodo *ini;
    Nodo *ult;
}List;

void Insere();
void Imprimir();
void Buscar();
void Deletar();

List *CriaLista();
Nodo *CriaNodo();
void pop();
void push();
void InserirList();
void ImprimirList();
void ImprimirListBusca();
void DeletarList();
void Ordenar();
void allDell();
Nodo *buscar();

void *pbuffer;
Var *aux;
Agenda *aponta;
Agenda *apontaaux;
List *lista;

int main (){
    pbuffer = (void*)malloc(sizeof(Var));
    if(pbuffer == NULL){
        printf("\nERRO\n");
        free(pbuffer);
        exit(-1);
    }
    aux = pbuffer;
    aux->Npessoas = 0;
    aux->i = 0;
    aux->j = 0;
    aponta = pbuffer;
    lista = CriaLista();

    printf("\nAgenda: \n1: AgendaVoid\n2: AgendaLista: ");
    scanf("%d", &aux->op2);

    if(aux->op2 == 1){
        while(aux->op != 5){
            aux->op = 0;
            printf("\nAgenda: \n1: Insere\n2: Lista\n3: Busca\n4: Apaga\n5: SAIR: ");
            scanf("%d", &aux->op);
            getchar();
            switch (aux->op){
                case 1: (aux->Npessoas)++;
                Insere();
                break;

                case 2: if(aux->Npessoas == 0){
                        printf("\nVAZIO\n");
                        }else{
                            Imprimir();
                        }
                break;

                case 3: if(aux->Npessoas == 0){
                            printf("\nVAZIO\n");
                        }else{
                            Buscar();
                        }
                break;

                case 4: if(aux->Npessoas == 0){
                            printf("\nVAZIO\n");
                        }else{
                            Deletar();
                        }
                break;

                case 5:
                free(pbuffer);
                exit(0);
                break;

                default:
                printf("\nOp. Invalida\n");
                break;
            }
        }
    }else if(aux->op2 == 2){
        while(aux->op != 5){
            aux->op = 0;
            printf("\nAgenda: \n1: Insere\n2: Lista\n3: Busca\n4: Remover\n5: SAIR: ");
            scanf("%d", &aux->op);
            getchar();
            switch(aux->op){
                case 1:
                InserirList();
                break;

                case 2:
                ImprimirList();
                break;

                case 3:
                ImprimirListBusca();
                break;

                case 4:
                DeletarList();
                break;

                case 5:
                allDell();
                free(pbuffer);
                exit(0);
                break;

                default:
                printf("\nOp. Invalida\n");
                break;
            }
        }
    }
    return 0;
}

void Insere(){
    pbuffer = realloc(pbuffer, sizeof(Var) + sizeof(Agenda)*(aux->Npessoas));
    aux = pbuffer;
    aponta = pbuffer + sizeof(Var) + sizeof(Agenda)*(aux->Npessoas) - sizeof(Agenda);
    printf("\nDigite um nome: ");
    scanf("%s", aponta->nome);
    printf("Digite um telefone: ");
    scanf("%d", &aponta->telefone);
}

void Imprimir(){
    aponta = pbuffer + sizeof(Var);
    for (aux->i = 0; (aux->i)<(aux->Npessoas); (aux->i)++){
        printf("\nNome: %s\n", aponta->nome);
        printf("Telefone: %d\n", aponta->telefone);
        aponta++;
    }
}

void Buscar(){
	printf("\nDigite um nome para Buscar: ");
	scanf("%s", aux->comp);
    if(aux->comp == NULL){
        printf("\nERRO\n");
        free(pbuffer);
        exit(-1);
    }
	for(aux->i = 0; (aux->i)<(aux->Npessoas); (aux->i)++ ){
        aponta = pbuffer + sizeof(Var);
        aponta += aux->i;
		if(strcmp(aux->comp, aponta->nome) == 0){
        printf("\nNome: %s\n", aponta->nome);
        printf("Telefone: %d\n", aponta->telefone);
        return;
        }else if((aux->i)+1 == (aux->Npessoas)){
            printf("\nNome Invalido\n");
            break;
        }
    }
}

void Deletar(){
	printf("\nDigite um nome para Deletar: ");
	scanf("%s", aux->comp);
	for(aux->i = 0; (aux->i)<=(aux->Npessoas); (aux->i)++ ){
        aponta = pbuffer + sizeof(Var);
        aponta += aux->i;
        apontaaux = pbuffer + sizeof(Var);

        if(aux->i == aux->Npessoas){
            printf("\nERRO\n");
            break;
        }
        if(strcmp(aux->comp, aponta->nome) == 0){
            while(aux->i < aux->Npessoas){
                aponta = pbuffer + sizeof(Var);
                aponta += aux->i;
                apontaaux = pbuffer + sizeof(Var);
                apontaaux += aux->i + 1;
                strcpy(aponta->nome, apontaaux->nome);
                aponta->telefone = apontaaux->telefone;
                (aux->i)++;
            }
            (aux->Npessoas)--;
            pbuffer = realloc(pbuffer, sizeof(Var) + sizeof(Agenda)*(aux->Npessoas));
            return;
        }
	}
}

List *CriaLista(){
    //testa se a lista foi criada mais de uma vez, ou se houve erro ao allocar
    //cria lista, inicio e fim apontam para NULL
    if(lista){
        printf("\nERRO\n");
        exit(1);
    }
    lista = (List*)malloc(sizeof(List));
    if(!lista){
        printf("\nERRO\n");
        exit(-1);
    }
    lista->ini = NULL;
    lista->ult = NULL;
    return lista;
}

Nodo *CriaNodo(){
    //cria um novo nodo, testa se há erro no alloc
    //prox e anterior apontam para NULL, preenche lista com nome e telefone
    //retorna o nodo com a lista
    Nodo *nNodo;
    nNodo = (Nodo*)malloc(sizeof(Nodo));
    if(!nNodo){
        printf("\nERRO\n");
        exit(-1);
    }
    nNodo->prox = NULL;
    nNodo->ant = NULL;
    printf("\nDigite um nome: ");
    scanf("%s", nNodo->info.nome);
    printf("\nDigite o telefone: ");
    scanf("%d", &nNodo->info.telefone);

    return nNodo;
}

void InserirList(){
    //insere uma info na ultima iteração da lista, percorre a lista até achar o ultimo
    Nodo *nNodo = CriaNodo();
    Nodo *ajuda = lista->ini;
    Nodo *ajudaAnt = ajuda;
    (aux->Npessoas)++;

    if(lista->ini == NULL){
        lista->ini = nNodo;
        lista->ult = lista->ini;
    }else{
        lista->ult = lista->ini;
        while(ajuda->prox){
            ajuda = ajuda->prox;
            ajuda->ant = ajudaAnt;
            ajudaAnt = ajudaAnt->prox;
            lista->ult = lista->ult->prox;
        }
        ajuda->prox = nNodo;
        ajuda = ajuda->prox;
        ajuda->ant = ajudaAnt;
        lista->ult = lista->ult->prox;

    }
}

void Ordenar(){
    //utiliza bubble sort para ordenar por nome
    if(!lista){
        printf("\nVAZIO\n");
        return;
    }
    Nodo *ii, *jj;
    for(ii = lista->ini->prox; ii; ii = ii->prox){
        for(jj = lista->ini; jj != lista->ult; jj = jj->prox){
            if(strcmp(jj->info.nome, jj->prox->info.nome) > 0){
                aux->agendaAux = jj->info;
                jj->info = jj->prox->info;
                jj->prox->info = aux->agendaAux;
            }
        }
    }
}

void ImprimirList(){
    //itera pela lista imprimindo todos
    if(!lista){
        printf("\nERRO\n");
        return;
    }
    Ordenar();
    push();
    pop();
}

void push(){
    pbuffer = realloc(pbuffer, sizeof(Var) + sizeof(Agenda) * aux->Npessoas);
    Nodo *ajuda = lista->ini;
    aux = pbuffer;

    aux->i = aux->Npessoas - 1;
    while(ajuda){
        *(Agenda *)(pbuffer + sizeof(Var) + sizeof(Agenda) * aux->i) = ajuda->info;
        (aux->i)--;
        ajuda = ajuda->prox;
    }
}

void pop(){
    Agenda *agenda = pbuffer + sizeof(Var) + sizeof(Agenda) * (aux->Npessoas - 1);
    aux->i = aux->Npessoas;
    while(aux->Npessoas){
        printf("\nNome: %s, Telefone: %d\n", agenda->nome, agenda->telefone);
        (aux->Npessoas)--;
        agenda--;
        pbuffer = realloc(pbuffer, sizeof(Var) + sizeof(Agenda) * aux->Npessoas);
        aux = pbuffer;
        agenda = pbuffer + sizeof(Var) + sizeof(Agenda) * (aux->Npessoas-1);
    }
    aux->Npessoas = aux->i;
}

Nodo *buscar(){
    //itera a função retornando um nome que a flag procura
    Nodo *ajuda = lista->ini;
    printf("Digite um nome: ");
    scanf("%s", aux->comp);
    while(ajuda && strcmp(aux->comp, ajuda->info.nome) != 0){
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
    Nodo *ajuda = buscar();
    if(ajuda){
        printf("\nNome: %s, Telefone: %d\n", ajuda->info.nome, ajuda->info.telefone);
    }else{
        printf("\nERRO\n");
        return;
    }
}

void DeletarList(){
    //utiliza a função buscar para encontrar um elemento que de match com a flag, itera pela lista e então libera essa info
    Nodo *delel = buscar();
    if(!delel){
        printf("\nERRO\n");
        return;
    }
    Nodo *ajuda = lista->ini;
    if(aux->Npessoas == 1){
        free(lista->ini);
        lista->ini = lista->ult = NULL;
    }else if(!delel->ant && delel->prox){
        lista->ini = lista->ini->prox;
        lista->ini->ant = NULL;
        free(delel);
    }else if(!delel->prox){
        lista->ult = lista->ult->ant;
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
    List *ajuda = lista;
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

//TENTATIVA DE MODULARIZAR O CÓDIGO APRESENTOU ERROS