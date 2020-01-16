#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "DoubleLinkedList.h"

class SimonApp : public aie::Application {
public:
	//defaults constructor
	SimonApp();
	//destructor
	virtual ~SimonApp();

	//Initializer function
	virtual bool startup();
	//Function for clean ran befor the app is exited
	virtual void shutdown();

	//runs every frame and is the logic behind it all
	//deltaTime is the time between frames 
	virtual void update(float deltaTime);
	//the draw function ran every frame
	virtual void draw();

	// Draws the buttons
	void DrawButtons();
	//Draws the gamescreen
	void DrawGameScreen();
	//Draws the timer
	void DrawTimer();

	//Sets the timer to the start
	void SetGameTimer();
	//sets the play timer to the start
	void SetPlayerTimer(); 

	 //updates the game timers status
	void CheckGameTimer(float dt);
	//updates the player timers status
	void CheckPlayerTimer(float dt);
	//updates the input status
	void CheckBtnPressed(aie::Input* input);

	//Runs the logic of the buttons and inputs
	void GameLogic(aie::Input *input, float dt);

	//Traverses to the next level and adds to the scire
	void NextLevel();
	//Sends the player to the fail screen 
	void Fail();

	//Checks if the player matched the queued button or not
	bool CheckPlayerMatched();
protected:
	 

	float scoreNodeTimer = 0;
	float gameTimer = 0; 
	float playerTimer = 0;  
	float btnIntervalTimer = 0;
	float keyPressed = 0;

	bool btnPressable = true;
	bool gameOn = false;
	bool nextLevel = false;
	bool failed = false;

	int curScore, hiScore;


	Button*				m_btn1;
	Button*				m_btn2;
	Button*				m_btn3;
	Button*				m_btn4;

	std::vector<int>	toBePressed;
	std::vector<Button*> buttons;
	std::vector<Button*> toBePlayed; 
	std::vector<int>	keysPressed;
	
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font; 

	
};