#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 20

void initializeGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

void printGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x] ? '*' : ' ');
        }
        printf("\n");
    }
}

int getNeighborCount(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int newX = (x + dx + WIDTH) % WIDTH;
            int newY = (y + dy + HEIGHT) % HEIGHT;
            count += grid[newY][newX];
        }
    }
    return count;
}

void updateGrid(int grid[HEIGHT][WIDTH]) {
    int newGrid[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = getNeighborCount(grid, x, y);
            if (grid[y][x] == 1) {
                newGrid[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                newGrid[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = newGrid[y][x];
        }
    }
}

int main() {
    int grid[HEIGHT][WIDTH];
    initializeGrid(grid);

    while (1) {
        printGrid(grid);
        updateGrid(grid);
        usleep(200000); 
        system("clear");
    }

    return 0;
}
