#include "SFML/Graphics.hpp"
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &plansza):board(plansza){
  Pole = sf::Sprite();

  std::string sciezka = "/home/runner/SFML-MP-SAPER/Tekstury/";
  Pukryte.loadFromFile(sciezka+"hidden.png");
  Podkryte.loadFromFile(sciezka+"revealed.png");
  Mina.loadFromFile(sciezka+"mine.png");
  Flaga.loadFromFile(sciezka+"flag.png");
  jeden.loadFromFile(sciezka+"1minep.png");
  dwa.loadFromFile(sciezka+"2minep.png");
  trzy.loadFromFile(sciezka+"3minep.png");
  cztery.loadFromFile(sciezka+"4minep.png");
  piec.loadFromFile(sciezka+"5minep.png");
  szesc.loadFromFile(sciezka+"6minep.png");
  siedem.loadFromFile(sciezka+"7minep.png");
  osiem.loadFromFile(sciezka+"8minep.png");
  koniecl.loadFromFile(sciezka+"game_over.png");
}

void MSSFMLView::draw(sf::RenderWindow &win){
  for(int x = 0; x < board.getBoardWidth(); x++){
    for(int y = 0; y < board.getBoardHeight(); y++){
      int w, h = 0;
      h = 30+y*20;
      w = 50+x*20;

      if(board.getFieldInfo(y, x) == '_'){
        Pole.setTexture(Pukryte);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == ' '){
        Pole.setTexture(Podkryte);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == 'x'){
        Pole.setTexture(Mina);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == 'F'){
        Pole.setTexture(Flaga);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '1'){
        Pole.setTexture(jeden);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '2'){
        Pole.setTexture(dwa);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '3'){
        Pole.setTexture(trzy);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '4'){
        Pole.setTexture(cztery);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '5'){
        Pole.setTexture(piec);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '6'){
        Pole.setTexture(szesc);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '7'){
        Pole.setTexture(siedem);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
      if(board.getFieldInfo(y, x) == '8'){
        Pole.setTexture(osiem);
        Pole.setPosition(w, h);
        win.draw(Pole);
      }
    }
  }
  
}