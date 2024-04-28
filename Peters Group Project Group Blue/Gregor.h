// Name : Leo Bolaks
// Login: C00299368
// Work Done: loaded gregor 17-04-2024, added gregor movement 17-04-2024, added boundaries, rotatation, fixed speed, set lives, set up collisions 18-04-2024, fixed hearts animation
//
//------------------------------
// Name: Elisabeth Sykorova
// Login: C00301316
// Work Done: loaded heart sprites, animated hearts, hearts state switching based on health 18-04-2024, animated gregor, added sounds
//


#ifndef Gregor_HPP
#define Gregor_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ctime"
#include "cstdlib"

class Gregor
{
	sf::Texture m_gregorTexture; // texture for gregor
	sf::Sprite m_gregorSprite; // sprite for gregor

	sf::RectangleShape m_gregorHitbox; // hitbox for gregor

	int m_lives = 3;

	// gregors directions
	const int NORTH = 1;
	const int SOUTH = 2;
	const int EAST = 3;
	const int WEST = 4;
	const int NE = 5;
	const int NW = 6;
	const int SE = 7;
	const int SW = 8;
	int m_direction = NORTH;

	const int GREGOR_SCREEN_WIDTH = 1200;
	const int GREGOR_SCREEN_HEIGHT = 900;

	float m_speed = 3.0f; // gregors speed
	sf::Vector2f m_location;

	const float COUNTDOWN_DURATION = 30.0f;
	float m_countdown = 0.0f;

	bool m_gregorAlive = true;

	// hearts
	sf::Texture m_heartsTexture;
	sf::Sprite m_heartsSprite;
	sf::Vector2f m_heartDimensions{ 3040,1100 };
	// animating hearts
	int m_hCurrentFrame = 0; // tracks the current frame, is used to multiply coordinates of texture rect
	float m_hFrameIncrement = 0.2; // increments the frame counter with each update
	float m_hFrameCounter = 0.0f; // keeps the float count of current frame
	int m_hLastFrame;
	const int NO_HEART_FRAMES = 4;

	float m_scaleHearts = 0.17;

	// animating gregor
	int m_currentFrame = 0;
	float m_frameIncrement = 0.2; // increments the frame counter with each update
	float m_frameCounter = 0.0f; // keeps the float count of current frame
	int m_lastFrame;
	const int NO_FRAMES = 8;
	sf::Vector2f m_gregorDimensions{ 1000.0f,1000.0f };

	// sound effects
	sf::SoundBuffer m_stepsBuffer;
	sf::Sound m_stepsSound;

	bool m_soundOn = true;



public:
	Gregor();

	void loadGregor();
	void loadSound();
	void playSound();

	void soundIsOn(bool t_soundOn);

	sf::Sprite getGregor(); // gets gregors sprite
	sf::RectangleShape getGregorHitbox(); // gets gregors hitbox

	void update();

	bool checkGregorAlive();

	void takeAwayLife();
	void takeAway2Lives();
	void lifeCheck();

	void move();
	void randomMove();
	void animate();

	void gregorReset();

	// hearts
	void loadHearts();
	sf::Sprite getHearts();
	void animateHearts();

	


};
#endif