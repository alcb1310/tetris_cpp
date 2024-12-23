#include "game.hpp"
#include "constants.hpp"
#include <cstdlib>
#include <raylib.h>

Game::Game() {
  // This is the constructor
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mine");
  SetTargetFPS(FPS);

  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  lastUpdateTime = 0;
  gameOver = false;
}

Game::~Game() {
  // This is the destructor
  CloseWindow();
}

void Game::Run() {

  while (!WindowShouldClose()) {
    HandleInput();

    if (EventTriggered(0.1)) {
      MoveBlockDown();
    }

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

void Game::HandleInput() {
  int key = GetKeyPressed();
  if (gameOver) {
    if (key != 0) {
      Reset();
    } else {
      return;
    }
  }

  switch (key) {
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    break;
  case KEY_UP:
    RotateBlock();
    break;
  }
}

void Game::MoveBlockLeft() {
  currentBlock.Move(0, -1);
  if (IsBlockOutside() || !BlockFits()) {
    currentBlock.Move(0, 1);
  }
}

void Game::MoveBlockRight() {
  currentBlock.Move(0, 1);
  if (IsBlockOutside() || !BlockFits()) {
    currentBlock.Move(0, -1);
  }
}

void Game::MoveBlockDown() {
  currentBlock.Move(1, 0);
  if (IsBlockOutside() || !BlockFits()) {
    currentBlock.Move(-1, 0);
    LockBlock();
  }
}

bool Game::IsBlockOutside() {
  std::vector<Position> tiles = currentBlock.GetCelPositions();
  for (Position item : tiles) {
    if (grid.IsCellOutside(item.row, item.col)) {
      return true;
    }
  }

  return false;
}

void Game::RotateBlock() {
  currentBlock.Rotate();
  if (IsBlockOutside() || !BlockFits()) {
    currentBlock.UndoRotate();
  }
}

bool Game::EventTriggered(double inteval) {
  double currentTime = GetTime();

  if (currentTime - lastUpdateTime >= inteval) {
    lastUpdateTime = currentTime;
    return true;
  }

  return false;
}

void Game::LockBlock() {
  std::vector<Position> tiles = currentBlock.GetCelPositions();

  for (Position item : tiles) {
    grid.grid[item.row][item.col] = currentBlock.id;
  }

  currentBlock = nextBlock;
  if (!BlockFits()) {
    gameOver = true;
    return;
  }

  nextBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::BlockFits() {
  std::vector<Position> tiles = currentBlock.GetCelPositions();

  for (Position item : tiles) {
    if (!grid.IsCellEmpty(item.row, item.col)) {
      return false;
    }
  }

  return true;
}

void Game::Reset() {
  grid.Initialize();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  lastUpdateTime = 0;
  gameOver = false;
}
