#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>
TNo* TNo_create_n_fill(int key, TNo* parent);
bool BinTree_insert_r(TNo** root, TNo* p, int key);

BinTree* BinTree_create(){
    BinTree* tree = malloc(sizeof(BinTree));
    if(tree){
        tree->root = NULL;
    }
    return tree;
}
bool BinTree_insert_r(TNo** root, TNo* p, int key){
    if(*root == NULL){
        *root = TNo_create_n_fill(key, p);
        return *root != NULL;
    }else{
        if(key < (*root)->key)
            return BinTree_insert_r(&(*root)->left, *root, key);
        else 
            return BinTree_insert_r(&(*root)->right, *root, key);
    }
}
bool BinTree_insert(BinTree *T, int key){
    return BinTree_insert_r(&(T->root), NULL,key);
}


TNo* TNo_create_n_fill(int key, TNo* parent){
    TNo* novo = malloc(sizeof(TNo));
    if(novo){
        novo->key = key;
        novo->left = NULL;
        novo->right = NULL;
        novo->p = parent;
    }
    return novo;
}

void BinTree_pre(TNo* root){
    if(root!=NULL){
        printf("%d, ", root->key);
        BinTree_pre(root->left);
        BinTree_pre(root->right);
    }
}

void BinTree_inorder(TNo* root){
    if(root!=NULL){
        BinTree_inorder(root->left);
        printf("%d, ", root->key);
        BinTree_inorder(root->right);
    }
}