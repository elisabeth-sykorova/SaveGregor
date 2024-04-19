//Name: Leo Bolaks
//Login: C00299368
//Work Done: added font

#ifndef Menu_HPP
#define Menu_HPP

#include <SFML/Graphics.hpp>

class Menu
{
	sf::Font m_saveGregorFont; // font for main text
	sf::Text m_saveGregorText; // text for main text


public:
	Menu();

	void loadMenu();

	sf::Text getSaveGregorText();


};
#endif