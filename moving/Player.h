#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	void Update(float dt);
	void Movement(float dt, sf::Event& event);
	void Render(sf::RenderWindow& window);
private:
	sf::Texture m_texture;
	sf::IntRect m_textureRect;
	sf::Sprite m_sprite;

	int m_counter; //Used for the sprite sheet
	float m_speed;
};

