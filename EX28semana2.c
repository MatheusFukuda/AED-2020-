#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
}pessoa;

int main(){
    int op, Npe = 0, i = 0, j = 0, iaux = 0;
    char aux[30];
    pessoa *p;
    p = (pessoa*)malloc(sizeof(pessoa));
    if(p == NULL){
        printf("\nERRO\n");
        free(p);
        exit(-1);
    }
    pessoa Npessoa;
    while(op != 2){
        op = 0;
        printf("\nGostaria de adicionar?\n1)SIM\n2)NAO: ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
            Npe++;
            printf("\nDigite um nome: ");
            scanf("%s", Npessoa.nome);
            printf("Digite a idade: ");
            scanf("%d", &Npessoa.idade);
            printf("Digite a altura: ");
            scanf("%d", &Npessoa.altura);

            p = (pessoa*)realloc(p, sizeof(pessoa) * Npe);
            p[Npe-1] = Npessoa;
            break;

            case 2:
            for(i = 0; i < Npe; i++){
                for(j = 0; j < (Npe-1); j++){
                    if(strcmp(p[j].nome, p[j+1].nome) > 0){
                        strcpy(aux, p[j].nome);
                        strcpy(p[j].nome, p[j+1].nome);
                        strcpy(p[j+1].nome, aux);

                        iaux = p[j].idade;
                        p[j].idade = p[j+1].idade;
                        p[j+1].idade = iaux;

                        iaux = p[j].altura;
                        p[j].altura = p[j+1].altura;
                        p[j+1].altura = iaux;

                    }
                }
            }
            for(i = 0; i < Npe; i++){
                printf("\nNmr #%d", i + 1);
                printf("\nNome: %s", p[i].nome);
                printf("\nIdade: %d", p[i].idade);
                printf("\nAltura: %d\n", p[i].altura);
            }
            free(p);
            exit(0);
            break;

            default:
            printf("\nOp. Invalida\n");
            break;
        }
    }
    return 0;
}