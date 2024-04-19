#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	loadMenu();
}

void Menu::loadMenu()
{
	if (!m_saveGregorFont.loadFromFile("ASSETS\\FONTS\\GregorFont.ttf"))
	{
		std::cout << "Error loading gregor font" << std::endl;
	}
	m_saveGregorText.setFont(m_saveGregorFont);
	m_saveGregorText.setCharacterSize(50);
	m_saveGregorText.setFillColor(sf::Color::Black);
	m_saveGregorText.setString("Save Gregor!");
	m_saveGregorText.setPosition(500, 450);

}

sf::Text Menu::getSaveGregorText()
{
	return m_saveGregorText;
}
