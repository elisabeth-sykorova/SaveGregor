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
	float m_scale = 0.27;


public:
	BigApple();

	void loadBigApple();
	sf::Sprite getSprite();
	void spawn();



};
#endif
