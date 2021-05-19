#ifndef __DFS_H__
#define __DFS_H__

#include <stdbool.h>
#include "Data.h"
#include "BST.h"

typedef struct // DFS 결과를 저장받는 list
{
	int arr[12];
	int idx;
}LIST;

void DFStoArray(NODE* root, LIST*); // DFS 결과를 LIST에 저장

//bool DFS(NODE* root, int* searchNum, DATA* result, bool found);

#endif

