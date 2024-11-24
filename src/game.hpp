#ifndef GAME_HPP
#define GAME_HPP

#include "blocks.cpp"
#include "constants.hpp"
#include "grid.hpp"
#include <raylib.h>

class Game {
public:
  Game() {
    // This is the constructor
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mine");
    SetTargetFPS(FPS);

    grid = Grid();
    grid.Print();
  }

  ~Game() {
    // This is the destructor
    CloseWindow();
  }

  void run() {
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(DARK_BLUE);

      grid.Draw();
      zBlock.Draw();
      EndDrawing();
    }
  }

private:
  // TODO: Add private members
  Grid grid;
  LBlock lblock;
  JBlock jBlock;
  IBlock iBlock;
  OBlock oBlock;
  SBlock sBlock;
  TBlock tBlock;
  ZBlock zBlock;

protected:
  // TODO: Add protected members
};

#endif // !GAME_HPP
