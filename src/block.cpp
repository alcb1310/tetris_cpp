#include "block.hpp"
#include "colors.hpp"
#include <vector>

Block::Block() {
  cellSize = 30;
  rotatioState = 0;
  colors = GetCellColors();
}

void Block::Draw() {
  std::vector<Position> tiles = cells[rotatioState];
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1, cellSize - 1,
                  cellSize - 1, colors[id]);
  }
}
