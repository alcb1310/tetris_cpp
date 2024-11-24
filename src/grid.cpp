#include "grid.hpp"
#include "colors.hpp"
#include <iostream>
#include <raylib.h>
#include <vector>

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;

  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      grid[row][col] = 0;
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << grid[row][col] << " ";
    }

    std::cout << std::endl;
  }
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellValue = grid[row][col];
      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int col) {
  return row < 0 || row >= numRows || col < 0 || col >= numCols;
}

bool Grid::IsCellEmpty(int row, int col) { return grid[row][col] == 0; }
