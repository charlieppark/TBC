#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "BST.h"
#include "DFS.h"

int main()
{
    FILE* fp_r = fopen("input-3.txt", "r"); // input
    FILE* fp_w = fopen("output.txt", "w"); // output

    if ((fp_r == NULL) || (fp_w == NULL)) // 파일 스트림 open에 실패했다면
    {
        printf("FILE error");
        exit(1);
    }

    int caseNum; // 전체 케이스 수

    while (fscanf(fp_r, "%d", &caseNum) != 1) continue;

    for (int i = 0; i < caseNum; i++)
    {
        int num; // 케이스의 숫자 개수

        while (fscanf(fp_r, "%d", &num) != 1) continue;

        char* str = (char*)malloc(sizeof(char) * 7); // dfs(2), bfs(3) 등을 받는 문자열

        if (str == NULL) // malloc 할당에 실패했다면 (이후 설명 생략)
        {
            printf("MALLOC FAILED ERROR. QUIT PROGRAM.\n");
            exit(1);
        }

        while (fscanf(fp_r, "%s", str) != 1) continue;

        char depthOrBreadth = *str; // 'd'fs인지 'b'fs인지

        int searchNum = *(str + 4) - '0'; // 탐색 횟수

        free(str);

        if (searchNum > num) // searchNum > num일 경우 탐색 횟수가 원소 수보다 많으므로 오류
        {
            printf("SEARCH NUM is wrong. Please input search num smaller than the number of each cases.\n");
            exit(1);
        }

        NODE* tree = NULL;

        for (int j = 0; j < num; j++)
        {
            int elements;

            while (fscanf(fp_r, "%d", &elements) != 1) continue;

            if (addBST(&tree, elements) == false) // 숫자를 BST에 저장
            {
                printf("ADD ERROR. QUIT PROGRAM\n"); // 실패할 경우 ERROR
                exit(1);
            }
        }

        if (depthOrBreadth == 'b') // BFS
        {
            DATA result = 0; // 결과를 받는 포인터

            if (!BFS(tree, &searchNum, &result)) // BFS에 실패했다면
            {
                printf("BFS ERROR. QUIT PROGRAM.\n");
                exit(1);
            }

            fprintf(fp_w, "%d\n", result);
        }
        else if (depthOrBreadth == 'd') // DFS
        {
            DATA result = 0;

            LIST* list = (LIST*)malloc(sizeof(LIST)); // DFS 결과 전체를 받는 list

            if (list == NULL)
            {
                printf("MALLOC FAILED ERROR. QUIT PROGRAM.\n");
                exit(1);
            }

            list->idx = 0;

            DFStoArray(tree, list); // DFS 결과를 list에 저장
            fprintf(fp_w, "%d\n", list->arr[searchNum - 1]); // list에서 탐색 횟수에 해당하는 원소 출력

            free(list);
        }
        else // dfs나 bfs가 아닌 다른 문자열이 들어왔을 경우
        {
            printf("CHOICE ERROR. Choose dfs() or bfs(). QUIT PROGRAM.\n");
            exit(1);
        }
        freeBST(tree);
    }

    fclose(fp_r);
    fclose(fp_w);

    return 0;
}