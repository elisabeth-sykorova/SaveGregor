// Name: Leo Bolaks
// Login: C00299368
// Work Done: 
//----------------------------------------------------------------------------------------------------------------
// Name: Elisabeth Sykorova
// Login: C00301316
// Work Done: Mouse move/ released functions, added mouse dot circle shape,

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "Gregor.h"
#include "SmallApple.h"
#include "BigApple.h"
#include "RottenApple.h"
#include "Settings.h"
#include "Instructions.h"
#include "Upgrades.h"
#include "Menu.h"

enum class GameStates
{
	Menu,
	Game,
	End
};
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	void setupMouseDot();

	void smallAppleCollisions();
	void bigAppleCollisions();

	void menuCollisions();
	void endCollisions();
	void soundButtonCollision();

	void gregorCheck();

	void addEnemies();

	void gameReset();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	int m_deflections = 0;

	int m_activeSmallApple = 1; // active number of small apples
	int m_activeBigApple = 0; // active number of big apples

	static const int MAX_SMALL_APPLES = 5;
	static const int MAX_BIG_APPLES = 2;

	SmallApple smallApples[MAX_SMALL_APPLES];
	Gregor gregor;
	BigApple bigApples[MAX_BIG_APPLES];
	Menu menu;

	// mouse point
	sf::Vector2f m_mouseEndVector;
	sf::CircleShape m_mouseDot;
	sf::Vector2f m_mousePosition;

	void processMouseMove(sf::Event t_event);
	void processMouseReleased();

	GameStates m_gameState = GameStates::Menu;

};

#endif // !GAME_HPP

