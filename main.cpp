#include <iostream>
#include "MinesweeperBoard.h"

void intro(){
  std::cout << "Milosz xxx032" << std::endl;
}

int main(){
  intro()
  ;MinesweeperBoard kek = MinesweeperBoard(10, 10, HARD) //wysokość, szerokość
  ;kek.debug_display()
;}