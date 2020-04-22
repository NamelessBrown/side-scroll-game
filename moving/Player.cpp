#include "Player.h"

Player::Player()
	:m_speed(4.5f)
{
	m_counter = 0;
	m_texture.loadFromFile("Textures/playerSheet.png");

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 46, 50));
	m_sprite.setPosition(0.f, 540.f);
}

void Player::Update(float dt)
{
	Movement(dt);
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::Movement(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_sprite.move(m_speed * dt, 0.f);
		m_sprite.setTextureRect(sf::IntRect(0, 0, 46, 50));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_sprite.move(-m_speed * dt, 0.f);
		m_sprite.setTextureRect(sf::IntRect(0, 0, 46, 50));
	}
	else
	{
		m_sprite.setTextureRect(sf::IntRect(0, 0, 46, 50));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		m_sprite.setTextureRect(sf::IntRect(0, 0, 46, 50));
	}

}
