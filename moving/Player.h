#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player() = default;
	Player(sf::Texture& texture);

	const sf::Sprite& GetPlayer() const { return m_sprite; }
	const int& GetHealth() const { return m_health; }

	void LostHp(int damage);
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
	sf::Sprite m_sprite;

	//int m_counter; //Used for the sprite sheet
	int m_health = 100;
	float m_speed  = 4.5f;
	bool m_movingLeft = false;

	Animation m_animations[int(AnimationIndex::Count)];
	AnimationIndex m_currentAnimation = AnimationIndex::Walking;
};

