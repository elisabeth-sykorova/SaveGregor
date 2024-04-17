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

void Gregor::update()
{
	move();
}

void Gregor::move()
{
	m_location = m_gregorSprite.getPosition();

	if (m_direction == NORTH)
	{
		if (m_location.y > 200)
		{
			m_location.y -= m_speed;
		}
	}
	if (m_direction == NW)
	{
		if (m_location.y > 200 && m_location.x > 200)
		{
			m_location.y -= m_speed;
			m_location.x -= m_speed;
		}
	}
	if (m_direction == NE)
	{
		if (m_location.y > 200 && m_location.x < 1000)
		{
			m_location.y -= m_speed;
			m_location.x += m_speed;
		}
	}
	if (m_direction == SOUTH)
	{
		if (m_location.y < 700)
		{
			m_location.y += m_speed;
		}
	}
	if (m_direction == SW)
	{
		if (m_location.y < 700 && m_location.x > 200)
		{
			m_location.y += m_speed;
			m_location.x -= m_speed;
		}
	}
	if (m_direction == SE)
	{
		if (m_location.y < 700 && m_location.x < 1000)
		{
			m_location.y += m_speed;
			m_location.x += m_speed;
		}
	}
	if (m_direction == EAST)
	{
		if (m_location.x < 700)
		{
			m_location.x += m_speed;
		}
	}
	if (m_direction == WEST)
	{
		if (m_location.x > 200)
		{
			m_location.x -= m_speed;
		}
	}
	m_gregorSprite.setPosition(m_location);
}
