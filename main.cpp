#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "linkedList_struct.h"

int width = 20, height = 10;
int x, y, fruitX, fruitY, score;
int gameOver;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;
node_t* snake = NULL;
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void gotoxy(short x, short y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void setup() {
    gameOver = 0;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    segment_t start;
    start.x = width / 2;
    start.y = height / 2;
    snake = addBeginning(NULL, start);
    hideCursor();
}

void draw() {
    
    gotoxy(0, 0);
    for (int i = 0; i < width + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) printf("#");

            int printed = 0;
            node_t* temp = snake;
            while (temp != NULL) {
                if (temp->data.x == j && temp->data.y == i) {
                    printf("O");
                    printed = 1;
                    break;
                }
                temp = temp->next;
            }

            if (fruitX == j && fruitY == i && !printed) {
                printf("@");
                printed = 1;
            }

            if (!printed) printf(" ");

            if (j == width - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void logic() {
    segment_t newHead = snake->data;
    switch (dir) {
    case LEFT:  newHead.x--; break;
    case RIGHT: newHead.x++; break;
    case UP:    newHead.y--; break;
    case DOWN:  newHead.y++; break;
    default: return;
    }

    if (newHead.x < 0 || newHead.x >= width || newHead.y < 0 || newHead.y >= height) {
        gameOver = 1;
        return;
    }

    node_t* temp = snake;
    while (temp != NULL) {
        if (temp->data.x == newHead.x && temp->data.y == newHead.y) {
            gameOver = 1;
            return;
        }
        temp = temp->next;
    }

    snake = addBeginning(snake, newHead);

    if (newHead.x == fruitX && newHead.y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    else {
        deleteLast(snake);
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // 100 ms bekle (oyun hýzý)
    }
    return 0;
} 