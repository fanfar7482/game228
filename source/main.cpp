#include <iostream>
#include "raylib/5.5/include/raylib.h"
#include "raylib/5.5/include/raymath.h"
#include <random>
#include <chrono>
#include <thread>

void drawBoard(int rows, int cols, float cellSize) {

    Rectangle r1 = {0, 0, cellSize, cellSize};

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            r1.x = col * cellSize;
            r1.y = row * cellSize;

            DrawRectangleRec(r1, GREEN);
            DrawRectangleLinesEx(r1, (cellSize / 80), GRAY);
        }
    }
}

int main() {

    int windowX = 1920, windowY = 1080;
    
    InitWindow(windowX, windowY, "qwerty");
    
    while(!WindowShouldClose()) {
        
        BeginDrawing();

        drawBoard(24, 54, 30);

        EndDrawing();
    }

    return 0;
}