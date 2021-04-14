#ifndef MSBoardTextView_H
#define MSBoardTextView_H

#include "MinesweeperBoard.h"

class MSBoardTextView{
private:
  MinesweeperBoard &board;

public:
  MSBoardTextView(MinesweeperBoard &plansza);
  void display() const;
};

#endif