#include "game.hpp"
#include "game_state_start.hpp"

int main(int argc, char const *argv[]) {
    Game game;

    game.pushState(new GameStateStart(&game));
    game.gameLoop();
    
    return 0;
}
