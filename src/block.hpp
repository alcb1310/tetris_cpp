#pragma once

#include "position.hpp"
#include <map>
#include <raylib.h>
#include <vector>

class Block {
public:
  int id;
  std::map<int, std::vector<Position>> cells;
  void Draw();
  void Move(int rows, int cols);

  Block();

private:
  int cellSize;
  int rotatioState;
  int rowOffset;
  int colOffset;

  std::vector<Color> colors;
  std::vector<Position> GetCelPositions();

protected:
};
