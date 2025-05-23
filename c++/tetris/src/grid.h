#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Init();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullCRows();
    int grid[20][10];

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int rows);
    int rows;
    int cols;
    int cellSize;
    std::vector<Color> colors;
};