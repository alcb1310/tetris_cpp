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
  std::vector<Position> GetCelPositions();
  void Rotate();
  void UndoRotate();

  Block();

private:
  int cellSize;
  int rotationState;
  int rowOffset;
  int colOffset;

  std::vector<Color> colors;

protected:
};
