#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int *v, int n);
void insertion();
void selection();
void quick();
void merge();

int main(){

    int n, *v, i, op = 0;
    printf("Entry: ");
    scanf("%d", &n);
    srand(time(NULL));

    v = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        *(v+i) = rand() %100;
    }
    printf("\nRandom Numbers:");
    for(i = 0; i < n; i++)
    printf(" %d", *(v+i));

    while(op != 6){
        op = 0;
        printf("\nMENU:\n1: Bubble\n2: Insertion\n3: Selection\n4: Quick\n5: Merge\n6: SAIR\nEntry: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                bubble(v, n);
                printf("\nOrd.: ");
                for(i = 0; i < n; i++)
                printf(" %d", *(v+i));
                exit(0);
            break;

            case 2:
                insertion(v, n);
                printf("\nOrd.: ");
                for(i = 0; i < n; i++)
                printf(" %d", *(v+i));
                exit(0);
            break;

            case 3:
                selection();
            break;

            case 4:
                quick();
            break;

            case 5:
                merge();
            break;

            default:
                printf("\nERRO\n");
            break;
        }
    }
    return 0;
}

void bubble(int *v, int n){
    int i, j, aux;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
void insertion(){
    
}
void selection(){}
void quick(){}
void merge(){}