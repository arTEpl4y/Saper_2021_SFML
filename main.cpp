#include <iostream>

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
  Field board[10][10];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

public:
  MinesweeperBoard();
  void debug_display() const;
};

MinesweeperBoard::MinesweeperBoard(){
  width = 10;
  height = 10;

  for(int kolumna = 0; kolumna < width; kolumna++){
    for(int wiersz = 0; wiersz < height; wiersz++){
      board[wiersz][kolumna].hasMine = 0;
      board[wiersz][kolumna].hasFlag = 0;
      board[wiersz][kolumna].isRevealed = 0;
    }
  }
}

void intro(){
  std::cout << "MP xxx032" << std::endl;
}

int main() {
  intro();
  MinesweeperBoard();
}