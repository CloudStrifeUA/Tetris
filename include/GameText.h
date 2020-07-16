#ifndef _GAMETEXT_H
#define _GAMETEXT_H

#include<SFML/Graphics.hpp>
#include"GameConstants.h"
#include"Exceptions.h"

struct GameText:public sf::Text
{
    sf::Font font;
    GameText(const std::string& msg = "", const int& text_size = DEFAULT_TEXT_SIZE);
};

#endif