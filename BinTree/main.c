#include "BinTree.h"
#include <stdio.h>
void print_tree(BinTree *tree){
    puts("Pre: ");
    BinTree_pre(tree->root);
    puts("\nInorder: ");
    BinTree_inorder(tree->root);
}
int main(){
    int V[] = {4,2,3,1,0,6,5,7};
    BinTree *T = BinTree_create();
    for(int i=0; i<8; i++){
        if(!BinTree_insert(T, V[i]))
            printf("Error: BinTree_insert V[%i]=%i\n", i, V[i]);
    }
    print_tree(T);
    return 0;
}