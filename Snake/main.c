/*
  main.c
  Snake
  Created by Chan Ho Park on 2021.4.27.
*/

#include <Windows.h> // COORD
#include <conio.h> // _kbhit(), _getch()
#include <stdbool.h> // bool

void gotoxy(int x, int y);
void move_point(int x, int y);
void move_direction(int dir, int* x, int* y);
void hidecursor();
void map(int size);
bool collide_wall();

const int map_size = 50;

#include <stdio.h>

int main()
{
    hidecursor();

    map(map_size);

    int x = map_size / 2 + 2;
    int y = map_size / 2 + 2;

    gotoxy(x, y);
    
    int key_in = 0;

    while (1)
    {
        if (_kbhit())
        {
            key_in = _getch();

            if (key_in == 224)
            {
                key_in = _getch();

                move_direction(key_in, &x, &y);
            }
        }
    }
    

    return 0;
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void map(int size)
{
    for (int i = 0; i < size + 2; i++)
    {
        printf("□");
        
        for (int j = 0; j < size; j++)
        {
            if ((i == 0) || (i == size + 1))
            {
                printf("□");
            }
            else
            {
                printf("  ");
            }
        }

        printf("□\n");
    }

}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void move_point(int x, int y)
{
    gotoxy(x, y);
    printf("■");
}

void move_direction(int dir, int* x, int* y)
{
    switch (dir)
    {
    case 72: // ↑
        while ((!_kbhit()) && !collide_wall())
        {
            system("cls");
            map(map_size);
            *y += 2;
            move_point(*x, *y);
        }
        break;
    case 80: // ↓
        while ((!_kbhit()) && !collide_wall())
        {
            system("cls");
            map(map_size);
            *y -= 2;
            move_point(*x, (*y)--);
        }
        break;

    case 75: // ←
        while ((!_kbhit()) && !collide_wall())
        {
            system("cls");
            map(map_size);
            *x -= 2;
            move_point((*x)--, *y);
        }
        break;

    case 77: // →
        while ((!_kbhit()) && !collide_wall())
        {
            system("cls");
            map(map_size);
            *x += 2;
            move_point((*x)++, *y);
        }
        break;
    default:
        break;
    }
}

bool collide_wall()
{
    CONSOLE_SCREEN_BUFFER_INFO pCur;

    COORD pos;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pCur);

    pos.X = pCur.dwCursorPosition.X;

    pos.Y = pCur.dwCursorPosition.Y;

    if ((pos.X == map_size * 2) || (pos.X == 0) || (pos.Y == map_size * 2) || (pos.Y == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}