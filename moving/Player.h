#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player();

	const sf::Sprite& GetPlayer() const { return m_sprite; }

	void Update(float dt);
	void Render(sf::RenderWindow& window);
private:
	enum class AnimationIndex
	{
		Walking, Fighting, Standing, FightingLeft, Count
	};

	void Movement(float dt);
	void CheckBounds();
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	//int m_counter; //Used for the sprite sheet
	float m_speed;
	bool m_movingLeft;

	Animation m_animations[int(AnimationIndex::Count)];
	AnimationIndex m_currentAnimation = AnimationIndex::Walking;
};

