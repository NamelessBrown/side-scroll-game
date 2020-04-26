#include "Player.h"

Player::Player(sf::Texture& texture)
{
	m_animations[int(AnimationIndex::Walking)] = Animation(texture, 3, 46 * 3, 50 * 3, 46, 50);
	m_animations[int(AnimationIndex::Fighting)] = Animation(texture, 4, 46 * 2, 50 * 2, 46, 50);
	m_animations[int(AnimationIndex::Standing)] = Animation(texture, 1, 0, 0, 46, 50);

	m_sprite.setTexture(texture);
	m_sprite.setPosition(0.f, 540.f);
}

void Player::LostHp(int damage)
{
	m_health -= damage;
}

void Player::Update(float dt)
{
	Movement(dt);

	if (m_movingLeft)
	{
		m_sprite.setScale(-1.0f, 1.0f);
	}
	else
	{
		m_sprite.setScale(1.0f, 1.0f);
	}

	m_animations[int(m_currentAnimation)].Update(dt);
	m_animations[int(m_currentAnimation)].Apply(m_sprite);

	CheckBounds();
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
		m_currentAnimation = AnimationIndex::Walking;
		m_movingLeft = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_sprite.move(-m_speed * dt, 0.f);
		m_currentAnimation = AnimationIndex::Walking;
		m_movingLeft = true;
	}
	else
	{
		m_currentAnimation = AnimationIndex::Standing;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		m_currentAnimation = AnimationIndex::Fighting;
	}

}

void Player::CheckBounds()
{
	if (m_sprite.getPosition().x < 5 || m_sprite.getPosition().x > 1000)
	{
		m_sprite.setPosition(15.f, 540.f);
	}
}
