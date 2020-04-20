#include "Player.h"

Player::Player()
	:m_speed(4.5f)
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

void Player::Movement(float dt, sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:

		switch (event.key.code)
		{
		case sf::Keyboard::Key::D:
			m_sprite.move(m_speed * dt, 0.f);
			break;
		case sf::Keyboard::Key::A:
			m_sprite.move(-m_speed * dt, 0.f);
			break;
		case sf::Keyboard::Key::W:
			m_sprite.move(0.f, -m_speed * dt);
			break;
		default:
			m_sprite.move(0.f, 0.f);
			break;
		}

		break;
	}
}
