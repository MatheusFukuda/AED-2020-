#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char *vintenove, nome, aux[20], *teste, *bah, c;
int i = 0, j = 1, op, uso = 0, len;

    vintenove = (char*)malloc(sizeof(char));
    if(!vintenove){
        printf("erro no malloc");
        free(vintenove);
        exit(-1);
    }
    while(op != 4){
        printf("\n1. Inserir\n2. Remover\n3. Listar\n4. Sair: ");
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                printf("\nDigite um nome para Inserir: ");
                nome = vintenove[i];
                j = 1;
                while(nome != '\n'){
                    nome = getc(stdin);
                    vintenove = (char*)realloc(vintenove, (j * sizeof(char)) + (uso * sizeof(char)));
                    vintenove[i] = nome;
                    i++;
                    j++;
                    uso++;
                }
                vintenove[i] = '\0';
                break;

            case 2:
                if(vintenove == NULL){
                    printf("\nNao ha nomes para deletar");
                }else{
                    printf("\nDigite um nome para Deletar: ");
                    j = 0;
                    while((c = getchar()) != '\n'){
                        aux[j++] = c;
                    }
                    aux[j++] = '\n';
                    aux[j++] = '\0';
                    len = strlen(aux);
                    if(strstr(vintenove, aux) != NULL){
                        if(teste = strstr(vintenove, aux)){
                            *teste = '\0';
                            strcat(vintenove, teste+(len));
                            i = i - (len);
                            uso = uso - (len);
                            vintenove=(char*)realloc(vintenove, (j*sizeof(char)) + (uso * sizeof(char)));
                        }
                    }else{
                        printf("\nNome nao existe na lista\n");
                    }
                }
                break;
            case 3:
                if(vintenove == NULL){
                    printf("\nLista vazia\n");
                }else{
                printf("\n%s", vintenove);
                }
                break;
            case 4:
                free(vintenove);
                exit(0);
                break;

            default:
                printf("\nOperacao invalida\n");
                break;
        }
    }
    return 0;
}