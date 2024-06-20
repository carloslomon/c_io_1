#include <stdio.h> 
#include <stdlib.h> 
#include "isort.h"
#include <time.h> 
#include <string.h> 

int* malloc_arr(int n);
void sort_integer_array(int *start, int *end, int isAscending);
void print_arr(int *arr, int n);
void copy_arrs(int *og_arr, int *copy1, int *copy2, int n);
int comparator_asc(const void *p, const void *q);
int comparator_desc(const void *p, const void *q);
void isort(int n);
int main(){
    int n; 
    printf("Enter a postive integer: ");
    scanf("%d", &n);
    printf("\n You entered %d ok!\n", n);
    isort(n);
    return 0;
}
void isort(int n){
    int *arr1 = malloc_arr(n);
    int *arr2 = malloc_arr(n);
    int *arr3 = malloc_arr(n); 
    //Here we create three diffrent arrays locations in memory
    copy_arrs(arr1, arr2, arr3, n);
    sort_integer_array(arr2, &(*(arr2+n-1)), 1); 
    //Note the array name is equiv to &arr[0]
    //Note  &(*(arr2+n-1)) is equi to arr2 + n-1
    sort_integer_array(arr3, arr3 + n-1, 0);
    //Here we use the simpler implementation
    printf("\noriginal: ");
    print_arr(arr1, n);
    printf("\n\nAscending Order: ");
    print_arr(arr2, n);
    printf("\n\nDescending Order: ");
    print_arr(arr3, n);
    printf("\n");
}

int *malloc_arr(int n){
    int *p = (int *)(malloc(n * sizeof(int)));
    if(p==NULL){
        perror("malloc returned null");
        exit(1);
    }
    return p;
}

void sort_integer_array(int *start, int *end, int isAscending){
    int len = (int)(end - start + 1);
    printf("\nlength: %d\n", len);
    qsort(start, len, sizeof(int), ((int(*)(const void *, const void *))(isAscending ? comparator_asc:comparator_desc)));
}

void copy_arrs(int *og_arr, int *copy1, int *copy2, int n){
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        *(og_arr +i) = (random()%100);
        *(copy1 + i) = *(og_arr +i);
        *(copy2 + i) = *(og_arr + i);
    }
}
int comparator_asc(const void *p, const void *q){
    int l = *(int *)p;
    int r = *(int *)q;
    if(r < l){ 
        return 1;
    }else if(l < r){
        return -1;
    }
    else{
        return 0;
    }
}
int comparator_desc(const void *p, const void *q){
    int l = *(int *)p;
    int r = *(int *)q;
    if(r < l){ 
        return -1;
    }else if(l < r){
        return 1;
    }
    else{
        return 0;
    }
}
void print_arr(int *arr, int n){
    int i =0;
    for(;i < n-1; i++){
        printf("%d, ", *(arr+i));
    }
    printf("%d", *(arr + i));
    free(arr);
    arr = NULL;
}





