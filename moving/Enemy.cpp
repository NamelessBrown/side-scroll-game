#include "Enemy.h"
#include <random>

Enemy::Enemy()
{
	m_texture.loadFromFile("Textures/zombies.png");

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> m_distribution(0, 4);

	//m_type = (ZomebieType)m_distribution(rng);
	m_type = ZomebieType::skinny;

	switch (m_type)
	{
	case ZomebieType::handWalker:
		m_animation = Animation(m_texture, 4, 0, 0, 128, 128);
		break;
	case ZomebieType::fat:
		m_animation = Animation(m_texture, 3, 128, 128, 128, 128);
		break;
	case ZomebieType::skinny:
		m_animation = Animation(m_texture, 4, 0, 128 * 2, 128, 128);
		break;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(50.f, 50.f);
}

void Enemy::Update(float dt)
{
	m_animation.Update(dt);
	m_animation.Apply(m_sprite);
}

void Enemy::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
