#include <iostream>
#include "block.h"
#include <windows.h>
using namespace std;

int dy = 0;
int dx = 3;

int map[10][10] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void print()
{
    system("cls");

    int buf[10][10];
    memcpy(buf, map, 10 * 10 * 4);

    // block to buf
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (block[y][x] == 1)
            {
                buf[dy + y][dx + x] = 1;
            }
        }
    }

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (buf[y][x] == 0)
            {
                cout << ' ';
            }
            else
            {
                cout << '#';
            }
        }
        cout << endl;
    }
}

int down()
{
    if (isStack(dy + 1, dx) == 0)
    {
        dy++;
        return 0;
    }

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (block[y][x] == 0)
                continue;
            map[dy + y][dx + x] = 1;
        }
    }

    setBlock();

    dy = 0;
    dx = 3;
    return 0;
}

int main()
{
    setBlock();
    while (1)
    {
        print();
        if (GetAsyncKeyState(VK_UP) & 0x8001)
        {
            spin();
            if (isStack(dy, dx) == 1)
            {
                spin();
                spin();
                spin();
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            down();
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            if (isStack(dy, dx + 1) == 0)
                dx++;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            if (isStack(dy, dx - 1) == 0)
                dx--;
        }
        Sleep(100);
    }
    return 0;
};
