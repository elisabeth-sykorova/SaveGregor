#include "Gregor.h"
#include <iostream>

Gregor::Gregor()
{
	loadGregor();
}

void Gregor::loadGregor()
{
	if (!m_gregorTexture.loadFromFile("ASSETS\\IMAGES\\Gregor.png"))
	{
		std::cout << "Error loading gregor" << std::endl;
	}
	m_gregorSprite.setTexture(m_gregorTexture);
	m_gregorSprite.setOrigin(500, 500);
	m_gregorSprite.setScale(0.17, 0.17);
	m_gregorSprite.setPosition(600, 450);

}

sf::Sprite Gregor::getGregor()
{
	return m_gregorSprite;
}
