#include"TetrisWindow.h"
#include<sstream>

TetrisWindow::TetrisWindow():sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH + SCOREBOARD_WIDTH, WINDOW_HEIGHT), "Tetris"){}

void TetrisWindow::Start()
{
    m_aBlocks.GenerateBlock();
}

void TetrisWindow::OnPressUp()
{
    m_aBlocks.rotate();
}

void TetrisWindow::OnPressLeft()
{
    m_aBlocks.move(-1, 0);
}

void TetrisWindow::OnPressRight()
{
    m_aBlocks.move(1, 0);
}

void TetrisWindow::OnPressDown()
{
    score += 5;
}

void TetrisWindow::Tick()
{
    if(!m_aBlocks.move(0, 1))
    {
        for(const auto& block: m_aBlocks)
        {
            m_aField[block.m_y][block.m_x].first = block.color;
            m_aField[block.m_y][block.m_x].second = true;
        }
        bGameOver = m_aBlocks[0].m_y == 0;
        if(!bGameOver)
        {
            int line_pos = m_aField.size() - 1;
            for(int i = line_pos; i >=0; i--)
            {
                int count = 0;
                for(int j = 0; j < m_aField[i].size(); j++)
                {
                    count += m_aField[i][j].second;
                    m_aField[line_pos][j] = m_aField[i][j];
                }
                if(count < m_aField[i].size())
                    line_pos--;
                else score += 100;
            }

            m_aBlocks.GenerateBlock();
        }
    }
}

void TetrisWindow::DrawAll()
{
    sf::RectangleShape block_to_draw(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    for(int i = 0; i < m_aField.size(); i++)
        for(int j = 0; j < m_aField[i].size(); j++)
            if(m_aField[i][j].second)
            {
                block_to_draw.setPosition(sf::Vector2f(CELL_SIZE*j, CELL_SIZE*i));
                block_to_draw.setFillColor(m_aField[i][j].first);
                this -> draw(block_to_draw);
            }
    for(const auto& block:m_aBlocks)
    {
        block_to_draw.setPosition(sf::Vector2f(CELL_SIZE*block.m_x, CELL_SIZE*block.m_y));
        block_to_draw.setFillColor(block.color);
        this -> draw(block_to_draw);
    }
}

bool TetrisWindow::IsOver() const
{
    return bGameOver;
}

const long int& TetrisWindow::GetScore() const
{
    return score;
}

void TetrisWindow::DrawScore()
{
    std::stringstream ss;
    ss << "SCORE:\n" << score;
    game_text.setString(ss.str());
    game_text.setPosition({WINDOW_WIDTH + SCOREBOARD_WIDTH/4, 0.0});
    game_text.setCharacterSize(SCOREBOARD_WIDTH/2);
    this -> draw(game_text);
}

void TetrisWindow::PrintGameText(const std::string& text, const sf::Vector2f& position, uint text_size)
{
    game_text.setString(text);
    game_text.setPosition(position);
    game_text.setCharacterSize(text_size);
    this -> draw(game_text);
}