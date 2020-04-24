#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

/*  
	TODO: make a health system depented on the type of zombie
	TODO: make a speed system that is depented on the type of zombie
*/

class Enemy
{
public:
	Enemy(sf::Texture& texture);

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	enum class ZomebieType
	{
		handWalker, fat, skinny, oneManJand   
	};
private:
	sf::Sprite m_sprite;
	sf::Texture& m_texture;

	ZomebieType m_type;
	Animation m_animation;
};

