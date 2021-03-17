#include <iostream>
#include "MinesweeperBoard.h"

#define min(x, y) x<y ? x:y

MinesweeperBoard::MinesweeperBoard(int wysokosc, int szerokosc){
    width = min(szerokosc, 100);
    height = min(wysokosc, 100);
    Field pole;
    pole.hasMine = false;
    pole.hasFlag = false;
    pole.isRevealed = false;

    for(int y = 0; y < height; y++){
      for(int x = 0; x < width; x++){     //based
        board[y][x] = pole;
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