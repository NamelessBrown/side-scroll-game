#pragma once

#include <SFML/Graphics.hpp>

class Collision
{
public:
	static bool AxisAlignedBoundingBox(const sf::Sprite& box1, const sf::Sprite& box2);
private:
	Collision();
	~Collision();
};

