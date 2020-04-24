#include "Collision.h"

/* Axis Aligned bounding boxes the most simple collision detection */
bool Collision::AxisAlignedBoundingBox(const sf::Sprite& box1, const sf::Sprite& box2)
{
    if (box1.getPosition().x < box2.getPosition().x + box2.getGlobalBounds().width &&
        box1.getPosition().x + box1.getGlobalBounds().width >  box2.getPosition().x &&
        box1.getPosition().y < box2.getPosition().y + box2.getGlobalBounds().height &&
        box1.getPosition().y + box1.getGlobalBounds().height > box2.getPosition().y) 
    {
        // collision detected!
        return true;
    }

	return false;
}

Collision::~Collision()
{
}
