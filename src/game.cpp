#include "game.hpp"
#include "constants.hpp"

Game::Game() {
  // This is the constructor
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mine");
  SetTargetFPS(FPS);

  grid = Grid();
  blocks = {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

Game::~Game() {
  // This is the destructor
  CloseWindow();
}

void Game::Run() {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARK_BLUE);

    grid.Draw();
    blocks[4].Draw();
    EndDrawing();
  }
}
