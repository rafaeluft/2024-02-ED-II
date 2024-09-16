#ifndef BINTREE_H
#define BINTREE_H
#include <stdbool.h>
typedef struct _no {
    int key;
    struct _no *left, *right;
}TNo;

typedef struct {
    TNo* root;
}BinTree;

BinTree* BinTree_create();
bool BinTree_insert(BinTree *, int);
void BinTree_pre(TNo* root);
void BinTree_inorder(TNo* root);

#endif