#ifndef _TETRIS_BLOCK_H
#define _TETRIS_BLOCK_H

#include<array>
#include<vector>
#include"GameConstants.h"
#include<SFML/Graphics.hpp>

enum 
{
    LEFT = 0,
    RIGHT,
    UP,
    DOWN
};

struct Block
{
    int m_x;
    int m_y;
    sf::Color color;
};

using BlocksField = std::array<std::array<bool, BLOCKS_AMOUNT>, BLOCKS_AMOUNT>;

class TetrisBlock
{
    std::array<Block, BLOCKS_AMOUNT> m_aBlocks{0};
    BlocksField m_aFields{0};

    bool checkPosition(int x, int y) const;

    void GenerateWays(const Block& block, std::vector<int>& posible_ways) const;

    public:

    Block* begin();

    Block* end();

    Block& operator[] (const int& i);

    bool AllowMove(int dx, int dy) const;

    bool move(int dx, int dy);

    void rotate();

    void GenerateBlock();
};

#endif //_TETRIS_BLOCK_h