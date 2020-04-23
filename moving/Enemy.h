#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Enemy
{
public:
	Enemy();

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	Animation m_animation;
};

