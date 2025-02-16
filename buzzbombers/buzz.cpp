#include <iostream>
#include<fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

// Initializing Dimensions.
// resolutionX and resolutionY determine the rendering resolution.

const int resolutionX = 960;
const int resolutionY = 640;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionX / boxPixelsX; // Total rows on grid
const int gameColumns = resolutionY / boxPixelsY; // Total columns on grid

// Initializing GameGrid.
int gameGrid[gameRows][gameColumns] = {};
//draws player
void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite);
//move bullet level 1
void moveBullet_lvl1(float& bullet_y,bool& bullet_exists, Clock& bulletClock,bool isRegularBeeShot_lvl1[],float& bullet_x, float regularBee_x_lvl1[], float regularBee_y_lvl1[], float yellowHoneyComb_x_lvl1[],float yellowHoneyComb_y_lvl1[], Sound& hit,bool regularBeeShotProcessed_lvl1[],RenderWindow& window, Sprite& yellowHoneyCombSprite,bool regularBees_lvl1[],bool yellowHoneyCombs_lvl1[], bool pregenYellowHoneyCombs_lvl1[],int randomHoneyComb_x_lvl1[], int randomHoneyComb_y_lvl1[],bool beehives[],float beehive_x[],float beehive_y[],float& bird_y,float& bird_x,int& birdHitCount,const int BEEHIVES);
//move bullet lvl2
void moveBullet_lvl2(float& bullet_y,bool& bullet_exists, Clock& bulletClock,bool isRegularBeeShot_lvl2[],bool isFastBeeShot_lvl2[],float& bullet_x,float regularBee_x_lvl2[],float fastBee_x_lvl2[],float regularBee_y_lvl2[],float fastBee_y_lvl2[],float yellowHoneyComb_x_lvl2[],float yellowHoneyComb_y_lvl2[],float redHoneyComb_x_lvl2[],float redHoneyComb_y_lvl2[], Sound& hit,bool regularBeeShotProcessed_lvl2[],bool fastBeeShotProcessed_lvl2[],RenderWindow& window, Sprite& yellowHoneyCombSprite,Sprite& redHoneyCombSprite,bool regularBees_lvl2[],bool fastBees_lvl2[],bool yellowHoneyCombs_lvl2[],bool redHoneyCombs_lvl2[], bool pregenYellowHoneyCombs_lvl2[],int randomHoneyComb_x_lvl2[], int randomHoneyComb_y_lvl2[],bool beehives[],float beehive_x[],float beehive_y[],float& bird_y,float& bird_x,int& birdHitCount,const int BEEHIVES);
//move bullet lvl3
void moveBullet_lvl3(float& bullet_y,bool& bullet_exists, Clock& bulletClock,bool isRegularBeeShot_lvl3[],bool isFastBeeShot_lvl3[],float& bullet_x,float regularBee_x_lvl3[],float fastBee_x_lvl3[],float regularBee_y_lvl3[],float fastBee_y_lvl3[],float yellowHoneyComb_x_lvl3[],float yellowHoneyComb_y_lvl3[],float redHoneyComb_x_lvl3[],float redHoneyComb_y_lvl3[], Sound& hit,bool regularBeeShotProcessed_lvl3[],bool fastBeeShotProcessed_lvl3[],RenderWindow& window, Sprite& yellowHoneyCombSprite,Sprite& redHoneyCombSprite,bool regularBees_lvl3[],bool fastBees_lvl3[],bool yellowHoneyCombs_lvl3[],bool redHoneyCombs_lvl3[], bool pregenYellowHoneyCombs_lvl3[],int randomHoneyComb_x_lvl3[], int randomHoneyComb_y_lvl3[],bool beehives[],float beehive_x[],float beehive_y[],float& bird_y,float& bird_x,int& birdHitCount,const int BEEHIVES);
void drawBullet(RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite);

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Write your functions declarations here. Some have been written for you. //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

//main menu
void menu(RenderWindow& window, int& gameState);
//level select menu
void levelSelect(RenderWindow& window, int& levelState, int& gameState);
//moves player left
void movePlayerLeft(float& player_x, Sprite& playerSprite, Clock& movementClock, Sound& obstacle, float pollinatedFlower_x[],bool isPollinated[]);
//moves player right
void movePlayerRight(float& player_x, Sprite& playerSprite, Clock& movementClock, Sound& obstacle,bool isPollinated[], float pollinatedFlower_x[]);
//checks for out of bounds left
void outOfBoundsLeft(float& player_x, Sound& obstacle);
//checks for out of bounds right
void outOfBoundsRight(float& player_x, Sound& obstacle);
//draws bees
void drawRegularBee_lvl1(RenderWindow& window, Sprite regularBeeSprite_lvl1[], float regularBee_x_lvl1[], float regularBee_y_lvl1[], bool regularBees_lvl1[]);
void drawRegularBee_lvl2(RenderWindow& window, Sprite regularBeeSprite_lvl2[], float regularBee_x_lvl2[], float regularBee_y_lvl2[], bool regularBees_lvl2[]);
void drawRegularBee_lvl3(RenderWindow& window, Sprite regularBeeSprite_lvl3[], float regularBee_x_lvl3[], float regularBee_y_lvl3[], bool regularBees_lvl3[]);
void drawFastBee_lvl2(RenderWindow& window, Sprite fastBeeSprite_lvl2[], float fastBee_x_lvl2[], float fastBee_y_lvl2[], bool fastBees_lvl2[]);
void drawFastBee_lvl3(RenderWindow& window, Sprite fastBeeSprite_lvl3[], float fastBee_x_lvl3[], float fastBee_y_lvl3[], bool fastBees_lvl3[]);
//moves the bees
void moveRegularBee_lvl1(float regularBee_x_lvl1[], float regularBee_y_lvl1[], bool regularBeeRight_lvl1[],Sprite regularBeeSprite_lvl1[], bool regularBees_lvl1[], RenderWindow& window,bool isBeeStopped_lvl1[],Clock beeStopClock_lvl1[]);
void moveRegularBee_lvl2(float regularBee_x_lvl2[], float regularBee_y_lvl2[], bool regularBeeRight_lvl2[],Sprite regularBeeSprite_lvl2[], bool regularBees_lvl2[], RenderWindow& window,bool isBeeStopped_lvl2[],Clock beeStopClock_lvl2[]);
void moveRegularBee_lvl3(float regularBee_x_lvl3[], float regularBee_y_lvl3[], bool regularBeeRight_lvl3[],Sprite regularBeeSprite_lvl3[], bool regularBees_lvl3[], RenderWindow& window,bool isBeeStopped_lvl3[],Clock beeStopClock_lvl3[]);
void moveFastBee_lvl2(float fastBee_x_lvl2[],float fastBee_y_lvl2[],bool fastBeeRight_lvl2[],Sprite fastBeeSprite_lvl2[],bool fastBees_lvl2[],RenderWindow& window);
void moveFastBee_lvl3(float fastBee_x_lvl3[],float fastBee_y_lvl3[],bool fastBeeRight_lvl3[],Sprite fastBeeSprite_lvl3[],bool fastBees_lvl3[],RenderWindow& window);
//pauses bees randomly
void pauseBees_lvl1(Clock beeStopClock_lvl1[], bool isBeeStopped_lvl1[]);
void pauseBees_lvl2(Clock beeStopClock_lvl2[], bool isBeeStopped_lvl2[]);
void pauseBees_lvl3(Clock beeStopClock_lvl3[], bool isBeeStopped_lvl3[]);
//checks if worker bee collides with player
void beeCollidePlayer_lvl1(float regularBee_x_lvl1[],float regularBee_y_lvl1[],float& player_x,float& player_y, bool isRegularBeeCollidePlayer_lvl1[],bool isRegularBeeCollidePlayerProcessed_lvl1[]);
void beeCollidePlayer_lvl2(float regularBee_x_lvl2[],float regularBee_y_lvl2[],float fastBee_x_lvl2[],float fastBee_y_lvl2[],float& player_x,float& player_y,bool isRegularBeeCollidePlayer_lvl2[],bool isFastBeeCollidePlayer_lvl2[],bool isRegularBeeCollidePlayerProcessed_lvl2[],bool isFastBeeCollidePlayerProcessed_lvl2[]);
void beeCollidePlayer_lvl3(float regularBee_x_lvl3[],float regularBee_y_lvl3[],float fastBee_x_lvl3[],float fastBee_y_lvl3[],float& player_x,float& player_y,bool isRegularBeeCollidePlayer_lvl3[],bool isFastBeeCollidePlayer_lvl3[],bool isRegularBeeCollidePlayerProcessed_lvl3[],bool isFastBeeCollidePlayerProcessed_lvl3[]);
//checks if pairs of 8 bullets have been shot
void bulletsX8 (int& bulletCount, bool& areBulletsX8, const int LOWER_HEALTH);
//reduces health if conditions are met
void reducePlayerHealth_lvl1 (int& health, bool isRegularBeeCollidePlayer_lvl1[],const int& LOWER_HEALTH, bool& areBulletsX8,bool isRegularBeeCollidePlayerProcessed_lvl1[]);
void reducePlayerHealth_lvl2(int& health,bool isRegularBeeCollidePlayer_lvl2[],bool isFastBeeCollidePlayer_lvl2[], const int& LOWER_HEALTH,bool& areBulletsX8, bool isRegularBeeCollidePlayerProcessed_lvl2[],bool isFastBeeCollidePlayerProcessed_lvl2[]);
void reducePlayerHealth_lvl3(int& health,bool isRegularBeeCollidePlayer_lvl3[],bool isFastBeeCollidePlayer_lvl3[], const int& LOWER_HEALTH,bool& areBulletsX8, bool isRegularBeeCollidePlayerProcessed_lvl3[],bool isFastBeeCollidePlayerProcessed_lvl3[]);
//draws yellow honeycombs upon hitting regular bees
void drawYellowHoneyComb_lvl1(RenderWindow& window,Sprite& yellowHoneyCombSprite,float yellowHoneyComb_x_lvl1[],float yellowHoneyComb_y_lvl1[], int i);
void drawYellowHoneyComb_lvl2(RenderWindow& window,Sprite& yellowHoneyCombSprite,float yellowHoneyComb_x_lvl2[],float yellowHoneyComb_y_lvl2[], int i);
void drawYellowHoneyComb_lvl3(RenderWindow& window,Sprite& yellowHoneyCombSprite,float yellowHoneyComb_x_lvl3[],float yellowHoneyComb_y_lvl3[], int i);
void drawRedHoneyComb_lvl2(RenderWindow& window,Sprite& redHoneyCombSprite,float redHoneyComb_x_lvl2[],float redHoneyComb_y_lvl2[], int i);
void drawRedHoneyComb_lvl3(RenderWindow& window,Sprite& redHoneyCombSprite,float redHoneyComb_x_lvl3[],float redHoneyComb_y_lvl3[], int i);
//checks if a bee collides with honeycomb
void beeCollideComb_lvl1(float regularBee_x_lvl1[], float regularBee_y_lvl1[],bool isRegularBeeCollideComb_lvl1[], int randomHoneyComb_x_lvl1[], int randomHoneyComb_y_lvl1[],bool regularBeeRight_lvl1[],Sprite regularBeeSprite_lvl1[], bool yellowHoneyCombs_lvl1[],float yellowHoneyComb_x_lvl1[], float yellowHoneyComb_y_lvl1[],Clock collideClock_lvl1[], bool beehives[], float beehive_x[], float beehive_y[], bool regularBees_lvl1[]);
void beeCollideComb_lvl2(float regularBee_x_lvl2[], float regularBee_y_lvl2[],bool isRegularBeeCollideComb_lvl2[], int randomHoneyComb_x_lvl2[], int randomHoneyComb_y_lvl2[],bool regularBeeRight_lvl2[],Sprite regularBeeSprite_lvl2[], bool yellowHoneyCombs_lvl2[],bool redHoneyCombs_lvl2[],float yellowHoneyComb_x_lvl2[], float yellowHoneyComb_y_lvl2[],float redHoneyComb_x_lvl2[],float redHoneyComb_y_lvl2[],Clock collideClock_lvl2[], bool beehives[], float beehive_x[], float beehive_y[], bool regularBees_lvl2[]);
void beeCollideComb_lvl3(float regularBee_x_lvl3[], float regularBee_y_lvl3[],bool isRegularBeeCollideComb_lvl3[], int randomHoneyComb_x_lvl3[], int randomHoneyComb_y_lvl3[],bool regularBeeRight_lvl3[],Sprite regularBeeSprite_lvl3[], bool yellowHoneyCombs_lvl3[],bool redHoneyCombs_lvl3[],float yellowHoneyComb_x_lvl3[], float yellowHoneyComb_y_lvl3[],float redHoneyComb_x_lvl3[],float redHoneyComb_y_lvl3[],Clock collideClock_lvl3[], bool beehives[], float beehive_x[], float beehive_y[], bool regularBees_lvl3[]);
//increases bullet count when bullets are shot
void increaseBulletCount(int& bulletCount);
//draws remaining cans of the player
void drawRemainingCans(RenderWindow& window,Sprite& remainingCanSprite1, Sprite& remainingCanSprite2,float& can1_x,float& can1_y,bool remainingCanCount[]);
//checks if player has died
void playerDeath(int& health,bool remainingCanCount[],int& remainingCanIndex, bool& gameOver,const int FLOWERS,bool isPollinated[],bool& rightCornerProcessed, bool& leftCornerProcessed, bool& placeLeftFlowers, bool& placeRightFlowers);
//draws player health bar inside the can
void drawPlayerHealth(RenderWindow& window, int& health,float& player_x,float& player_y);
//displays the player score
void showScore(RenderWindow& window, int score);
//awards bonus cans to the player
void bonusCans(bool remainingCanCount[], int score, const int BONUS_CAN_SCORE);
//creates flowers
void pollinateFlowers_lvl1(bool isPollinated[], float regularBee_x_lvl1[], float regularBee_y_lvl1[], float pollinatedFlower_x[], float pollinatedFlower_y[], bool isFlowerProcessed[],bool regularBees_lvl1[],bool regularBeeRight_lvl1[],bool flowerPlaced[],bool& leftCornerProcessed, bool& rightCornerProcessed, bool& placeRightFlowers, bool& placeLeftFlowers);
void pollinateFlowers_lvl2(bool isPollinated[], float regularBee_x_lvl2[], float regularBee_y_lvl2[],float fastBee_x_lvl2[], float fastBee_y_lvl2[], float pollinatedFlower_x[], float pollinatedFlower_y[],bool isFlowerProcessed[],bool regularBees_lvl2[],bool fastBees_lvl2[], bool regularBeeRight_lvl2[],bool fastBeeRight_lvl2[], bool flowerPlaced[], bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers);
void pollinateFlowers_lvl3(bool isPollinated[], float regularBee_x_lvl3[], float regularBee_y_lvl3[],float fastBee_x_lvl3[], float fastBee_y_lvl3[], float pollinatedFlower_x[], float pollinatedFlower_y[],bool isFlowerProcessed[],bool regularBees_lvl3[],bool fastBees_lvl3[], bool regularBeeRight_lvl3[],bool fastBeeRight_lvl3[], bool flowerPlaced[], bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers);
//draws the flowers
void drawFlowers(RenderWindow& window, Sprite flowerSprite[],float pollinatedFlower_x[],float pollinatedFlower_y[],bool isPollinated[],bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers);
//forms a beehive when bee gets stuck
void formBeehive();
//draws the beehive
void drawBeehive(RenderWindow& window, Sprite beehiveSprite[], const int BEEHIVES,float beehive_x[], float beehive_y[], bool beehives[]);
//moves the bird
void moveBird(int& frames, int& randomDirection, int& currentDirection, float& bird_x, float& bird_y, int birdDirections[], bool& birdPaused, int& pauseFrames, int& birdHitCount, bool& birdSick,int& sickFrames, Sprite& birdSprite);
//draws the bird
void drawBird(RenderWindow& window, Sprite& birdSprite, float& bird_x, float& bird_y);
//checks if bird has reached a comb
void birdCollideComb_lvl1(float& bird_y, float& bird_x, int randomHoneyComb_x_lvl1[],int randomHoneyComb_y_lvl1[],float yellowHoneyComb_x_lvl1[],float yellowHoneyComb_y_lvl1[], bool& birdPaused, bool isBirdCollidePregenComb_lvl1[], bool isBirdCollideYellowComb_lvl1[],bool yellowHoneyCombs_lvl1[], bool pregenYellowHoneyCombs_lvl1[], bool& birdSick, int& score);
void birdCollideComb_lvl2(float& bird_y, float& bird_x, int randomHoneyComb_x_lvl2[],int randomHoneyComb_y_lvl2[],float yellowHoneyComb_x_lvl2[],float yellowHoneyComb_y_lvl2[],float redHoneyComb_x_lvl2[], float redHoneyComb_y_lvl2[], bool& birdPaused, bool isBirdCollidePregenComb_lvl2[], bool isBirdCollideYellowComb_lvl2[],bool isBirdCollideRedComb_lvl2[], bool yellowHoneyCombs_lvl1[],bool redHoneyCombs_lvl2[], bool pregenYellowHoneyCombs_lvl1[], bool& birdSick, int& score);
void birdCollideComb_lvl3(float& bird_y, float& bird_x, int randomHoneyComb_x_lvl3[],int randomHoneyComb_y_lvl3[],float yellowHoneyComb_x_lvl3[],float yellowHoneyComb_y_lvl3[],float redHoneyComb_x_lvl3[], float redHoneyComb_y_lvl3[], bool& birdPaused, bool isBirdCollidePregenComb_lvl3[], bool isBirdCollideYellowComb_lvl3[],bool isBirdCollideRedComb_lvl3[], bool yellowHoneyCombs_lvl3[],bool redHoneyCombs_lvl3[], bool pregenYellowHoneyCombs_lvl3[], bool& birdSick,int& score);
//transitions between levels
void levelTransition1(int& levelState, RenderWindow& window, bool regularBees_lvl1[], int& score);
void levelTransition2(int& levelState, RenderWindow& window, bool regularBees_lvl2[], bool fastBees_lvl2[], int& score);
//displays game over screen
void gameOverScreen(RenderWindow& window, int& score);
//plays different music for each level
void playMusic(Music& lvl1Music,Music& lvl2Music,Music& lvl3Music,int& levelState);
//displays high scores
void displayScores(RenderWindow& window, int& gameState, char playerNames[][50], int highScores[]);
//game completed state
void gameCompleted(int& levelState, RenderWindow& window, bool regularBees_lvl3[], bool fastBees_lvl3[], int& score, bool& isGameCompleted);
//prompts the user to enter their name
void enterName(RenderWindow& window, char playerName[], int& score,bool& nameSubmitted);

