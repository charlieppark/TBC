#include "maze.h"

Data* reverse(Data* maze, int row, int col)
{
	Data* reversed = (Data*)malloc(sizeof(Data) * row * col); // 180도 회전을 위해 미로와 같은 크기의 배열 할당

	if (reversed == NULL) // 제대로 할당되지 않았을 경우
	{
		printf("reverse() malloc error"); // 에러 메시지 출력
		exit(1); // 프로그램 종료
	}

	// 180도 회전
	for (int i = 0; i < row * col; i++) // 미로의 모든 원소에 대해서
	{
		*(reversed + i) = *(maze + row * col - 1 - i); // 회전축이 되는 점에 점 대칭인 원소를 저장
	}

	return reversed; // 회전된 배열 반환
}

Data* read_maze(FILE* fp, int row, int col)
{
	Data* maze = (Data*)malloc(sizeof(Data) * row * col); // 미로를 읽어서 저장할 배열

	if (maze == NULL)
	{
		printf("malloc error");
		exit(1);
	}

	for (int j = 0; j < row; j++)
	{
		int temp_int;

		for (int k = 0; k < col; k++)
		{
			while (fscanf(fp, "%d", &temp_int) != 1) continue; // 미로를 읽어서

			*(maze + j * col + k) = temp_int; // 배열에 저장
		}
	}

	return maze; // 저장한 배열 반환
}

void print_maze(Data* maze, int row, int col, FILE* fp)
{
	if (maze == NULL) // 길이 없는 경우
	{
		fprintf(fp, "0\n"); // fp에 0 출력
		return;
	}
	else // 길이 있는 경우
	{
		fprintf(fp, "%d\n", *(maze + row * col - 1) - 1); // 미로 도착지점의 값을 fp에 저장
		return;
	}
}

Data clockwise_way(Data* m, int cur_r, int cur_c, int r, int c, Data* v, char t)
{
	if (t) // 0이 아닌 경우, t초의 실행 제한 시간을 가짐
	{
		clock_t process_t = clock(); // 실행 제한 시간을 확인할 시간 변수

		if (( ((double)process_t - (double)start_t) / CLOCKS_PER_SEC) > (float)t) // 실행 제한 시간을 넘기면
			return -2;
	}

	int result;

	*(v + (r - cur_r) * c + (c - cur_c)) = 1; // 방문한 지점 표시

	if (cur_r * cur_c == 1) // 도착 지점에 도착시
	{
		*m = 2; // 도착 지점 체크
		*(v + (r - cur_r) * c + (c - cur_c)) = 0; // 방문을 미방문으로 바꿈
		return 1; // 값이 있음을 반환
	}
	else
	{
		if ((*(m - c) == 1) && cur_r < r && *(v + (r - cur_r) * c + (c - cur_c) - c) != 1)
		// 위 방향에 길이 있음 and 위로 갔을 때 배열을 벗어나지 않음 and 방문한 지점이 아닐 때
		{
			if (result = clockwise_way(m - c, cur_r + 1, cur_c, r, c, v, t))
			// 위 방향의 점을 시작점으로 하는 미로를 인자로 넘겨 재귀 호출
			// 길이 있을 때 분기문 진입
			{
				if (result < 0) // 시간이 지났다면
					return result; // 반환
				return result; // 시간이 지나지 않았을때 결과 반환
			}
		}

		if ((*(m + 1) == 1) && (cur_c > 1) && *(v + (r - cur_r) * c + (c - cur_c) + 1) != 1)
		// 오른쪽에 길이 있음 and 오른쪽으로 갔을 때 배열을 벗어나지 않음 and 방문한 지점이 아닐 때
		{
			if (result = clockwise_way(m + 1, cur_r, cur_c - 1, r, c, v, t))
			{
				if (result < 0)
					return result;
				return result;
			}
		}

		if ((*(m + c) == 1) && (cur_r > 1) &&  *(v + (r - cur_r) * c + (c - cur_c) + c) != 1)
		// 아래 방향에 길이 있음 and 아래로 갔을 때 배열을 벗어나지 않음 and 방문한 지점이 아닐 때
		{
			if (result = clockwise_way(m + c, cur_r - 1, cur_c, r, c, v, t))
			{
				if (result < 0)
					return result;
				return result;
			}
		}

		*(v + (r - cur_r) * c + (c - cur_c)) = 0;
		// 길이 없을 때 되돌아오며 방문하지 않은 점으로 표시

		return 0;
	}
}

Data counter_way(Data* m, int cur_r, int cur_c, int r, int c, Data* v, char t)
{
	Data* reversed = reverse(m, r, c); // 인자로 들어온 미로를 180도 회전하여 저장

	int result = clockwise_way(reversed, r, c, r, c, v, t); //180도 회전한 배열을 시계 방향 순으로 탐색

	Data* temp = reverse(reversed, r, c); // 탐색을 마친 결과를 180도 회전 -> 총 360도 회전으로 원래 상태

	memcpy(m, temp, sizeof(Data) * r * c); // 탐색 결과를 m에 복사

	free(temp);
	free(reversed);

	return result;
}

// Report에 설명이 있어 주석 생략
Data find_way(Data* m, int cur_r, int cur_c, int r, int c, Data* v)
{
	int out = 0;

	*(v + (r - cur_r) * c + (c - cur_c)) = 1;

	if (*(m + cur_r * cur_c - 1) > 1000000)
		return -1;

	if (cur_r * cur_c == 1)
	{
		*m += 1;
		*(v + (r - cur_r) * c + (c - cur_c)) = 0;
		return 1;
	}
	else
	{
		int existence = 0;

		if ((*(m - c) > 0) && cur_r < r && *(v + (r - cur_r) * c + (c - cur_c) - c) != 1)
		{
			if (out = find_way(m - c, cur_r + 1, cur_c, r, c, v))
			{
				if (out < 0)
					return out;

				existence = 1;
			}
		}		

		if ((*(m + 1) > 0) && (cur_c > 1) &&  *(v + (r - cur_r) * c + (c - cur_c) + 1) != 1)
		{
			if (out = find_way(m + 1, cur_r, cur_c - 1, r, c, v))
			{
				if (out < 0)
					return out;

				existence = 1;
			}
		}

		if ((*(m + c) > 0) && (cur_r > 1) &&  *(v + (r - cur_r) * c + (c - cur_c) + c) != 1)
		{
			if (out = find_way(m + c, cur_r - 1, cur_c, r, c, v))
			{
				if (out < 0)
					return out;

				existence = 1;
			}
		}

		*(v + (r - cur_r) * c + (c - cur_c)) = 0;

		return existence;
	}
}

/*
Data* pave(Data* way, int row, int col, Data* clock, Data* counter)
{
	for (int i = 1; i < col; i++)
	{
		for (int j = 1; j < row; j++)
		{
			if ((*(clock + j * col + i) == 2) && (*(clock + (j - 1) * col + i) != 2))
			{
				*(way + (j - 1) * col + i) = 0;
				break;
			}
		}
	}

	for (int i = col - 2; i >= 0; i--)
	{
		for (int j = row - 2; j >= 0; j--)
		{
			if ((*(counter + j * col + i) == 2) && (*(counter + (j + 1) * col + i) != 2))
			{
				*(way + (j + 1) * col + i) = 0;
				break;
			}
		}
	}

	return way;
}

*/