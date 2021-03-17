#ifndef MinesweeperBoard_H
#define MinesweeperBoard_H

enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};

struct Field{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard{
private:
  Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy
  int stan_gry;
  bool pierwszy_ruch;
  
public:
  MinesweeperBoard(int wysokosc, int szerokosc, GameMode mode);
  void debug_display() const;
  void setField(int y, int x, bool mina, bool flaga, bool odkryte);
  void toggleFlag(int y, int x);
  void revealField(int y, int x);
};

#endif