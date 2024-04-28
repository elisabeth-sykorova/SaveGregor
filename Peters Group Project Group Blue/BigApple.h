// Name : Leo Bolaks
// Login: C00299368
// Work Done: set up sprite, set up sprite spawn, movement, and line following Gregor, respawn, collisions, deflecting,
//

#ifndef BigApple_HPP
#define BigApple_HPP

#include <SFML/Graphics.hpp>
/// <summary>
/// constants for spawn sides and the size of the screen
/// </summary>
const int NORTH_BIG_APPLE = 0;
const int SOUTH_BIG_APPLE = 1;
const int EAST_BIG_APPLE = 2;
const int WEST_BIG_APPLE = 3;

const int SCREEN_WIDTH_BIG_APPLE = 1200;
const int SCREEN_HEIGHT_BIG_APPLE = 900;

class BigApple
{
	sf::Texture m_texture; // texture for apple
	sf::Vector2f m_position{ 0.0f,0.0f }; // position of apple
	sf::Sprite m_sprite; // sprite for apple
	float m_scale = 0.13f; // scaled down
	float m_speed = 2.0f; // speed of apple
	float m_lineLength; // line along which apple moves
	sf::Vector2f m_velocity; // velocity at which it moves

	int m_counter = 0; // click counter
	

	bool m_bigAppleAlive = false; // if the apple is alive

	bool m_reflected = false; // if the apple is reflected 

	// animating apple
	int m_currentFrame = 0;
	float m_frameIncrement = 0.2; // increments the frame counter with each update
	float m_frameCounter = 0.0f; // keeps the float count of current frame
	int m_lastFrame;
	const int NO_FRAMES = 30;
	sf::Vector2f m_dimensions{ 1000.0f,1000.0f };

	bool m_countedReflection = false;


public:
	BigApple();

	void loadBigApple();
	sf::Sprite getSprite();

	void update(sf::Vector2f t_gregorPosition);
	void animate();

	void spawn();
	void setLine(sf::Vector2f t_gregorPosition);
	void move();

	void respawn(sf::Vector2f t_gregorPosition);

	void setAliveFalse();

	void deflectCounter();
	bool checkDeflected();
	void countReflection();
	bool getCountedReflection();



};
#endif
