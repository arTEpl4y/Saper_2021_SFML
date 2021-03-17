#ifndef MinesweeperBoard_H
#define MinesweeperBoard_H

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
  
public:
  MinesweeperBoard(int wysokosc, int szerokosc);
  void debug_display() const;
  void setField(int y, int x, bool mina, bool flaga, bool odkryte);
};

#endif