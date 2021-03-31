#ifndef MinesweeperBoard_H
#define MinesweeperBoard_H

#include "Array2D.h"

enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};

struct Field{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard{
private:
  //Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  Array2D<Field> board;
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy
  int stan_gry;
  int maxMines;
  bool pierwszy_ruch;
  int odkryte_pola;
  
public:
  MinesweeperBoard(int wysokosc, int szerokosc, GameMode mode);
  void debug_display() const;
  void setField(int y, int x, bool mina, bool flaga, bool odkryte);
  void toggleFlag(int y, int x);
  void revealField(int y, int x);
  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;
  int countMines(int y, int x) const;
  bool hasFlag(int y, int x) const;
  bool isRevealed(int y, int x) const;
  bool isInbounds(int y, int x) const;
  GameState getGameState() const;
  char getFieldInfo(int y, int x) const;
};

#endif