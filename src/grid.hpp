#pragma once

#include <raylib.h>
#include <vector>
class Grid {
public:
  int grid[20][10];

  Grid();
  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(int row, int col);
  bool IsCellEmpty(int row, int col);

private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};
