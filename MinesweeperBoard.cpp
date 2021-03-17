#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int wysokosc, int szerokosc, GameMode mode){
  width = std::min(szerokosc, 100);
  height = std::min(wysokosc, 100);
  int maxMines = wysokosc*szerokosc*mode/10;
  int remainingFields = wysokosc*szerokosc;
  srand (time(NULL));
  stan_gry = RUNNING;
  pierwszy_ruch = true;

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){     //based
      if(mode == DEBUG){
        if(y == 0 || (x == 0 && y%2 == 0) || x == y){
          setField(y, x, true, false, false);
        }else{
          setField(y, x, false, false, false);
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