// Name : Leo Bolaks
// Login: C00299368
// Work Done: loaded gregor 17-04-2024, added gregor movement 17-04-2024,

#ifndef Gregor_HPP
#define Gregor_HPP

#include <SFML/Graphics.hpp>

#include "ctime"
#include "cstdlib"

class Gregor
{
	sf::Texture m_gregorTexture; // texture for gregor
	sf::Sprite m_gregorSprite; // sprite for gregor

	// gregors directions
	const int NORTH = 1;
	const int SOUTH = 2;
	const int EAST = 3;
	const int WEST = 4;
	const int NE = 5;
	const int NW = 6;
	const int SE = 7;
	const int SW = 8;
	int m_direction = NORTH;

	const int GREGOR_SCREEN_WIDTH = 1200;
	const int GREGOR_SCREEN_HEIGHT = 900;

	float m_speed = 3.0f; // gregors speed
	sf::Vector2f m_location;

	const float COUNTDOWN_DURATION = 30.0f;
	float m_countdown = 0.0f;


public:
	Gregor();

	void loadGregor();

	sf::Sprite getGregor(); // gets gregors sprite

	void update();

	void move();
	void randomMove();


};
#endif