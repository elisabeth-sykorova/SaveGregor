// Name : Leo Bolaks
// Login: C00299368
// Work Done: loaded gregor 17-04-2024

#ifndef Gregor_HPP
#define Gregor_HPP

#include <SFML/Graphics.hpp>

class Gregor
{
	sf::Texture m_gregorTexture; // texture for gregor
	sf::Sprite m_gregorSprite; // sprite for gregor


public:
	Gregor();

	void loadGregor();

	sf::Sprite getGregor(); // gets gregors sprite


};
#endif