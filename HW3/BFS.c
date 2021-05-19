#include "BFS.h"

typedef struct _queue
{
	NODE* node[12];
	int frontIdx;
	int rearIdx;
}QUEUE; // 간단한 queue구조체

bool BFS(NODE* root, int* searchNum, DATA* result)
{
	NODE* current = root;
	QUEUE queue = { .frontIdx = 0, .rearIdx = 0 };
	queue.node[queue.rearIdx] = root; //root enqueue

	int tempNum = *searchNum;

	while (current != NULL)
	{
		if (current->left != NULL)
		{
			//left subtree enqueue
			queue.rearIdx++;
			queue.node[queue.rearIdx] = current->left;
		}
		if (current->right != NULL)
		{
			//right subtree enqueue
			queue.rearIdx++;
			queue.node[queue.rearIdx] = current->right;
		}

		if (queue.frontIdx <= queue.rearIdx) // queue가 비어있지 않다면
		{
			tempNum--;
			if (tempNum == 0)
			{ // 탐색 횟수에 맞는 데이터
				*result = current->data;
				return true;
			}
			//dequeue
			queue.frontIdx++;
			current = queue.node[queue.frontIdx];
		}
		else
			current = NULL;
	}
	return false; // 탐색 실패
}
