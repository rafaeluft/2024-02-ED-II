#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>
TNo* TNo_create_n_fill(int key);
void BinTree_insert_r(int x, TNo** pt, bool *h);
void Case_1(TNo** pt, bool *h);
void Case_2(TNo** pt, bool *h);

BinTree* BinTree_create(){
    BinTree* tree = malloc(sizeof(BinTree));
    if(tree){
        tree->root = NULL;
    }
    return tree;
}
void BinTree_insert_r(int x, TNo** pt, bool *h){
    if(*pt == NULL){
        *pt = TNo_create_n_fill(x);
        *h = true;
    }else{
        if(x < (*pt)->key){
            BinTree_insert_r(x, &(*pt)->left, h);
            if (*h==true){
                switch((*pt)->bal){
                    case 1: (*pt)->bal = 0; *h = false; break;
                    case 0: (*pt)->bal = -1; break;
                    case -1: Case_1(pt, h); break;
                }
                //printf("Estou em [%d]: Valor de h=%d\n", (*pt)->key, *h);
            }
        }
        else{
            BinTree_insert_r(x, &(*pt)->right, h);
            if (*h==true){
                switch((*pt)->bal){
                    case -1: (*pt)->bal = 0; *h = false; break;
                    case 0: (*pt)->bal = 1; break;
                    case 1: Case_2(pt, h); break;
                }
            }
        }
    }
}
bool BinTree_insert(BinTree *T, int key){
    bool h;
    BinTree_insert_r(key, &(T->root), &h);
    //TODO: modiciar aqui para retornar se alocou com sucesso...
    return true;
}


TNo* TNo_create_n_fill(int key){
    TNo* novo = malloc(sizeof(TNo));
    if(novo){
        novo->key = key;
        novo->left = NULL;
        novo->right = NULL;
        novo->bal = 0;
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

void Case_1(TNo** pt, bool *h){
    TNo* ptu = (*pt)->left;
    if(ptu->bal == -1){
        (*pt)->left = ptu->right;
        ptu->right = *pt;
        (*pt)->bal = 0; *pt = ptu;
    }else{
        //puts("Dupla a direita");
        TNo* ptv = ptu->right;
        ptu->right = ptv->left;
        ptv->left = ptu;
        (*pt)->left = ptv->right; 
        ptv->right = *pt;
        (*pt)->bal = (ptv->bal == -1) ? 1:0;
        ptu->bal = (ptv->bal == 1) ? -1:0;
        *pt = ptv;
    }
    (*pt)->bal = 0;
    *h = false;
}
void Case_2(TNo **pt, bool *h){
    TNo* ptu = (*pt)->right;
    if(ptu->bal == 1){
        (*pt)->right = ptu->left;
        ptu->left = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }else{
        TNo* ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        (*pt)->right = ptv->left;
        ptv->left = *pt;
        (*pt)->bal = (ptv->bal == 1) ? -1:0;
        ptu->bal = (ptv->bal == -1)? 1:0;
        *pt = ptv;
    }
    (*pt)->bal = 0;
    *h = false;
}