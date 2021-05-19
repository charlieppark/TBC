#include "DFS.h"

void DFStoArray(NODE* root, LIST* list)
{
	if (isTEmpty(root)) // leaf에 도달할경우
		return;

	list->arr[list->idx] = root->data; // DFS로 탐색되는 값을 배열에 순차적으로 저장
	list->idx++;

	DFStoArray(root->left, list); // left subtree를 재귀적으로 탐색
	DFStoArray(root->right, list); // right subtree를 재귀적으로 탐색
}

/*bool DFS(NODE* root, int* searchNum, DATA* result, bool found)
{
	if (found == true)
		return true;

	if (*searchNum == 1)
	{
		*result = root->data;
		return true;
	}

	if (isTEmpty(root->left) && isTEmpty(root->right))
	{
		return false;
	}

	int tempNum;

	tempNum = *searchNum;

	if (!isTEmpty(root->left))
	{
		tempNum--;
		if (found = DFS(root->left, &tempNum, result, found))
			return found;
	}

	if (!isTEmpty(root->right))
	{
		tempNum--;
		if (found = DFS(root->right, &tempNum, result, found))
			return found;
	}

	return found;
}*/