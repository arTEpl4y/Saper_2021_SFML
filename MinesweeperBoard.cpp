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