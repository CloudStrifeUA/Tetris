#ifndef _TETRISWINDOW_H
#define _TETRISWINDOW_H

#include"TetrisBlock.h"
#include"GameText.h"

using TetrisField = std::array<std::array<std::pair<sf::Color, bool>, ALONG_WIDTH>, ALONG_HEIGHT>;

class TetrisWindow: public sf::RenderWindow
{
    static inline TetrisField m_aField{{{{{{0, 0, 0}, 0}}}}};
    static inline TetrisBlock m_aBlocks;
    GameText game_text;
    friend TetrisBlock;

    long int score = 0;
    bool bGameOver = false;
    
    public:

    TetrisWindow();

    void Start();

    void OnPressUp();

    void OnPressLeft();

    void OnPressRight();

    void OnPressDown();

    void Tick();

    void DrawAll();

    bool IsOver() const;

    void DrawScore();

    const long int& GetScore() const;
    
    void PrintGameText(const std::string& text, const sf::Vector2f& position, uint text_size = DEFAULT_TEXT_SIZE);
};

#endif