CC = gcc
CFLAGS = -I/opt/homebrew/Cellar/glfw/3.3.9/include -O2 
LDFLAGS = -L/opt/homebrew/Cellar/glfw/3.3.9/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -lm

main: main.o
    $(CC) -o main main.o $(LDFLAGS)

main.o: main.c
    $(CC) -c main.c $(CFLAGS)