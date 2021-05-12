#ifndef __MAZE_H__
#define __MAZE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // 실행 시간 제한을 위해 time.h 사용

extern clock_t start_t;

typedef int Data; // 결과값에 따라 Data 지정
// 현재는 int 범위 안에서 결과값이 나오므로 int로 지정

Data* read_maze(FILE*, int, int);
void print_maze(Data*, int, int, FILE*);
Data clockwise_way(Data*, int, int, int, int, Data*, char);
Data counter_way(Data*, int, int, int, int, Data*, char);
Data find_way(Data*, int, int, int, int, Data*);
//Data* pave(Data*, int, int, Data*, Data*);
Data* reverse(Data*, int, int);

#endif
