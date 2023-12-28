#include <stdio.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 30

char map[HEIGHT][WIDTH];
int playerX = 1;
int playerY = 1;
int score = 0;

void initializeMap()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == 0 || x == WIDTH - 1)
                map[y][x] = '|';
            else if (y == 0 || y == HEIGHT - 1)
                map[y][x] = '_';
            else if (y == 3 && x == 2)
                map[y][x] = '#';
            else if (y == 7 && x == 5)
                map[y][x] = '#';
            else if (y == 1 && x == 9)
                map[y][x] = '#';
            else if (y == 6 && x == 3)
                map[y][x] = '#';
            else
                map[y][x] = ' ';
        }
    }
    map[playerY][playerX] = '0';
    map[3][4] = '*';
    map[5][8] = '*';
    map[7][2] = '*';
    map[9][6] = '*';
    map[10][10] = '*';
    map[3][9] = '*';
    map[2][2] = '*';

    map[1][1] = '*';
    map[4][3] = '*';

    map[6][5] = '*';
    map[8][7] = '*';
    map[15][9] = '*';
}

void printMap()
{
    system("clear");
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void movePlayer(int dx, int dy)
{
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (map[newY][newX] == ' ' || map[newY][newX] == '*')
    {
        if (map[newY][newX] == '*')
        {
            score++;
        }
        map[playerY][playerX] = ' ';
        playerY = newY;
        playerX = newX;
        map[playerY][playerX] = '^';
    }
}

int main()
{
    initializeMap();
    char input;
    do
    {
        printMap();
        scanf(" %c", &input);
        switch (input)
        {
        case 'w':
            movePlayer(0, -1);
            break;
        case 'a':
            movePlayer(-1, 0);
            break;
        case 's':
            movePlayer(0, 1);
            break;
        case 'd':
            movePlayer(1, 0);
            break;
        }
    } while (input != 'q');
    return 0;
}