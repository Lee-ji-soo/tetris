#include <iostream>
using namespace std;

int block[4][4] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0};

int mobiles[7][4][4] = {
    {
        1,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
    },
    {
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        0,
        1,
        0,
        0,
        0,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        0,
        1,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        1,
        1,
        0,
        0,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    },
    {
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    },
};

void setBlock()
{
    srand(time(0));

    int r = rand() % 3; // 0 ~ 1

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            block[y][x] = mobiles[r][y][x];
        }
    }
}

void spin()
{
    // turn 90 degree

    int temp[4][4] = {0};

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            temp[x][3 - y] = block[y][x]; // turn 90 dgree
        }
    }

    memcpy(block, temp, 64); // 4byte * 16;
    void pull();
    pull();
}

void pull()
{
    // 1.minY, minX
    // 2. temp
    // 3. block to temp move to Zeropoint
    // 4. temp to block memcpy

    int temp[4][4] = {0};
    int minY = 99;
    int minX = 99;

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (block[y][x] == 1)
            {
                if (minY > y)
                {
                    minY = y;
                }
                if (minX > x)
                {
                    minX = x;
                }
            }
        }
    }

    for (int y = minY; y < 4; y++)
    {
        for (int x = minX; x < 4; x++)
        {
            temp[y - minY][x - minX] = block[y][x];
        }
    }

    memcpy(block, temp, 64);
}