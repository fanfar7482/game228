#include <iostream>
#include "raylib/5.5/include/raylib.h"
#include "raylib/5.5/include/raymath.h"
#include <random>
#include <chrono>
#include <thread>

struct Cell {
    Rectangle rec;
    Color color;
};

std::vector<std::vector<Cell>> board;
int BOARD_ROWS, BOARD_COLS;

void initBoard(int rows, int cols, float cellSize) {
    BOARD_ROWS = rows;
    BOARD_COLS = cols;

    board.clear();
    board.resize(rows, std::vector<Cell>(cols));

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            board[row][col].rec = {col * cellSize, row * cellSize, cellSize, cellSize};
            board[row][col].color = DARKGRAY;
        }
    }
}

void setCellColor(int row, int col, Color color) {
    if (row < 0 || row >= BOARD_ROWS) return;
    if (col < 0 || col >= BOARD_COLS) return;

    board[row][col].color = color;
}

void drawBoard() {
    for (int row = 0; row < BOARD_ROWS; row++) {
        for (int col = 0; col < BOARD_COLS; col++) {
            const Cell& cell = board[row][col];
            DrawRectangleRec(cell.rec, cell.color);
            DrawRectangleLines(cell.rec.x, cell.rec.y, cell.rec.width, cell.rec.height, PINK);
        }
    }
}

void start() {

}

int main() {

    int windowX = 1920, windowY = 1080;
    
    InitWindow(windowX, windowY, "qwerty");
    initBoard(24, 52, 30);
    setCellColor(12, 26, RED);
    
    while(!WindowShouldClose()) {
        
        BeginDrawing();

        drawBoard();

        EndDrawing();
    }

    return 0;
}