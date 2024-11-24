#pragma once

#include "block.hpp"
#include "blocks.cpp"
#include "grid.hpp"
#include <raylib.h>
#include <vector>

class Game {
public:
  Game();

  ~Game();

  void Run();
  void Draw();

  void HandleInput();

private:
  // TODO: Add private members
  Grid grid;
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;

  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  bool IsBlockOutside();

protected:
  // TODO: Add protected members
};
