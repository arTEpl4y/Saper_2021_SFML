#include <iostream>

#include "Array2D.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

void intro(){
  std::cout << "Milosz xxx032" << std::endl;
}

int main(){
  intro();
  MinesweeperBoard kek (10, 10, HARD); //wysokość, szerokość
  MSBoardTextView lol (kek);
  kek.debug_display();
  /*std::cout << kek.countMines(1,0) << std::endl;
  std::cout << kek.countMines(2,9) << std::endl;
  std::cout << kek.countMines(2,1) << std::endl;
  std::cout << kek.countMines(6,7) << std::endl;
  std::cout << kek.getFieldInfo(3,1) << std::endl;*/
  MSTextController ctrl (kek, lol);

  ctrl.play();
}