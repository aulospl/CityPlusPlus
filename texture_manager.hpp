#ifndef TEXTURE_MANAGER_HPP
#define  TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager{
private:
    //Array of textures used
    std::map<std::string, sf::Texture> textures;

public:
    //Add texture from file
    void loadTexture(const std::string& name, const std::string &filename);

    //Translate an id into a reference
    sf::Texture& getRef(const std::string& texture);

    //constructor
    TextureManager(){}
};


#endif
