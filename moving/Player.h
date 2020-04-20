#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	sf::Texture m_texture;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;
};

