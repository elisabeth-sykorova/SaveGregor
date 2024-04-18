// Name : Leo Bolaks
// Login: C00299368
// Work Done: set up sprite, set up sprite spawn, movement, and line following Gregor, respawn, collisions
//

#ifndef BigApple_HPP
#define BigApple_HPP

#include <SFML/Graphics.hpp>

const int NORTH_BIG_APPLE = 0;
const int SOUTH_BIG_APPLE = 1;
const int EAST_BIG_APPLE = 2;
const int WEST_BIG_APPLE = 3;

const int SCREEN_WIDTH_BIG_APPLE = 1200;
const int SCREEN_HEIGHT_BIG_APPLE = 900;

class BigApple
{
	sf::Texture m_texture;
	sf::Vector2f m_position{ 0.0f,0.0f };
	sf::Sprite m_sprite;
	float m_scale = 0.13f;
	float m_speed = 2.0f;
	float m_lineLength;
	sf::Vector2f m_velocity;
	

	bool m_bigAppleAlive = false;

	bool m_reflected = false;


public:
	BigApple();

	void loadBigApple();
	sf::Sprite getSprite();

	void update(sf::Vector2f t_gregorPosition);

	void spawn();
	void setLine(sf::Vector2f t_gregorPosition);
	void move();

	void respawn(sf::Vector2f t_gregorPosition);

	void setAliveFalse();



};
#endif
