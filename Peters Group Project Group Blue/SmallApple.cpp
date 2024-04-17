#include "SmallApple.h"
#include <iostream>

SmallApple::SmallApple()
{
	loadSmallApple();
}

void SmallApple::loadSmallApple()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\smallApple.png"))
	{
		std::cout << "problem loading small apple texture" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setScale(0.17, 0.17);
}

sf::Sprite SmallApple::getSprite()
{
	return m_sprite;
}
