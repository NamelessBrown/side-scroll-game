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
	enum class ZomebieType
	{
		handWalker, fat, skinny, oneManJand   
	};
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	ZomebieType m_type;
	Animation m_animation;
};

