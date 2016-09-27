#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

//Fixes cyclic dependecy of GameState class
class GameState;

class Game{
public:
    std::stack<GameState*> states;
    sf::RenderWindow window;

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    //Main game loop
    void gameLoop();

    Game();
    ~Game();
};

#endif
