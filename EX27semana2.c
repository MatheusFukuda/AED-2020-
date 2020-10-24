#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void *buffer;
void *r_realloc(void *point, size_t newsize){
    void *new_pointer;
    new_pointer = (void*)malloc(sizeof(buffer) * newsize);
    new_pointer =  memcpy(new_pointer, point, newsize);
    point = new_pointer;
    free(new_pointer);
    return point;
}
int main(){
    buffer = malloc(sizeof(buffer));
    int size = 0;
    scanf("%d", &size);
    r_realloc(buffer, size);
    free(buffer);
    return 0;
}