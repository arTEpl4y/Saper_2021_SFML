#include <iostream>

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &plansza, MSBoardTextView &widok):board(plansza), view(widok){

}

void MSTextController::play(){
  std::string action;
  int x, y = 0;

  do{
    view.display();
    if(board.getGameState() == FINISHED_LOSS){
      std::cout << "GAME OVER" << std::endl;
      break;
    }
    if(board.getGameState() == FINISHED_WIN){
      std::cout << "CONGRATULATIONS! YOU WON!" << std::endl;
      break;
    }
    std::cout << "Please specify action(reveal or flag) and row/column: " << std::endl;
    std::cin >> action;
    std::cin >> y;
    std::cin >> x;

    if(action == "reveal"){
      board.revealField(y, x);
    }
    if(action == "flag"){
      board.toggleFlag(y, x);
    }

  }while(board.getGameState() == RUNNING);
}