#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"
/*
 * Author: Aulos Plautius Martines Marino
 * Github: https://github.com/aulospl/
 */

/* Defines the Game State class, responsible for managing the different stages of the game
 *
 */

class GameState{
    public:
        Game* game;

        virtual void draw(const float dt) = 0;
        virtual void update(const float dt) = 0;
        virtual void handleInput() = 0;
};


#endif
