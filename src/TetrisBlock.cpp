#include"TetrisBlock.h"
#include<iostream>
#include"TetrisWindow.h"

bool TetrisBlock::AllowMove(int dx, int dy) const
{
    if(!(dx >= 0 && dx < ALONG_WIDTH && dy < ALONG_HEIGHT && dy >= 0 ))
        return false;
    else if(TetrisWindow::m_aField[dy][dx].second)
        return false;
    return true;
}

bool TetrisBlock::move(int dx, int dy)
{
    for(const auto& block:TetrisWindow::m_aBlocks)
    {
        if(!AllowMove(block.m_x + dx, block.m_y + dy))
        {   
            return false;
        }
    }
    for(auto& block:m_aBlocks)
    {
        block.m_x += dx;
        block.m_y += dy;
    }
    return true;
}

void TetrisBlock::rotate()
{
    auto RotationPoint = TetrisWindow::m_aBlocks[1];
    for(const auto& block: m_aBlocks)
    {
        if(!AllowMove(RotationPoint.m_x + RotationPoint.m_y - block.m_y, block.m_x - RotationPoint.m_x + RotationPoint.m_y))
        {
            return;
        }
    }

    for(auto& block: TetrisWindow::m_aBlocks)
    {
        int tmp = RotationPoint.m_x + RotationPoint.m_y - block.m_y;
        block.m_y = block.m_x - RotationPoint.m_x + RotationPoint.m_y;
        block.m_x = tmp;
    }
}

bool TetrisBlock::checkPosition(int x, int y) const
{
    if(!(x >= 0 && x < m_aFields.size() && y >= 0 && y < m_aFields.size()))
    {
        return false;
    }
    else if(m_aFields[y][x])
    {
        return false;
    }
    return true;
}

void TetrisBlock::GenerateWays(const Block& block, std::vector<int>& posible_ways) const
{
    for(int i = -1; i <= 5; i += 2)
    {
        
        if(i <= 1)
        {   
            if(checkPosition(block.m_x + i - m_aBlocks[0].m_x, block.m_y - m_aBlocks[0].m_y))
            { 
                posible_ways.push_back((i == -1)?LEFT:RIGHT);
            }
        }
        else
        {
            
            if(checkPosition(block.m_x - m_aBlocks[0].m_x, block.m_y + i - 4 - m_aBlocks[0].m_y))
            {
                posible_ways.push_back((i == 3)?UP:DOWN);
            }
        }
    }
}

Block* TetrisBlock::begin()
{
    return m_aBlocks.begin();
}

Block* TetrisBlock::end()
{
    return m_aBlocks.end();
}

Block& TetrisBlock::operator[] (const int& i)
{
    return m_aBlocks[i];
}

void TetrisBlock::GenerateBlock()
{
    Block block{
    .m_x = ALONG_WIDTH/2,
    .m_y = 0,
    .color = {COLOR_SHIFT + rand()%(256 - COLOR_SHIFT), COLOR_SHIFT + rand()%(256 - COLOR_SHIFT), COLOR_SHIFT + rand()%(256 - COLOR_SHIFT)}
     };
    m_aBlocks[0] = block;
    m_aFields[0][0] = true;
    for(int i = 1; i < m_aBlocks.size(); i++)
    {
        std::vector<int> posible_ways;
        posible_ways.clear();
        GenerateWays(block, posible_ways);
        switch(posible_ways[rand()%posible_ways.size()])
        {
            case LEFT:
            {
                block.m_x += -1;
                break;
            }
            case RIGHT:
            {
                block.m_x += 1;
                break;
            }
            case UP:
            {
                block.m_y += -1;
                break;
            }
            case DOWN:
            {
                block.m_y += 1;
                break;
            }
        }
        m_aFields[block.m_y - m_aBlocks[0].m_y][block.m_x - m_aBlocks[0].m_x] = true;
        block.color = {COLOR_SHIFT + rand()%(256 - COLOR_SHIFT), COLOR_SHIFT + rand()%(256 - COLOR_SHIFT), COLOR_SHIFT + rand()%(256 - COLOR_SHIFT)};
        m_aBlocks[i] = block;
    }
    for(auto& i:m_aFields)
        for(auto& j:i)
            j = 0;
} 