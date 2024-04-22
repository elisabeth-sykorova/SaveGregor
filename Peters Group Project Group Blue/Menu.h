//Name: Leo Bolaks
//Login: C00299368
//Work Done: added font
//
//-------------------------------
// Name: Elisabeth Sykorova
// Login: C00301316
// Work Done: added start button sprite and textures, animated start button, added switching between two start button states(/textures)
//

#ifndef Menu_HPP
#define Menu_HPP

#include <SFML/Graphics.hpp>

class Menu
{

	static const int MENU_SCREEN_WIDTH = 1200;
	static const int MENU_SCREEN_HEIGHT = 900;

	sf::Font m_saveGregorFont; // font for main text
	sf::Text m_saveGregorText; // text for main text

	sf::Texture m_startGameTexture;
	sf::Sprite m_startGameSprite;

	const int START_GAME = 0; // for Save Gregor button
	const int RESTART_GAME = 1; // for Try Again button
	int m_currentStartButton = 1; // switches between "Save Gregor" and "Try again" based on the game phase
	int m_newStartButton = 1; // used to switch start game button texture when the state changes

	float m_frameIncrement = 0.2;
	float m_frameCounter = 0.0f; // tracks the current frame as float
	int m_lastFrame = 0;
	int m_currentFrame = 0; // no. current frame as int
	const int NO_BUTTON_FRAMES = 4; // number of start game button frames
	
	sf::Vector2f m_saveGregorXY = { 882, 380 };
	sf::Vector2f m_tryAgainXY = { 730, 380 };
	sf::Vector2f m_startButtonXY = m_saveGregorXY; // initializing to say "save gregor"




public:
	Menu();

	void loadMenu();
	sf::Text getSaveGregorText();

	// button sprites
	void loadSprites();
	sf::Sprite getStartGameSprite();
	void animateSprites();

	void setStartButtonState(int t_startButtonState); // used to switch the start button state and change its texture (0 - Save Gregor = start, 1 - Try Again = restart)
	void setRespawnButton();



};
#endif