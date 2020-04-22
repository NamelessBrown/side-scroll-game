#include "Player.h"

Player::Player()
	:m_speed(4.5f)
{
	m_counter = 0;
	m_texture.loadFromFile("Textures/playerSheet.png");


	m_animations[int(AnimationIndex::WalkingRight)] = Animation(m_texture, 3, 46 * 3, 50 * 3, 46, 50);
	m_animations[int(AnimationIndex::WalkingLeft)] = Animation(m_texture, 3, 46 * 3, 50 * 3, 46, 50);
	m_animations[int(AnimationIndex::Fighting)] = Animation(m_texture, 8, 0, 0, 46, 50);
	m_animations[int(AnimationIndex::Standing)] = Animation(m_texture, 1, 0, 0, 46, 50);

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0.f, 540.f);
}

void Player::Update(float dt)
{
	Movement(dt);

	if (m_currentAnimation == AnimationIndex::WalkingLeft)
	{
		m_sprite.setScale(-1.0f, 1.0f);
	}
	else
	{
		m_sprite.setScale(1.0f, 1.0f);
	}

	m_animations[int(m_currentAnimation)].Update(dt);
	m_animations[int(m_currentAnimation)].Apply(m_sprite);
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
		m_currentAnimation = AnimationIndex::WalkingRight;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_sprite.move(-m_speed * dt, 0.f);
		m_currentAnimation = AnimationIndex::WalkingLeft;
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
