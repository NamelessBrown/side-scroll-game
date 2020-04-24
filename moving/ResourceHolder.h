#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class ResourceHolder
{
public:
	ResourceHolder();
	sf::Texture& getTexture(std::string path);
private:
	std::map<std::string, sf::Texture> m_textures;
};

