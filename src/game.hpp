#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "constants.hpp"

class Game {
public:
  Game() {
    // This is the constructor
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mine");
    SetTargetFPS(FPS);
  }

  ~Game() {
    // This is the destructor
    CloseWindow();
  }

  void run() {
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      EndDrawing();
    }
  }

private:
  // TODO: Add private members

protected:
  // TODO: Add protected members
};

#endif // !GAME_HPP 
