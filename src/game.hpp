#ifndef GAME_HPP
#define GAME_HPP

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

    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[17][8] = 7;

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
      EndDrawing();
    }
  }

private:
  // TODO: Add private members
  Grid grid;

protected:
  // TODO: Add protected members
};

#endif // !GAME_HPP
