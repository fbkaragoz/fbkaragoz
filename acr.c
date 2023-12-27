#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>


#define WIDTH 50
#define HEIGHT 30

int main() {
    char screen[WIDTH * HEIGHT];
    const char* logo = "CDLI";
    int frame = 0;
    int logoLength = strlen(logo);
    int logoPosition = WIDTH;

    while (1){
        memset(screen, ' ', WIDTH * HEIGHT);
        int startPos = (logoPosition % (WIDTH + logoLength)) - logoLength;
        for (int i = 0; i < logoLength; ++i){
            int x = startPos + i;
            if (x >= 0 && x < WIDTH){
                screen[HEIGHT / 2 * WIDTH + x] = logo[i];
            }
        for (int x = 0; x<WIDTH; ++x){
            int waveHeight = (sin(frame * 0.1 + x * 0.2) + 1) * (HEIGHT / 3);
            int y = HEIGHT / 2 + waveHeight;

            if (y >= 0 && y < HEIGHT) {
                screen[y * WIDTH + x] = '*';
            }
        }
        }
        printf("\033[H");
        for (int i = 0; i<HEIGHT; i++){
            for (int j = 0; j<WIDTH; j++){
                putchar(screen[i * WIDTH + j]);

            }
            putchar('\n');
        }
        --logoPosition;
        if (logoPosition < -logoLength){
            logoPosition = WIDTH;

        }
        usleep(100000);
    }
}
