#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
/*
 * Pushes a new game state in to the stack
 * @param in: GameState*
 */
void Game::pushState(GameState* state){
    this->states.push(state);

    return;
}

/*
 * Pops a game state from the stack
 */

 void Game::popState(){
     delete this->states.top();
     this.states.pop();

     return;
 }


void Game::changeState(GameState* state){
    if(!this->states.empty())
        popState();

    pushState(state);

    return;
}


GameState* Game::peekState(){
    if(this->states.empty())
        return nullptr;

    return this->states.top;
}

/*
 * Main game loop
 */
void Game::gameLoop(){
    sf::Clock clock;

    while (this->window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if(peekState() == nullptr)
            continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();

    }
}
/*
 * Constructor
*/
Game::Game(){
    this->window.create(sf::videoMode(800, 600), "CityPlusPlus");
    this->window.setFramerateLimit(60);
}

/*
 * Destructor
*/
Game::~Game(){
    while(!this->states.empty())
        popState();
}
