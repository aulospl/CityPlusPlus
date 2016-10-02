#include <SFML/Graphics.hpp>

#include "game_state_start.hpp"
#include "game_state_editor.hpp"
#include "game_state.hpp"

void GameStateStart::draw(const float dt)
{
    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    return;
}

void GameStateStart::update(const float dt)
{
    sf::Event event;

    while(this->game->window.pollEvent(event)){
        switch(event.type){
            // Close the window
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            // Resize window
            case sf::Event::Resized:
            {
                /*
                    This change the number of pixels displayed in the view to prevent distortion
                    when resizing the window, by maintaining a 1:1 scale between window size and view size
                */
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(float(event.size.width)/float(this->game->background.getTexture()->getSize().x), float(event.size.height)/float(this->game->background.getTexture()->getSize().y));
                break;
            }
            // Key pressed controls
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape)
                    this->game->window.close();
                else if(event.key.code == sf::Keyboard::Space)
                    this->loadgame();
                    
                break;
            }

            default:
                break;
        }
    }

    return;
}

void GameStateStart::loadgame(){
    this->game->pushState(new GameStateEditor(this->game));
    return;
}

GameStateStart::GameStateStart(Game* game){
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}
