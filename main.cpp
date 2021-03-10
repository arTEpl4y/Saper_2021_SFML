#include <iostream>

#define min(x, y) x<y ? x:y

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
  Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

public:
  MinesweeperBoard(int wiersz, int kolumna){
    width = min(wiersz, 100);
    height = min(kolumna, 100);
    Field pole;
    pole.hasMine = 0;
    pole.hasFlag = 0;
    pole.isRevealed = 0;

    for(int x = 0; x < width; x++){
      for(int y = 0; y < width; y++){ //based
        board[x][y] = pole;
      }
    }

  }
  void debug_display() const;
};

void intro(){
  std::cout << "MP xxx032" << std::endl;
}

int main(){
  intro();
  MinesweeperBoard kek = MinesweeperBoard(10 , 10);
}