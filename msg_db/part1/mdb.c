#include "mdb.h"
#include "../../linked_list_1/part1/mylist.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int loadmdb(FILE *fp, struct List *dest){
    struct MdbRec myRec;
    struct Node *node = NULL;
    int count = 0;
    init_list(dest);

    //puts record into linked list
    while(fread(&myRec, sizeof(myRec), 1, fp)==1){
        struct MdbRec *record = (struct MdbRec*)(sizeof(myRec));
        if(!record){
            perror("Malloc error");
            exit(1);
        }
        memcpy(record, &myRec, sizeof(myRec));
        node = add_after(dest, node,record);
        if(node == NULL){
            perror("add_after error");
            exit(1);
        }
        ++count;

        if(ferror(fp)){
            perror("error reading file");
            exit(1);
        }

    }
    return count;
}

//free all memory allocated 
void freemdb(struct List *mdbLst){
    struct Node *curr = mdbLst->head;
    while(curr){
        curr = curr->next;
        free(pop_front(mdbLst));
        // why is it equal to free(pop_front(mdbLst->head)) 
    }
}
/*When you do not want to compile all files without testing such that there will finally be a defualt, 
*then add the main function.
*/
/*int main(int argc, char *argv[]) {
    // Your code here
    return 0;
}*/