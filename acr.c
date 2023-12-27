#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 30

int main() {
    char screen[WIDTH * HEIGHT];
    const char* logo = "CDLI";
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
