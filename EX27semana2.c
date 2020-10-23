#include<stdio.h>
#include<stdlib.h>

void *r_realloc(void *point, size_t newsize){
    void *new_pointer;
    new_pointer = (void*)malloc(sizeof(void) * newsize);
    new_pointer =  memcpy(new_pointer, point, newsize);
    point = new_pointer;
    return point;
}
