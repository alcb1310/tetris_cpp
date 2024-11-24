#include "game.hpp"
#include "constants.hpp"
#include <cstdlib>

Game::Game() {
  // This is the constructor
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mine");
  SetTargetFPS(FPS);

  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

Game::~Game() {
  // This is the destructor
  CloseWindow();
}

void Game::Run() {

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARK_BLUE);

    Draw();
    EndDrawing();
  }
}

Block Game::GetRandomBlock() {
  if (blocks.empty()) {
    blocks = GetAllBlocks();
  }

  int randomIndex = rand() % blocks.size();

  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);

  return block;
}

std::vector<Block> Game::GetAllBlocks() {
  return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();
}
