#include "Player.h"

Player::Player()
{
	m_counter = 4;
	m_textureRect = sf::IntRect(0, 0, 368 / m_counter - 50, 200 / m_counter + 1);
	m_texture.loadFromFile("Textures/playerSheet.png", m_textureRect);

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0.f, 540.f);
}

void Player::Update(float dt)
{
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