int main()
{
	srand(time(0));

	// Declaring RenderWindow.
	RenderWindow window(VideoMode(resolutionX, resolutionY), "Buzz Bombers", Style::Close | Style::Resize | Style::Titlebar);

	// Used to position your window on every launch. Use according to your needs.
	window.setPosition(Vector2i(500, 200));
	
	//this is for the game states like menu, play, exit etc
	int gameState = 0; // for menu
	int levelState = 1; //this will be used for the menu for the level select
	bool gamePaused = 0;
	bool nameSubmitted = 0;
	//things needed for high score tracking
	char playerName[50] = ""; //will store the players name at the end of the game
	char playerNames[1000][50] = {""}; //will hold the names from the file
	int highScores[1000];
	
	//menu
	while (1)
	{
		if (gameState == 0)
		{
			menu(window, gameState);
		}
		else if (gameState == 2)
		{
			levelSelect(window, levelState, gameState);
		}
		else if (gameState == 4)
		{
			displayScores(window, gameState,playerNames, highScores);
		}
		else if (gameState == 1)
		{
			break;
		}
	}
	
	// Initializing Background Music.
		Music lvl1Music;
		lvl1Music.openFromFile("Music/Music3.ogg");
		Music lvl2Music;
		lvl2Music.openFromFile("Music/risk.ogg");
		Music lvl3Music;
		lvl3Music.openFromFile("Music/LavaReef.ogg");
	
	//obstacle sound
	SoundBuffer buffer;
	buffer.loadFromFile("Sound Effects/Obstacle.wav");
	Sound obstacle;
	obstacle.setBuffer(buffer);
	//shooting sound
	buffer.loadFromFile("Sound Effects/fire.wav");
	Sound shoot;
	shoot.setBuffer(buffer);
	//hit sound
	buffer.loadFromFile("Sound Effects/hit.wav");
	Sound hit;
	hit.setBuffer(buffer);

	// Initializing Player and Player Sprites.
	//reset----
	float player_x = (gameRows / 2) * boxPixelsX;
	float player_y = (gameColumns - 4) * boxPixelsY;

	Texture playerTexture;
	Sprite playerSprite;
	playerTexture.loadFromFile("Textures/spray.png");
	playerSprite.setTexture(playerTexture);
	//	playerSprite.setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));

	// Initializing Bullet and Bullet Sprites
	// Data for bullet / Spray pellet
	//reset----
	float bullet_x = player_x; 
	float bullet_y = player_y;
	bool bullet_exists = false;
	
	Clock bulletClock;
	Texture bulletTexture;
	Sprite bulletSprite;
	bulletTexture.loadFromFile("Textures/bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(3, 3);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	
	//my clocks
	Clock movementClock; //to add a delay between movements
	Clock bulletSoundClock; // to add a delay between shooting sounds
	Clock regularBeeClock; // to add a delay to bee movements
	Clock fastBeeClock;
	Clock pauseButtonClock; //to avoid multiple presses of pause button
	Clock collideClock_lvl1[20]; //adds a cooldown before checking for another collision bw bee and comb
	Clock collideClock_lvl2[15];
	Clock collideClock_lvl3[20];
	Clock beeStopClock_lvl1[20];
	Clock beeStopClock_lvl2[15];
	Clock beeStopClock_lvl3[20];
	
	//my variables
	int score = 0; //this will count the points scored by the player throughout the game
	int bulletCount = 0; //this counts the total number of bullets shot, reset----
	int health = 100; //reset-----
	float can1_x = 10; // coordinates for the remaining can display
	float can1_y = 580;
	int remainingCanIndex = 1;
	int regularBeePosIncrement = 0;
	
	//my booleans/ flags
	//reset all-----
	bool areBulletsX8 = 0;
	bool gameOver = 0;
	bool isGameCompleted = 0;
	bool leftCornerProcessed = 0;
	bool rightCornerProcessed = 0;
	bool placeRightFlowers = 0;
	bool placeLeftFlowers = 0;
	
	//my named constants
	const int MAX_BULLETS = 56;
	const int LOWER_HEALTH = 8;
	const int BONUS_CAN_SCORE = 80000;
	const int remainingCans = 20; //use if needed------
	const int FLOWERS = 30;
	const int BEEHIVES = 30;
	
	//my arrays
	//regular bees for each level
	bool regularBees_lvl1[20];
	bool regularBees_lvl2[15];
	bool regularBees_lvl3[20];
	float regularBee_x_lvl1[20];
	float regularBee_y_lvl1[20] = {0};
	float regularBee_x_lvl2[15];
	float regularBee_y_lvl2[15] = {0};
	float regularBee_x_lvl3[20];
	float regularBee_y_lvl3[20] = {0};
	//fast bees for each level
	bool fastBees_lvl2[5];
	bool fastBees_lvl3[10];
	float fastBee_x_lvl2[5];
	float fastBee_y_lvl2[5] = {0};
	float fastBee_x_lvl3[10];
	float fastBee_y_lvl3[10] = {0};
	//pregenerated honeycombs
	bool pregenYellowHoneyCombs_lvl1[3] = {1,1,1};
	int randomHoneyComb_x_lvl1[3];
	int randomHoneyComb_y_lvl1[3];
	bool pregenYellowHoneyCombs_lvl2[9] = {1,1,1,1,1,1,1,1,1};
	int randomHoneyComb_x_lvl2[9];
	int randomHoneyComb_y_lvl2[9];
	bool pregenYellowHoneyCombs_lvl3[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int randomHoneyComb_x_lvl3[15];
	int randomHoneyComb_y_lvl3[15];
	//yellow honeycombs
	bool yellowHoneyCombs_lvl1[20] = {0};
	float yellowHoneyComb_x_lvl1[20];
	float yellowHoneyComb_y_lvl1[20];
	bool yellowHoneyCombProcessed_lvl1[20] = {0};
	bool yellowHoneyCombs_lvl2[15] = {0};
	float yellowHoneyComb_x_lvl2[15];
	float yellowHoneyComb_y_lvl2[15];
	bool yellowHoneyCombProcessed_lvl2[15] = {0};
	bool yellowHoneyCombs_lvl3[20] = {0};
	float yellowHoneyComb_x_lvl3[20];
	float yellowHoneyComb_y_lvl3[20];
	bool yellowHoneyCombProcessed_lvl3[20] = {0};
	//red honeycombs
	bool redHoneyCombs_lvl2[5] = {0};
	float redHoneyComb_x_lvl2[5];
	float redHoneyComb_y_lvl2[5];
	bool redHoneyCombs_lvl3[10] = {0};
	float redHoneyComb_x_lvl3[10];
	float redHoneyComb_y_lvl3[10];
	bool redHoneyCombProcessed_lvl2[5] = {0};
	bool redHoneyCombProcessed_lvl3[10] = {0};
	//beehives, reset------
	bool beehives[BEEHIVES] = {0};
	float beehive_x[BEEHIVES]; 
	float beehive_y[BEEHIVES];
	//if bee collides with honeycomb
	bool isRegularBeeCollideComb_lvl1[23] = {0};
	bool isRegularBeeCollideComb_lvl2[29] = {0};
	bool isRegularBeeCollideComb_lvl3[45] = {0};
	//if bee collides with player,
	bool isRegularBeeCollidePlayer_lvl1[20] = {0};
	bool isRegularBeeCollidePlayer_lvl2[15] = {0};
	bool isRegularBeeCollidePlayer_lvl3[20] = {0};
	bool isFastBeeCollidePlayer_lvl2[5] = {0};
	bool isFastBeeCollidePlayer_lvl3[10] = {0};
	bool isRegularBeeCollidePlayerProcessed_lvl1[20] = {0};
	bool isRegularBeeCollidePlayerProcessed_lvl2[15] = {0};
	bool isRegularBeeCollidePlayerProcessed_lvl3[20] = {0};
	bool isFastBeeCollidePlayerProcessed_lvl2[5] = {0};
	bool isFastBeeCollidePlayerProcessed_lvl3[10] = {0};
	//remaining cans
	bool remainingCanCount[20] = {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//regular and fast bee directions
	bool regularBeeRight_lvl1[20];
	bool regularBeeRight_lvl2[15];
	bool regularBeeRight_lvl3[20];
	bool fastBeeRight_lvl2[5];
	bool fastBeeRight_lvl3[10];
	//if bee is shot
	bool isRegularBeeShot_lvl1[20] = {0};
	bool regularBeeShotProcessed_lvl1[20] = {0};
	bool isRegularBeeShot_lvl2[15] = {0};
	bool regularBeeShotProcessed_lvl2[15] = {0};
	bool isRegularBeeShot_lvl3[20] = {0};
	bool regularBeeShotProcessed_lvl3[20] = {0};
	bool isFastBeeShot_lvl2[5] = {0};
	bool fastBeeShotProcessed_lvl2[5] = {0};
	bool isFastBeeShot_lvl3[10] = {0};
	bool fastBeeShotProcessed_lvl3[10] = {0};
	//if bee is paused
	bool isBeeStopped_lvl1[20] = {0};
	bool isBeeStopped_lvl2[15] = {0};
	bool isBeeStopped_lvl3[20] = {0};
	//if flowers have been pollinated, reset----
	bool isPollinated[FLOWERS] = {0};
	bool isFlowerProcessed[FLOWERS] = {0};
	bool flowerPlaced[FLOWERS] = {0};
	float pollinatedFlower_x[FLOWERS];
	float pollinatedFlower_y[FLOWERS];
	//everything needed for hummingbird
	//0 for left, 1 for down, 2 for up, 3 for right, 4 for top left, 5 for right, 6 for bottom left,
	// 7 for bottom right
	int birdDirections[8] = {0,1,2,3,4,5,6,7};
	int randomDirection = rand() % 7;
	int currentDirection = 3; //reset----
	//reset--- excep lvls
	float bird_x = 0;
	float bird_y = 0;
	int frames = 0;
	int pauseFrames = 0;
	bool birdPaused = 0;
	bool birdSick = 0;
	int sickFrames = 0;
	int birdHitCount  = 0;
	bool isBirdCollidePregenComb_lvl1[3] = {0};
	bool isBirdCollideYellowComb_lvl1[20] = {0};
	bool isBirdCollidePregenComb_lvl2[9] = {0};
	bool isBirdCollideYellowComb_lvl2[15] = {0};
	bool isBirdCollideRedComb_lvl2[5] = {0};
	bool isBirdCollidePregenComb_lvl3[15] = {0};
	bool isBirdCollideYellowComb_lvl3[20] = {0};
	bool isBirdCollideRedComb_lvl3[10] = {0};
	//pollinated flowers
	
	//initializing my arrays
	//random function to give coordinates to pre generated honeycombs
	for (int i = 0; i < 3; i++)
	{
		randomHoneyComb_x_lvl1[i] = (rand() % 900);
		randomHoneyComb_y_lvl1[i] = (rand() % 470);
	}
	for (int i = 0; i < 9; i++)
	{
		randomHoneyComb_x_lvl2[i] = (rand() % 900);
		randomHoneyComb_y_lvl2[i] = (rand() % 470);
	}
	for (int i = 0; i < 15; i++)
	{
		randomHoneyComb_x_lvl3[i] = (rand() % 900);
		randomHoneyComb_y_lvl3[i] = (rand() % 470);
	}
	//initializing all bees
	for (int i = 0; i < 20; i++)
	{
		regularBees_lvl1[i] = 1;
		regularBees_lvl3[i] = 1;	
	}
	for (int i = 0; i < 15; i++)
	{
		regularBees_lvl2[i] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		fastBees_lvl3[i] = 1;
		if (i <= 4)
		{
			fastBees_lvl2[i] = 1;
		} 
	}
	//giving half the bees the right direction
	for (int i = 0; i < 20; i++)
	{
		regularBeeRight_lvl1[i] = (i < 10) ? (1) : (0);
		regularBeeRight_lvl3[i] = (i < 10) ? (1) : (0);		
	}
	for (int i = 0; i < 15; i++)
	{
		regularBeeRight_lvl2[i] = (i < 7) ? (1) : (0);
	}
	for (int i = 0; i < 5; i++)
	{
		fastBeeRight_lvl2[i] = (i < 3) ? (1) : (0);
	}
	for (int i = 0; i < 10; i++)
	{
		fastBeeRight_lvl3[i] = (i < 5) ? (1) : (0);
	}
	//initial positions of all bees
	for (int i = 0; i < 10; i++)
	{
		regularBee_x_lvl1[i] = 0 + regularBeePosIncrement;
		regularBee_x_lvl2[i] = 0 + regularBeePosIncrement;
		regularBeePosIncrement -= 500;
	}
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 10; i < 20; i++)
	{
		regularBee_x_lvl1[i] = 900 + regularBeePosIncrement;
		regularBee_x_lvl2[i] = 900 + regularBeePosIncrement;
		regularBeePosIncrement += 500;
	}
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 0; i < 7; i++)
	{
		regularBee_x_lvl3[i] = 0 + regularBeePosIncrement;
		regularBeePosIncrement -= 500;
	}
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 7; i < 14; i++)
	{
		regularBee_x_lvl3[i] = 900 + regularBeePosIncrement;
		regularBeePosIncrement += 500;
	}
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 0; i < 3; i++)
	{
		fastBee_x_lvl2[i] = 0 + regularBeePosIncrement;
		regularBeePosIncrement -= 500;
	}
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 3; i < 5; i++)
	{
		fastBee_x_lvl2[i] = 900 + regularBeePosIncrement;
		regularBeePosIncrement += 500;
	} 
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 0; i < 5; i++)
	{
		fastBee_x_lvl3[i] = 0 + regularBeePosIncrement;
		regularBeePosIncrement -= 500;
	}
	//reset var to 0
	regularBeePosIncrement = 0;
	for (int i = 5; i < 10; i++)
	{
		fastBee_x_lvl3[i] = 900 + regularBeePosIncrement;
		regularBeePosIncrement += 500;
	}
	//positions of all yellow honeycombs
	for (int i = 0; i < 20; i++)
	{
		yellowHoneyComb_x_lvl1[i] = regularBee_x_lvl1[i];
		yellowHoneyComb_y_lvl1[i] = regularBee_y_lvl1[i];
		yellowHoneyComb_x_lvl3[i] = regularBee_x_lvl3[i];
		yellowHoneyComb_y_lvl3[i] = regularBee_y_lvl3[i];
		if (i < 15)
		{
			yellowHoneyComb_x_lvl2[i] = regularBee_x_lvl2[i];
			yellowHoneyComb_y_lvl2[i] = regularBee_y_lvl2[i];
		}
	}
	//positions of all red honeycombs
	for (int i = 0; i < 10; i++)
	{
		redHoneyComb_x_lvl3[i] = fastBee_x_lvl3[i];
		redHoneyComb_y_lvl3[i] = fastBee_y_lvl3[i];
		if (i < 5)
		{
			redHoneyComb_x_lvl2[i] = fastBee_x_lvl2[i];
			redHoneyComb_y_lvl2[i] = fastBee_y_lvl2[i];
		}
	}
	//default positions of the flowers
	for (int i = 0; i < FLOWERS; i++)
	{
		pollinatedFlower_x[i] = -600;
	}
	//some out of bounds locations for the beehives
	for (int i = 0; i < BEEHIVES; i++)
	{
		beehive_x[i] = -1000;
		beehive_y[i] = -1000;
	}
	
	//my sprites/textures
	//regular bee
	Texture regularBeeTexture;
	Sprite regularBeeSprite_lvl1[20];
	Sprite regularBeeSprite_lvl2[15];
	Sprite regularBeeSprite_lvl3[20];
	regularBeeTexture.loadFromFile("Textures/Regular_bee.png");
	//fast bee
	Texture fastBeeTexture;
	Sprite fastBeeSprite_lvl2[5];
	Sprite fastBeeSprite_lvl3[10];
	fastBeeTexture.loadFromFile("Textures/Fast_bee.png");
	//yellow honeycombs
	Texture yellowHoneyCombTexture;
	Sprite yellowHoneyCombSprite;
	yellowHoneyCombTexture.loadFromFile("Textures/honeycomb.png");
	yellowHoneyCombSprite.setTexture(yellowHoneyCombTexture);
	yellowHoneyCombSprite.setScale(0.7,0.7);
	//Red honeycombs
	Texture redHoneyCombTexture;
	Sprite redHoneyCombSprite;
	redHoneyCombTexture.loadFromFile("Textures/honeycomb_red.png");
	redHoneyCombSprite.setTexture(redHoneyCombTexture);
	redHoneyCombSprite.setScale(0.7,0.7);
	//remaining cans
	Sprite remainingCanSprite1;
	remainingCanSprite1.setTexture(playerTexture);
	remainingCanSprite1.setScale(0.7,0.7);
	Sprite remainingCanSprite2;
	remainingCanSprite2.setTexture(playerTexture);
	remainingCanSprite2.setScale(0.7,0.7);
	//flowers
	Texture flowerTexture;
	Sprite flowerSprite[FLOWERS];
	flowerTexture.loadFromFile("Textures/obstacles.png");
	//beehives
	Texture beehiveTexture;
	Sprite beehiveSprite[BEEHIVES];
	beehiveTexture.loadFromFile("Textures/hive.png");
	//hummingbird
	Texture birdTexture;
	Sprite birdSprite;
	birdTexture.loadFromFile("Textures/bird.png");
	birdSprite.setTexture(birdTexture);
	birdSprite.setColor(Color::Blue);
	birdSprite.setScale(1.5,1.5);
	birdSprite.setTextureRect(sf::IntRect(0,0,32,64));
	birdSprite.setPosition(bird_x,bird_y);
	
	//beehive sprites initialization
	for (int i = 0; i < BEEHIVES; i++)
	{
		beehiveSprite[i].setTexture(beehiveTexture);
	}
	//regular bees lvl1
	for (int i = 0; i < 20; i++)
	{
		regularBeeSprite_lvl1[i].setTexture(regularBeeTexture);
		regularBeeSprite_lvl1[i].setScale(1,1);
		regularBeeSprite_lvl1[i].setTextureRect(sf::IntRect(0,0,boxPixelsX,boxPixelsY));
		regularBeeSprite_lvl1[i].setPosition(regularBee_x_lvl1[i], regularBee_y_lvl1[i]);
	}
	//regular bees lvl2
	for (int i = 0; i < 15; i++)
	{
		regularBeeSprite_lvl2[i].setTexture(regularBeeTexture);
		regularBeeSprite_lvl2[i].setScale(1,1);
		regularBeeSprite_lvl2[i].setTextureRect(sf::IntRect(0,0,boxPixelsX,boxPixelsY));
		regularBeeSprite_lvl2[i].setPosition(regularBee_x_lvl2[i], regularBee_y_lvl2[i]);
	}
	//regular bees lvl3
	for (int i = 0; i < 20; i++)
	{
		regularBeeSprite_lvl3[i].setTexture(regularBeeTexture);
		regularBeeSprite_lvl3[i].setScale(1,1);
		regularBeeSprite_lvl3[i].setTextureRect(sf::IntRect(0,0,boxPixelsX,boxPixelsY));
		regularBeeSprite_lvl3[i].setPosition(regularBee_x_lvl3[i], regularBee_y_lvl3[i]);
	}
	//fast bees lvl2
	for (int i = 0; i < 5; i++)
	{
		fastBeeSprite_lvl2[i].setTexture(fastBeeTexture);
		fastBeeSprite_lvl2[i].setScale(1,1);
		fastBeeSprite_lvl2[i].setTextureRect(sf::IntRect(0,0,boxPixelsX,boxPixelsY));
		fastBeeSprite_lvl2[i].setPosition(fastBee_x_lvl2[i], fastBee_y_lvl2[i]);
	}
	//fast bees lvl3
	for (int i = 0; i < 10; i++)
	{
		fastBeeSprite_lvl3[i].setTexture(fastBeeTexture);
		fastBeeSprite_lvl3[i].setScale(1,1);
		fastBeeSprite_lvl3[i].setTextureRect(sf::IntRect(0,0,boxPixelsX,boxPixelsY));
		fastBeeSprite_lvl3[i].setPosition(fastBee_x_lvl3[i], fastBee_y_lvl3[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		regularBeeSprite_lvl1[i].setScale(-1,1);
		regularBeeSprite_lvl3[i].setScale(-1,1);
	}
	for (int i = 10; i < 20; i++)
	{
		regularBeeSprite_lvl1[i].setScale(1,1);
		regularBeeSprite_lvl3[i].setScale(1,1);
	}
	for (int i = 0; i < 7; i++)
	{
		regularBeeSprite_lvl2[i].setScale(-1,1);
	}
	for (int i = 7; i < 15; i++)
	{
		regularBeeSprite_lvl2[i].setScale(1,1);
	}
	for (int i = 0; i < 3; i++)
	{
		fastBeeSprite_lvl2[i].setScale(-1,1);
	}
	for (int i = 3; i < 5; i++)
	{
		fastBeeSprite_lvl2[i].setScale(1,1);
	}
	for (int i = 0; i < 5; i++)
	{
		fastBeeSprite_lvl3[i].setScale(-1,1);
	}
	for (int i = 5; i < 10; i++)
	{
		fastBeeSprite_lvl3[i].setScale(1,1);
	}
	//flowers
	for (int i = 0; i < FLOWERS; i++)
	{
		flowerSprite[i].setTexture(flowerTexture);
	}
	
	//my images
	//pause background
	Texture lvl1Background;
	lvl1Background.loadFromFile("images/lvl1bg.jpg");
	Sprite lvl1Sprite;
	lvl1Sprite.setTexture(lvl1Background);
	//lvl1 bg
	Texture lvl1BackgroundImg;
	lvl1BackgroundImg.loadFromFile("images/lvl1background.png");
	Sprite lvl1bgSprite;
	lvl1bgSprite.setTexture(lvl1BackgroundImg);
	//lvl2 bg
	Texture lvl2Background;
	lvl2Background.loadFromFile("images/lvl2bg.png");
	Sprite lvl2Sprite;
	lvl2Sprite.setTexture(lvl2Background);
	//lvl3 bg
	Texture lvl3Background;
	lvl3Background.loadFromFile("images/lvl3bg.jpg");
	Sprite lvl3Sprite;
	lvl3Sprite.setTexture(lvl3Background);
	
	// The ground on which player moves
	RectangleShape groundRectangle(Vector2f(960, 64));
	groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
	groundRectangle.setFillColor(Color::Green);
	
	//gameplay
	while (window.isOpen()) {

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				gameState = 3;
				return 0;
			}
		}

		///////////////////////////////////////////////////////////////
		//                                                           //
		// Call Your Functions Here. Some have been written for you. //
		// Be vary of the order you call them, SFML draws in order.  //
		//                                                           //
		///////////////////////////////////////////////////////////////
		//pause menu
		if (e.type == Event::KeyPressed)
		{
			if (pauseButtonClock.getElapsedTime().asSeconds() > 0.05)
			{
				if (e.key.scancode == Keyboard::Scan::R)
				{
					gamePaused = !gamePaused;
					pauseButtonClock.restart();
				}
				if (e.key.scancode == Keyboard::Scan::Q)
				{
					gameState = 0;
					pauseButtonClock.restart();
				}
			}
		}
		if (gamePaused)
		{
			Texture pauseBackground;
			pauseBackground.loadFromFile("images/lvl1bg.jpg");
			Sprite pauseSprite;
			pauseSprite.setTexture(pauseBackground);
			Font pausedFont;
			pausedFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
			Text pausedText;
			pausedText.setFont(pausedFont);
			pausedText.setString("GAME PAUSED");
			pausedText.setCharacterSize(50);
			pausedText.setFillColor(Color::Yellow);
			pausedText.setPosition(180,200);
			Text resumeText;
			resumeText.setFont(pausedFont);
			resumeText.setString("PRESS R TO RESUME");
			resumeText.setCharacterSize(30);
			resumeText.setFillColor(Color::Magenta);
			resumeText.setPosition(250,300);
			Text quitText;
			quitText.setFont(pausedFont);
			quitText.setString("PRESS Q TO QUIT");
			quitText.setCharacterSize(30);
			quitText.setFillColor(Color::Red);
			quitText.setPosition(250,350);
			window.clear();
			window.draw(pauseSprite);
			window.draw(pausedText);
			window.draw(resumeText);
			window.draw(quitText);
			window.display();
		}
		
		
		if(gamePaused == 0)
		{
		//keep music looping even after it ends ----
		//add sound effects ------
		//game over if stuck and no cans ------
		//music
		playMusic(lvl1Music,lvl2Music,lvl3Music,levelState);
		if (levelState == 1)
		{
			window.draw(lvl1bgSprite);
		}
		else if (levelState == 2)
		{
			window.draw(lvl2Sprite);
		}
		else if (levelState == 3)
		{
			window.draw(lvl3Sprite);
		}
		
		//shoots the bullet by pressing spacebar
		if (e.type == Event::KeyPressed)
		{
			if (e.key.scancode == Keyboard::Scan::Space)
			{
				if (bullet_x == player_x && bullet_y == player_y)
				{
					//bullet sound effect only when the bullet is shot
					shoot.play();
					shoot.setVolume(50);
					//increases the bullet count
					increaseBulletCount(bulletCount);
				}
				//sets it to exist
				bullet_exists = true;
			}
		}
		//moves and draws the bullet if it exists
		if (bullet_exists == true)
		{
			if (levelState == 1)
			{
				moveBullet_lvl1(bullet_y,bullet_exists,bulletClock, isRegularBeeShot_lvl1, bullet_x,regularBee_x_lvl1,regularBee_y_lvl1,yellowHoneyComb_x_lvl1,yellowHoneyComb_y_lvl1,hit, regularBeeShotProcessed_lvl1,window, yellowHoneyCombSprite,regularBees_lvl1,yellowHoneyCombs_lvl1, pregenYellowHoneyCombs_lvl1,randomHoneyComb_x_lvl1, randomHoneyComb_y_lvl1, beehives,beehive_x,beehive_y, bird_y,bird_x,birdHitCount,BEEHIVES);
			}
			else if (levelState == 2)
			{
				moveBullet_lvl2(bullet_y,bullet_exists,bulletClock,isRegularBeeShot_lvl2, isFastBeeShot_lvl2,bullet_x,regularBee_x_lvl2,fastBee_x_lvl2,regularBee_y_lvl2,fastBee_y_lvl2, yellowHoneyComb_x_lvl2 ,yellowHoneyComb_y_lvl2,redHoneyComb_x_lvl2,redHoneyComb_y_lvl2, hit,regularBeeShotProcessed_lvl2,fastBeeShotProcessed_lvl2,window,yellowHoneyCombSprite, redHoneyCombSprite,regularBees_lvl2,fastBees_lvl2,yellowHoneyCombs_lvl2,redHoneyCombs_lvl2, pregenYellowHoneyCombs_lvl2,randomHoneyComb_x_lvl2,randomHoneyComb_y_lvl2,beehives,beehive_x, beehive_y, bird_y, bird_x,birdHitCount,BEEHIVES);
			}
			else if (levelState == 3)
			{
				moveBullet_lvl3(bullet_y,bullet_exists,bulletClock,isRegularBeeShot_lvl3, isFastBeeShot_lvl3,bullet_x,regularBee_x_lvl3,fastBee_x_lvl3,regularBee_x_lvl3,regularBee_y_lvl3,fastBee_y_lvl3, yellowHoneyComb_y_lvl3,redHoneyComb_x_lvl3,redHoneyComb_y_lvl3, hit,regularBeeShotProcessed_lvl3,fastBeeShotProcessed_lvl3,window,yellowHoneyCombSprite, redHoneyCombSprite,regularBees_lvl3,fastBees_lvl3,yellowHoneyCombs_lvl3,redHoneyCombs_lvl3, pregenYellowHoneyCombs_lvl3,randomHoneyComb_x_lvl3,randomHoneyComb_y_lvl3,beehives,beehive_x, beehive_y, bird_y, bird_x,birdHitCount,BEEHIVES);
			}
			drawBullet(window, bullet_x, bullet_y, bulletSprite);
		}
		else
		{
			bullet_x = player_x;
			bullet_y = player_y;
		}
		//draws and renders the player along with the ground rectangle
		drawPlayer(window, player_x, player_y, playerSprite);
		//draws player health bar
		drawPlayerHealth(window,health, player_x, player_y);
		//draws beehive
		drawBeehive(window,beehiveSprite,BEEHIVES,beehive_x,beehive_y, beehives);
		//displays the ground
		window.draw(groundRectangle);
		//displays player score
		showScore(window, score);
		//draws the amount of cans left in the bottom left corner of the screen
		drawRemainingCans(window, remainingCanSprite1,remainingCanSprite2, can1_x, can1_y, remainingCanCount);
		//draws yellow honeycomb if regular bee has been shot
		//lvl1
		if (levelState == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				if (regularBeeShotProcessed_lvl1[i])
				{
					score += 100;
					regularBeeShotProcessed_lvl1[i]  = 0;
					yellowHoneyComb_x_lvl1[i] = regularBee_x_lvl1[i];
					yellowHoneyComb_y_lvl1[i] = regularBee_y_lvl1[i];
					regularBee_x_lvl1[i] = -100;
					regularBee_y_lvl1[i] = 800;
					hit.play();
					hit.setVolume(50);
					yellowHoneyCombProcessed_lvl1[i]= 1;
				}
			}
		}
		//lvl2
		else if (levelState == 2)
		{
			for (int i = 0; i < 15; i++)
			{
				if (regularBeeShotProcessed_lvl2[i])
				{
					score += 100;
					regularBeeShotProcessed_lvl2[i]  = 0;
					yellowHoneyComb_x_lvl2[i] = regularBee_x_lvl2[i];
					yellowHoneyComb_y_lvl2[i] = regularBee_y_lvl2[i];
					regularBee_x_lvl2[i] = -100;
					regularBee_y_lvl2[i] = 800;
					hit.play();
					hit.setVolume(50);
					yellowHoneyCombProcessed_lvl2[i]= 1;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (fastBeeShotProcessed_lvl2[i])
				{
					score += 1000;
					fastBeeShotProcessed_lvl2[i]  = 0;
					redHoneyComb_x_lvl2[i] = fastBee_x_lvl2[i];
					redHoneyComb_y_lvl2[i] = fastBee_y_lvl2[i];
					fastBee_x_lvl2[i] = -100;
					fastBee_y_lvl2[i] = 800;
					hit.play();
					hit.setVolume(50);
					redHoneyCombProcessed_lvl2[i]= 1;
				}
			}
		}
		//lvl 3
		else if (levelState == 3)
		{
			for (int i = 0; i < 20; i++)
			{
				if (regularBeeShotProcessed_lvl3[i])
				{
					score += 100;
					regularBeeShotProcessed_lvl3[i]  = 0;
					yellowHoneyComb_x_lvl3[i] = regularBee_x_lvl3[i];
					yellowHoneyComb_y_lvl3[i] = regularBee_y_lvl3[i];
					regularBee_x_lvl3[i] = -100;
					regularBee_y_lvl3[i] = 800;
					hit.play();
					hit.setVolume(50);
					yellowHoneyCombProcessed_lvl3[i]= 1;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (fastBeeShotProcessed_lvl3[i])
				{
					score += 1000;
					fastBeeShotProcessed_lvl3[i]  = 0;
					redHoneyComb_x_lvl3[i] = fastBee_x_lvl3[i];
					redHoneyComb_y_lvl3[i] = fastBee_y_lvl3[i];
					fastBee_x_lvl3[i] = -100;
					fastBee_y_lvl3[i] = 800;
					hit.play();
					hit.setVolume(50);
					redHoneyCombProcessed_lvl3[i]= 1;
				}
			}
		}
		if (levelState == 1)
		{
			//drawing pre generated honeycombs for level 1
			for (int i = 0; i < 3; i++)
			{
				if (pregenYellowHoneyCombs_lvl1[i])
				{
					yellowHoneyCombSprite.setPosition(randomHoneyComb_x_lvl1[i], randomHoneyComb_y_lvl1[i]);
					window.draw(yellowHoneyCombSprite);
				}
			}
		}
		else if (levelState == 2)
		{
			//drawing pre generated honeycombs for level 2
			for (int i = 0; i < 9; i++)
			{
				if (pregenYellowHoneyCombs_lvl2[i])
				{
					yellowHoneyCombSprite.setPosition(randomHoneyComb_x_lvl2[i], randomHoneyComb_y_lvl2[i]);
					window.draw(yellowHoneyCombSprite);
				}
			}
		}
		else if (levelState == 3)
		{
			//drawing pre generated honeycombs for level 3
			for (int i = 0; i < 15; i++)
			{
				if (pregenYellowHoneyCombs_lvl3[i])
				{
					yellowHoneyCombSprite.setPosition(randomHoneyComb_x_lvl3[i], randomHoneyComb_y_lvl3[i]);
					window.draw(yellowHoneyCombSprite);
				}
			}
		}
		//lvl1 honeycombs
		if (levelState == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				if (yellowHoneyCombProcessed_lvl1[i] == 1 && yellowHoneyCombs_lvl1[i] == 1)
				{
					drawYellowHoneyComb_lvl1(window,yellowHoneyCombSprite,yellowHoneyComb_x_lvl1,yellowHoneyComb_y_lvl1, i);
				}
			}
		}
		//lvl2 honeycombs
		if (levelState == 2)
		{
			for (int i = 0; i < 15; i++)
			{
				if (yellowHoneyCombProcessed_lvl2[i] == 1 && yellowHoneyCombs_lvl2[i] == 1)
				{
					drawYellowHoneyComb_lvl2(window,yellowHoneyCombSprite,yellowHoneyComb_x_lvl2,yellowHoneyComb_y_lvl2, i);
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (redHoneyCombProcessed_lvl2[i] == 1 && redHoneyCombs_lvl2[i] == 1)
				{
					drawRedHoneyComb_lvl2(window,redHoneyCombSprite,redHoneyComb_x_lvl2,redHoneyComb_y_lvl2, i);
				}
			}
		}
		//lvl3 honeycombs
		if (levelState == 3)
		{
			for (int i = 0; i < 20; i++)
			{
				if (yellowHoneyCombProcessed_lvl3[i] == 1 && yellowHoneyCombs_lvl3[i] == 1)
				{
					drawYellowHoneyComb_lvl3(window,yellowHoneyCombSprite,yellowHoneyComb_x_lvl3,yellowHoneyComb_y_lvl3, i);
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (redHoneyCombProcessed_lvl3[i] == 1 && redHoneyCombs_lvl3[i] == 1)
				{
					drawRedHoneyComb_lvl3(window,redHoneyCombSprite,redHoneyComb_x_lvl3,redHoneyComb_y_lvl3, i);
				}
			}
		}
		//moves the bee, sets a delay aswell
		if (levelState == 1)
		{
			if (regularBeeClock.getElapsedTime().asMilliseconds() > 20)
			{
				moveRegularBee_lvl1(regularBee_x_lvl1, regularBee_y_lvl1, regularBeeRight_lvl1,regularBeeSprite_lvl1, regularBees_lvl1, window, isBeeStopped_lvl1, beeStopClock_lvl1); 
				pauseBees_lvl1( beeStopClock_lvl1, isBeeStopped_lvl1);
				regularBeeClock.restart();
			}
		}
		else if (levelState == 2)
		{
			if (regularBeeClock.getElapsedTime().asMilliseconds() > 20)
			{
				moveRegularBee_lvl2(regularBee_x_lvl2, regularBee_y_lvl2, regularBeeRight_lvl2,regularBeeSprite_lvl2, regularBees_lvl2, window, isBeeStopped_lvl2, beeStopClock_lvl2); 
				pauseBees_lvl2( beeStopClock_lvl2, isBeeStopped_lvl2);
				regularBeeClock.restart();
			}
			if (fastBeeClock.getElapsedTime().asMilliseconds() > 20)
			{
				moveFastBee_lvl2(fastBee_x_lvl2, fastBee_y_lvl2, fastBeeRight_lvl2,fastBeeSprite_lvl2, fastBees_lvl2, window); 
				fastBeeClock.restart();
			}
		}
		else if (levelState == 3)
		{
			if (regularBeeClock.getElapsedTime().asMilliseconds() > 20)
			{
				moveRegularBee_lvl3(regularBee_x_lvl3, regularBee_y_lvl3, regularBeeRight_lvl3,regularBeeSprite_lvl3, regularBees_lvl3, window, isBeeStopped_lvl3, beeStopClock_lvl3); 
				pauseBees_lvl3( beeStopClock_lvl3, isBeeStopped_lvl3);
				regularBeeClock.restart();
			}
			if (fastBeeClock.getElapsedTime().asMilliseconds() > 20)
			{
				moveFastBee_lvl3(fastBee_x_lvl3, fastBee_y_lvl3, fastBeeRight_lvl3,fastBeeSprite_lvl3, fastBees_lvl3, window); 
				fastBeeClock.restart();
			}
		}
		//draws the bees
		if (levelState == 1)
		{
			drawRegularBee_lvl1(window, regularBeeSprite_lvl1, regularBee_x_lvl1, regularBee_y_lvl1, regularBees_lvl1);
		}
		else if (levelState == 2)
		{
			drawRegularBee_lvl2(window, regularBeeSprite_lvl2, regularBee_x_lvl2, regularBee_y_lvl2, regularBees_lvl2);
			drawFastBee_lvl2(window, fastBeeSprite_lvl2, fastBee_x_lvl2, fastBee_y_lvl2, fastBees_lvl2);
		}
		else if (levelState == 3)
		{
			drawRegularBee_lvl3(window, regularBeeSprite_lvl3, regularBee_x_lvl3, regularBee_y_lvl3, regularBees_lvl3);
			drawFastBee_lvl3(window, fastBeeSprite_lvl3, fastBee_x_lvl3, fastBee_y_lvl3, fastBees_lvl3);
		}
		//moves the bird
		moveBird(frames, randomDirection, currentDirection, bird_x, bird_y, birdDirections, birdPaused, pauseFrames,birdHitCount, birdSick,sickFrames,birdSprite);
		//has bird reached a comb
		if (levelState == 1)
		{
			birdCollideComb_lvl1(bird_y,bird_x,randomHoneyComb_x_lvl1,randomHoneyComb_y_lvl1, yellowHoneyComb_x_lvl1,yellowHoneyComb_y_lvl1 ,birdPaused, isBirdCollidePregenComb_lvl1, isBirdCollideYellowComb_lvl1, yellowHoneyCombs_lvl1, pregenYellowHoneyCombs_lvl1, birdSick, score);
		}
		else if (levelState == 2)
		{
			birdCollideComb_lvl2(bird_y, bird_x,randomHoneyComb_x_lvl2, randomHoneyComb_y_lvl2, yellowHoneyComb_x_lvl2,yellowHoneyComb_y_lvl2,redHoneyComb_x_lvl2,redHoneyComb_y_lvl2, birdPaused,  isBirdCollidePregenComb_lvl2,isBirdCollideYellowComb_lvl2,isBirdCollideRedComb_lvl2, yellowHoneyCombs_lvl2, redHoneyCombs_lvl2,pregenYellowHoneyCombs_lvl2,birdSick,score);
		}
		else if (levelState == 3)
		{
			birdCollideComb_lvl3(bird_y, bird_x,randomHoneyComb_x_lvl3, randomHoneyComb_y_lvl3, yellowHoneyComb_x_lvl3,yellowHoneyComb_y_lvl3,redHoneyComb_x_lvl3,redHoneyComb_y_lvl3, birdPaused,  isBirdCollidePregenComb_lvl3,isBirdCollideYellowComb_lvl3,isBirdCollideRedComb_lvl3, yellowHoneyCombs_lvl3, redHoneyCombs_lvl3,pregenYellowHoneyCombs_lvl3,birdSick,score);
		}
		//draws the bird
		drawBird(window, birdSprite, bird_x, bird_y);
		//checks if flower is to be pollinated
		if (levelState == 1)
		{
			pollinateFlowers_lvl1(isPollinated, regularBee_x_lvl1, regularBee_y_lvl1, pollinatedFlower_x, pollinatedFlower_y, isFlowerProcessed,regularBees_lvl1, regularBeeRight_lvl1, flowerPlaced, leftCornerProcessed, rightCornerProcessed,placeRightFlowers, placeLeftFlowers);
		}
		else if (levelState == 2)
		{
			pollinateFlowers_lvl2(isPollinated, regularBee_x_lvl2, regularBee_y_lvl2, fastBee_x_lvl2, fastBee_y_lvl2, pollinatedFlower_x, pollinatedFlower_y, isFlowerProcessed,regularBees_lvl2,fastBees_lvl2, regularBeeRight_lvl2,fastBeeRight_lvl2, flowerPlaced, leftCornerProcessed, rightCornerProcessed, placeRightFlowers, placeLeftFlowers);
		}
		else if (levelState == 3)
		{
			pollinateFlowers_lvl3(isPollinated, regularBee_x_lvl3, regularBee_y_lvl3, fastBee_x_lvl3, fastBee_y_lvl3, pollinatedFlower_x, pollinatedFlower_y, isFlowerProcessed,regularBees_lvl3,fastBees_lvl3, regularBeeRight_lvl3,fastBeeRight_lvl3, flowerPlaced, leftCornerProcessed, rightCornerProcessed, placeRightFlowers, placeLeftFlowers);
		}
		//draws the pollinated flowers
		drawFlowers(window,flowerSprite, pollinatedFlower_x, pollinatedFlower_y, isPollinated, leftCornerProcessed, rightCornerProcessed,placeRightFlowers, placeLeftFlowers);
		//displays and clears the window
		window.display();
		window.clear();
		//to move the player left and right
		if (e.type == Event::KeyPressed)
		{
			//this avoids buffer issues by setting a delay
			if (movementClock.getElapsedTime().asSeconds() > 0.05)
			{
				if (e.key.scancode == Keyboard::Scan::Left)
				{
					movePlayerLeft(player_x,playerSprite, movementClock, obstacle, pollinatedFlower_x, isPollinated);
					movementClock.restart();
				}
				else if (e.key.scancode == Keyboard::Scan::Right)
				{
					movePlayerRight(player_x,playerSprite, movementClock, obstacle, isPollinated,pollinatedFlower_x);
					movementClock.restart();
				}
			}
		}
		//checks if the bee collides with the comb
		if (levelState == 1)
		{
			beeCollideComb_lvl1(regularBee_x_lvl1,regularBee_y_lvl1, isRegularBeeCollideComb_lvl1, randomHoneyComb_x_lvl1, randomHoneyComb_y_lvl1,regularBeeRight_lvl1, regularBeeSprite_lvl1, yellowHoneyCombs_lvl1, yellowHoneyComb_x_lvl1,yellowHoneyComb_y_lvl1,collideClock_lvl1,beehives, beehive_x, beehive_y, regularBees_lvl1);
		}
		else if (levelState == 2)
		{
			beeCollideComb_lvl2(regularBee_x_lvl2, regularBee_y_lvl2,isRegularBeeCollideComb_lvl2, randomHoneyComb_x_lvl2,randomHoneyComb_y_lvl2,regularBeeRight_lvl2,regularBeeSprite_lvl2, yellowHoneyCombs_lvl2,redHoneyCombs_lvl2,yellowHoneyComb_x_lvl2,yellowHoneyComb_y_lvl2, redHoneyComb_x_lvl2, redHoneyComb_y_lvl2,collideClock_lvl2, beehives,beehive_x,beehive_y, regularBees_lvl2);
		}
		else if (levelState == 3)
		{
			beeCollideComb_lvl3(regularBee_x_lvl3, regularBee_y_lvl3,isRegularBeeCollideComb_lvl3, randomHoneyComb_x_lvl3,randomHoneyComb_y_lvl3,regularBeeRight_lvl3,regularBeeSprite_lvl3, yellowHoneyCombs_lvl3,redHoneyCombs_lvl3,yellowHoneyComb_x_lvl3,yellowHoneyComb_y_lvl3, redHoneyComb_x_lvl3, redHoneyComb_y_lvl3,collideClock_lvl3, beehives,beehive_x,beehive_y, regularBees_lvl3);
		}
		//checks if regular bee had a collision with player
		if (levelState == 1)
		{
			beeCollidePlayer_lvl1(regularBee_x_lvl1, regularBee_y_lvl1, player_x, player_y,isRegularBeeCollidePlayer_lvl1, isRegularBeeCollidePlayerProcessed_lvl1);
		}
		else if (levelState == 2)
		{
			beeCollidePlayer_lvl2(regularBee_x_lvl2, regularBee_y_lvl2,fastBee_x_lvl2,fastBee_y_lvl2, player_x, player_y,isRegularBeeCollidePlayer_lvl2,isFastBeeCollidePlayer_lvl2, isRegularBeeCollidePlayerProcessed_lvl2,isFastBeeCollidePlayerProcessed_lvl2);
		}
		else if (levelState == 3)
		{
			beeCollidePlayer_lvl3(regularBee_x_lvl3, regularBee_y_lvl3,fastBee_x_lvl3,fastBee_y_lvl3, player_x, player_y,isRegularBeeCollidePlayer_lvl3,isFastBeeCollidePlayer_lvl3, isRegularBeeCollidePlayerProcessed_lvl3,isFastBeeCollidePlayerProcessed_lvl3);
		}
		//checks if multiple of 8 amount of bullets have been shot
		bulletsX8(bulletCount,areBulletsX8,LOWER_HEALTH);
		//reduces player health if certain conditions are met
		if (levelState == 1)
		{
			reducePlayerHealth_lvl1(health,isRegularBeeCollidePlayer_lvl1, LOWER_HEALTH,areBulletsX8, isRegularBeeCollidePlayerProcessed_lvl1);
		}
		else if (levelState == 2)
		{
			reducePlayerHealth_lvl2(health,isRegularBeeCollidePlayer_lvl2,isFastBeeCollidePlayer_lvl2, LOWER_HEALTH,areBulletsX8, isRegularBeeCollidePlayerProcessed_lvl2,isFastBeeCollidePlayerProcessed_lvl2);
		}
		else if (levelState == 3)
		{
			reducePlayerHealth_lvl3(health,isRegularBeeCollidePlayer_lvl3,isFastBeeCollidePlayer_lvl3, LOWER_HEALTH,areBulletsX8, isRegularBeeCollidePlayerProcessed_lvl3,isFastBeeCollidePlayerProcessed_lvl3);
		}
		//checks if player has died
		playerDeath(health, remainingCanCount, remainingCanIndex, gameOver,FLOWERS, isPollinated, rightCornerProcessed, leftCornerProcessed, placeLeftFlowers, placeRightFlowers);
		//changes levels
		if (levelState == 1)
		{
			levelTransition1( levelState, window, regularBees_lvl1, score);
			//resetting variables
			if (levelState == 2)
			{
				bullet_x = player_x; 
				bullet_y = player_y;
				bullet_exists = false;
				bulletCount = 0;
				health = 100;
				areBulletsX8 = 0;
				gameOver = 0;
				leftCornerProcessed = 0;
				rightCornerProcessed = 0;
				placeRightFlowers = 0;
				placeLeftFlowers = 0;
				for (int i = 0; i < BEEHIVES; i++)
				{
					beehives[i] = 0;
					beehive_x[i] = -1000;
					beehive_y[i] = -1000;
				}
				for (int i = 0; i < FLOWERS; i++)
				{
					isPollinated[i] = 0;
					isFlowerProcessed[i] = 0;
					flowerPlaced[i] = 0;
					pollinatedFlower_x[i] = -600;
				}
				currentDirection = 3;
				bird_x = 0;
				bird_y = 0;
				frames = 0;
				pauseFrames = 0;
				birdPaused = 0;
				birdSick = 0;
				sickFrames = 0;
				birdHitCount  = 0;
				birdSprite.setColor(Color::Blue);
				//adding beehive score
				for (int i = 0; i < BEEHIVES; i++)
				{
					if (beehives[i] == 1)
					{
						int position = beehive_y[i] / 64;
						if (position == 1 || position == 2)
						{
							score += 2000;
						}
						else if (position == 3 || position == 4 || position == 5)
						{
							score += 1600;
						}
						else
						{
							score += 1000;
						}
					}
				}
			}
		}
		else if (levelState == 2)
		{
			levelTransition2(levelState, window, regularBees_lvl2, fastBees_lvl2, score);
			//resetting variables
			if (levelState == 3)
			{
				bullet_x = player_x; 
				bullet_y = player_y;
				bullet_exists = false;
				bulletCount = 0;
				health = 100;
				areBulletsX8 = 0;
				gameOver = 0;
				leftCornerProcessed = 0;
				rightCornerProcessed = 0;
				placeRightFlowers = 0;
				placeLeftFlowers = 0;
				for (int i = 0; i < BEEHIVES; i++)
				{
					beehives[i] = 0;
					beehive_x[i] = -1000;
					beehive_y[i] = -1000;
				}
				for (int i = 0; i < FLOWERS; i++)
				{
					isPollinated[i] = 0;
					isFlowerProcessed[i] = 0;
					flowerPlaced[i] = 0;
					pollinatedFlower_x[i] = -600;
				}
				currentDirection = 3;
				bird_x = 0;
				bird_y = 0;
				frames = 0;
				pauseFrames = 0;
				birdPaused = 0;
				birdSick = 0;
				sickFrames = 0;
				birdHitCount  = 0;
				birdSprite.setColor(Color::Blue);
				//adding beehive score
				for (int i = 0; i < BEEHIVES; i++)
				{
					if (beehives[i] == 1)
					{
						int position = beehive_y[i] / 64;
						if (position == 1 || position == 2)
						{
							score += 2000;
						}
						else if (position == 3 || position == 4 || position == 5)
						{
							score += 1600;
						}
						else
						{
							score += 1000;
						}
					}
				}
			}
		}
		else if (levelState == 3)
		{
			gameCompleted(levelState,window,regularBees_lvl3,fastBees_lvl3, score, isGameCompleted);
			//adding beehive score
			if (isGameCompleted)
			{
				for (int i = 0; i < BEEHIVES; i++)
				{
					if (beehives[i] == 1)
					{
						int position = beehive_y[i] / 64;
						if (position == 1 || position == 2)
						{
							score += 2000;
						}
						else if (position == 3 || position == 4 || position == 5)
						{
							score += 1600;
						}
						else
						{
							score += 1000;
						}
					}
				}
			}
		}
		//will prompt the player for their name
		if (gameOver || isGameCompleted)
		{
			enterName(window, playerName, score, nameSubmitted);
			if (nameSubmitted)
			{
				gameOver = 0;
				isGameCompleted = 0;
				displayScores(window, gameState,playerNames, highScores);
			}
		}
		if (gameOver)
		{
			gameOverScreen(window, score);
		}
		//awards bonus cans if certain criteria is met
		bonusCans(remainingCanCount, score, BONUS_CAN_SCORE);
	}
	}
}

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Write your functions definitions here. Some have been written for you. //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

//opens the menu
void menu(RenderWindow& window, int& gameState)
{
	//loading the font to be used for the menu
	Font menuFont;
	menuFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
	//background image for menu
	Texture menuBackground;
	menuBackground.loadFromFile("images/menubg2.png");
	Sprite menuSprite;
	menuSprite.setTexture(menuBackground);
	//displaying the logo
	Text logo("Buzz Bombers", menuFont, 50);
	logo.setPosition(180, 100);
	logo.setFillColor(Color::Green);
	//displaying the play button
	Text playButton("-> PRESS P TO PLAY GAME", menuFont, 30);
	playButton.setPosition(100,250);
	playButton.setFillColor(Color::White);
	//displaying the choose level button
	Text levelButton("-> PRESS L TO CHOOSE LEVELS",menuFont, 30);
	levelButton.setPosition(100,300);
	levelButton.setFillColor(Color::Blue);
	//displaying the highscore button
	Text highscoreButton("-> PRESS H FOR HIGHSCORES",menuFont, 30);
	highscoreButton.setPosition(100,350);
	highscoreButton.setFillColor(Color::Magenta);
	//displaying the exit button
	Text exitButton("-> PRESS E TO EXIT",menuFont, 30);
	exitButton.setPosition(100,400);
	exitButton.setFillColor(Color::Red);
	//text with my name and details
	Text details("By Hassan Rizwan - CS1002 Final Project",menuFont, 15);
	details.setPosition(180,600);
	details.setFillColor(Color::White);
	//playing the bgm for the menu
	Music bgMusic;
	bgMusic.openFromFile("Music/magical_journey.ogg");
	bgMusic.play();
	bgMusic.setVolume(50);
	//now running the menu loop
	while (window.isOpen() && gameState == 0)
	{
		Event e;
		while (window.pollEvent(e))
		{
			//exits the program
			if (e.type == Event::Closed)
			{
				gameState = 3;
				exit(0);
			}
			//checks for different options
			if (e.type == Event::KeyPressed)
			{
				//starts playing the game
				if (e.key.scancode == Keyboard::Scan::P)
				{
					gameState = 1;
					bgMusic.stop();
					return;
				}
				//opens the choose level menu
				else if (e.key.scancode == Keyboard::Scan::L)
				{
					gameState = 2;
					bgMusic.stop();
					return;
				}
				else if (e.key.scancode == Keyboard::Scan::H)
				{
					gameState = 4; //for the highscores
				}
				//exits the game
				else if (e.key.scancode == Keyboard::Scan::E)
				{
					gameState = 3;
					exit(0);
				} 
			}
			window.clear();
			window.draw(menuSprite);
			window.draw(logo);
			window.draw(playButton);
			window.draw(levelButton);
			window.draw(highscoreButton);
			window.draw(exitButton);
			window.draw(details);
			window.display();
		}
	}
}
//level select menu
void levelSelect(RenderWindow& window, int& levelState, int& gameState)
{
	Font menuFont;
	menuFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
	//background image for menu
	Texture levelBackground;
	levelBackground.loadFromFile("images/menubg1.jpg");
	Sprite levelSprite;
	levelSprite.setTexture(levelBackground);
	//level 1
	Text Level1("-> PRESS 1 TO PLAY LEVEL 1", menuFont, 30);
	Level1.setPosition(100,250);
	Level1.setFillColor(Color::White);
	//level 2
	Text Level2("-> PRESS 2 TO PLAY LEVEL 2",menuFont, 30);
	Level2.setPosition(100,300);
	Level2.setFillColor(Color::Blue);
	//level 3
	Text Level3("-> PRESS 3 TO PLAY LEVEL 3",menuFont, 30);
	Level3.setPosition(100,350);
	Level3.setFillColor(Color::Red);
	//main menu
	Text mainMenu("-> PRESS E TO GO TO BACK",menuFont, 30);
	mainMenu.setPosition(100,400);
	mainMenu.setFillColor(Color::White);
	//playing the bgm for the menu
	Music bgMusic;
	bgMusic.openFromFile("Music/magical_journey.ogg");
	bgMusic.play();
	bgMusic.setVolume(50);
	//now running the level select menu loop
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			//exits the program
			if (e.type == Event::Closed)
			{
				gameState = 3;
				exit(0);
			}
			//checks for different options
			if (e.type == Event::KeyPressed)
			{
				if (e.key.scancode == Keyboard::Scan::Num1)
				{
					gameState = 1;
					levelState = 1;
					bgMusic.stop();
					return;
				}
				if (e.key.scancode == Keyboard::Scan::Num2)
				{
					gameState = 1;
					levelState = 2;
					bgMusic.stop();
					return;
				}
				if (e.key.scancode == Keyboard::Scan::Num3)
				{
					gameState = 1;
					levelState = 3;
					bgMusic.stop();
					return;
				}
				if (e.key.scancode == Keyboard::Scan::E)
				{
					gameState = 0;
					bgMusic.stop();
					return;
				}
			}
			window.clear();
			window.draw(levelSprite);
			window.draw(Level1);
			window.draw(Level2);
			window.draw(Level3);
			window.draw(mainMenu);
			window.display();
		}
	}
}
//draws and renders the player
void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite) {
	playerSprite.setPosition(player_x, player_y);
	window.draw(playerSprite);
}
//moves the shot bullet for lvl1
void moveBullet_lvl1(float& bullet_y,bool& bullet_exists, Clock& bulletClock,bool isRegularBeeShot_lvl1[],float& bullet_x, float regularBee_x_lvl1[], float regularBee_y_lvl1[], float yellowHoneyComb_x_lvl1[],float yellowHoneyComb_y_lvl1[], Sound& hit,bool regularBeeShotProcessed_lvl1[],RenderWindow& window, Sprite& yellowHoneyCombSprite,bool regularBees_lvl1[],bool yellowHoneyCombs_lvl1[], bool pregenYellowHoneyCombs_lvl1[],int randomHoneyComb_x_lvl1[], int randomHoneyComb_y_lvl1[],bool beehives[],float beehive_x[],float beehive_y[],float& bird_y,float& bird_x,int& birdHitCount,const int BEEHIVES) {
	if (bulletClock.getElapsedTime().asMilliseconds() < 20)
		return;

	bulletClock.restart();
	bullet_y -= 14;
	if (bullet_y < -32)
		bullet_exists = false;
	
	//lvl 1, checks for collision between bee and bullets
	for (int i = 0; i < 20; i++) 
	{
		float bullet_height = bullet_y + (16*3);
		float bullet_length = bullet_x + (16*3);
		float regularBee_height = regularBee_y_lvl1[i] + (22*1);
		float regularBee_length = regularBee_x_lvl1[i] + (46*1);
		float honeyComb_height = yellowHoneyComb_y_lvl1[i] + (64*0.7);
		float honeyComb_length = yellowHoneyComb_x_lvl1[i] + (64*0.7);
		float pregenHoneyComb_height = randomHoneyComb_y_lvl1[i] + (64*0.7);
		float pregenHoneyComb_length = randomHoneyComb_x_lvl1[i] + (64*0.7);
		float hive_height = beehive_y[i] + (64*1);
		float hive_length = beehive_x[i] + (64*1);
		//bee and bullet
		if (bullet_length >= regularBee_x_lvl1[i] && bullet_x <= regularBee_length && bullet_height >= regularBee_y_lvl1[i] && bullet_y <= regularBee_height && regularBees_lvl1[i] == 1)
		{
			regularBees_lvl1[i] = 0;
			regularBeeShotProcessed_lvl1[i] = 1;
			bullet_exists = false;
			yellowHoneyCombs_lvl1[i] = 1;
			yellowHoneyComb_x_lvl1[i] = regularBee_x_lvl1[i];
			yellowHoneyComb_y_lvl1[i] = regularBee_y_lvl1[i];
		}
		//bullet and yellow comb
		if (bullet_length >= yellowHoneyComb_x_lvl1[i] && bullet_x <= honeyComb_length && bullet_height >= yellowHoneyComb_y_lvl1[i] && bullet_y <= honeyComb_height && yellowHoneyCombs_lvl1[i] == 1)
		{
			yellowHoneyCombs_lvl1[i] = 0;
			bullet_exists = false;
		}
		//bullet and pregen comb
		if (bullet_length >= randomHoneyComb_x_lvl1[i] && bullet_x <= pregenHoneyComb_length && bullet_height >= randomHoneyComb_y_lvl1[i] && bullet_y <= pregenHoneyComb_height && pregenYellowHoneyCombs_lvl1[i] == 1)
		{
			randomHoneyComb_x_lvl1[i] = -800;
			randomHoneyComb_y_lvl1[i] = -800;
			pregenYellowHoneyCombs_lvl1[i] = 0;
			bullet_exists = false;
		}
		//bullet and hive
		if (bullet_length >= beehive_x[i] && bullet_x <= hive_length && bullet_height >= beehive_y[i] && bullet_y <= hive_height && beehives[i] == 1)
		{
			beehives[i] = 0;
			bullet_exists = false;
		}
	}
		float bullet_height = bullet_y + (16*3);
		float bullet_length = bullet_x + (16*3);
		float bird_height = bird_y + (32*1.5);
		float bird_length = bird_x + (64*1.5);
		//bullet and bird
		if (bullet_length >= bird_x && bullet_x <= bird_length && bullet_height >= bird_y && bullet_y <= bird_height)
		{
			birdHitCount++;
			bullet_exists = false;
		}	
}
//moves bullet for lvl 2
void moveBullet_lvl2(float& bullet_y,bool& bullet_exists, Clock& bulletClock,bool isRegularBeeShot_lvl2[],bool isFastBeeShot_lvl2[],float& bullet_x,float regularBee_x_lvl2[],float fastBee_x_lvl2[],float regularBee_y_lvl2[],float fastBee_y_lvl2[],float yellowHoneyComb_x_lvl2[],float yellowHoneyComb_y_lvl2[],float redHoneyComb_x_lvl2[],float redHoneyComb_y_lvl2[],Sound& hit,bool regularBeeShotProcessed_lvl2[],bool fastBeeShotProcessed_lvl2[],RenderWindow& window, Sprite& yellowHoneyCombSprite,Sprite& redHoneyCombSprite,bool regularBees_lvl2[],bool fastBees_lvl2[],bool yellowHoneyCombs_lvl2[],bool redHoneyCombs_lvl2[], bool pregenYellowHoneyCombs_lvl2[],int randomHoneyComb_x_lvl2[], int randomHoneyComb_y_lvl2[],bool beehives[],float beehive_x[],float beehive_y[],float& bird_y,float& bird_x,int& birdHitCount,const int BEEHIVES)
{
	if (bulletClock.getElapsedTime().asMilliseconds() < 20)
		return;

	bulletClock.restart();
	bullet_y -= 14;
	if (bullet_y < -32)
		bullet_exists = false;
		
	//worker bees
	for (int i = 0; i < 15; i++) 
	{
		float bullet_height = bullet_y + (16*3);
		float bullet_length = bullet_x + (16*3);
		float regularBee_height = regularBee_y_lvl2[i] + (22*1);
		float regularBee_length = regularBee_x_lvl2[i] + (46*1);
		float honeyComb_height = yellowHoneyComb_y_lvl2[i] + (64*0.7);
		float honeyComb_length = yellowHoneyComb_x_lvl2[i] + (64*0.7);
		float pregenHoneyComb_height = randomHoneyComb_y_lvl2[i] + (64*0.7);
		float pregenHoneyComb_length = randomHoneyComb_x_lvl2[i] + (64*0.7);
		float hive_height = beehive_y[i] + (64*1);
		float hive_length = beehive_x[i] + (64*1);
		//bee and bullet
		if (bullet_length >= regularBee_x_lvl2[i] && bullet_x <= regularBee_length && bullet_height >= regularBee_y_lvl2[i] && bullet_y <= regularBee_height && regularBees_lvl2[i] == 1)
		{
			regularBees_lvl2[i] = 0;
			regularBeeShotProcessed_lvl2[i] = 1;
			bullet_exists = false;
			yellowHoneyCombs_lvl2[i] = 1;
			yellowHoneyComb_x_lvl2[i] = regularBee_x_lvl2[i];
			yellowHoneyComb_y_lvl2[i] = regularBee_y_lvl2[i];
		}
		//bullet and yellow comb
		if (bullet_length >= yellowHoneyComb_x_lvl2[i] && bullet_x <= honeyComb_length && bullet_height >= yellowHoneyComb_y_lvl2[i] && bullet_y <= honeyComb_height && yellowHoneyCombs_lvl2[i] == 1)
		{
			yellowHoneyCombs_lvl2[i] = 0;
			bullet_exists = false;
		}
		//bullet and pregen comb
		if (bullet_length >= randomHoneyComb_x_lvl2[i] && bullet_x <= pregenHoneyComb_length && bullet_height >= randomHoneyComb_y_lvl2[i] && bullet_y <= pregenHoneyComb_height && pregenYellowHoneyCombs_lvl2[i] == 1)
		{
			randomHoneyComb_x_lvl2[i] = -800;
			randomHoneyComb_y_lvl2[i] = -800;
			pregenYellowHoneyCombs_lvl2[i] = 0;
			bullet_exists = false;
		}
		//bullet and hive
		if (bullet_length >= beehive_x[i] && bullet_x <= hive_length && bullet_height >= beehive_y[i] && bullet_y <= hive_height && beehives[i] == 1)
		{
			beehives[i] = 0;
			bullet_exists = false;
		}
	}
	//fast bees
	for (int i = 0; i < 5; i++)
	{
		float bullet_height = bullet_y + (16*3);
		float bullet_length = bullet_x + (16*3);
		float fastBee_height = fastBee_y_lvl2[i] + (22*1);
		float fastBee_length = fastBee_x_lvl2[i] + (46*1);
		float redComb_length = redHoneyComb_x_lvl2[i] + (64*0.7);
		float redComb_height = redHoneyComb_y_lvl2[i] + (64*0.7);
		//bee and bullet
		if (bullet_length >= fastBee_x_lvl2[i] && bullet_x <= fastBee_length && bullet_height >= fastBee_y_lvl2[i] && bullet_y <= fastBee_height && fastBees_lvl2[i] == 1)
		{
			fastBees_lvl2[i] = 0;
			fastBeeShotProcessed_lvl2[i] = 1;
			bullet_exists = false;
			redHoneyCombs_lvl2[i] = 1;
			redHoneyComb_x_lvl2[i] = fastBee_x_lvl2[i];
			redHoneyComb_y_lvl2[i] = fastBee_y_lvl2[i];
		}
		//bullet and red comb
		if (bullet_length >= redHoneyComb_x_lvl2[i] && bullet_x <= redComb_length && bullet_height >= redHoneyComb_y_lvl2[i] && bullet_y <= redComb_height && redHoneyCombs_lvl2[i] == 1)
		{
			redHoneyCombs_lvl2[i] = 0;
			bullet_exists = false;
		}
	}
	//bullet and bird
	float bullet_height = bullet_y + (16*3);
	float bullet_length = bullet_x + (16*3);
	float bird_height = bird_y + (32*1.5);
	float bird_length = bird_x + (64*1.5);
	//bullet and bird
	if (bullet_length >= bird_x && bullet_x <= bird_length && bullet_height >= bird_y && bullet_y <= bird_height)
	{
		birdHitCount++;
		bullet_exists = false;
	}	
}
//moves bullet for lvl 3
void moveBullet_lvl3(float& bullet_y,bool& bullet_exists, Clock& bulletClock,bool isRegularBeeShot_lvl3[],bool isFastBeeShot_lvl3[],float& bullet_x,float regularBee_x_lvl3[],float fastBee_x_lvl3[],float regularBee_y_lvl3[],float fastBee_y_lvl3[],float yellowHoneyComb_x_lvl3[],float yellowHoneyComb_y_lvl3[],float redHoneyComb_x_lvl3[],float redHoneyComb_y_lvl3[], Sound& hit,bool regularBeeShotProcessed_lvl3[],bool fastBeeShotProcessed_lvl3[],RenderWindow& window, Sprite& yellowHoneyCombSprite,Sprite& redHoneyCombSprite,bool regularBees_lvl3[],bool fastBees_lvl3[],bool yellowHoneyCombs_lvl3[],bool redHoneyCombs_lvl3[], bool pregenYellowHoneyCombs_lvl3[],int randomHoneyComb_x_lvl3[], int randomHoneyComb_y_lvl3[],bool beehives[],float beehive_x[],float beehive_y[],float& bird_y,float& bird_x,int& birdHitCount,const int BEEHIVES)
{
	if (bulletClock.getElapsedTime().asMilliseconds() < 20)
		return;

	bulletClock.restart();
	bullet_y -= 14;
	if (bullet_y < -32)
		bullet_exists = false;
	//worker bees
	for (int i = 0; i < 20; i++) 
	{
		float bullet_height = bullet_y + (16*3);
		float bullet_length = bullet_x + (16*3);
		float regularBee_height = regularBee_y_lvl3[i] + (22*1);
		float regularBee_length = regularBee_x_lvl3[i] + (46*1);
		float honeyComb_height = yellowHoneyComb_y_lvl3[i] + (64*0.7);
		float honeyComb_length = yellowHoneyComb_x_lvl3[i] + (64*0.7);
		float pregenHoneyComb_height = randomHoneyComb_y_lvl3[i] + (64*0.7);
		float pregenHoneyComb_length = randomHoneyComb_x_lvl3[i] + (64*0.7);
		float hive_height = beehive_y[i] + (64*1);
		float hive_length = beehive_x[i] + (64*1);
		//bee and bullet
		if (bullet_length >= regularBee_x_lvl3[i] && bullet_x <= regularBee_length && bullet_height >= regularBee_y_lvl3[i] && bullet_y <= regularBee_height && regularBees_lvl3[i] == 1)
		{
			regularBees_lvl3[i] = 0;
			regularBeeShotProcessed_lvl3[i] = 1;
			bullet_exists = false;
			yellowHoneyCombs_lvl3[i] = 1;
			yellowHoneyComb_x_lvl3[i] = regularBee_x_lvl3[i];
			yellowHoneyComb_y_lvl3[i] = regularBee_y_lvl3[i];
		}
		//bullet and yellow comb
		if (bullet_length >= yellowHoneyComb_x_lvl3[i] && bullet_x <= honeyComb_length && bullet_height >= yellowHoneyComb_y_lvl3[i] && bullet_y <= honeyComb_height && yellowHoneyCombs_lvl3[i] == 1)
		{
			yellowHoneyCombs_lvl3[i] = 0;
			bullet_exists = false;
		}
		//bullet and pregen comb
		if (bullet_length >= randomHoneyComb_x_lvl3[i] && bullet_x <= pregenHoneyComb_length && bullet_height >= randomHoneyComb_y_lvl3[i] && bullet_y <= pregenHoneyComb_height && pregenYellowHoneyCombs_lvl3[i] == 1)
		{
			randomHoneyComb_x_lvl3[i] = -800;
			randomHoneyComb_y_lvl3[i] = -800;
			pregenYellowHoneyCombs_lvl3[i] = 0;
			bullet_exists = false;
		}
		//bullet and hive
		if (bullet_length >= beehive_x[i] && bullet_x <= hive_length && bullet_height >= beehive_y[i] && bullet_y <= hive_height && beehives[i] == 1)
		{
			beehives[i] = 0;
			bullet_exists = false;
		}
	}
	//fast bees
	for (int i = 0; i < 10; i++)
	{
		float bullet_height = bullet_y + (16*3);
		float bullet_length = bullet_x + (16*3);
		float fastBee_height = fastBee_y_lvl3[i] + (22*1);
		float fastBee_length = fastBee_x_lvl3[i] + (46*1);
		float redComb_length = redHoneyComb_x_lvl3[i] + (64*0.7);
		float redComb_height = redHoneyComb_y_lvl3[i] + (64*0.7);
		//bee and bullet
		if (bullet_length >= fastBee_x_lvl3[i] && bullet_x <= fastBee_length && bullet_height >= fastBee_y_lvl3[i] && bullet_y <= fastBee_height && fastBees_lvl3[i] == 1)
		{
			fastBees_lvl3[i] = 0;
			fastBeeShotProcessed_lvl3[i] = 1;
			bullet_exists = false;
			redHoneyCombs_lvl3[i] = 1;
			redHoneyComb_x_lvl3[i] = fastBee_x_lvl3[i];
			redHoneyComb_y_lvl3[i] = fastBee_y_lvl3[i];
		}
		//bullet and red comb
		if (bullet_length >= redHoneyComb_x_lvl3[i] && bullet_x <= redComb_length && bullet_height >= redHoneyComb_y_lvl3[i] && bullet_y <= redComb_height && redHoneyCombs_lvl3[i] == 1)
		{
			redHoneyCombs_lvl3[i] = 0;
			bullet_exists = false;
		}
	}
	//bullet and bird
	float bullet_height = bullet_y + (16*3);
	float bullet_length = bullet_x + (16*3);
	float bird_height = bird_y + (32*1.5);
	float bird_length = bird_x + (64*1.5);
	//bullet and bird
	if (bullet_length >= bird_x && bullet_x <= bird_length && bullet_height >= bird_y && bullet_y <= bird_height)
	{
		birdHitCount++;
		bullet_exists = false;
	}	

}
//renders the bullet if it is shot
void drawBullet(sf::RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite) {
	bulletSprite.setPosition(bullet_x, bullet_y);
	window.draw(bulletSprite);
}

