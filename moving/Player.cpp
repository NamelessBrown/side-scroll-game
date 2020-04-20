#include "Player.h"

Player::Player()
{
	m_textureRect = sf::IntRect(0,0, 184, 100);
	m_texture.loadFromFile("Textures/playerSheet.png", m_textureRect);

	m_sprite.setTexture(m_texture);
}

void Player::Update(float dt)
{
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
