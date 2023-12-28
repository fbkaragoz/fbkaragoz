#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

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
                if (x == 0 || x == WIDTH - 1) map[y][x] = '|';
                else if (y == 0 || y == HEIGHT - 1) map[y][x] = '-';
                else map[y][x] = ' ';
            }

        } 
        map[playerY][playerX] = '0';
        map[3][4] = '*';
        map[5][8] = '*';
        map[7][2] = '*';
        map[9][6] = '*';

    }

void printMap() {
    system("clear");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);

}

void movePlayer(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (map[newY][newX] == ' ' || map[newY][newX] == '*') {
        if (map[newY][newX] == '*') {
            score++;
        }
        map[playerY][playerX] = ' ';
        playerY = newY;
        playerX = newX;
        map[playerY][playerX] = '0';
    }
}

int main() {
    initializeMap();
    char input;
    do {
        printMap();
        scanf(" %c", &input);
        switch (input) {
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