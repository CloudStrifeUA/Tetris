#include<iostream>
#include<random>
#include<chrono>
#include<string>
#include<sstream>

#include<GameConstants.h>
#include<TetrisBlock.h>
#include<TetrisWindow.h>

int main()
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    try
    {
        TetrisWindow game;
        sf::Clock clock;
        double time;
        double delay = DEFAULT_TICK_DELAY;
        game.Start();
        while(game.isOpen())
        {
            game.clear();
            sf::Event event;
            if(game.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    game.close();
                }
            }
            if(!game.IsOver())
            {
                game.DrawScore();
                time += clock.getElapsedTime().asSeconds();
                clock.restart();
                if(event.type == sf::Event::KeyPressed)
                {
                    if(event.key.code == sf::Keyboard::Up) game.OnPressUp();
                    else if(event.key.code == sf::Keyboard::Left) game.OnPressLeft();
                    else if(event.key.code == sf::Keyboard::Right) game.OnPressRight();
                }

                if(time >= delay)
                {
                    game.Tick();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        game.OnPressDown();
                        delay = 0.05;
                    }
                    else delay = DEFAULT_TICK_DELAY;
                    time = 0.0;
                }
                game.DrawAll();
            }
            else
            {
                std::stringstream ss;
                ss << "GAME OVER!\n" << "SCORE: " << game.GetScore();
                game.PrintGameText(ss.str(), {0.0, WINDOW_HEIGHT/6}, WINDOW_WIDTH/2);
            }
            game.display();
        }
    }
    catch(const ResourceNotFound& e)
    {
        std::cout << e.what() << std::endl;
    }
}