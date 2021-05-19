#include "BST.h"

static NODE* initBST() // addBST 내부에서만 사용되므로 static
{
	NODE* root = (NODE*)malloc(sizeof(NODE)); // tree (or subtree)의 root 할당
	
	if (root == NULL)
	{
		printf("MALLOC FAILED ERROR. QUIT PROGRAM.\n");
		exit(1);
	}

	root->left = NULL;
	root->right = NULL;
	return root;
}

bool isTEmpty(NODE* root)
{
	return (root == NULL);
}

static NODE* findSmallestBST(NODE* root) // 재귀적으로 left subtree의 leaf 까지 도달
{
	if (isTEmpty(root->left))
	{
		return root;
	}
	return findSmallestBST(root->left);
}

static NODE* findLargestBST(NODE* root) // 재귀적으로 right subtree의 leaf 까지 도달
{
	if (isTEmpty(root->right))
	{
		return root;
	}
	return findLargestBST(root->right);
}

NODE* searchBST(NODE* root, DATA targetKey)
{
	if (isTEmpty(root))
	{
		return NULL;
	}

	if (targetKey < root->data)
	{
		return searchBST(root->left, targetKey);
	}
	else if (targetKey > root->data)
	{
		return searchBST(root->right, targetKey);
	}
	else
	{
		return root;
	}
}

bool addBST(NODE** rootPtr, DATA newData)
{
	if (isTEmpty(*rootPtr)) // 빈 트리이거나 leaf에 도달했을 때
	{
		*rootPtr = initBST();
		(*rootPtr)->data = newData;
		return true; // 삽입 성공
	}
	

	// 노드의 데이터와 newData간의 비교를 통해 newData의 삽입 위치를 탐색
	if (newData < (*rootPtr)->data)
	{
		return addBST(&((*rootPtr)->left), newData);
	}
	else
	{
		return addBST(&((*rootPtr)->right), newData);
	}

	return false; // 삽입 실패
}

bool deleteBST(NODE* root, DATA dltKey) // dltKey 값과 같은 값을 가진 node를 찾아 삭제
{
	if (isTEmpty(root))
	{
		return false;
	}

	// dltKey의 크기를 이용해 비교하면서 존재할만한 위치를 탐색
	if (dltKey < root->data)
	{
		return deleteBST(root->left, dltKey);
	}
	else if (dltKey > root->data)
	{
		return deleteBST(root->right, dltKey);
	}
	else // dltKey 값을 갖는 node를 찾았을 경우
	{
		if (isTEmpty(root->left)) // left subtree 가 없다면
		{
			// right subtree의 가장 작은 값을 찾아 현재 root자리에 대입
			NODE* temp = findSmallestBST(root->right);
			root->data = temp->data;
			free(temp);
			return true;
		}
		else if (isTEmpty(root->right)) // right subtree 가 없다면
		{
			// left subtree의 가장 큰 값을 찾아 현재 root자리에 대입
			NODE* temp = findLargestBST(root->left);
			root->data = temp->data;
			free(temp);
			return true;
		}
		else // left subtree와 right subtree가 모두 존재할 때
		{
			// 기본 동작으로 left subtree의 가장 큰 값을 root에 대입하는 것으로 설정
			NODE* deleteNode = root;
			NODE* largest = findLargestBST(root->left);
			deleteNode->data = largest->data;
			return deleteBST(deleteNode->left, largest->data);
		}
	}
}

bool freeBST(NODE* root)
{
	if (!isTEmpty(root))
	{
		freeBST(root->left);
		freeBST(root->right);
		free(root);
	}

	return true;
}

void printBST(NODE* root)
{
	if (isTEmpty(root))
		return;

	print(root->data);
	printBST(root->left);
	printBST(root->right);
}