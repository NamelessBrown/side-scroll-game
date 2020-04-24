#include "Enemy.h"
#include <random>

Enemy::Enemy(sf::Texture& texture)
	:m_texture(texture)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> m_distribution(0, 4);

	m_type = (ZomebieType)m_distribution(rng);

	switch (m_type)
	{
	case ZomebieType::handWalker:
		m_animation = Animation(m_texture, 4, 0, 0, 128, 128);
		break;
	case ZomebieType::fat:
		m_animation = Animation(m_texture, 4, 0, 128, 128, 128);
		break;
	case ZomebieType::skinny:
		m_animation = Animation(m_texture, 4, 0, 128 * 2, 128, 128);
		break;
	case ZomebieType::oneManJand:
		m_animation = Animation(m_texture, 4, 0, 128 * 3, 128, 128);
		break;
	default:
		m_animation = Animation(m_texture, 4, 0, 0, 128, 128);
		break;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setScale(-1.0f, 1.0f);
	m_sprite.setPosition(940.f, 460.f);
}

void Enemy::Update(float dt)
{
	m_sprite.move(-2.2f * dt, 0);
	m_animation.Update(dt);
	m_animation.Apply(m_sprite);
}

void Enemy::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
