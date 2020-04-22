#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player();

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_counter; //Used for the sprite sheet
	float m_speed;

	Animation m_animation;

	void Movement(float dt);
};

