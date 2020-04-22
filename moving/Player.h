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
	enum class AnimationIndex
	{
		WalkingRight, Fighting, Standing, WalkingLeft, Count
	};

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_counter; //Used for the sprite sheet
	float m_speed;

	Animation m_animations[int(AnimationIndex::Count)];
	AnimationIndex m_currentAnimation = AnimationIndex::WalkingRight;

	void Movement(float dt);
};

