#include "Player.h"

Player::Player()
	:m_speed(4.5f)
{
	m_counter = 0;
	m_texture.loadFromFile("Textures/playerSheet.png");

	m_animation = Animation(m_texture, 8, 46, 50, 46, 50);

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0.f, 540.f);
}

void Player::Update(float dt)
{
	Movement(dt);
	m_animation.Update(dt);
	m_animation.Apply(m_sprite);
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
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_sprite.move(-m_speed * dt, 0.f);
	}
	else
	{
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
	}

}
