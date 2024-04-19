/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>
#include "ctime"
#include"cstdlib"



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1200U, 900U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	setupMouseDot();

	for (int index = 0; index < MAX_SMALL_APPLES; index++)
	{
		smallApples[index].spawn();
		smallApples[index].setLine(gregor.getGregor().getPosition());
	}
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	srand((int)time(nullptr)); // set the seed once
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseMoved == newEvent.type) // user pressed a mouse button 
		{
			processMouseMove(newEvent);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)
		{
			processMouseReleased();
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}



}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	if (m_gameState == GameStates::Game)
	{
		gregor.update();
		smallAppleCollisions();
		bigAppleCollisions();
		gregor.animateHearts();

		for (int index = 0; index < MAX_SMALL_APPLES; index++)
		{
			smallApples[index].update(gregor.getGregor().getPosition());
		}
		for (int i = 0; i < MAX_BIG_APPLES; i++)
		{
			bigApples[i].update(gregor.getGregor().getPosition());
		}
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	if (m_gameState == GameStates::Menu)
	{
		m_window.draw(menu.getSaveGregorText());
		m_window.draw(menu.getSaveGregorSprite());
	}
	if (m_gameState == GameStates::Game)
	{
		m_window.draw(gregor.getGregor());
		m_window.draw(gregor.getGregorHitbox());
		for (int index = 0; index < MAX_SMALL_APPLES; index++)
		{
			m_window.draw(smallApples[index].getSprite());
		}
		for (int i = 0; i < MAX_BIG_APPLES; i++)
		{
			m_window.draw(bigApples[i].getSprite());
		}
		m_window.draw(m_mouseDot);
		m_window.draw(gregor.getGregor());
		m_window.draw(gregor.getHearts());
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}

void Game::setupMouseDot()
{
	m_mouseDot.setRadius(1.0);
	m_mouseDot.setOrigin(0.5, 0.5);
	m_mouseDot.setFillColor(sf::Color::Black);
}

void Game::processMouseMove(sf::Event t_event)
{
	m_mouseEndVector.x = static_cast<float>(t_event.mouseMove.x);
	m_mouseEndVector.y = static_cast<float>(t_event.mouseMove.y);
	m_mouseDot.setPosition(m_mouseEndVector); // circle shape with the location of mouse to use for intersecting
}

void Game::processMouseReleased()
{
	for (int index = 0; index < MAX_SMALL_APPLES; index++)
	{
		if (m_mouseDot.getGlobalBounds().intersects(smallApples[index].getSprite().getGlobalBounds()))
		{
			smallApples[index].setReflectTrue();
		}
	}
	for (int i = 0; i < MAX_BIG_APPLES; i++)
	{
		if (m_mouseDot.getGlobalBounds().intersects(bigApples[i].getSprite().getGlobalBounds()))
		{
			bigApples[i].deflectCounter();
		}
	}
}

void Game::smallAppleCollisions()
{
	for (int i = 0; i < MAX_SMALL_APPLES; i++)
	{
		if (smallApples[i].getSprite().getGlobalBounds().intersects(gregor.getGregorHitbox().getGlobalBounds()))
		{
			smallApples[i].setAliveFalse();
			gregor.takeAwayLife();
		}
	}
}

void Game::bigAppleCollisions()
{
	for (int i = 0; i < MAX_BIG_APPLES; i++)
	{
		if (bigApples[i].getSprite().getGlobalBounds().intersects(gregor.getGregorHitbox().getGlobalBounds()))
		{
			bigApples[i].setAliveFalse();
			gregor.takeAway2Lives();
		}
	}
}