//moves the player left
void movePlayerLeft(float& player_x, Sprite& playerSprite, Clock& movementClock,Sound& obstacle, float pollinatedFlower_x[], bool isPollinated[])
{
	
	//changes the player's position
	player_x -= 32;
	//implementing out of bounds check for the player,since its length is 900,player cannot go beyond
	outOfBoundsLeft(player_x, obstacle);
	//checking if player collides with flower
	for (int i = 0; i < 26; i++)
	{
		if (isPollinated[i])
		{
			if (player_x >= pollinatedFlower_x[i] && player_x < pollinatedFlower_x[i] + 32)
			{
				player_x = pollinatedFlower_x[i] + 32;
			}
		}
	}
	//moves the player
	playerSprite.move(player_x,0);
}
//moves the player right
void movePlayerRight(float& player_x, Sprite& playerSprite, Clock& movementClock, Sound& obstacle, bool isPollinated[], float pollinatedFlower_x[])
{
	//changes the player's position
	player_x += 32;
	//implementing out of bounds check for the player,since its length is 900,player cannot go beyond
	outOfBoundsRight(player_x, obstacle);
	//checking if player collides with flower
	for (int i = 0; i < 26; i++)
	{
		if (isPollinated[i])
		{
			if (player_x + 32 > pollinatedFlower_x[i] && player_x <= pollinatedFlower_x[i])
			{
				player_x = pollinatedFlower_x[i] - 32;
			}
		}
	}
	//moves the player
	playerSprite.move(player_x,0);
}
//out of bounds check for the left side
void outOfBoundsLeft(float& player_x, Sound& obstacle)
{
	//not letting the player go out of bounds by using ternary operator
	player_x = (player_x < 0) ? (0) : player_x;
	//applying the obstacle sound effect
	if (player_x == 0)
	{
		obstacle.play();
		obstacle.setVolume(50);
	}
}
//out of bounds check for the right side
void outOfBoundsRight(float& player_x, Sound& obstacle)
{
	//not letting the player go out of bounds by using ternary operator
	player_x = (player_x > 900) ? (900) : player_x;
	//applying the obstacle sound effect
	if (player_x == 900)
	{
		obstacle.play();
		obstacle.setVolume(50);
	}
}
//draws the bees
void drawRegularBee_lvl1(RenderWindow& window, Sprite regularBeeSprite_lvl1[], float regularBee_x_lvl1[], float regularBee_y_lvl1[], bool regularBees_lvl1[])
{
	for (int i = 0; i < 20; i++)
	{
		if (regularBees_lvl1[i] == 1)
		{
			regularBeeSprite_lvl1[i].setPosition(regularBee_x_lvl1[i], regularBee_y_lvl1[i]);
			window.draw(regularBeeSprite_lvl1[i]);	
		}
	}
}
void drawRegularBee_lvl2(RenderWindow& window, Sprite regularBeeSprite_lvl2[], float regularBee_x_lvl2[], float regularBee_y_lvl2[], bool regularBees_lvl2[])
{
	for (int i = 0; i < 15; i++)
	{
		if (regularBees_lvl2[i] == 1)
		{
			regularBeeSprite_lvl2[i].setPosition(regularBee_x_lvl2[i], regularBee_y_lvl2[i]);
			window.draw(regularBeeSprite_lvl2[i]);	
		}
	}
}
void drawRegularBee_lvl3(RenderWindow& window, Sprite regularBeeSprite_lvl3[], float regularBee_x_lvl3[], float regularBee_y_lvl3[], bool regularBees_lvl3[])
{
	for (int i = 0; i < 20; i++)
	{
		if (regularBees_lvl3[i] == 1)
		{
			regularBeeSprite_lvl3[i].setPosition(regularBee_x_lvl3[i], regularBee_y_lvl3[i]);
			window.draw(regularBeeSprite_lvl3[i]);	
		}
	}
}
void drawFastBee_lvl2(RenderWindow& window, Sprite fastBeeSprite_lvl2[], float fastBee_x_lvl2[], float fastBee_y_lvl2[], bool fastBees_lvl2[])
{
	for (int i = 0; i < 5; i++)
	{
		if (fastBees_lvl2[i] == 1)
		{
			fastBeeSprite_lvl2[i].setPosition(fastBee_x_lvl2[i], fastBee_y_lvl2[i]);
			window.draw(fastBeeSprite_lvl2[i]);	
		}
	}
}
void drawFastBee_lvl3(RenderWindow& window, Sprite fastBeeSprite_lvl3[], float fastBee_x_lvl3[], float fastBee_y_lvl3[], bool fastBees_lvl3[])
{
	for (int i = 0; i < 10; i++)
	{
		if (fastBees_lvl3[i] == 1)
		{
			fastBeeSprite_lvl3[i].setPosition(fastBee_x_lvl3[i], fastBee_y_lvl3[i]);
			window.draw(fastBeeSprite_lvl3[i]);	
		}
	}
}
//moves the regular bee lvl1
void moveRegularBee_lvl1(float regularBee_x_lvl1[], float regularBee_y_lvl1[], bool regularBeeRight_lvl1[],Sprite regularBeeSprite_lvl1[], bool regularBees_lvl1[], RenderWindow& window,bool isBeeStopped_lvl1[],Clock beeStopClock_lvl1[])
{
	//moves the bee horizontally
	for (int i = 0; i < 20; i++)
	{
		if (regularBees_lvl1[i])
		{
			if (isBeeStopped_lvl1[i] == 0)
			{
				if (regularBeeRight_lvl1[i] == 1)
				{
					regularBee_x_lvl1[i] += 5;
				}
				else if (regularBeeRight_lvl1[i] == 0)
				{
					regularBee_x_lvl1[i] -= 5;
				}
			}
			else
			{
				if (beeStopClock_lvl1[i].getElapsedTime().asSeconds() > (rand()%3 + 0.5))
				{
					isBeeStopped_lvl1[i] = 0;
				}
			}
		}
	}
	
	//goes down when the bee hits the boundary
	for (int i = 0; i < 20; i++)
	{
		if (regularBee_x_lvl1[i] == 900 && regularBee_y_lvl1[i] < 489)
		{
			regularBee_y_lvl1[i] += 32;
			regularBeeRight_lvl1[i] = 0;
			regularBeeSprite_lvl1[i].setScale(1,1);
		}
		else if (regularBee_x_lvl1[i] == 0 && regularBee_y_lvl1[i] < 489)
		{
			regularBee_y_lvl1[i] += 32;
			regularBeeRight_lvl1[i] = 1;
			regularBeeSprite_lvl1[i].setScale(-1,1);
		}
	}
}
//moves the regular bee lvl2
void moveRegularBee_lvl2(float regularBee_x_lvl2[], float regularBee_y_lvl2[], bool regularBeeRight_lvl2[],Sprite regularBeeSprite_lvl2[], bool regularBees_lvl2[], RenderWindow& window,bool isBeeStopped_lvl2[],Clock beeStopClock_lvl2[])
{
	//moves the bee horizontally
	for (int i = 0; i < 15; i++)
	{
		if (regularBees_lvl2[i])
		{
			if (isBeeStopped_lvl2[i] == 0)
			{
				if (regularBeeRight_lvl2[i] == 1)
				{
					regularBee_x_lvl2[i] += 5;
				}
				else if (regularBeeRight_lvl2[i] == 0)
				{
					regularBee_x_lvl2[i] -= 5;
				}
			}
			else
			{
				if (beeStopClock_lvl2[i].getElapsedTime().asSeconds() > (rand()%3 + 0.5))
				{
					isBeeStopped_lvl2[i] = 0;
				}
			}
		}
	}
	//goes down when the bee hits the boundary
	for (int i = 0; i < 15; i++)
	{
		if (regularBee_x_lvl2[i] == 900 && regularBee_y_lvl2[i] < 489)
		{
			regularBee_y_lvl2[i] += 32;
			regularBeeRight_lvl2[i] = 0;
			regularBeeSprite_lvl2[i].setScale(1,1);
		}
		else if (regularBee_x_lvl2[i] == 0 && regularBee_y_lvl2[i] < 489)
		{
			regularBee_y_lvl2[i] += 32;
			regularBeeRight_lvl2[i] = 1;
			regularBeeSprite_lvl2[i].setScale(-1,1);
		}
	}
}
//moves the regular bee lvl3
void moveRegularBee_lvl3(float regularBee_x_lvl3[], float regularBee_y_lvl3[], bool regularBeeRight_lvl3[],Sprite regularBeeSprite_lvl3[], bool regularBees_lvl3[], RenderWindow& window,bool isBeeStopped_lvl3[],Clock beeStopClock_lvl3[])
{
	//moves the bee horizontally
	for (int i = 0; i < 20; i++)
	{
		if (regularBees_lvl3[i])
		{
			if (isBeeStopped_lvl3[i] == 0)
			{
				if (regularBeeRight_lvl3[i] == 1)
				{
					regularBee_x_lvl3[i] += 5;
				}
				else if (regularBeeRight_lvl3[i] == 0)
				{
					regularBee_x_lvl3[i] -= 5;
				}
			}
			else
			{
				if (beeStopClock_lvl3[i].getElapsedTime().asSeconds() > (rand()%3 + 0.5))
				{
					isBeeStopped_lvl3[i] = 0;
				}
			}
		}
	}
	//goes down when the bee hits the boundary
	for (int i = 0; i < 20; i++)
	{
		if (regularBee_x_lvl3[i] == 900 && regularBee_y_lvl3[i] < 489)
		{
			regularBee_y_lvl3[i] += 32;
			regularBeeRight_lvl3[i] = 0;
			regularBeeSprite_lvl3[i].setScale(1,1);
		}
		else if (regularBee_x_lvl3[i] == 0 && regularBee_y_lvl3[i] < 489)
		{
			regularBee_y_lvl3[i] += 32;
			regularBeeRight_lvl3[i] = 1;
			regularBeeSprite_lvl3[i].setScale(-1,1);
		}
	}
}
//moves fast bees lvl2
void moveFastBee_lvl2(float fastBee_x_lvl2[],float fastBee_y_lvl2[],bool fastBeeRight_lvl2[],Sprite fastBeeSprite_lvl2[],bool fastBees_lvl2[],RenderWindow& window)
{
	//moves the bee horizontally
	for (int i = 0; i < 5; i++)
	{
		if (fastBees_lvl2[i])
		{
			if (fastBeeRight_lvl2[i] == 1)
			{
				fastBee_x_lvl2[i] += 10;
			}
			else if (fastBeeRight_lvl2[i] == 0)
			{
				fastBee_x_lvl2[i] -= 10;
			}
		}
	}
	//goes down when the bee hits the boundary
	for (int i = 0; i < 5; i++)
	{
		if (fastBee_x_lvl2[i] == 900 && fastBee_y_lvl2[i] < 489)
		{
			fastBee_y_lvl2[i] += 32;
			fastBeeRight_lvl2[i] = 0;
			fastBeeSprite_lvl2[i].setScale(1,1);
		}
		else if (fastBee_x_lvl2[i] == 0 && fastBee_y_lvl2[i] < 489)
		{
			fastBee_y_lvl2[i] += 32;
			fastBeeRight_lvl2[i] = 1;
			fastBeeSprite_lvl2[i].setScale(-1,1);
		}
	}
}
//moves fast bees lvl3
void moveFastBee_lvl3(float fastBee_x_lvl3[],float fastBee_y_lvl3[],bool fastBeeRight_lvl3[],Sprite fastBeeSprite_lvl3[],bool fastBees_lvl3[],RenderWindow& window)
{
	//moves the bee horizontally
	for (int i = 0; i < 10; i++)
	{
		if (fastBees_lvl3[i])
		{
			if (fastBeeRight_lvl3[i] == 1)
			{
				fastBee_x_lvl3[i] += 10;
			}
			else if (fastBeeRight_lvl3[i] == 0)
			{
				fastBee_x_lvl3[i] -= 10;
			}
		}
	}
	//goes down when the bee hits the boundary
	for (int i = 0; i < 10; i++)
	{
		if (fastBee_x_lvl3[i] == 900 && fastBee_y_lvl3[i] < 489)
		{
			fastBee_y_lvl3[i] += 32;
			fastBeeRight_lvl3[i] = 0;
			fastBeeSprite_lvl3[i].setScale(1,1);
		}
		else if (fastBee_x_lvl3[i] == 0 && fastBee_y_lvl3[i] < 489)
		{
			fastBee_y_lvl3[i] += 32;
			fastBeeRight_lvl3[i] = 1;
			fastBeeSprite_lvl3[i].setScale(-1,1);
		}
	}
}
//stops bees randomly
void pauseBees_lvl1(Clock beeStopClock_lvl1[], bool isBeeStopped_lvl1[])
{
	for (int i = 0; i < 20; i++)
	{
		if (isBeeStopped_lvl1[i] == 0 && (rand()%1000 < 5))
		{
			isBeeStopped_lvl1[i] = 1;
			beeStopClock_lvl1[i].restart();
		}
	}
}
void pauseBees_lvl2(Clock beeStopClock_lvl2[], bool isBeeStopped_lvl2[])
{
	for (int i = 0; i < 15; i++)
	{
		if (isBeeStopped_lvl2[i] == 0 && (rand()%1000 < 5))
		{
			isBeeStopped_lvl2[i] = 1;
			beeStopClock_lvl2[i].restart();
		}
	}
}
void pauseBees_lvl3(Clock beeStopClock_lvl3[], bool isBeeStopped_lvl3[])
{
	for (int i = 0; i < 20; i++)
	{
		if (isBeeStopped_lvl3[i] == 0 && (rand()%1000 < 5))
		{
			isBeeStopped_lvl3[i] = 1;
			beeStopClock_lvl3[i].restart();
		}
	}
}
//checks if bee collided with the player
void beeCollidePlayer_lvl1(float regularBee_x_lvl1[],float regularBee_y_lvl1[],float& player_x, float& player_y,bool isRegularBeeCollidePlayer_lvl1[],bool isRegularBeeCollidePlayerProcessed_lvl1[])
{
	for (int i = 0; i < 20; i++) 
	{
		float regularBee_height = regularBee_y_lvl1[i] + (22*1);
		float regularBee_length = regularBee_x_lvl1[i] + (46*1);
		float player_length = player_x + 64;
		float player_height = player_y + 64;
		if (player_length >= regularBee_x_lvl1[i] && player_x <= regularBee_length && player_height >= regularBee_y_lvl1[i] && player_y <= regularBee_height && isRegularBeeCollidePlayerProcessed_lvl1[i] == 0)
		{
			isRegularBeeCollidePlayer_lvl1[i] = 1;
		}
	}
}
//lvl2
void beeCollidePlayer_lvl2(float regularBee_x_lvl2[],float regularBee_y_lvl2[],float fastBee_x_lvl2[],float fastBee_y_lvl2[],float& player_x,float& player_y,bool isRegularBeeCollidePlayer_lvl2[],bool isFastBeeCollidePlayer_lvl2[],bool isRegularBeeCollidePlayerProcessed_lvl2[],bool isFastBeeCollidePlayerProcessed_lvl2[])
{
	for (int i = 0; i < 15; i++) 
	{
		float regularBee_height = regularBee_y_lvl2[i] + (22*1);
		float regularBee_length = regularBee_x_lvl2[i] + (46*1);
		float player_length = player_x + 64;
		float player_height = player_y + 64;
		if (player_length >= regularBee_x_lvl2[i] && player_x <= regularBee_length && player_height >= regularBee_y_lvl2[i] && player_y <= regularBee_height && isRegularBeeCollidePlayerProcessed_lvl2[i] == 0)
		{
			isRegularBeeCollidePlayer_lvl2[i] = 1;
		}
	}
	for (int i = 0; i < 5; i++) 
	{
		float fastBee_height = fastBee_y_lvl2[i] + (22*1);
		float fastBee_length = fastBee_x_lvl2[i] + (46*1);
		float player_length = player_x + 64;
		float player_height = player_y + 64;
		if (player_length >= fastBee_x_lvl2[i] && player_x <= fastBee_length && player_height >= fastBee_y_lvl2[i] && player_y <= fastBee_height && isFastBeeCollidePlayerProcessed_lvl2[i] == 0)
		{
			isFastBeeCollidePlayer_lvl2[i] = 1;
		}
	}
}
//lvl3
void beeCollidePlayer_lvl3(float regularBee_x_lvl3[],float regularBee_y_lvl3[],float fastBee_x_lvl3[],float fastBee_y_lvl3[],float& player_x,float& player_y,bool isRegularBeeCollidePlayer_lvl3[],bool isFastBeeCollidePlayer_lvl3[],bool isRegularBeeCollidePlayerProcessed_lvl3[],bool isFastBeeCollidePlayerProcessed_lvl3[])
{
	for (int i = 0; i < 20; i++) 
	{
		float regularBee_height = regularBee_y_lvl3[i] + (22*1);
		float regularBee_length = regularBee_x_lvl3[i] + (46*1);
		float player_length = player_x + 64;
		float player_height = player_y + 64;
		if (player_length >= regularBee_x_lvl3[i] && player_x <= regularBee_length && player_height >= regularBee_y_lvl3[i] && player_y <= regularBee_height && isRegularBeeCollidePlayerProcessed_lvl3[i] == 0)
		{
			isRegularBeeCollidePlayer_lvl3[i] = 1;
		}
	}
	for (int i = 0; i < 10; i++) 
	{
		float fastBee_height = fastBee_y_lvl3[i] + (22*1);
		float fastBee_length = fastBee_x_lvl3[i] + (46*1);
		float player_length = player_x + 64;
		float player_height = player_y + 64;
		if (player_length >= fastBee_x_lvl3[i] && player_x <= fastBee_length && player_height >= fastBee_y_lvl3[i] && player_y <= fastBee_height && isFastBeeCollidePlayerProcessed_lvl3[i] == 0)
		{
			isFastBeeCollidePlayer_lvl3[i] = 1;
		}
	}
}
//checks if player has shot bullets that are multiple of 8
void bulletsX8 (int& bulletCount, bool& areBulletsX8, const int LOWER_HEALTH)
{
	if (bulletCount == LOWER_HEALTH)
	{
		areBulletsX8 = 1;
		bulletCount = 0;
	}
}
//reduces player health if the condition has been met
void reducePlayerHealth_lvl1 (int& health, bool isRegularBeeCollidePlayer_lvl1[],const int& LOWER_HEALTH, bool& areBulletsX8,bool isRegularBeeCollidePlayerProcessed_lvl1[])
{
	for (int i = 0; i < 20; i++)
	{
		if (isRegularBeeCollidePlayer_lvl1[i] == 1)
		{
			isRegularBeeCollidePlayer_lvl1[i] = 0;
			isRegularBeeCollidePlayerProcessed_lvl1[i] = 1;
			health -= 5;
		}
	}
	if (areBulletsX8)
	{
		areBulletsX8 = 0;
		health -= 15;
	}
}
//lvl2
void reducePlayerHealth_lvl2(int& health,bool isRegularBeeCollidePlayer_lvl2[],bool isFastBeeCollidePlayer_lvl2[], const int& LOWER_HEALTH,bool& areBulletsX8, bool isRegularBeeCollidePlayerProcessed_lvl2[],bool isFastBeeCollidePlayerProcessed_lvl2[])
{
	for (int i = 0; i < 15; i++)
	{
		if (isRegularBeeCollidePlayer_lvl2[i] == 1)
		{
			isRegularBeeCollidePlayer_lvl2[i] = 0;
			isRegularBeeCollidePlayerProcessed_lvl2[i] = 1;
			health -= 5;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (isFastBeeCollidePlayer_lvl2[i] == 1)
		{
			isFastBeeCollidePlayer_lvl2[i] = 0;
			isFastBeeCollidePlayerProcessed_lvl2[i] = 1;
			health -= 5;
		}
	}
	if (areBulletsX8)
	{
		areBulletsX8 = 0;
		health -= 15;
	}
}
//lvl3
void reducePlayerHealth_lvl3(int& health,bool isRegularBeeCollidePlayer_lvl3[],bool isFastBeeCollidePlayer_lvl3[], const int& LOWER_HEALTH,bool& areBulletsX8, bool isRegularBeeCollidePlayerProcessed_lvl3[],bool isFastBeeCollidePlayerProcessed_lvl3[])
{
	for (int i = 0; i < 20; i++)
	{
		if (isRegularBeeCollidePlayer_lvl3[i] == 1)
		{
			isRegularBeeCollidePlayer_lvl3[i] = 0;
			isRegularBeeCollidePlayerProcessed_lvl3[i] = 1;
			health -= 5;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (isFastBeeCollidePlayer_lvl3[i] == 1)
		{
			isFastBeeCollidePlayer_lvl3[i] = 0;
			isFastBeeCollidePlayerProcessed_lvl3[i] = 1;
			health -= 5;
		}
	}
	if (areBulletsX8)
	{
		areBulletsX8 = 0;
		health -= 15;
	}
}
//draws honeycombs upon shooting regular bee lvl1
void drawYellowHoneyComb_lvl1(RenderWindow& window,Sprite& yellowHoneyCombSprite,float yellowHoneyComb_x_lvl1[],float yellowHoneyComb_y_lvl1[], int i)
{
	yellowHoneyCombSprite.setPosition(yellowHoneyComb_x_lvl1[i], yellowHoneyComb_y_lvl1[i]);
	window.draw(yellowHoneyCombSprite);
}
//draws honeycombs upon shooting regular bee lvl2
void drawYellowHoneyComb_lvl2(RenderWindow& window,Sprite& yellowHoneyCombSprite,float yellowHoneyComb_x_lvl2[],float yellowHoneyComb_y_lvl2[], int i)
{
	yellowHoneyCombSprite.setPosition(yellowHoneyComb_x_lvl2[i], yellowHoneyComb_y_lvl2[i]);
	window.draw(yellowHoneyCombSprite);
}
//draws honeycombs upon shooting regular bee lvl3
void drawYellowHoneyComb_lvl3(RenderWindow& window,Sprite& yellowHoneyCombSprite,float yellowHoneyComb_x_lvl3[],float yellowHoneyComb_y_lvl3[], int i)
{
	yellowHoneyCombSprite.setPosition(yellowHoneyComb_x_lvl3[i], yellowHoneyComb_y_lvl3[i]);
	window.draw(yellowHoneyCombSprite);
}
//draws honeycombs upon shooting fast bee lvl2
void drawRedHoneyComb_lvl2(RenderWindow& window,Sprite& redHoneyCombSprite,float redHoneyComb_x_lvl2[],float redHoneyComb_y_lvl2[], int i)
{
	redHoneyCombSprite.setPosition(redHoneyComb_x_lvl2[i], redHoneyComb_y_lvl2[i]);
	window.draw(redHoneyCombSprite);
}
//draws honeycombs upon shooting fast bee lvl3
void drawRedHoneyComb_lvl3(RenderWindow& window,Sprite& redHoneyCombSprite,float redHoneyComb_x_lvl3[],float redHoneyComb_y_lvl3[], int i)
{
	redHoneyCombSprite.setPosition(redHoneyComb_x_lvl3[i], redHoneyComb_y_lvl3[i]);
	window.draw(redHoneyCombSprite);
}
//changes direction if bee collides with honeycomb
void beeCollideComb_lvl1(float regularBee_x_lvl1[], float regularBee_y_lvl1[],bool isRegularBeeCollideComb_lvl1[], int randomHoneyComb_x_lvl1[], int randomHoneyComb_y_lvl1[],bool regularBeeRight_lvl1[],Sprite regularBeeSprite_lvl1[], bool yellowHoneyCombs_lvl1[],float yellowHoneyComb_x_lvl1[], float yellowHoneyComb_y_lvl1[],Clock collideClock_lvl1[], bool beehives[], float beehive_x[], float beehive_y[], bool regularBees_lvl1[]) 
{
	//goes down when the bee hits a pre generated honeycomb, this is for pregen combs of lvl1
	for (int i = 0; i < 20; i++)
	{
		if (collideClock_lvl1[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl1[i] + (22*1);
		float regularBee_length = regularBee_x_lvl1[i] + (46*1);
		for (int j = 0; j < 3; j++)
		{
			float honeyComb_height = randomHoneyComb_y_lvl1[j] + (64*0.7);
			float honeyComb_length = randomHoneyComb_x_lvl1[j] + (64*0.7);
			if (honeyComb_length >= regularBee_x_lvl1[i] && randomHoneyComb_x_lvl1[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl1[i] && randomHoneyComb_y_lvl1[j] <= regularBee_height)
			{
				//checking if bee is trapped when its going right
				if (regularBeeRight_lvl1[i] == 1)
				{
					//pregen-pregen lvl1
					for (int k = 0; k < 3; k++)
					{
						if (randomHoneyComb_y_lvl1[k] >= regularBee_y_lvl1[i] - 32 - 0.1 && randomHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] - 32 + 0.1)
						{
							if (randomHoneyComb_x_lvl1[k] >= regularBee_x_lvl1[i] - 46 && randomHoneyComb_x_lvl1[k] <= regularBee_x_lvl1[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl1[i];
								beehive_y[i] = regularBee_y_lvl1[i];
								regularBees_lvl1[i] = 0;
							}
						}
					}
					//pregen-yellow lvl1
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl1[k] >= regularBee_y_lvl1[i] - 32 - 0.1 && yellowHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] - 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl1[k] >= regularBee_x_lvl1[i] - 46 && yellowHoneyComb_x_lvl1[k] <= regularBee_x_lvl1[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl1[i];
								beehive_y[i] = regularBee_y_lvl1[i];
								regularBees_lvl1[i] = 0;
							}
						}
					}
				}
				//checking if its trapped when going left
				else
				{
					//pregen-pregen lvl1
					for (int k = 0; k < 3; k++)
					{
						if (randomHoneyComb_y_lvl1[k] >= regularBee_y_lvl1[i] - 32 - 0.1 && randomHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] - 32 + 0.1)
						{
							if (randomHoneyComb_x_lvl1[k] <= regularBee_x_lvl1[i] + 46 && yellowHoneyComb_x_lvl1[k] >= regularBee_x_lvl1[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl1[i];
								beehive_y[i] = regularBee_y_lvl1[i];
								regularBees_lvl1[i] = 0;
							}
						}
					}
					//pregen-yellow lvl1
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl1[k] >= regularBee_y_lvl1[i] - 32 - 0.1 && yellowHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] - 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl1[k] >= regularBee_x_lvl1[i] - 46 && yellowHoneyComb_x_lvl1[k] <= regularBee_x_lvl1[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl1[i];
								beehive_y[i] = regularBee_y_lvl1[i];
								regularBees_lvl1[i] = 0;
							}
						}
					}
				}		
				isRegularBeeCollideComb_lvl1[i] = 1;
				regularBee_y_lvl1[i] += 32;
				if (regularBeeRight_lvl1[i] == 0)
				{
					regularBeeRight_lvl1[i] = 1;
					regularBeeSprite_lvl1[i].setScale(-1,1);
				}
				else if (regularBeeRight_lvl1[i] == 1)
				{
					regularBeeRight_lvl1[i] = 0;
					regularBeeSprite_lvl1[i].setScale(1,1);
				}
				collideClock_lvl1[i].restart();
			}
		}
	}
	//goes down when a bee hits another honeycomb, this is for regular combs of lvl1
	for (int i = 0; i < 20; i++)
	{
		if (collideClock_lvl1[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl1[i] + (22*1);
		float regularBee_length = regularBee_x_lvl1[i] + (46*1);
		for (int j = 0; j < 20; j++)
		{
			if (yellowHoneyCombs_lvl1[j])
			{
				float honeyComb_height = yellowHoneyComb_y_lvl1[j] + (64*0.7);
				float honeyComb_length = yellowHoneyComb_x_lvl1[j] + (64*0.7);
				if (honeyComb_length >= regularBee_x_lvl1[i] && yellowHoneyComb_x_lvl1[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl1[i] && yellowHoneyComb_y_lvl1[j] <= regularBee_height)
				{
				//checking if bee is trapped when its going right
				if (regularBeeRight_lvl1[i] == 1)
				{
					//yellow-yellow lvl1
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl1[k] >= regularBee_y_lvl1[i] + 32 - 0.1 && yellowHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] + 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl1[k] >= regularBee_x_lvl1[i] - 46 && yellowHoneyComb_x_lvl1[k] <= regularBee_x_lvl1[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl1[i];
								beehive_y[i] = regularBee_y_lvl1[i];
								regularBees_lvl1[i] = 0;
							}
						}
					}
					//yellow-leftboundary lvl1
					for (int k = 0; k < 20; k++)
					{
						if (regularBee_x_lvl1[i] <= 0 && (yellowHoneyComb_y_lvl1[k] + (64*0.7) >= regularBee_y_lvl1[i]) && (yellowHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] + 22) &&(yellowHoneyComb_x_lvl1[k] + regularBee_x_lvl1[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl1[i];
							beehive_y[i] = regularBee_y_lvl1[i];
							regularBees_lvl1[i] = 0;
						}
					}
				}
				//checking if its trapped when going left
				else
				{
					//yellow yellow lvl1
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl1[k] >= regularBee_y_lvl1[i] + 32 - 0.1 && yellowHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] + 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl1[k] <= regularBee_x_lvl1[i] + 46 && yellowHoneyComb_x_lvl1[k] >= regularBee_x_lvl1[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl1[i];
								beehive_y[i] = regularBee_y_lvl1[i];
								regularBees_lvl1[i] = 0;
							}
						}
					}
					//yellow-rightboundary lvl1
					for (int k = 0; k < 20; k++)
					{
						if (regularBee_x_lvl1[i] >= 900 && (yellowHoneyComb_y_lvl1[k] + (64*0.7) >= regularBee_y_lvl1[i]) && (yellowHoneyComb_y_lvl1[k] <= regularBee_y_lvl1[i] + 22) &&(regularBee_x_lvl1[i] - yellowHoneyComb_x_lvl1[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl1[i];
							beehive_y[i] = regularBee_y_lvl1[i];
							regularBees_lvl1[i] = 0;
						}
					}
				}	
					isRegularBeeCollideComb_lvl1[i] = 1;
					regularBee_y_lvl1[i] += 32;
					if (regularBeeRight_lvl1[i] == 0)
					{
						regularBeeRight_lvl1[i] = 1;
						regularBeeSprite_lvl1[i].setScale(-1,1);
					}
					else if (regularBeeRight_lvl1[i] == 1)
					{
						regularBeeRight_lvl1[i] = 0;
						regularBeeSprite_lvl1[i].setScale(1,1);
					}
					collideClock_lvl1[i].restart();
				}
			}
		}
	}
}
//lvl2
void beeCollideComb_lvl2(float regularBee_x_lvl2[], float regularBee_y_lvl2[],bool isRegularBeeCollideComb_lvl2[], int randomHoneyComb_x_lvl2[], int randomHoneyComb_y_lvl2[],bool regularBeeRight_lvl2[],Sprite regularBeeSprite_lvl2[], bool yellowHoneyCombs_lvl2[],bool redHoneyCombs_lvl2[],float yellowHoneyComb_x_lvl2[], float yellowHoneyComb_y_lvl2[],float redHoneyComb_x_lvl2[],float redHoneyComb_y_lvl2[],Clock collideClock_lvl2[], bool beehives[], float beehive_x[], float beehive_y[], bool regularBees_lvl2[]) 
{
	//goes down when the bee hits a pre generated honeycomb
	for (int i = 0; i < 15; i++)
	{
		if (collideClock_lvl2[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl2[i] + (22*1);
		float regularBee_length = regularBee_x_lvl2[i] + (46*1);
		for (int j = 0; j < 9; j++)
		{
			float honeyComb_height = randomHoneyComb_y_lvl2[j] + (64*0.7);
			float honeyComb_length = randomHoneyComb_x_lvl2[j] + (64*0.7);
			if (honeyComb_length >= regularBee_x_lvl2[i] && randomHoneyComb_x_lvl2[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl2[i] && randomHoneyComb_y_lvl2[j] <= regularBee_height)
			{
				//checking if bee is trapped when its going right
				if (regularBeeRight_lvl2[i] == 1)
				{
					//pregen-pregen lvl2
					for (int k = 0; k < 9; k++)
					{
						if (randomHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] - 32 - 0.1 && randomHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] - 32 + 0.1)
						{
							if (randomHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i] - 46 && randomHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i] - 64;
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//pregen-leftboundary lvl2
					for (int k = 0; k < 9; k++)
					{
						if (regularBee_x_lvl2[i] <= 0 && (randomHoneyComb_y_lvl2[k] + (64*0.7) >= regularBee_y_lvl2[i]) && (randomHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 22) &&(randomHoneyComb_x_lvl2[k] + regularBee_x_lvl2[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl2[i];
							beehive_y[i] = regularBee_y_lvl2[i];
							regularBees_lvl2[i] = 0;
						}
					}
					//pregen-yellow lvl2
					for (int k = 0; k < 15; k++)
					{
						if (yellowHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] - 32 - 0.1 && yellowHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] - 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i] - 46 && yellowHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i] - 64;
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//pregen red lvl3
					for (int k = 0; k < 5; k++)
					{
						if (redHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] - 32 - 0.1 && redHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] - 32 + 0.1)
						{
							if (redHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i] - 46 && redHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i] - 64;
								regularBees_lvl2[i] = 0;
							}
						}
					}
				}
				//checking if its trapped when going left
				else
				{
					//pregen-pregen lvl2
					for (int k = 0; k < 9; k++)
					{
						if (randomHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] - 32 - 0.1 && randomHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] - 32 + 0.1)
						{
							if (randomHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i] + 46 && yellowHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i] - 64;
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//pregen-yellow lvl2
					for (int k = 0; k < 15; k++)
					{
						if (yellowHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] - 32 - 0.1 && yellowHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] - 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i] - 46 && yellowHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i] - 64;
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//pregen-red lvl2
					for (int k = 0; k < 5; k++)
					{
						if (redHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] - 32 - 0.1 && redHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] - 32 + 0.1)
						{
							if (redHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i] - 46 && redHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i] - 64;
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//pregen-rightboundary lvl2
					for (int k = 0; k < 9; k++)
					{
						if (regularBee_x_lvl2[i] >= 900 && (randomHoneyComb_y_lvl2[k] + (64*0.7) >= regularBee_y_lvl2[i]) && (randomHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 22) &&(regularBee_x_lvl2[i] - randomHoneyComb_x_lvl2[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl2[i];
							beehive_y[i] = regularBee_y_lvl2[i];
							regularBees_lvl2[i] = 0;
						}
					}
				}		
				isRegularBeeCollideComb_lvl2[i] = 1;
				regularBee_y_lvl2[i] += 32;
				if (regularBeeRight_lvl2[i] == 0)
				{
					regularBeeRight_lvl2[i] = 1;
					regularBeeSprite_lvl2[i].setScale(-1,1);
				}
				else if (regularBeeRight_lvl2[i] == 1)
				{
					regularBeeRight_lvl2[i] = 0;
					regularBeeSprite_lvl2[i].setScale(1,1);
				}
				collideClock_lvl2[i].restart();
			}
		}
	}
	//goes down when a bee hits another yellow honeycomb
	for (int i = 0; i < 15; i++)
	{
		if (collideClock_lvl2[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl2[i] + (22*1);
		float regularBee_length = regularBee_x_lvl2[i] + (46*1);
		for (int j = 0; j < 15; j++)
		{
			if (yellowHoneyCombs_lvl2[j])
			{
				float honeyComb_height = yellowHoneyComb_y_lvl2[j] + (64*0.7);
				float honeyComb_length = yellowHoneyComb_x_lvl2[j] + (64*0.7);
				if (honeyComb_length >= regularBee_x_lvl2[i] && yellowHoneyComb_x_lvl2[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl2[i] && yellowHoneyComb_y_lvl2[j] <= regularBee_height)
				{
				//checking if bee is trapped when its going right
				if (regularBeeRight_lvl2[i] == 1)
				{
					//yellow-yellow lvl2
					for (int k = 0; k < 15; k++)
					{
						if (yellowHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] + 32 - 0.1 && yellowHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i] - 46 && yellowHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i];
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//yellow-leftboundary lvl2
					for (int k = 0; k < 15; k++)
					{
						if (regularBee_x_lvl2[i] <= 0 && (yellowHoneyComb_y_lvl2[k] + (64*0.7) >= regularBee_y_lvl2[i]) && (yellowHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 22) &&(yellowHoneyComb_x_lvl2[k] + regularBee_x_lvl2[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl2[i];
							beehive_y[i] = regularBee_y_lvl2[i];
							regularBees_lvl2[i] = 0;
						}
					}
					//red-leftboundary lvl2
					for (int k = 0; k < 5; k++)
					{
						if (regularBee_x_lvl2[i] <= 0 && (redHoneyComb_y_lvl2[k] + (64*0.7) >= regularBee_y_lvl2[i]) && (redHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 22) &&(redHoneyComb_x_lvl2[k] + regularBee_x_lvl2[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl2[i];
							beehive_y[i] = regularBee_y_lvl2[i];
							regularBees_lvl2[i] = 0;
						}
					}
				}
				//checking if its trapped when going left
				else
				{
					//yellow yellow lvl2
					for (int k = 0; k < 15; k++)
					{
						if (yellowHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] + 32 - 0.1 && yellowHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i] + 46 && yellowHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i];
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//red red lvl2
					for (int k = 0; k < 5; k++)
					{
						if (redHoneyComb_y_lvl2[k] >= regularBee_y_lvl2[i] + 32 - 0.1 && redHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 32 + 0.1)
						{
							if (redHoneyComb_x_lvl2[k] <= regularBee_x_lvl2[i] + 46 && redHoneyComb_x_lvl2[k] >= regularBee_x_lvl2[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl2[i];
								beehive_y[i] = regularBee_y_lvl2[i];
								regularBees_lvl2[i] = 0;
							}
						}
					}
					//yellow-rightboundary lvl2
					for (int k = 0; k < 15; k++)
					{
						if (regularBee_x_lvl2[i] >= 900 && (yellowHoneyComb_y_lvl2[k] + (64*0.7) >= regularBee_y_lvl2[i]) && (yellowHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 22) &&(regularBee_x_lvl2[i] - yellowHoneyComb_x_lvl2[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl2[i];
							beehive_y[i] = regularBee_y_lvl2[i];
							regularBees_lvl2[i] = 0;
						}
					}
					//red-rightboundary lvl2
					for (int k = 0; k < 5; k++)
					{
						if (regularBee_x_lvl2[i] >= 900 && (redHoneyComb_y_lvl2[k] + (64*0.7) >= regularBee_y_lvl2[i]) && (redHoneyComb_y_lvl2[k] <= regularBee_y_lvl2[i] + 22) &&(regularBee_x_lvl2[i] - redHoneyComb_x_lvl2[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl2[i];
							beehive_y[i] = regularBee_y_lvl2[i];
							regularBees_lvl2[i] = 0;
						}
					}
				}	
					isRegularBeeCollideComb_lvl2[i] = 1;
					regularBee_y_lvl2[i] += 32;
					if (regularBeeRight_lvl2[i] == 0)
					{
						regularBeeRight_lvl2[i] = 1;
						regularBeeSprite_lvl2[i].setScale(-1,1);
					}
					else if (regularBeeRight_lvl2[i] == 1)
					{
						regularBeeRight_lvl2[i] = 0;
						regularBeeSprite_lvl2[i].setScale(1,1);
					}
					collideClock_lvl2[i].restart();
				}
			}
		}
	}
	//red honeycomb
	for (int i = 0; i < 15; i++)
	{
		if (collideClock_lvl2[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl2[i] + (22*1);
		float regularBee_length = regularBee_x_lvl2[i] + (46*1);
		for (int j = 0; j < 5; j++)
		{
			float honeyComb_height = redHoneyComb_y_lvl2[j] + (64*0.7);
			float honeyComb_length = redHoneyComb_x_lvl2[j] + (64*0.7);
			if (honeyComb_length >= regularBee_x_lvl2[i] && randomHoneyComb_x_lvl2[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl2[i] && randomHoneyComb_y_lvl2[j] <= regularBee_height)
			{
				isRegularBeeCollideComb_lvl2[i] = 1;
				regularBee_y_lvl2[i] += 32;
				if (regularBeeRight_lvl2[i] == 0)
				{
					regularBeeRight_lvl2[i] = 1;
					regularBeeSprite_lvl2[i].setScale(-1,1);
				}
				else if (regularBeeRight_lvl2[i] == 1)
				{
					regularBeeRight_lvl2[i] = 0;
					regularBeeSprite_lvl2[i].setScale(1,1);
				}
				collideClock_lvl2[i].restart();
			}
		}
	}

}
//lvl3
void beeCollideComb_lvl3(float regularBee_x_lvl3[], float regularBee_y_lvl3[],bool isRegularBeeCollideComb_lvl3[], int randomHoneyComb_x_lvl3[], int randomHoneyComb_y_lvl3[],bool regularBeeRight_lvl3[],Sprite regularBeeSprite_lvl3[], bool yellowHoneyCombs_lvl3[],bool redHoneyCombs_lvl3[],float yellowHoneyComb_x_lvl3[], float yellowHoneyComb_y_lvl3[],float redHoneyComb_x_lvl3[],float redHoneyComb_y_lvl3[],Clock collideClock_lvl3[], bool beehives[], float beehive_x[], float beehive_y[], bool regularBees_lvl3[]) 
{
	//goes down when the bee hits a pre generated honeycomb
	for (int i = 0; i < 20; i++)
	{
		if (collideClock_lvl3[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl3[i] + (22*1);
		float regularBee_length = regularBee_x_lvl3[i] + (46*1);
		for (int j = 0; j < 9; j++)
		{
			float honeyComb_height = randomHoneyComb_y_lvl3[j] + (64*0.7);
			float honeyComb_length = randomHoneyComb_x_lvl3[j] + (64*0.7);
			if (honeyComb_length >= regularBee_x_lvl3[i] && randomHoneyComb_x_lvl3[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl3[i] && randomHoneyComb_y_lvl3[j] <= regularBee_height)
			{
				//checking if bee is trapped when its going right
				if (regularBeeRight_lvl3[i] == 1)
				{
					//pregen-pregen lvl3
					for (int k = 0; k < 15; k++)
					{
						if (randomHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] - 32 - 0.1 && randomHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] - 32 + 0.1)
						{
							if (randomHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && randomHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i] - 64;
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//pregen-leftboundary lvl3
					for (int k = 0; k < 15; k++)
					{
						if (regularBee_x_lvl3[i] <= 0 && (randomHoneyComb_y_lvl3[k] + (64*0.7) >= regularBee_y_lvl3[i]) && (randomHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 22) &&(randomHoneyComb_x_lvl3[k] + regularBee_x_lvl3[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl3[i];
							beehive_y[i] = regularBee_y_lvl3[i];
							regularBees_lvl3[i] = 0;
						}
					}
					//pregen-yellow lvl3
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] - 32 - 0.1 && yellowHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] - 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && yellowHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i] - 64;
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//pregen red lvl3
					for (int k = 0; k < 10; k++)
					{
						if (redHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] - 32 - 0.1 && redHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] - 32 + 0.1)
						{
							if (redHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && redHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i] - 64;
								regularBees_lvl3[i] = 0;
							}
						}
					}
				}
				//checking if its trapped when going left
				else
				{
					//pregen-pregen lvl3
					for (int k = 0; k < 15; k++)
					{
						if (randomHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] - 32 - 0.1 && randomHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] - 32 + 0.1)
						{
							if (randomHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i] + 46 && yellowHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i] - 64;
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//pregen-yellow lvl3
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] - 32 - 0.1 && yellowHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] - 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && yellowHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i] - 64;
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//pregen-red lvl3
					for (int k = 0; k < 10; k++)
					{
						if (redHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] - 32 - 0.1 && redHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] - 32 + 0.1)
						{
							if (redHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && redHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i] - 64;
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//pregen-rightboundary lvl3
					for (int k = 0; k < 15; k++)
					{
						if (regularBee_x_lvl3[i] >= 900 && (randomHoneyComb_y_lvl3[k] + (64*0.7) >= regularBee_y_lvl3[i]) && (randomHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 22) &&(regularBee_x_lvl3[i] - randomHoneyComb_x_lvl3[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl3[i];
							beehive_y[i] = regularBee_y_lvl3[i];
							regularBees_lvl3[i] = 0;
						}
					}
				}		
				isRegularBeeCollideComb_lvl3[i] = 1;
				regularBee_y_lvl3[i] += 32;
				if (regularBeeRight_lvl3[i] == 0)
				{
					regularBeeRight_lvl3[i] = 1;
					regularBeeSprite_lvl3[i].setScale(-1,1);
				}
				else if (regularBeeRight_lvl3[i] == 1)
				{
					regularBeeRight_lvl3[i] = 0;
					regularBeeSprite_lvl3[i].setScale(1,1);
				}
				collideClock_lvl3[i].restart();
			}
		}
	}
	//goes down when a bee hits another honeycomb
	for (int i = 0; i < 20; i++)
	{
		if (collideClock_lvl3[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl3[i] + (22*1);
		float regularBee_length = regularBee_x_lvl3[i] + (46*1);
		for (int j = 0; j < 15; j++)
		{
			if (yellowHoneyCombs_lvl3[j])
			{
				float honeyComb_height = yellowHoneyComb_y_lvl3[j] + (64*0.7);
				float honeyComb_length = yellowHoneyComb_x_lvl3[j] + (64*0.7);
				if (honeyComb_length >= regularBee_x_lvl3[i] && yellowHoneyComb_x_lvl3[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl3[i] && yellowHoneyComb_y_lvl3[j] <= regularBee_height)
				{
				//checking if bee is trapped when its going right
				if (regularBeeRight_lvl3[i] == 1)
				{
					//yellow-yellow lvl3
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] + 32 - 0.1 && yellowHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && yellowHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i];
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//red red lvl3
					for (int k = 0; k < 10; k++)
					{
						if (redHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] + 32 - 0.1 && redHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 32 + 0.1)
						{
							if (redHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i] - 46 && redHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i];
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//yellow-leftboundary lvl3
					for (int k = 0; k < 20; k++)
					{
						if (regularBee_x_lvl3[i] <= 0 && (yellowHoneyComb_y_lvl3[k] + (64*0.7) >= regularBee_y_lvl3[i]) && (yellowHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 22) &&(yellowHoneyComb_x_lvl3[k] + regularBee_x_lvl3[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl3[i];
							beehive_y[i] = regularBee_y_lvl3[i];
							regularBees_lvl3[i] = 0;
						}
					}
					//red-leftboundary lvl3
					for (int k = 0; k < 10; k++)
					{
						if (regularBee_x_lvl3[i] <= 0 && (redHoneyComb_y_lvl3[k] + (64*0.7) >= regularBee_y_lvl3[i]) && (redHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 22) &&(redHoneyComb_x_lvl3[k] + regularBee_x_lvl3[i] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl3[i];
							beehive_y[i] = regularBee_y_lvl3[i];
							regularBees_lvl3[i] = 0;
						}
					}
				}
				//checking if its trapped when going left
				else
				{
					//yellow yellow lvl3
					for (int k = 0; k < 20; k++)
					{
						if (yellowHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] + 32 - 0.1 && yellowHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 32 + 0.1)
						{
							if (yellowHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i] + 46 && yellowHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i];
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//red red lvl3
					for (int k = 0; k < 10; k++)
					{
						if (redHoneyComb_y_lvl3[k] >= regularBee_y_lvl3[i] + 32 - 0.1 && redHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 32 + 0.1)
						{
							if (redHoneyComb_x_lvl3[k] <= regularBee_x_lvl3[i] + 46 && redHoneyComb_x_lvl3[k] >= regularBee_x_lvl3[i])
							{
								beehives[i] = 1;
								beehive_x[i] = regularBee_x_lvl3[i];
								beehive_y[i] = regularBee_y_lvl3[i];
								regularBees_lvl3[i] = 0;
							}
						}
					}
					//yellow-rightboundary lvl3
					for (int k = 0; k < 20; k++)
					{
						if (regularBee_x_lvl3[i] >= 900 && (yellowHoneyComb_y_lvl3[k] + (64*0.7) >= regularBee_y_lvl3[i]) && (yellowHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 22) &&(regularBee_x_lvl3[i] - yellowHoneyComb_x_lvl3[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl3[i];
							beehive_y[i] = regularBee_y_lvl3[i];
							regularBees_lvl3[i] = 0;
						}
					}
					//red-rightboundary lvl3
					for (int k = 0; k < 10; k++)
					{
						if (regularBee_x_lvl3[i] >= 900 && (redHoneyComb_y_lvl3[k] + (64*0.7) >= regularBee_y_lvl3[i]) && (redHoneyComb_y_lvl3[k] <= regularBee_y_lvl3[i] + 22) &&(regularBee_x_lvl3[i] - redHoneyComb_x_lvl3[k] <= 46))
						{
							beehives[i] = 1;
							beehive_x[i] = regularBee_x_lvl3[i];
							beehive_y[i] = regularBee_y_lvl3[i];
							regularBees_lvl3[i] = 0;
						}
					}
				}	
					isRegularBeeCollideComb_lvl3[i] = 1;
					regularBee_y_lvl3[i] += 32;
					if (regularBeeRight_lvl3[i] == 0)
					{
						regularBeeRight_lvl3[i] = 1;
						regularBeeSprite_lvl3[i].setScale(-1,1);
					}
					else if (regularBeeRight_lvl3[i] == 1)
					{
						regularBeeRight_lvl3[i] = 0;
						regularBeeSprite_lvl3[i].setScale(1,1);
					}
					collideClock_lvl3[i].restart();
				}
			}
		}
	}
	//red honeycomb
	for (int i = 0; i < 20; i++)
	{
		if (collideClock_lvl3[i].getElapsedTime().asSeconds() < 0.05)
			continue;
		float regularBee_height = regularBee_y_lvl3[i] + (22*1);
		float regularBee_length = regularBee_x_lvl3[i] + (46*1);
		for (int j = 0; j < 10; j++)
		{
			float honeyComb_height = redHoneyComb_y_lvl3[j] + (64*0.7);
			float honeyComb_length = redHoneyComb_x_lvl3[j] + (64*0.7);
			if (honeyComb_length >= regularBee_x_lvl3[i] && randomHoneyComb_x_lvl3[j] <= regularBee_length && honeyComb_height >= regularBee_y_lvl3[i] && randomHoneyComb_y_lvl3[j] <= regularBee_height)
			{
				isRegularBeeCollideComb_lvl3[i] = 1;
				regularBee_y_lvl3[i] += 32;
				if (regularBeeRight_lvl3[i] == 0)
				{
					regularBeeRight_lvl3[i] = 1;
					regularBeeSprite_lvl3[i].setScale(-1,1);
				}
				else if (regularBeeRight_lvl3[i] == 1)
				{
					regularBeeRight_lvl3[i] = 0;
					regularBeeSprite_lvl3[i].setScale(1,1);
				}
				collideClock_lvl3[i].restart();
			}
		}
	}
}
//counts all the bullets that are shot
void increaseBulletCount(int& bulletCount)
{
	bulletCount++;
}
//draws the remaining cans
void drawRemainingCans(RenderWindow& window,Sprite& remainingCanSprite1,Sprite& remainingCanSprite2,float& can1_x,float& can1_y, bool remainingCanCount[])
{
	int increment = 0;
	for (int i = 0; i < 20; i++)
	{
		if (remainingCanCount[i] == 1)
		{
			remainingCanSprite1.setPosition(can1_x+increment, can1_y);
			window.draw(remainingCanSprite1);
			increment+=50;
		}
	}
}
//checks if player is dead
void playerDeath(int& health,bool remainingCanCount[],int& remainingCanIndex, bool& gameOver, const int FLOWERS,bool isPollinated[], bool& rightCornerProcessed, bool& leftCornerProcessed, bool& placeLeftFlowers, bool& placeRightFlowers)
{
	int remainingCans = 0;
	//counts the amount of remaining cans
	for (int i = 0; i < 20; i++)
	{
		if (remainingCanCount[i] == 1)
		{
			remainingCans++;
		}
	}
	//if health has dropped to 0 and no more cans left then game is over
	if (health <= 0 && remainingCans == 0)
	{
		gameOver = 1;
	}
	//if health below zero but cans are remaining
	if (health <= 0 && remainingCanIndex >= 0 && remainingCans != 0)
	{
		//bring in the next can
		health = 100;
		remainingCanCount[remainingCanIndex] = 0;
		remainingCanIndex--;
		//removes all flowers if next can is brought over
		for (int i = 0; i < FLOWERS; i++)
		{
			isPollinated[i] = 0;
		}
		rightCornerProcessed = 0;
		leftCornerProcessed = 0;
		placeRightFlowers = 0;
		placeLeftFlowers = 0;
	}
}
//draws health bar
void drawPlayerHealth(RenderWindow& window,int& health,float& player_x,float& player_y)
{
	const float maxHealthLevelHeight = 32.0f;
	float healthLevelHeight = (static_cast<float>(health) / 100.0f) * maxHealthLevelHeight;
	float healthLevelWidth = 20.0f;
	float offset = maxHealthLevelHeight - healthLevelHeight;
	RectangleShape healthLevel(Vector2f(healthLevelWidth, healthLevelHeight));
	healthLevel.setFillColor(Color::White);
	healthLevel.setPosition(player_x+22, player_y+32+offset);
	window.draw(healthLevel);
}
//shows the player score
void showScore(RenderWindow& window, int score)
{
	Font scoreFont;
	Text scoreText;
	scoreFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(Color::Black);
	scoreText.setPosition(700, 590);
	scoreText.setString(to_string(score));
	window.draw(scoreText);
}
//bonus cans
void bonusCans(bool remainingCanCount[], int score, const int BONUS_CAN_SCORE)
{
	for (int i = 0; i < 20; i++)
	{
		if (remainingCanCount[i] == 1)
		{
			continue;
		}
		else if (remainingCanCount[i] == 0)
		{
			if (score == BONUS_CAN_SCORE - 60000)
			{
				remainingCanCount[i] = 1;	
			}
			else if (score == BONUS_CAN_SCORE - 40000)
			{
				remainingCanCount[i] = 1;
			}
			else if (score == BONUS_CAN_SCORE)
			{
				remainingCanCount[i] = 1;
			}
			else if (score > BONUS_CAN_SCORE)
			{
				if (score % BONUS_CAN_SCORE)
				{
					remainingCanCount[i] = 1;
				}
			}
		}
	}
}
//pollinates flowers lvl1
void pollinateFlowers_lvl1(bool isPollinated[], float regularBee_x_lvl1[], float regularBee_y_lvl1[], float pollinatedFlower_x[], float pollinatedFlower_y[],bool isFlowerProcessed[],bool regularBees_lvl1[], bool regularBeeRight_lvl1[], bool flowerPlaced[], bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers)
{
	for (int i = 0; i < 20; i++)
	{
		if (regularBee_y_lvl1[i] >= 489)
		{
			bool placeFlower = 1;
			for (int j = 0; j < 30; j++)
			{
				if (isPollinated[j] == 1 && (regularBee_x_lvl1[i] >= pollinatedFlower_x[j] && regularBee_x_lvl1[i] < pollinatedFlower_x[j] + 32) || (regularBee_x_lvl1[i] + 32 > pollinatedFlower_x[j] && regularBee_x_lvl1[i] <= pollinatedFlower_x[j]))
				{
					placeFlower = 0;
					break;
				}
			}
			if (placeFlower)
			{
				for (int j = 0; j < 26; j++)
				{
					if (isPollinated[j] == 0 && leftCornerProcessed == 0 && regularBee_x_lvl1[i] == 0 && j+1 <= 25)
					{
						leftCornerProcessed = 1;
						placeLeftFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j+1] = 1;
						regularBees_lvl1[i] = 0;
						regularBee_x_lvl1[i] = -3000; 
						pollinatedFlower_x[j]=regularBee_x_lvl1[i];
						pollinatedFlower_x[j+1]=regularBee_x_lvl1[i] + 32;
						break;
					}
					else if (isPollinated[j] == 0 && rightCornerProcessed == 0 && regularBee_y_lvl1[i] >= 900 && j-1>=0)
					{
						rightCornerProcessed = 1;
						placeRightFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j-1] = 1;
						regularBees_lvl1[i] = 0;
						regularBee_x_lvl1[i] = -3000; 
						pollinatedFlower_x[j]=regularBee_x_lvl1[i];
						pollinatedFlower_x[j-1]=regularBee_x_lvl1[i] - 32;
						break;
					}
					else if (isPollinated[j] == 0)
					{
						pollinatedFlower_x[j]=regularBee_x_lvl1[i];
						regularBees_lvl1[i] = 0;
						regularBee_x_lvl1[i] = -3000; 
						isPollinated[j] = 1;
						break;
					}
					
				}
			}
		}
	}
}
//pollinates flowers lvl2
void pollinateFlowers_lvl2(bool isPollinated[], float regularBee_x_lvl2[], float regularBee_y_lvl2[],float fastBee_x_lvl2[], float fastBee_y_lvl2[], float pollinatedFlower_x[], float pollinatedFlower_y[],bool isFlowerProcessed[],bool regularBees_lvl2[],bool fastBees_lvl2[], bool regularBeeRight_lvl2[],bool fastBeeRight_lvl2[], bool flowerPlaced[], bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers)
{
	//regular bees
	for (int i = 0; i < 15; i++)
	{
		if (regularBee_y_lvl2[i] >= 489)
		{
			bool placeFlower = 1;
			for (int j = 0; j < 30; j++)
			{
				if (isPollinated[j] == 1 && (regularBee_x_lvl2[i] >= pollinatedFlower_x[j] && regularBee_x_lvl2[i] < pollinatedFlower_x[j] + 32) || (regularBee_x_lvl2[i] + 32 > pollinatedFlower_x[j] && regularBee_x_lvl2[i] <= pollinatedFlower_x[j]))
				{
					placeFlower = 0;
					break;
				}
			}
			if (placeFlower)
			{
				for (int j = 0; j < 26; j++)
				{
					if (isPollinated[j] == 0 && leftCornerProcessed == 0 && regularBee_x_lvl2[i] == 0 && j+1 <= 25)
					{
						leftCornerProcessed = 1;
						placeLeftFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j+1] = 1;
						regularBees_lvl2[i] = 0;
						regularBee_x_lvl2[i] = -3000; 
						pollinatedFlower_x[j]=regularBee_x_lvl2[i];
						pollinatedFlower_x[j+1]=regularBee_x_lvl2[i] + 32;
						break;
					}
					else if (isPollinated[j] == 0 && rightCornerProcessed == 0 && regularBee_y_lvl2[i] >= 900 && j-1>=0)
					{
						rightCornerProcessed = 1;
						placeRightFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j-1] = 1;
						regularBees_lvl2[i] = 0;
						regularBee_x_lvl2[i] = -3000; 
						pollinatedFlower_x[j]=regularBee_x_lvl2[i];
						pollinatedFlower_x[j-1]=regularBee_x_lvl2[i] - 32;
						break;
					}
					else if (isPollinated[j] == 0)
					{
						pollinatedFlower_x[j]=regularBee_x_lvl2[i];
						regularBees_lvl2[i] = 0;
						regularBee_x_lvl2[i] = -3000; 
						isPollinated[j] = 1;
						break;
					}
					
				}
			}
		}
	}
	//fast bees
	for (int i = 0; i < 5; i++)
	{
		if (fastBee_y_lvl2[i] >= 489)
		{
			bool placeFlower = 1;
			for (int j = 0; j < 30; j++)
			{
				if (isPollinated[j] == 1 && (fastBee_x_lvl2[i] >= pollinatedFlower_x[j] && fastBee_x_lvl2[i] < pollinatedFlower_x[j] + 32) || (fastBee_x_lvl2[i] + 32 > pollinatedFlower_x[j] && fastBee_x_lvl2[i] <= pollinatedFlower_x[j]))
				{
					placeFlower = 0;
					break;
				}
			}
			if (placeFlower)
			{
				for (int j = 0; j < 26; j++)
				{
					if (isPollinated[j] == 0 && leftCornerProcessed == 0 && fastBee_x_lvl2[i] == 0 && j+1 <= 25)
					{
						leftCornerProcessed = 1;
						placeLeftFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j+1] = 1;
						fastBees_lvl2[i] = 0;
						fastBee_x_lvl2[i] = -3000; 
						pollinatedFlower_x[j]=fastBee_x_lvl2[i];
						pollinatedFlower_x[j+1]=fastBee_x_lvl2[i] + 32;
						break;
					}
					else if (isPollinated[j] == 0 && rightCornerProcessed == 0 && fastBee_y_lvl2[i] >= 900 && j-1>=0)
					{
						rightCornerProcessed = 1;
						placeRightFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j-1] = 1;
						fastBees_lvl2[i] = 0;
						fastBee_x_lvl2[i] = -3000; 
						pollinatedFlower_x[j]=fastBee_x_lvl2[i];
						pollinatedFlower_x[j-1]=fastBee_x_lvl2[i] - 32;
						break;
					}
					else if (isPollinated[j] == 0)
					{
						pollinatedFlower_x[j]=fastBee_x_lvl2[i];
						fastBees_lvl2[i] = 0;
						fastBee_x_lvl2[i] = -3000; 
						isPollinated[j] = 1;
						break;
					}
					
				}
			}
		}
	}
}
//pollinates flowers lvl3
void pollinateFlowers_lvl3(bool isPollinated[], float regularBee_x_lvl3[], float regularBee_y_lvl3[],float fastBee_x_lvl3[], float fastBee_y_lvl3[], float pollinatedFlower_x[], float pollinatedFlower_y[],bool isFlowerProcessed[],bool regularBees_lvl3[],bool fastBees_lvl3[], bool regularBeeRight_lvl3[],bool fastBeeRight_lvl3[], bool flowerPlaced[], bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers)
{
	//regular bees
	for (int i = 0; i < 20; i++)
	{
		if (regularBee_y_lvl3[i] >= 489)
		{
			bool placeFlower = 1;
			for (int j = 0; j < 30; j++)
			{
				if (isPollinated[j] == 1 && (regularBee_x_lvl3[i] >= pollinatedFlower_x[j] && regularBee_x_lvl3[i] < pollinatedFlower_x[j] + 32) || (regularBee_x_lvl3[i] + 32 > pollinatedFlower_x[j] && regularBee_x_lvl3[i] <= pollinatedFlower_x[j]))
				{
					placeFlower = 0;
					break;
				}
			}
			if (placeFlower)
			{
				for (int j = 0; j < 26; j++)
				{
					if (isPollinated[j] == 0 && leftCornerProcessed == 0 && regularBee_x_lvl3[i] == 0 && j+1 <= 25)
					{
						leftCornerProcessed = 1;
						placeLeftFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j+1] = 1;
						regularBees_lvl3[i] = 0;
						regularBee_x_lvl3[i] = -3000; 
						pollinatedFlower_x[j]=regularBee_x_lvl3[i];
						pollinatedFlower_x[j+1]=regularBee_x_lvl3[i] + 32;
						break;
					}
					else if (isPollinated[j] == 0 && rightCornerProcessed == 0 && regularBee_y_lvl3[i] >= 900 && j-1>=0)
					{
						rightCornerProcessed = 1;
						placeRightFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j-1] = 1;
						regularBees_lvl3[i] = 0;
						regularBee_x_lvl3[i] = -3000; 
						pollinatedFlower_x[j]=regularBee_x_lvl3[i];
						pollinatedFlower_x[j-1]=regularBee_x_lvl3[i] - 32;
						break;
					}
					else if (isPollinated[j] == 0)
					{
						pollinatedFlower_x[j]=regularBee_x_lvl3[i];
						regularBees_lvl3[i] = 0;
						regularBee_x_lvl3[i] = -3000; 
						isPollinated[j] = 1;
						break;
					}
					
				}
			}
		}
	}
	//fast bees
	for (int i = 0; i < 10; i++)
	{
		if (fastBee_y_lvl3[i] >= 489)
		{
			bool placeFlower = 1;
			for (int j = 0; j < 30; j++)
			{
				if (isPollinated[j] == 1 && (fastBee_x_lvl3[i] >= pollinatedFlower_x[j] && fastBee_x_lvl3[i] < pollinatedFlower_x[j] + 32) || (fastBee_x_lvl3[i] + 32 > pollinatedFlower_x[j] && fastBee_x_lvl3[i] <= pollinatedFlower_x[j]))
				{
					placeFlower = 0;
					break;
				}
			}
			if (placeFlower)
			{
				for (int j = 0; j < 26; j++)
				{
					if (isPollinated[j] == 0 && leftCornerProcessed == 0 && fastBee_x_lvl3[i] == 0 && j+1 <= 25)
					{
						leftCornerProcessed = 1;
						placeLeftFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j+1] = 1;
						fastBees_lvl3[i] = 0;
						fastBee_x_lvl3[i] = -3000; 
						pollinatedFlower_x[j]=fastBee_x_lvl3[i];
						pollinatedFlower_x[j+1]=fastBee_x_lvl3[i] + 32;
						break;
					}
					else if (isPollinated[j] == 0 && rightCornerProcessed == 0 && fastBee_y_lvl3[i] >= 900 && j-1>=0)
					{
						rightCornerProcessed = 1;
						placeRightFlowers = 1;
						isPollinated[j] = 1;
						isPollinated[j-1] = 1;
						fastBees_lvl3[i] = 0;
						fastBee_x_lvl3[i] = -3000; 
						pollinatedFlower_x[j]=fastBee_x_lvl3[i];
						pollinatedFlower_x[j-1]=fastBee_x_lvl3[i] - 32;
						break;
					}
					else if (isPollinated[j] == 0)
					{
						pollinatedFlower_x[j]=fastBee_x_lvl3[i];
						fastBees_lvl3[i] = 0;
						fastBee_x_lvl3[i] = -3000; 
						isPollinated[j] = 1;
						break;
					}
				}
			}
		}
	}
}
//draws flowers
void drawFlowers(RenderWindow& window, Sprite flowerSprite[],float pollinatedFlower_x[],float pollinatedFlower_y[], bool isPollinated[],bool& leftCornerProcessed, bool& rightCornerProcessed,bool& placeRightFlowers, bool& placeLeftFlowers)
{
	for (int i = 0; i < 26; i++)
	{
		if (isPollinated[i] == 1 && placeLeftFlowers == 1 && i+1 <= 25)
		{
			flowerSprite[i].setPosition(0, 547);
			flowerSprite[i+1].setPosition(32,547);
			window.draw(flowerSprite[i]);
			window.draw(flowerSprite[i+1]);
			placeLeftFlowers = 0;
		}
		else if (isPollinated[i] == 1 && placeRightFlowers == 1 && i-1 >= 0)
		{
			flowerSprite[i].setPosition(900,547);
			flowerSprite[i-1].setPosition(864,547);
			window.draw(flowerSprite[i]);
			window.draw(flowerSprite[i+1]);
			placeRightFlowers = 0;
		}
		else if (isPollinated[i] == 1)
		{
			flowerSprite[i].setPosition(pollinatedFlower_x[i], 547);
			window.draw(flowerSprite[i]);
		}
	}
}
//draws beehives if they exist
void drawBeehive(RenderWindow& window, Sprite beehiveSprite[], const int BEEHIVES,float beehive_x[], float beehive_y[], bool beehives[])
{
	for (int i = 0; i < BEEHIVES; i++)
	{
		if (beehives[i])
		{
			beehiveSprite[i].setPosition(beehive_x[i], beehive_y[i]);
			window.draw(beehiveSprite[i]);
		}
	}
}
//move bird
void moveBird(int& frames, int& randomDirection, int& currentDirection, float& bird_x, float& bird_y, int birdDirections[], bool& birdPaused, int& pauseFrames, int& birdHitCount, bool& birdSick, int& sickFrames, Sprite& birdSprite)
{
	//will only change direction if 60 frames have passed
	if (frames > 60)
	{
		//assigning a random index
		randomDirection = rand() % 7;
		frames = 0;
		//assigning the current direction out of all 8
		//pausing the bird
		birdPaused = 1;
		currentDirection = birdDirections[randomDirection];
	}
	//unpausing the bee
	if (pauseFrames > 15)
	{
		pauseFrames = 0;
		birdPaused = 0;
	}
	if (sickFrames > 360)
	{
		birdHitCount = 0;
		sickFrames = 0;
		birdSick = 0;
		currentDirection = 0;
		birdSprite.setColor(Color::Blue);
	}
	//moving the bird on the basis of its direction
	//left
	if (birdPaused == 0)
	{
		if (birdSick == 0)
		{
			if (currentDirection == 0 && (bird_x - 10 >= 0))
			{
				bird_x -= 10;
			}
			//down
			else if (currentDirection == 1 && (bird_y + 5 <= 500))
			{
				bird_y += 5;
			}
			//up
			else if (currentDirection == 2 && (bird_y - 5 >= 0))
			{
				bird_y -= 5;
			}
			//right
			else if (currentDirection == 3 && (bird_x + 10 <= 900))
			{
				bird_x += 10;
			}
			//top left
			else if (currentDirection == 4 && (bird_x - 10 >= 0) && (bird_y - 5 >= 0))
			{
				bird_x -= 10;
				bird_y -= 5;
			}
			//top right
			else if (currentDirection == 5 && (bird_x + 10 <= 900) && (bird_y - 5 >= 0))
			{
				bird_x += 10;
				bird_y -= 5;
			}
			//bottom left
			else if (currentDirection == 6 && (bird_x - 10 >= 0) && (bird_y + 5 <= 500))
			{
				bird_x -= 10;
				bird_y += 5;
			}
			//bottom right
			else if (currentDirection == 7 && (bird_x + 10 <= 900) && (bird_y + 5 <= 500))
			{
				bird_x += 10;
				bird_y += 5;
			}
			//incrementing the frames
			frames++;
		}
		else
		{
			birdSprite.setColor(Color::Green);
			bird_x += 10;
			sickFrames++;
		}
	}
	else
	{
		pauseFrames++;
	}
	//checks if the bird is sick
	if (birdHitCount == 3)
	{
		birdSick = 1;
	}
}
//draw bird
void drawBird(RenderWindow& window, Sprite& birdSprite, float& bird_x, float& bird_y)
{
	birdSprite.setPosition(bird_x, bird_y);
	window.draw(birdSprite);
}
//checks if bird reaches honeycomb lvl1
void birdCollideComb_lvl1(float& bird_y, float& bird_x, int randomHoneyComb_x_lvl1[],int randomHoneyComb_y_lvl1[],float yellowHoneyComb_x_lvl1[],float yellowHoneyComb_y_lvl1[], bool& birdPaused, bool isBirdCollidePregenComb_lvl1[], bool isBirdCollideYellowComb_lvl1[], bool yellowHoneyCombs_lvl1[], bool pregenYellowHoneyCombs_lvl1[], bool& birdSick, int& score)
{
	float bird_height = bird_y + (32*1.5);
	float bird_length = bird_x + (64*1.5);
	//pre gen honeycombs lvl1
	for (int i = 0; i < 3; i++)
	{
		float honeyComb_height = randomHoneyComb_y_lvl1[i] + (64*0.7);
		float honeyComb_length = randomHoneyComb_x_lvl1[i] + (64*0.7);
		int position = randomHoneyComb_y_lvl1[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && randomHoneyComb_x_lvl1[i] <= bird_length && honeyComb_height >= bird_y && randomHoneyComb_y_lvl1[i] <= bird_height && birdSick == 0 && pregenYellowHoneyCombs_lvl1[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 1000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 800;
			}
			else
			{
				score += 500;
			}
			birdPaused = 1;
			isBirdCollidePregenComb_lvl1[i] = 1;
			pregenYellowHoneyCombs_lvl1[i] = 0;
			randomHoneyComb_x_lvl1[i] = -3000;
		}
	}
	//yellow honeycombs lvl1
	for (int i = 0; i < 20; i++)
	{
		float honeyComb_height = yellowHoneyComb_y_lvl1[i] + (64*0.7);
		float honeyComb_length = yellowHoneyComb_x_lvl1[i] + (64*0.7);
		int position = yellowHoneyComb_y_lvl1[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && yellowHoneyComb_x_lvl1[i] <= bird_length && honeyComb_height >= bird_y && yellowHoneyComb_y_lvl1[i] <= bird_height && birdSick == 0 && yellowHoneyCombs_lvl1[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 1000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 800;
			}
			else
			{
				score += 500;
			}
			birdPaused = 1;
			isBirdCollideYellowComb_lvl1[i] = 1;
			yellowHoneyCombs_lvl1[i] = 0;
			yellowHoneyComb_x_lvl1[i] = -3000;
		}
	}
}
//lvl2
void birdCollideComb_lvl2(float& bird_y, float& bird_x, int randomHoneyComb_x_lvl2[],int randomHoneyComb_y_lvl2[],float yellowHoneyComb_x_lvl2[],float yellowHoneyComb_y_lvl2[],float redHoneyComb_x_lvl2[], float redHoneyComb_y_lvl2[], bool& birdPaused, bool isBirdCollidePregenComb_lvl2[], bool isBirdCollideYellowComb_lvl2[],bool isBirdCollideRedComb_lvl2[], bool yellowHoneyCombs_lvl2[],bool redHoneyCombs_lvl2[], bool pregenYellowHoneyCombs_lvl2[], bool& birdSick, int& score)
{
	float bird_height = bird_y + (32*1.5);
	float bird_length = bird_x + (64*1.5);
	//pre gen honeycombs lvl2
	for (int i = 0; i < 9; i++)
	{
		float honeyComb_height = randomHoneyComb_y_lvl2[i] + (64*0.7);
		float honeyComb_length = randomHoneyComb_x_lvl2[i] + (64*0.7);
		int position = randomHoneyComb_y_lvl2[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && randomHoneyComb_x_lvl2[i] <= bird_length && honeyComb_height >= bird_y && randomHoneyComb_y_lvl2[i] <= bird_height && birdSick == 0 && pregenYellowHoneyCombs_lvl2[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 1000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 800;
			}
			else
			{
				score += 500;
			}
			birdPaused = 1;
			isBirdCollidePregenComb_lvl2[i] = 1;
			pregenYellowHoneyCombs_lvl2[i] = 0;
			randomHoneyComb_x_lvl2[i] = -3000;
		}
	}
	//yellow honeycombs lvl2
	for (int i = 0; i < 15; i++)
	{
		float honeyComb_height = yellowHoneyComb_y_lvl2[i] + (64*0.7);
		float honeyComb_length = yellowHoneyComb_x_lvl2[i] + (64*0.7);
		int position = yellowHoneyComb_y_lvl2[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && yellowHoneyComb_x_lvl2[i] <= bird_length && honeyComb_height >= bird_y && yellowHoneyComb_y_lvl2[i] <= bird_height && birdSick == 0 && yellowHoneyCombs_lvl2[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 1000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 800;
			}
			else
			{
				score += 500;
			}
			birdPaused = 1;
			isBirdCollideYellowComb_lvl2[i] = 1;
			yellowHoneyCombs_lvl2[i] = 0;
			yellowHoneyComb_x_lvl2[i] = -3000;
		}
	}
	//red honeycombs lvl2
	for (int i = 0; i < 5; i++)
	{
		float honeyComb_height = redHoneyComb_y_lvl2[i] + (64*0.7);
		float honeyComb_length = redHoneyComb_x_lvl2[i] + (64*0.7);
		int position = redHoneyComb_y_lvl2[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && redHoneyComb_x_lvl2[i] <= bird_length && honeyComb_height >= bird_y && redHoneyComb_y_lvl2[i] <= bird_height && birdSick == 0 && redHoneyCombs_lvl2[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 2000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 1800;
			}
			else
			{
				score += 1500;
			}
			birdPaused = 1;
			isBirdCollideRedComb_lvl2[i] = 1;
			redHoneyCombs_lvl2[i] = 0;
			redHoneyComb_x_lvl2[i] = -3000;
		}
	}
}
//lvl3
void birdCollideComb_lvl3(float& bird_y, float& bird_x, int randomHoneyComb_x_lvl3[],int randomHoneyComb_y_lvl3[],float yellowHoneyComb_x_lvl3[],float yellowHoneyComb_y_lvl3[],float redHoneyComb_x_lvl3[], float redHoneyComb_y_lvl3[], bool& birdPaused, bool isBirdCollidePregenComb_lvl3[], bool isBirdCollideYellowComb_lvl3[],bool isBirdCollideRedComb_lvl3[], bool yellowHoneyCombs_lvl3[],bool redHoneyCombs_lvl3[], bool pregenYellowHoneyCombs_lvl3[], bool& birdSick, int& score)
{
	float bird_height = bird_y + (32*1.5);
	float bird_length = bird_x + (64*1.5);
	//pre gen honeycombs lvl3
	for (int i = 0; i < 15; i++)
	{
		float honeyComb_height = randomHoneyComb_y_lvl3[i] + (64*0.7);
		float honeyComb_length = randomHoneyComb_x_lvl3[i] + (64*0.7);
		int position = randomHoneyComb_y_lvl3[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && randomHoneyComb_x_lvl3[i] <= bird_length && honeyComb_height >= bird_y && randomHoneyComb_y_lvl3[i] <= bird_height && birdSick == 0 && pregenYellowHoneyCombs_lvl3[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 1000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 800;
			}
			else
			{
				score += 500;
			}
			birdPaused = 1;
			isBirdCollidePregenComb_lvl3[i] = 1;
			pregenYellowHoneyCombs_lvl3[i] = 0;
			randomHoneyComb_x_lvl3[i] = -3000;
		}
	}
	//yellow honeycombs lvl3
	for (int i = 0; i < 20; i++)
	{
		float honeyComb_height = yellowHoneyComb_y_lvl3[i] + (64*0.7);
		float honeyComb_length = yellowHoneyComb_x_lvl3[i] + (64*0.7);
		int position = yellowHoneyComb_y_lvl3[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && yellowHoneyComb_x_lvl3[i] <= bird_length && honeyComb_height >= bird_y && yellowHoneyComb_y_lvl3[i] <= bird_height && birdSick == 0 && yellowHoneyCombs_lvl3[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 1000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 800;
			}
			else
			{
				score += 500;
			}
			birdPaused = 1;
			isBirdCollideYellowComb_lvl3[i] = 1;
			yellowHoneyCombs_lvl3[i] = 0;
			yellowHoneyComb_x_lvl3[i] = -3000;
		}
	}
	//red honeycombs lvl3
	for (int i = 0; i < 10; i++)
	{
		float honeyComb_height = redHoneyComb_y_lvl3[i] + (64*0.7);
		float honeyComb_length = redHoneyComb_x_lvl3[i] + (64*0.7);
		int position = redHoneyComb_y_lvl3[i] / 64; //height of 1 tier
		if (honeyComb_length >= bird_x && redHoneyComb_x_lvl3[i] <= bird_length && honeyComb_height >= bird_y && redHoneyComb_y_lvl3[i] <= bird_height && birdSick == 0 && redHoneyCombs_lvl3[i] == 1)
		{
			if (position == 1 || position == 2)
			{
				score += 2000;
			}
			else if (position == 3 || position == 4 || position == 5)
			{
				score += 1800;
			}
			else
			{
				score += 1500;
			}
			birdPaused = 1;
			isBirdCollideRedComb_lvl3[i] = 1;
			redHoneyCombs_lvl3[i] = 0;
			redHoneyComb_x_lvl3[i] = -3000;
		}
	}
}
//plays music
void playMusic(Music& lvl1Music,Music& lvl2Music,Music& lvl3Music,int& levelState)
{
	if (levelState == 1)
	{
		lvl1Music.play();
	}
	else if (levelState == 2)
	{
		lvl2Music.play();
	}
	else if (levelState == 3)
	{
		lvl3Music.play();
	}
}
//changes levels
void levelTransition1(int& levelState, RenderWindow& window, bool regularBees_lvl1[], int& score)
{
	int regularBeeCount = 0;
	int transitionFrames = 0;
		//counts bees
		for (int i = 0; i < 20; i++)
		{
			if (regularBees_lvl1[i] == 1)
			{
				regularBeeCount++;
			}
		}
		//maintains level state
		if (regularBeeCount != 0)
		{
			levelState = 1;
		}
		//changes level state
		else
		{
			levelState = 2;
		}
		//transition screen
		if (levelState == 2)
		{
			while (transitionFrames <= 360)
			{
				Font transitionFont;
				transitionFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
				Text transitionText;
				transitionText.setFont(transitionFont);
				transitionText.setString("LEVEL 1 COMPLETE!");
				transitionText.setCharacterSize(35);
				transitionText.setFillColor(Color::Green);
				transitionText.setPosition(180,200);
				window.draw(transitionText);
				Text scoreText;
				scoreText.setFont(transitionFont);
				scoreText.setString("Your Score: ");
				scoreText.setCharacterSize(20);
				scoreText.setFillColor(Color::Green);
				scoreText.setPosition(180,250);
				window.draw(transitionText);
				Text scoreString;
				scoreString.setFont(transitionFont);
				scoreString.setString(to_string(score));
				scoreString.setCharacterSize(20);
				scoreString.setFillColor(Color::White);
				scoreString.setPosition(500,250);
				window.draw(transitionText);
				window.draw(scoreText);
				window.draw(scoreString);
				window.display();
				transitionFrames++;
			}
		}
}
//changes levels
void levelTransition2(int& levelState, RenderWindow& window, bool regularBees_lvl2[], bool fastBees_lvl2[], int& score)
{
	int regularBeeCount = 0;
	int fastBeeCount = 0;
	int transitionFrames = 0;
		//counts bees
		for (int i = 0; i < 20; i++)
		{
			if (regularBees_lvl2[i] == 1)
			{
				regularBeeCount++;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			if (fastBees_lvl2[i] == 1)
			{
				fastBeeCount++;
			}
		}
		//maintains level state
		if (regularBeeCount != 0 && fastBeeCount != 0)
		{
			levelState = 2;
		}
		//changes level state
		else
		{
			levelState = 3;
		}
		//transition screen
		if (levelState == 3)
		{
			while (transitionFrames <= 360)
			{
				Font transitionFont;
				transitionFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
				Text transitionText;
				transitionText.setFont(transitionFont);
				transitionText.setString("LEVEL 2 COMPLETE!");
				transitionText.setCharacterSize(35);
				transitionText.setFillColor(Color::Green);
				transitionText.setPosition(180,200);
				window.draw(transitionText);
				Text scoreText;
				scoreText.setFont(transitionFont);
				scoreText.setString("Your Score: ");
				scoreText.setCharacterSize(20);
				scoreText.setFillColor(Color::Green);
				scoreText.setPosition(180,250);
				window.draw(transitionText);
				Text scoreString;
				scoreString.setFont(transitionFont);
				scoreString.setString(to_string(score));
				scoreString.setCharacterSize(20);
				scoreString.setFillColor(Color::White);
				scoreString.setPosition(500,250);
				window.draw(transitionText);
				window.draw(scoreText);
				window.draw(scoreString);
				window.display();
				transitionFrames++;
			}
		}
}
//if game is completed
void gameCompleted(int& levelState, RenderWindow& window, bool regularBees_lvl3[], bool fastBees_lvl3[], int& score, bool& isGameCompleted)
{
	int regularBeeCount = 0;
	int fastBeeCount = 0;
	int transitionFrames = 0;
		//counts bees
		for (int i = 0; i < 20; i++)
		{
			if (regularBees_lvl3[i] == 1)
			{
				regularBeeCount++;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (fastBees_lvl3[i] == 1)
			{
				fastBeeCount++;
			}
		}
		//maintains level state
		if (regularBeeCount != 0 && fastBeeCount != 0)
		{
			levelState = 3;
		}
		//changes level state
		else
		{
			isGameCompleted = 1;
			levelState = 0;
		}
		//transition screen
		if (isGameCompleted == 1)
		{
			while (transitionFrames <= 360)
			{
				Font transitionFont;
				transitionFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
				Text transitionText;
				transitionText.setFont(transitionFont);
				transitionText.setString("LEVEL 3 COMPLETE!");
				transitionText.setCharacterSize(35);
				transitionText.setFillColor(Color::Green);
				transitionText.setPosition(180,200);
				Text scoreText;
				scoreText.setFont(transitionFont);
				scoreText.setString("Your Score: ");
				scoreText.setCharacterSize(20);
				scoreText.setFillColor(Color::Green);
				scoreText.setPosition(180,250);
				Text scoreString;
				scoreString.setFont(transitionFont);
				scoreString.setString(to_string(score));
				scoreString.setCharacterSize(20);
				scoreString.setFillColor(Color::White);
				scoreString.setPosition(500,250);
				window.draw(transitionText);
				window.draw(scoreText);
				window.draw(scoreString);
				window.display();
				transitionFrames++;
			}
		}
}
//game over screen
void gameOverScreen(RenderWindow& window, int& score)
{
	int transitionFrames = 0;
	while (transitionFrames <= 360)
	{
		Font transitionFont;
				transitionFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
				Text transitionText;
				transitionText.setFont(transitionFont);
				transitionText.setString("GAME OVER!");
				transitionText.setCharacterSize(50);
				transitionText.setFillColor(Color::Red);
				transitionText.setPosition(180,200);
				Text scoreText;
				scoreText.setFont(transitionFont);
				scoreText.setString("Your Score: ");
				scoreText.setCharacterSize(20);
				scoreText.setFillColor(Color::Green);
				scoreText.setPosition(180,250);
				window.draw(transitionText);
				Text scoreString;
				scoreString.setFont(transitionFont);
				scoreString.setString(to_string(score));
				scoreString.setCharacterSize(20);
				scoreString.setFillColor(Color::White);
				scoreString.setPosition(500,250);
				window.draw(transitionText);
				window.draw(scoreText);
				window.draw(scoreString);
				window.draw(transitionText);
				window.display();
				transitionFrames++;
	}
	exit(0);
}
//displays highscores
void displayScores(RenderWindow& window, int& gameState, char playerNames[][50], int highScores[])
{
	ifstream highscorefile("highscores.txt");
	//reading all the data of the file into arrays and also counting the amount of entries
	int playersNum = 0;
	while (playersNum < 1000 && highscorefile >> playerNames[playersNum] >> highScores[playersNum])
	{
		playersNum++;
	}
	highscorefile.close();
	//now using bubble sort to get top 10 scores
	char temp[50] = "";
	for (int i = playersNum-1 ; i >= 0; i--)
	{
		for (int j = 0; j <= i ; j++)
		{
			if (highScores[j] < highScores[j+1])
			{
				//sorting the score
				highScores[j] = highScores[j] ^ highScores[j+1];
				highScores[j+1] = highScores[j] ^ highScores[j+1];
				highScores[j] = highScores[j] ^ highScores[j+1];
				//bringing the name aswell
				for (int k = 0; k < 50; k++)
				{
					temp[k] = playerNames[j][k];
				}
				for (int k = 0; k < 50; k++)
				{
					playerNames[j][k] = playerNames[j+1][k];
				}
				for (int k = 0; k < 50; k++)
				{
					playerNames[j+1][k] = temp[k];
				}
			}
		}
	}
	//font
	Font menuFont;
	menuFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
	//displaying the logo
	Text logo("High Scores", menuFont, 20);
	logo.setPosition(180, 100);
	logo.setFont(menuFont);
	logo.setFillColor(Color::Green);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (e.type == Event::KeyPressed)
			{
				if (e.key.scancode == Keyboard::Scan::E)
				{
					exit(0);
				}
			}
			window.clear();
			//displaying the high scores
			for (int i = 0; i < 10; i++)
			{
				Text highScoreText;
				highScoreText.setString(string(playerNames[i]) + "     " + to_string(highScores[i]));
				highScoreText.setPosition(180, (100 + (30*(i+1))));
				highScoreText.setFont(menuFont);
				highScoreText.setCharacterSize(10);
				highScoreText.setFillColor(Color::Magenta);
				window.draw(highScoreText);
			}
			//back button
			Text back("PRESS E TO EXIT", menuFont, 15);
			back.setPosition(180, 600);
			back.setFont(menuFont);
			back.setFillColor(Color::White);
			window.draw(logo);
			window.draw(back);
			window.display();
		}
	}
}
//gets player name
void enterName(RenderWindow& window, char playerName[], int& score, bool& nameSubmitted)
{
	Font menuFont;
	menuFont.loadFromFile("fonts/PressStart2P-Regular.ttf");
	Text labelText("ENTER YOUR NAME: ", menuFont, 30);
	labelText.setPosition(180, 200);
	labelText.setFillColor(Color::Yellow);
	Text playerNameText("", menuFont, 30);
	playerNameText.setPosition(180, 250);
	playerNameText.setFillColor(Color::White);
	Clock delayClock;
	int current = 0;
	while (window.isOpen() && nameSubmitted == 0)
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}
		if (e.type == Event::TextEntered)
		{
			if (delayClock.getElapsedTime().asSeconds() > 0.05)
			{
			//handles deleting
			if (e.text.unicode == '\b')
			{
				if (current > 0)
				{
					current--;
					playerName[current] = '\0';
				}
			}
			//registers entered name
			else if (e.text.unicode == '\r')
			{
				nameSubmitted = 1;
			}
			//enters the name
			else if (current <= 50)
			{
				playerName[current] = static_cast<char>(e.text.unicode);
				current++;
				playerName[current] = '\0';
			}
			}
			delayClock.restart();
		}
		//setting the name
		playerNameText.setString(playerName);
		window.clear();
		window.draw(playerNameText);
		window.draw(labelText);
		window.display();
	}
	ofstream highscorefile("highscores.txt", std::ios::app);
	highscorefile << playerName << " " << score;
	highscorefile.close();
}
