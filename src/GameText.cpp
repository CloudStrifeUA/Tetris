#include"GameText.h"

GameText::GameText(const std::string& msg, const int& text_size):sf::Text(msg, font, text_size)
{
    if(!font.loadFromFile(FONT_PATH))
    {
        throw ResourceNotFound(FONT_PATH);
    }
}