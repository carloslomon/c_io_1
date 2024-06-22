#include <stdio.h> 
void binary(int n);
void convert(int n);
//Note, convert is hardcoded first befor binary to emphasize that if a fctn header is defined before it can be called within an fctn that is harcoded first
void convert(int n){
    printf("Signed decimal integer: %d\n", n);
    printf("Unsigned decimal integer: %u\n", n);
    printf("Hexadecimal: %x \n", n);
    binary(n);
}

void binary(int n){
    int i = 31; 
    printf("Binary: ");
    while(i>=0){
        int x = n&(1u<<i) ? 1 : 0; //checks if the ith bit of n is set to 1 or zero 1 & 1 is 1 and 1 & 0 is 0
        printf("%d", x);
        i--;
    }
    printf("\n");
}