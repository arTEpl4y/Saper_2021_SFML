#ifndef MSSFMLView_H
#define MSSFMLView_H

#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

class MSSFMLView{
private:
  MinesweeperBoard &board;
  sf::Sprite Pole;
  sf::Texture Pukryte;
  sf::Texture Podkryte;
  sf::Texture Mina;
  sf::Texture Flaga;
  sf::Texture jeden;
  sf::Texture dwa;
  sf::Texture trzy;
  sf::Texture cztery;
  sf::Texture piec;
  sf::Texture szesc;
  sf::Texture siedem;
  sf::Texture osiem;

public:
  MSSFMLView(MinesweeperBoard &plansza);
  void draw(sf::RenderWindow &win);
};

#endif