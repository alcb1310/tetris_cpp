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

private:
  // TODO: Add private members
  Grid grid;
  std::vector<Block> blocks;

protected:
  // TODO: Add protected members
};

