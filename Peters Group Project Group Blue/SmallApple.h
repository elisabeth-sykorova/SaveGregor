// Name: Elisabeth Sykorova
// Login: C00301316
// Work done: loaded, random spawn behind borders - 17.4, reflection, move, set line, set a check for if its deflected
//------------------------------------------------------------------------------------
// Name: Leo Bolaks
// Login: C00299368
// Work Done: helped debug, added respawn, added update,



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
	float m_scale = 0.2f;
	float m_speed = 2.5f;
	float m_lineLength;
	sf::Vector2f m_velocity;

	sf::Vector2f m_dimensions{ 500.0f,500.0f };

	bool m_smallAppleAlive = false;

	bool m_reflected = false;

	sf::CircleShape m_mousePoint;

	// animating
	int m_currentFrame = 0;
	float m_frameIncrement = 0.2; // increments the frame counter with each update
	float m_frameCounter = 0.0f; // keeps the float count of current frame
	int m_lastFrame;
	const int NO_FRAMES = 30;


public:
	SmallApple();

	void loadSmallApple();
	sf::Sprite getSprite();
	void spawn();
	void setLine(sf::Vector2f t_gregorPosition);
	void move();
	void animate();

	void setAliveFalse();

	bool checkDeflected();

	void update(sf::Vector2f t_gregorPosition);

	void respawn(sf::Vector2f t_gregorPosition);

	void setReflectTrue();


};
#endif