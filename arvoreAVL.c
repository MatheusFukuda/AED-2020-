#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int h;      //altura
    int val;    //valor
    struct node *esq;
    struct node *dir;
};

typedef struct node* idk; //(?)
int inserir(idk *raiz, int valor);
int remover(idk *raiz, int valor);
void RDD(idk *raiz); //rotação dupla direita
void RDE(idk *raiz); //rotação dupla esquerda
void RE(idk *raiz);  //rotação esquerda
void RD(idk *raiz);  //rotação direita
int compMaior(int x, int y);
idk *makeTree();
void freeTree(idk *raiz);
int altura (struct node *node);
struct node *findMenor(struct node *atual);
void freeNo(struct node* node);
int FB(struct node *node);
int alr_avl(struct node *raiz);
void ordem(struct node *raiz);

int main(){
    int n, i, p;
    idk *raiz = makeTree();
    printf("Informe o nmr de Nodos(n): ");
    scanf("%d", &n);
    srand(time(0));
    for(i = 0; i < n; i++){
        p = rand()%100;
        printf("\nNmr#%d: %d",i+1, p);
        p = inserir(raiz, p);
    }

    if(alr_avl(*raiz)){
        printf("\nArvore AVL: "); //ordem é que printa: raiz, todos nós a esquerda, todos nós a direita
        ordem(*raiz);
        printf("\nOK\n");
    }

    freeTree(raiz);
    return 0;
}

void ordem(struct node *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->val);
        ordem(raiz->esq);
        ordem(raiz->dir);
    }
}

int compMaior(int x, int y){
    if (x > y)
    return x;
    else
    return y;
}

int altura(struct node *node){
    if(node == NULL)
        return -1;
    else
        return node->h; 
}

void freeTree(idk *raiz){
    if(raiz == NULL)
        return;
    freeNo(*raiz);
    free(raiz);
}

void freeNo(struct node* node){
    if(node == NULL)
        return;
    freeNo(node->esq);
    freeNo(node->dir);
    free(node);
    node = NULL;
}

idk *makeTree(){
    idk *raiz = (idk*)malloc(sizeof(idk));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int inserir(idk *raiz, int valor){
    int aux;
    if(*raiz == NULL){
        struct node *nwe;
        nwe = (struct node*)malloc(sizeof(struct node));
        if(nwe == NULL){
            return 0;
        }
        nwe->val = valor;
        nwe->h = 0;
        nwe->esq = NULL;
        nwe->dir = NULL;
        *raiz = nwe;
        return 1;
    }
    struct node *atual = *raiz;
    if(valor < atual->val){
        //add a esq, pois valor é menor
        aux = inserir(&(atual->esq), valor);
        if(aux == 1){
            if(FB(atual) >= 2){
                if(valor < (*raiz)->esq->val)
                    RE(raiz);
                else
                    RDD(raiz);
            }
        }
    }else{
        if(valor > atual->val){
            //add a direita
            aux = inserir(&(atual->dir), valor);
            if(aux == 1){
                if(FB(atual) >= 2){
                    if((*raiz)->dir->val < valor)
                    RD(raiz);
                    else
                    RDE(raiz);
                }
            }
        }else{
            printf("\nERRO\n");
            return 0;
        }
    }
    atual->h = compMaior(altura(atual->esq), altura(atual->dir));
    return aux;
}

int FB(struct node *node){
    if(node == NULL)
    return -1;

    return labs(altura(node->esq) - altura(node->dir));
}

struct node *findMenor(struct node *atual){
    //procura o ultimo nó a esquerda
    struct node *ajuda1 = atual;
    struct node *ajuda2 = atual->esq;
    while(ajuda2 != NULL){
        ajuda1 = ajuda2;
        ajuda2 = ajuda2->esq;
    }
    return ajuda1;
}

int alr_avl(struct node *raiz){
    int sid;

    if(raiz == NULL)
    return 1;

    if(!alr_avl(raiz->esq))
    return 0;

    if(!alr_avl(raiz->dir))
    return 0;

    sid = FB(raiz);
    if(sid > 1)
    return 0;
    else
    return 1;
}

void RDD(idk *raiz){
    RE(&(*raiz)->dir);
    RD(raiz);

}
void RDE(idk *raiz){
    RD(&(*raiz)->esq);
    RE(raiz);
}

void RE(idk *raiz){
    struct node *help;
    help = (*raiz)->dir;
    (*raiz)->dir = help->esq;
    help->esq = *raiz;
    (*raiz)->h = compMaior(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    help->h =  compMaior(altura(help->dir), (*raiz)->h) + 1;
    *raiz = help;
}

void RD(idk *raiz){
    struct node *help;
    help = (*raiz)->esq;
    (*raiz)->esq = help->dir;
    help->dir = *raiz;
    (*raiz)->h = compMaior(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    help->h = compMaior(altura(help->esq), (*raiz)->h) + 1;
    *raiz = help;
}

int remover(idk *raiz, int valor){
    int aux;
    if(*raiz == NULL){
        printf("\nERRO\n");
        return 0;
    }

    if(valor < (*raiz)->val){
        aux = remover(&(*raiz)->esq, valor);
        if(aux == 1){
            if(FB(*raiz) >= 2){
                if(altura((*raiz)->dir->esq) <= altura((*raiz)->dir->dir))
                RD(raiz);
                else
                RDE(raiz);
            }
        }
    }

    if((*raiz)->val < valor){
        aux = remover(&(*raiz)->dir, valor);
        if(aux == 1){
            if(FB(*raiz) >= 2){
                if(altura((*raiz)->esq->dir) <= altura((*raiz)->esq->esq))
                RE(raiz);
                else
                RDD(raiz);
            }
        }
    }

    if((*raiz)->val == valor){
        if((*raiz)->esq ==NULL || (*raiz)->dir == NULL){
            struct node *old = (*raiz);
            if((*raiz)->esq != NULL)
            *raiz = (*raiz)->esq;
            else
            *raiz = (*raiz)->dir;
            free(old);
        }else{
            struct node *pslb = findMenor((*raiz)->dir);
            (*raiz)->val = pslb->val;
            remover(&(*raiz)->dir, (*raiz)->val);
            if(FB(*raiz) >= 2){
                if(altura((*raiz)->esq->dir) <= altura((*raiz)->esq->esq))
                RE(raiz);
                else
                RDD(raiz);
            }
        }
        return 1;
    }
    return aux;
}

