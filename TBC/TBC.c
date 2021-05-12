#include "maze.h"

clock_t start_t; //maze_find 함수에 인자를 추가하지 않고 전역변수로 넘김

int main()
{
	FILE* fp_r = fopen("input.txt", "r"); // input.txt를 읽는 파일 스트림을 fp_r에 할당

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
		printf("%d\n", i);

		int row, col;

		while (fscanf(fp_r, "%d %d", &row, &col) != 2) continue; // 각 케이스의 행과 열을 row, col에 저장

		Data* maze = (Data*)malloc(sizeof(Data) * row * col); // 미로를 담는 Data 포인터 할당

		Data* clock_w = (Data*)malloc(sizeof(Data) * row * col); // 최상위 경로를 담는 Data 포인터 할당

		Data* counter_w = (Data*)malloc(sizeof(Data) * row * col); // 최하위 경로를 담는 Data 포인터 할당

		Data* visited = (Data*)calloc(row * col, sizeof(Data)); // 방문한 경로를 담는 Data 포인터 할당

		if ((maze == NULL) || (clock_w == NULL) || (counter_w == NULL) || (visited == NULL)) // 제대로 할당되지 않았을 경우
		{
			printf("malloc error"); // 에러 메시지 출력
			exit(1); // 프로그램 종료
		}

		maze = read_maze(fp_r, row, col); // read_maze를 통해 미로를 읽어들임

		memcpy(clock_w, maze, sizeof(Data) * row * col); // clockwise_way() 호출 전 미로 저장

		memcpy(counter_w, maze, sizeof(Data) * row * col); // counter_way() 호출 전 미로 저장

		start_t = clock(); // 제한 시간을 측정하기 위한 시간 변수

		if (counter_way(counter_w, row, col, row, col, visited, 1) != 0)
		// 도착지점에서 제한시간 내에 탐색 시 경로가 없는 경우가 아니라면 if 문 진입
		{
			memset(visited, 0, sizeof(Data) * row * col);
			// 방문한 경로 0으로 초기화

			if (clockwise_way(clock_w, row, col, row, col, visited, 0)) // 길이 있다면
			{
				memset(visited, 0, sizeof(Data) * row * col);
				find_way(maze, row, col, row, col, visited); // 전체 경로 탐색
					
				print_maze(maze, row, col, fp_w); // 총 경로 수 output.txt로 출력
			}
			else
			{
				print_maze(NULL, row, col, fp_w); // 경로 없음을 output.txt로 출력
			}
		}
		else
		{
			print_maze(NULL, row, col, fp_w); // 경로 없음을 output.txt로 출력
		} 
		free(clock_w);
		free(counter_w);
		free(visited);
		free(maze);
	}

	fclose(fp_r);
	fclose(fp_w);


	return 0;
}
