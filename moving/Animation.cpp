#include "Animation.h"

Animation::Animation(sf::Texture& texture, int numberOfFrames, int x, int y, int width, int height)
	:m_numberOfFrames(numberOfFrames), m_texture(texture), m_frames(numberOfFrames)
{
	for (unsigned i = 0; i < m_frames.size(); i++)
	{
		m_frames[i] = sf::IntRect(x + i * width, y, width, height);
	}

}

void Animation::Apply(sf::Sprite& sprite) const
{
	sprite.setTexture(m_texture);
	sprite.setTextureRect(m_frames[m_iFrame]);
}

void Animation::Update(float dt)
{
	m_time += dt;

	while (m_time > m_holdTime)
	{
		m_time -= m_holdTime;
		Advance();
	}
}

void Animation::Advance()
{
	if (++m_iFrame >= m_numberOfFrames)
	{
		m_iFrame = 0;
	}
}
