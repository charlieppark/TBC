#ifndef __BST_H__
#define __BST_H__

#include <stdlib.h>
#include <stdbool.h>
#include "Data.h"

typedef struct _node
{
	DATA data;
	struct _node* left; // left subtree
	struct _node* right; // right subtree
} NODE;

NODE* searchBST(NODE* root, DATA targetKey); 

bool addBST(NODE** rootPtr, DATA newData);
// 빈 트리에서 추가하는 경우 root를 수정하므로 rootPtr은 이중포인터

bool deleteBST(NODE* root, DATA dltKey);

void printBST(NODE* root);

bool freeBST(NODE* root); // 전체 node를 free 하는 함수

bool isTEmpty(NODE* root);

#endif

