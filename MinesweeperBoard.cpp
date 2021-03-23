#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int wysokosc, int szerokosc, GameMode mode){
  width = std::min(szerokosc, 100);
  height = std::min(wysokosc, 100);
  maxMines = wysokosc*szerokosc*mode/10;
  int remainingFields = wysokosc*szerokosc;
  srand (time(NULL));
  stan_gry = RUNNING;
  pierwszy_ruch = true;

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){     //based
      if(mode == DEBUG){
        if(y == 0 || (x == 0 && y%2 == 0) || x == y){
          setField(y, x, true, false, true);
        }else{
          setField(y, x, false, false, true);
        }
      }else{
        if((maxMines > 0 && mode >= rand()%10+1) || remainingFields <= maxMines){
          setField(y, x, true, false, false);
          maxMines--;
        }else{
          setField(y, x, false, false, false);
        }
      }
      remainingFields--;
    }
  }
}

int MinesweeperBoard::getBoardWidth() const{
  return width;
}

int MinesweeperBoard::getBoardHeight() const{
  return height;
}

int MinesweeperBoard::getMineCount() const{
  return maxMines;
}

int MinesweeperBoard::countMines(int y, int x) const{
  if(board[y][x].isRevealed == false || y > height || x > width || y < 0 || x < 0){
    return -1;
  }else{
    int number_of_mines = 0;
    for(int i = -1; i <= 1; i++){
      for(int j = -1; j <= 1; j++){
        if((i == 0 && j == 0) || y+i > height || x+j > width || y+i < 0 || x+j < 0){
          continue;
        }else{
          if(board[y+i][x+j].hasMine == true){
            number_of_mines++;
          }else{
            continue;
          }
        }
      }
    }
    return number_of_mines;
  }
}

bool MinesweeperBoard::hasFlag(int y, int x) const{
  if(board[y][x].hasFlag == true){
    return true;
  }else{
    if(board[y][x].isRevealed == true || board[y][x].hasFlag == false || y > height || x > width || y < 0 || x < 0){
      return false;
    }
  }
}

void MinesweeperBoard::debug_display() const{
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      std::cout << "[" << (board[y][x].hasMine ? "M":".") << (board[y][x].hasFlag ? "o":".") << (board[y][x].isRevealed ? "f":".") << "]";
    }
    std::cout << std::endl;
  }
}

void MinesweeperBoard::setField(int y, int x, bool mina, bool flaga, bool odkryte){
  board[y][x].hasMine = mina;
  board[y][x].hasFlag = flaga;
  board[y][x].isRevealed = odkryte;
}

void MinesweeperBoard::toggleFlag(int y, int x){
  if(board[y][x].isRevealed == false && stan_gry == RUNNING && y < height && x < width && y >= 0 && x >= 0){
    board[y][x].hasFlag = !board[y][x].hasFlag; //negacja
  }
}

void MinesweeperBoard::revealField(int y, int x){
  if(board[y][x].isRevealed == true || y > height || x > width || y < 0 || x < 0 || stan_gry != RUNNING || board[y][x].hasFlag == true){
  }else{
    if(board[y][x].isRevealed == false && board[y][x].hasMine == false){
      board[y][x].isRevealed = !board[y][x].isRevealed;
    }else{
      if(pierwszy_ruch == true && board[y][x].hasMine == true){
        while(true){
          int x1, y1 = 0;
          x1 = rand()%width;
          y1 = rand()%height;
          if(board[y1][x1].hasMine == false){
            board[y][x].hasMine = false;
            board[y1][x1].hasMine = true;
            break;
          }
        }
        board[y][x].isRevealed = true;
      }else{
        stan_gry = FINISHED_LOSS;
      }
    }
  }
}

bool MinesweeperBoard::isRevealed(int y, int x) const{
  if(board[y][x].isRevealed == true){
    return true;
  }else{
    return false;
  }
}

GameState MinesweeperBoard::getGameState() const{
  
}