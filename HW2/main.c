#define _CRT_SECURE_NO_WARNINGS

#define MAX_LEN 100

#include <stdlib.h>
#include "postFixEvaluate.h"

int main()
{
	FILE* fp_r = fopen("input-1.txt", "r"); // input-1.txt를 읽는 파일 스트림을 fp_r에 할당

	FILE* fp_w = fopen("output.txt", "w"); // output.txt를 쓰는 파일 스트림을 fp_w에 할당

	if ((fp_r == NULL) || (fp_w == NULL)) // 제대로 할당되지 않았을 경우
	{
		printf("FILE error"); // 에러 메시지 출력
		exit(1); // 프로그램 종료
	}

	int N;

	while (fscanf(fp_r, "%d", &N) != 1) continue; // N에 전체 케이스 수 저장

	for (int i = 0; i < N; i++)
	{
		char s[MAX_LEN];

		while (fscanf(fp_r, "%s", s) != 1) continue; // 수식을 s에 저장

		Data result;

		if (postFixEval(s, &result)) // 수식 계산 결과를 result에 저장 -- 계산에 성공했다면
			fprintf(fp_w, FORMAT, result); 
		else // 계산에 실패했다면
			fprintf(fp_w, "0\n");
	}

	fclose(fp_r);
	fclose(fp_w);

	return 0;
}