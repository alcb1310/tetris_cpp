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
  double lastUpdateTime;
  bool gameOver;

  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  bool IsBlockOutside();
  void RotateBlock();
  bool EventTriggered(double interval);
  void LockBlock();
  bool BlockFits();
  void Reset();

protected:
  // TODO: Add protected members
};
