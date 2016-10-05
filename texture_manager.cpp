#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "texture_manager.hpp"

void TextureManager::loadTexture(const std::string& name, const std::string& filename){
    //load the textures
    sf::Texture tex;
    tex.loadFromFile(filename);

    //add it to the list of textures
    this->textures[name] =  tex;

    return;
}


sf::Texture& TextureManager::getRef(const std::string& texture){
    return this->textures.at(texture);
}
