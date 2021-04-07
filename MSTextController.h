#ifndef MSTextController_H
#define MSTextController_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController{
private:
  MinesweeperBoard &board;
  MSBoardTextView &view;
  
public:
  MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
  void play();
};

#endif