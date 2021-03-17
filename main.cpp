#include <iostream>
#include "MinesweeperBoard.h"

void intro(){
  std::cout << "Milosz xxx032" << std::endl;
}

int main(){
  intro();
  MinesweeperBoard kek = MinesweeperBoard(6, 9); //wysokość, szerokość
  
  kek.setField(1, 1, true, true, false);
  kek.setField(2, 1, false, false, true);
  kek.setField(2, 4, true, false, false);

  kek.debug_display();
}