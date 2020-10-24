#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int *colunaMatriz(int **mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor(int *vet, int n);


int main(){
    int **matriz = 0, *retur = 0;
    int op = 0, i = 0, idk = 0;
    int mm = 0, mn = 0;
    while(op != 6){
        op = 0;
        printf("\n1)Criar e redimencionar matrix");     //fornecer m e n
        printf("\n2)Realizar a leitura dos elementos"); //ler m e n
        printf("\n3)Soma dos elementos");               //soma de m + n
        printf("\n4)Elementos de uma coluna");          //valore de uma coluna
        printf("\n5)Imprimir matriz");                  //m = linha
        printf("\n6)SAIR: ");                           //n = coluna
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
            if(matriz != NULL){
                liberaMatriz(matriz, mn);
            }else{
                printf("\nDigite o valor de linhas: ");
                scanf("%d", &mm);
                printf("\nDigite o valor de colunas: ");
                scanf("%d", &mn);
                matriz = criaMatriz(mm, mn);
            }
            break;

            case 2:
            if(matriz == NULL){
                printf("\nERRO\n");
                break;
            }else{
                leiaMatriz(matriz, mm, mn);
            }
            break;

            case 3:
            if(matriz == NULL){
                printf("\nERRO\n");
                break;
            }else{
                printf("\nSoma total da Matriz: %d\n", somaMatriz(matriz, mm, mn));
            }
            break;

            case 4:
            printf("\nNmr da coluna: ");
            scanf("%d", &idk);
            if((idk >= 0) && (idk < mn)){
                retur = colunaMatriz(matriz, mm, mn, idk);
                imprimeVetor(retur, mm);
                free(retur);
            }else{
                printf("\nERRO\n");
            }
            break;

            case 5:
            if(matriz == NULL){
                printf("\nERRO\n");
                break;
            }
            imprimeMatriz(matriz, mm, mn);
            break;

            case 6:
            liberaMatriz(matriz, mm);
            free(retur);
            free(matriz);
            exit(0);
            break;

            default:
            printf("\nOp. Invalida\n");
            break;
        }
    }
    return 0;
}

int **criaMatriz(int m, int n){
    int **matriz;
    matriz = (int **)malloc(sizeof(int *) * m);
    if(matriz == NULL){
        printf("\nERRO\n");
        free(matriz);
        exit(-1);
    }
    for (int i = 0; i < m; i++){
        matriz[i] = (int *)malloc(sizeof(int) * n);
    }

    return (int **)matriz;
}

void leiaMatriz(int **mat, int m, int n){
    int cont = 0;
    for(int mm = 0; mm < m; mm++){
        for(int mn = 0; mn < n; mn++){
            cont++;
            printf("\nDigite o #%d numero: ", cont - 1);
            scanf("%d", &mat[mm][mn]);
        }
    }
}

int somaMatriz(int **mat, int m, int n){
    int total = 0, saux = 0;
    for(int mm = 0; mm < m; mm++){
        for(int mn = 0; mn < n; mn++){
            saux = saux + mat[mm][mn];
        }
        total = total + saux;
        saux = 0;
    }
    return total;
}

int *colunaMatriz(int **mat, int m, int n, int ncoluna){
    if(n < ncoluna){
        printf("\nERRO\n");
    }
    int *retur = 0;
    retur = (int *)malloc(sizeof(int) * m);
    for(int mm = 0; mm < m; mm++){
        retur[mm] = mat[mm][ncoluna];
    }
    return (int *)retur;
}
void liberaMatriz(int **mat, int ncoluna){
    for(int i = 0; i < ncoluna; i++){
        if(mat[i] != NULL){
            free(mat[i]);
        }
    }
    free(mat);
}
void imprimeMatriz(int **mat, int m, int n){
    printf("\n");
    for(int mm = 0; mm < m; mm++){
        for(int nm = 0; nm < n; nm++){
            printf("%d ", mat[mm][nm]);
        }
        printf("\n");
    }
}
void imprimeVetor(int *vet, int n){
    for(int i = 0; i < n; i++){
        printf("\n%d", vet[i]);
    }
    printf("\n");
}