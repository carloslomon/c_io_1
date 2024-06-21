/*
    *UNI: cal2266
    *Author: Carlos Lopez 
    *Description: prints string and uppercase duplicate. 
    *twecho
*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
char** malloc_arrpointer(int n);
char* malloc_arr(int n);
static char **duplicateArgs(int argc, char **argv); 
static char **duplicateArgs(int argc, char **argv){
    int size = (argc+1) * sizeof(char*);// size of char* is 2  so it is kinda redundant
    char **copy = malloc_arrpointer(size);
    for(int i=0;i < argc; i++){
        int size1 = (strlen(argv[i])*sizeof(char))+1;
        copy[i] = malloc_arr(size1);
        for(int j = 0; j<(size1-1); j++){
            copy[i][j] = toupper(argv[i][j]); // same as *(arr[i] + j) or 
           //lastly i could have used **copy++ = toupper(**argv++);  
       } 
         copy[i][size1-1] = '\0';// equivalent to *(copy[i] + size1-1)
       }
       copy[argc] = NULL; // sets las val to null so it can stop
       return copy; 
}

static void freeDuplicatedArgs(char **copy){
    char **tmp = copy;
    while(*copy!=NULL){
        free(*copy++);
        }
        free(tmp); 
}

int main(int argc, char **argv){
    if(argc <= 1){
        return 1; 
    }
    char **copy = duplicateArgs(argc, argv);
    char **p = copy;
    argv++;
    p++;
    while (*argv) {
        printf("%s %s\n", *argv++, *p++);
    }
        freeDuplicatedArgs(copy);
        return 0;
}
char* malloc_arr(int n){
    char *p = (char *) malloc(n); 
    if (p == NULL) {
        perror("malloc returned NULL");        
        exit(1);
        // used to create the array of characters 
    }
    return p;
}
char** malloc_arrpointer(int n){
    char **p = (char **)malloc(n); 
    if (p == NULL) {
        perror("malloc returned NULL");
        exit(1);
    }
    return p;
    //used to create the array of pointers
}
//we can make this more fun and 
//ask for an implementation of 