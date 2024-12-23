#include "block.hpp"
#include "colors.hpp"
#include <vector>

Block::Block() {
  cellSize = 30;
  rotationState = 0;
  rowOffset = 0;
  colOffset = 0;
  colors = GetCellColors();
}

void Block::Draw() {
  std::vector<Position> tiles = GetCelPositions();
  for (Position item : tiles) {
    DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, colors[id]);
  }
}

void Block::Move(int rows, int cols) {
  rowOffset += rows;
  colOffset += cols;
}

std::vector<Position> Block::GetCelPositions() {
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;
  for (Position &item : tiles) {
    Position newPosition = Position(item.row + rowOffset, item.col + colOffset);
    movedTiles.push_back(newPosition);
  }

  return movedTiles;
}

void Block::Rotate() { rotationState = (rotationState + 1) % cells.size(); }

void Block::UndoRotate() {
  rotationState--;
  if (rotationState < 0) {
    rotationState = cells.size() - 1;
  }
}
