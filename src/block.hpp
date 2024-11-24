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

  Block();

private:
  int cellSize;
  int rotatioState;

  std::vector<Color> colors;

protected:
};
