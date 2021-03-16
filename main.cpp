#include <iostream>

#define min(x, y) x<y ? x:y

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
  void setField(int y, int x, bool mina, bool flaga, bool odkryte);

public:
  MinesweeperBoard(int wysokosc, int szerokosc);
  void debug_display() const;
};

void MinesweeperBoard::setField(int y, int x, bool mina, bool flaga, bool odkryte){
    board[y][x].hasMine = mina;    
    board[y][x].hasFlag = flaga;
    board[y][x].isRevealed = odkryte;
}

MinesweeperBoard::MinesweeperBoard(int wysokosc, int szerokosc){
    width = min(szerokosc, 100);
    height = min(wysokosc, 100);
    Field pole;
    pole.hasMine = false;
    pole.hasFlag = false;
    pole.isRevealed = false;

    for(int y = 0; y < height; y++){
      for(int x = 0; x < width; x++){     //based
        board[y][x] = pole;
      }
    }

    setField(1, 1, true, true, false);
    setField(2, 1, false, false, true);
    setField(2, 4, true, false, false);
}

void MinesweeperBoard::debug_display() const{
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      std::cout << "[" << (board[y][x].hasMine ? "M":".") << (board[y][x].hasFlag ? "o":".") << (board[y][x].isRevealed ? "f":".") << "]";
    }
    std::cout << std::endl;
  }
}

void intro(){
  std::cout << "Milosz xxx032" << std::endl;
}

int main(){
  intro();
  MinesweeperBoard kek = MinesweeperBoard(6, 9); //wysokość, szerokość
  kek.debug_display();
}