// Name: Elisabeth Sykorova
// Login: C00301316
// Work done: loaded, random spawn behind borders - 17.4.



#ifndef SmallApple_HPP
#define SmallApple_HPP

#include <SFML/Graphics.hpp>

const int NORTH_SMALL_APPLE = 0;
const int SOUTH_SMALL_APPLE = 1;
const int EAST_SMALL_APPLE = 2;
const int WEST_SMALL_APPLE = 3;

const int SCREEN_WIDTH_SMALL_APPLE = 1200;
const int SCREEN_HEIGHT_SMALL_APPLE = 900;

class SmallApple
{
	sf::Texture m_texture;
	sf::Vector2f m_position{ 0.0f,0.0f };
	sf::Sprite m_sprite;
	float m_scale = 0.17f;
	float m_speed = 2.5f;
	float m_lineLength;
	sf::Vector2f m_velocity;

	bool m_smallAppleAlive = false;


public:
	SmallApple();

	void loadSmallApple();
	sf::Sprite getSprite();
	void spawn();
	void setLine(sf::Vector2f t_gregorPosition);
	void move();

	void setAliveFalse();

	void update(sf::Vector2f t_gregorPosition);

	void respawn(sf::Vector2f t_gregorPosition);


};
#endif