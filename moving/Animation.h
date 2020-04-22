#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

/*
	Special thanks to ChiliTomatoNoodle!
	Thank you ChiliTomatoNoodle for this blessed code! I changed it up a bit to match what I needed!
*/

class Animation
{
public:
	Animation() = default;
	Animation(sf::Texture& texture, int numberOfFrames, int x, int y, int width, int height);

	void Apply(sf::Sprite& sprite) const;
	void Update(float dt);
private:
	void Advance();
private:
	static constexpr float m_holdTime = 5.5f;
	float m_time = 0.0f;
	int m_numberOfFrames = 0;
	int m_iFrame = 0;

	std::vector<sf::IntRect> m_frames;
	sf::Texture m_texture;

};

