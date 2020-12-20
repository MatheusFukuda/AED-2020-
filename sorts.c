#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int *v, int n);
void insertion(int *v, int n);
void selection(int *v, int n);
void quick(int *v, int left, int right);
void merge(int *v, int l, int m, int r);
void mergesort(int *v, int l, int r);

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
                selection(v, n);
                printf("\nOrd.: ");
                for(i = 0; i < n; i++)
                    printf(" %d", *(v+1));
                exit(0);
            break;

            case 4:
                quick(v, 0, n);
                printf("\nOrd.: ");
                for(i = 0; i < n; i++)
                    printf(" %d", *(v+1));
                exit(0);
            break;

            case 5:
                mergesort(v, 0, n);
                printf("\nOrd.: ");
                for(i = 0; i < n; i++)
                    printf(" %d", *(v+1));
                exit(0);
            break;

            case 6:
                printf("\nSaindo\n");
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

void insertion(int *v, int n){
    int i, j, aux;
    for(i = 0; i < n; i++){
        aux = v[i];
        j = i-1;
        while(j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void selection(int *v, int n){
    int i, j, aux, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

void quick(int *v, int left, int right){
    int pivo, i, j, aux;
    i = left;
    j = right;
    pivo = v[(left + right) / 2];

    do{
        while(v[i] < pivo)
            i++;
        while(v[j] > pivo)
            j--;
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while (i <= j);
    if(left < j){
        quick(v, left, j);
    }
    if(i < right){
        quick(v, i, right);
    }
}

void merge(int *v, int l, int m, int r){
    int i, j, k;
    int n1 = m + l + 1;
    int n2 = r - m;
    int L[n1], R[n2];


    for(i = 0; i < n1; i++)
        L[i] = v[l + i];
    for(j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int *v, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergesort(v, l, m);
        mergesort(v, m+1, r);
        merge(v, l, m, r);
    }
}