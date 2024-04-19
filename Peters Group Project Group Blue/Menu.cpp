#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	loadMenu();
	loadSprites();
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
	m_saveGregorText.setString("Save Gregor");
	m_saveGregorText.setPosition(500, 450);

}

void Menu::loadSprites()
{
	if (!m_saveGregorTexture.loadFromFile("ASSETS\\IMAGES\\save_gregor.png"))
	{
		std::cout << "Error loading gregor texture" << std::endl;
	}

	m_saveGregorSprite.setTexture(m_saveGregorTexture);
	m_saveGregorSprite.setOrigin(468, 188);
	m_saveGregorSprite.setPosition(1200/2, 900/2);
	m_saveGregorSprite.setScale(0.5, 0.5);

	m_saveGregorSprite.setTextureRect(sf::IntRect(0, 0, 936, 376));
}

sf::Sprite Menu::getSaveGregorSprite()
{
	return m_saveGregorSprite;
}

sf::Text Menu::getSaveGregorText()
{
	return m_saveGregorText;
}
