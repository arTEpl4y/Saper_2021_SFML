#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &plansza):board(plansza){
  
}

void MSBoardTextView::display() const{
  for(int y = 0; y < board.getBoardHeight(); y++){
    for(int x = 0; x < board.getBoardWidth(); x++){     //board.based
      std::cout << "[" << board.getFieldInfo(y, x) << "]";
    }
    std::cout << std::endl;
  }
}