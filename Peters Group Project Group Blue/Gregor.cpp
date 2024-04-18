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

	m_gregorHitbox.setSize(sf::Vector2f(70, 70));
	m_gregorHitbox.setOrigin(35, 35);
	m_gregorHitbox.setFillColor(sf::Color::Transparent);
	m_gregorHitbox.setOutlineColor(sf::Color::Green);
	m_gregorHitbox.setOutlineThickness(3);
	m_gregorHitbox.setPosition(m_gregorSprite.getPosition());

}

sf::Sprite Gregor::getGregor()
{
	return m_gregorSprite;
}

sf::RectangleShape Gregor::getGregorHitbox()
{
	return m_gregorHitbox;
}

void Gregor::update()
{
	move();
	randomMove();
}

void Gregor::move()
{
	m_location = m_gregorSprite.getPosition();

	if (m_direction == NORTH)
	{
		m_gregorSprite.setRotation(0);
		if (m_location.y > 150)
		{
			m_location.y -= m_speed;
		}
	}
	if (m_direction == NW)
	{
		m_gregorSprite.setRotation(-45);
		if (m_location.y > 150)
		{
			m_location.y -= m_speed;
		}
		if (m_location.x > 150)
		{
			m_location.x -= m_speed;
		}
		
	}
	if (m_direction == NE)
	{
		m_gregorSprite.setRotation(45);
		if (m_location.y > 150)
		{
			m_location.y -= m_speed;
		}
		if (m_location.x < GREGOR_SCREEN_WIDTH - 150)
		{
			m_location.x += m_speed;
		}
		
	}
	if (m_direction == SOUTH)
	{
		m_gregorSprite.setRotation(180);
		if (m_location.y < GREGOR_SCREEN_HEIGHT - 150)
		{
			m_location.y += m_speed;
		}
	}
	if (m_direction == SW)
	{
		m_gregorSprite.setRotation(-135);
		if (m_location.y < GREGOR_SCREEN_HEIGHT - 150)
		{
			m_location.y += m_speed;
		}
		if (m_location.x > 150)
		{
			m_location.x -= m_speed;
		}
		
	}
	if (m_direction == SE)
	{
		m_gregorSprite.setRotation(135);
		if (m_location.y < GREGOR_SCREEN_HEIGHT - 150)
		{
			m_location.y += m_speed;
		}
		if (m_location.x < GREGOR_SCREEN_WIDTH - 150)
		{
			m_location.x += m_speed;
		}
		
	}
	if (m_direction == EAST)
	{
		m_gregorSprite.setRotation(90);
		if (m_location.x < GREGOR_SCREEN_WIDTH - 150)
		{
			m_location.x += m_speed;
		}
	}
	if (m_direction == WEST)
	{
		m_gregorSprite.setRotation(-90);
		if (m_location.x > 150)
		{
			m_location.x -= m_speed;
		}
	}
	m_gregorSprite.setPosition(m_location);
	m_gregorHitbox.setPosition(m_gregorSprite.getPosition());
}

void Gregor::randomMove()
{
	if (m_countdown != COUNTDOWN_DURATION) // constant is set to 30 to have a 0.5 second timer
	{
		m_countdown++;
	}
	else
	{

		m_direction = (rand() % 8) + 1; // generates a random number between 1 and 12
		m_countdown = 0; // sets countdown to 0
	}

}
