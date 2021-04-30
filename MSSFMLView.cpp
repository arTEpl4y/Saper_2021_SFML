#include "SFML/Graphics.hpp"
#include "MSSFMLView.h"
#include "Minesweeperboard.h"

MSSFMLView::MSSFMLView(Minesweeperboard &plansza):board(plansza){
  Pole = sf::Sprite();
  
  Pukryte.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/hidden.png");
  Podkryte.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/revealed.png");
  Mina.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/mine.png");
  Flaga.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/flag.png");
  jeden.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/1minep.png");
  dwa.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/2minep.png");
  trzy.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/3minep.png");
  cztery.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/4minep.png");
  piec.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/5minep.png");
  szesc.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/6minep.png");
  siedem.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/7minep.png");
  osiem.loadFromFile("/home/runner/SFML-KWO-SAPER/Tekstury/8minep.png");
}

void MSSFMLView::draw(sf::RenderWindow &win){
  for(int y = 0; y < board.getBoardHeight(); y++){
    for(int x = 0; x < board.getBoardHeight(); x++){
      int w, h = 0;
      w = y*20;
      h = x*20;

      if(board.getFieldInfo(y, x) == '')
    }
  }
}