#include "Array2D.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"

void intro(){
  std::cout << "Milosz xxx032" << std::endl;
}

int main(){
  intro();
  MinesweeperBoard kek (10, 10, NORMAL); //wysokość, szerokość
  MSBoardTextView lol (kek);
  MSTextController ctrl (kek, lol);
  MSSFMLView wysw(kek);

  kek.debug_display();

  sf::RenderWindow win(sf::VideoMode(800, 600), "Minesweeper");
  win.setFramerateLimit(60);

  while(win.isOpen()){
    sf::Event event; 
    while (win.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        win.close();
      }

      if(event.type==sf::Event::MouseButtonPressed){
        int Swid = (event.mouseButton.x-50)/20;
        int Shei = (event.mouseButton.y-30)/20;
        
        if(event.mouseButton.button==sf::Mouse::Left){
          kek.revealField(Shei, Swid);
        }
        if(event.mouseButton.button==sf::Mouse::Right){
          kek.toggleFlag(Shei, Swid);
        }
        /*if(kek.getGameState() == FINISHED_LOSE){
          
        }
        if(kek.getGameState() == FINISHED_WIN){
          
        }
      }
    }
  win.clear(sf::Color(108, 150, 177));
  wysw.draw(win);
  win.display(); 
  }

}