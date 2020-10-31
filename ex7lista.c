#include<stdio.h>
#include<stdlib.h>

float *Inserir(float *vetor, int count);
float *Deleta(float *vetor, int* count);
void Imprimir(float *vetor, int count);

int main(){
    int op;
    float *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &op);
    if(op <= 0){
        printf("\nERRO\n");
        exit(-1);
    }

    vetor = (float*)malloc(sizeof(float) * op);
    if(vetor == NULL){
        printf("\nERRO MALLOC\n");
        free(vetor);
        exit(-1);
    }
    vetor = Inserir(vetor, op);
    vetor = Deleta(vetor, &op);
    Imprimir(vetor, op);
    free(vetor);
    return 0;
}
float *Inserir(float *vetor, int count){
    if(count == 1){
        scanf("%f", vetor);
    }else{
    vetor = (float*)realloc(vetor, sizeof(float) * count);
        for(int i = 0; i < count; i++){
        printf("\nDIgite o #%d numero: ", i+1);
        scanf("%f", &vetor[i]);
        }
    }
    return vetor;
}
float *Deleta(float *vetor, int *count){
    for(int i = 0; i < *count - 1; i++){
        for(int j = i+1; j < *count;){
            if(vetor[i] == vetor[j]){
                for(int k = j; k < *count; k++){
                    vetor[k - 1] = vetor[k];
                }
                (*count)--;
            }else{
                j++;
            }
        }
    }
    vetor =(float*)realloc(vetor, sizeof(float) * *count);
    return vetor;
}
void Imprimir(float* vetor, int count){
    if(count > 1){
        for(int i = 0; i < count; i++){
            printf("\nVetor: %.2f", vetor[i]);
        }
    }else{
        printf("%.2f", *vetor);
    }
}