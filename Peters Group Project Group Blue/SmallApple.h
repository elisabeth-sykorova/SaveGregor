#ifndef SmallApple_HPP
#define SmallApple_HPP

#include <SFML/Graphics.hpp>

class SmallApple
{
	sf::Texture m_texture;
	sf::Vector2f m_position{ 0.0f,0.0f };
	sf::Sprite m_sprite;


public:
	SmallApple();

	void loadSmallApple();
	sf::Sprite getSprite();


};
#endif