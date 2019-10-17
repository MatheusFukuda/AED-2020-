#include<stdio.h>

int main(){

    int vetor[10] = {1,2,3,4,5,5,7,8,9,10};
    int i,j;

    for(i = 0; i < 9; i++){
        if (vetor[i] <= vetor[i + 1]){
            j = 1;
        }
        else{
        j = 0;
        break;
        }
    }
    if(j == 1)
        printf("ordenado");
    else
        printf("nao ordenado");
    return 0;
}