#include "Enemy.h"

Enemy::Enemy()
{
	m_texture.loadFromFile("Textures/zombies.png");
	m_animation = Animation(m_texture, 4, 0, 0, 128, 128);
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
