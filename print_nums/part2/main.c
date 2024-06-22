#include <stdio.h> 
#include "convert.h"
int main(){
    int n; 
    printf("Enter an integer: ");
    scanf("%d", &n);
    convert(n);
    return 0;
}