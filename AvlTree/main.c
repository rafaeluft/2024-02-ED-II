#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>
void print_tree(BinTree *tree){
    if(tree == NULL || tree->root == NULL)
    {
        puts("A arvore esta vazia");
        return;
    }
    puts("Pre: ");
    BinTree_pre(tree->root);
    puts("\nInorder: ");
    BinTree_inorder(tree->root);
}
int main(int argc, char *argv[]){

    BinTree *T = BinTree_create();
    for(int i=1; argc > 1 && i<argc; i++){
        int key = atoi(argv[i]);
        printf("Inserting key: %d\n", key);
        if(!BinTree_insert(T, key))
            printf("Error: BinTree_insert %i-th=%i\n", i, key);
    }
   /*
   int keys[] = {5, 3, 4};
    for(int i=0; i<3; i++){
        int key = keys[i];
        printf("Inserting key: %d\n", key);
        if(!BinTree_insert(T, key))
            printf("Error: BinTree_insert %i-th=%i\n", i, key);
    }
    */
    print_tree(T);
    return 0;
}