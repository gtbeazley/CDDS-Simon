#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Button.h"

#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <iostream>

SimonApp::SimonApp() {

}

SimonApp::~SimonApp() {

}

bool SimonApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	 
	//Create the four buttons with their ids
	m_btn1 = new Button(1);
	m_btn2 = new Button(2);
	m_btn3 = new Button(3);
	m_btn4 = new Button(4);

	//Adds each button to the processing list
	buttons.push_back(m_btn1);
	buttons.push_back(m_btn2);
	buttons.push_back(m_btn3);
	buttons.push_back(m_btn4);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_arrowKeysTexture = new aie::Texture("./Images/ArrowKeys.png");
	m_spaceBarTexture = new aie::Texture("./Images/SpaceBar.png");
	m_wasdTexture = new aie::Texture("./Images/WASD.png");

	return true;
}

void SimonApp::shutdown() {
	delete m_btn1;
	delete m_btn2;
	delete m_btn3;
	delete m_btn4; 
	delete m_font;
	delete m_2dRenderer;
}

void SimonApp::update(float deltaTime) {

	aie::Input*	input = aie::Input::getInstance(); 

	//Checks the boolean set to see if the game is still playing
	if (gameOn)
	{	
		//This continues the game to the next level..
		NextLevel();
		//.. and continues to update all logic in the game
		GameLogic(input, deltaTime);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_TAB))
	{
		instructionScreen = true;
	}
	else if (instructionScreen)
	{
		if (input->isKeyDown(aie::INPUT_KEY_BACKSPACE)) instructionScreen = false;
	}
	else if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		//If we know the game isnt playing that means we are in some sort of waiting state
		//this means once the player presses space all values are reset 
		curScore = 0;
		failed = false;
 		gameOn = true;
		nextLevel = true;
	}

	//Determines what timer to tick down whether its playing the seqence o rwaiting for the player input
	CheckGameTimer(deltaTime);
	if(!gameTimer)
		CheckPlayerTimer(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SimonApp::draw() {

	
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	 


	if (instructionScreen)
	{
		DrawInstructionScreen();

	}
	else
	{
	//Our draw logic
		DrawTimer();

		DrawButtons();

		DrawGameScreen();
	
	}

	//Lets player know they could do it even though they wouldn;t want to
	if(!instructionScreen)
		m_2dRenderer->setRenderColour(1, 1, 1);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	
	// done drawing sprites
	m_2dRenderer->end();
}

void SimonApp::SetGameTimer()
{
	if (toBePlayed.size() > 0)
	{
		gameTimer = toBePlayed.size() * 32;
	}

	if (toBePlayed.size() == 0)
	{
		gameTimer += 32;
	}
}

void SimonApp::SetPlayerTimer()
{
	playerTimer = toBePressed.size() * 32;
	if (toBePlayed.size() == 1)
	{
		playerTimer += 32.0f;
	}
}

void SimonApp::CheckGameTimer(float dt)
{
	if (gameTimer > 0)
		gameTimer -= dt * 32;
	else
		gameTimer = 0;
}

void SimonApp::CheckPlayerTimer(float dt)
{
	if (playerTimer > 0)
		playerTimer -= dt * 32;
	else
		playerTimer = 0;
}

void SimonApp::CheckBtnPressed(aie::Input* input)
{	
	//Checks to see if the user allowed to press keys
	if (btnPressable)
	{
		//Then checks te users input
		if (input->isKeyDown(aie::INPUT_KEY_UP)
			|| input->isKeyDown(aie::INPUT_KEY_W))
		{
			keyPressed = 1;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_LEFT)
			|| input->isKeyDown(aie::INPUT_KEY_A))
		{
			keyPressed = 2;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_RIGHT)
			|| input->isKeyDown(aie::INPUT_KEY_D))
		{
			keyPressed = 3;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_DOWN)
			|| input->isKeyDown(aie::INPUT_KEY_S))
		{
			keyPressed = 4;
		} 
	}

	//Checks the keys that was just pressed
	if (keyPressed != 0)
	{
		//adds the key pressed to the keys pressed array
		keysPressed.push_back(keyPressed);
		//Gives the player a time before they can repress the key
		btnIntervalTimer = 10;
		btnPressable = false;
	}

	//clears the pressed key
	keyPressed = 0;
}

void SimonApp::Fail()
{
	//Sets the highscore if needed
	if (curScore > hiScore)
		hiScore = curScore;
	//Resets all in game values
	gameOn = false;
	btnIntervalTimer = 0;
	btnPressable = true;
	keyPressed = 0; 
	toBePressed.clear(); 
	toBePlayed.clear();
	keysPressed.clear();
	//Tells the game to stop
	failed = true;
}

bool SimonApp::CheckPlayerMatched()
{
	// checks the list of keys that are to be pressed the list of keys that were pressed
	int i = 0;
	for (i = 0; i < keysPressed.size(); i++)
	{
		//if one of them are wrong this returns false
		if (keysPressed[i] != toBePressed[i])
			return false;

	} 
	//if we have exited the loop we have succeeded
	return true;
}

void SimonApp::NextLevel()
{
	if (nextLevel)
	{
		curScore++;
		//Generate random number from 0-3
		srand(time(NULL));
		int RGN = rand() % 4;

		//Push the buttons that are going to be checked for the game on to the array
		toBePlayed.push_back(buttons[RGN]);
		toBePressed.push_back(1 + RGN);

		//Set timers for the new sequence to be played
		SetGameTimer();
		SetPlayerTimer();
		keysPressed.clear();
		nextLevel = false;

	}
}

void SimonApp::GameLogic(aie::Input *input, float dt)
{
	//check if theres more time 
	if (playerTimer > 0
		&& gameTimer <= 0)
	{
		//check if there is a button that has been pressed
		CheckBtnPressed(input);

		//compare button pressed to buttons needed to press 
		if (btnPressable == false)//(btnIntervalTimer > 0)
		{
			if (!CheckPlayerMatched())
				Fail();
			else if (keysPressed.size() == toBePressed.size())
				nextLevel = true;
		}
	}
	//check if player time has run out
	else if (playerTimer <= 0)
		Fail();

	//check if the time between the buttons pressed is to quick
	if (btnIntervalTimer > 0)
	{
		btnIntervalTimer-= dt * 55;
		//btnPressable = false;
	}
	if (input->getPressedKeys().size() == 0)
	{
		btnIntervalTimer = 0;
		btnPressable = true;
	}
}

void SimonApp::DrawButtons()
{

	//draw the buttons according to the screen
	for (int i = 0; i < 4; i++)
	{
		buttons[i]->SetScreen(getWindowWidth(), getWindowHeight());
		buttons[i]->Draw(m_2dRenderer);
	}

	if (gameOn)
	{
		float fullTime = toBePlayed.size() * 32;
		// go through tobeplayed list

		for (int i = 0; i < buttons.size(); i++)
			buttons[i]->SetIsPlaying(false);
		for (int i = 0; i < toBePlayed.size(); i++)
		{
			//check if gameTimer 
			if (gameTimer > fullTime - (31 + (32 * i))
				&& gameTimer < fullTime - (32 * i))
				toBePlayed[i]->SetIsPlaying(true);
		}
	}
}

void SimonApp::DrawGameScreen()
{
	float l_screenX = getWindowWidth(), l_screenY = getWindowHeight();
	//If we're waiting for the player to start the game at any time, we print the message
	if (!gameOn)
	{
		m_2dRenderer->drawText(m_font, "Press SPACE to start", l_screenX / 2 - 180, l_screenY / 2 - 10);
		m_2dRenderer->drawText(m_font, "Press TAB for instructions on how to play", 0 , l_screenY *.95);
	}
	else
	{
		//If we're not waiting the player that means we're playing the game 
		if (gameTimer > 0)
		{
			//We check if the gameTimer has  more time for the sequence being played
			m_2dRenderer->drawText(m_font, "Playing Sequence", l_screenX / 2 - 150, l_screenY / 2 - 10);
		}
		else if (playerTimer > 0)
		{
			//If we know the first timer is up we must check if the second timer has more time
			//This is when we let the player start playing
			m_2dRenderer->drawText(m_font, "GOOOOOOO!!!!!", l_screenX / 2 - 100, l_screenY / 2 - 10);
		}

		for (int i = 0; i < toBePressed.size(); i++)
		{
			//The circles are drawn to show how many are left in a red colour
			m_2dRenderer->setRenderColour(1, 0, 0);
			m_2dRenderer->drawCircle(l_screenX / 4 + (30 * i), 660, 10);

		}
		for (int i = 0; i < keysPressed.size(); i++)
		{
			//The green cirles are shown to show hom many circles the player got correct
			if (keysPressed[i] == toBePressed[i])
				m_2dRenderer->setRenderColour(0, 1, 0);
			m_2dRenderer->drawCircle(l_screenX / 4 + (30 * i), 660, 10);
		}
	}

	// Checks if the player had just failed the game
	if (failed)
	{
		//Tell the player how they went
		m_2dRenderer->setRenderColour(.5, 0, 0);
		m_2dRenderer->drawBox(l_screenX / 2, l_screenY / 2 + 50, 100, 50);

		m_2dRenderer->setRenderColour(0, 0, 0);
		m_2dRenderer->drawText(m_font, "Fail", l_screenX / 2 - 35, l_screenY / 2 + 40);

		//Converts the score in to text to print on screen
		m_2dRenderer->setRenderColour(1, 1, 1);
		char cScrTxt[64];
		snprintf(cScrTxt, 64, "Your score: %i points", curScore);
		m_2dRenderer->drawText(m_font, cScrTxt, l_screenX / 2 - 180, l_screenY / 2 - 70);
		char hScrTxt[64];
		snprintf(hScrTxt, 64, "Highest Score: %i points", hiScore);
		m_2dRenderer->drawText(m_font, hScrTxt, l_screenX / 20, l_screenY / 8 * 7);
	}
}

void SimonApp::DrawInstructionScreen()
{
	if (instructionScreen)
	{
		float l_screenX = getWindowWidth(), l_screenY = getWindowHeight();
		m_2dRenderer->drawBox(l_screenX / 2, l_screenY / 2, l_screenX, l_screenY);
		m_2dRenderer->drawSprite(m_spaceBarTexture, l_screenX * .1, l_screenY *.8, 100, 100);
		m_2dRenderer->drawSprite(m_arrowKeysTexture, l_screenX *.1, l_screenY *.5, 100, 100);
		m_2dRenderer->drawSprite(m_wasdTexture, l_screenX *.54, l_screenY *.5, 120, 120);

		//The fonts will be written in black because of the white background
		m_2dRenderer->setRenderColour(0, 0, 0, 1);
		m_2dRenderer->drawText(m_font, "- start the new round", l_screenX * .15, l_screenY * .8);
		m_2dRenderer->drawText(m_font, "- press the buttons or ->", l_screenX * .15, l_screenY * .5);

		m_2dRenderer->drawText(m_font, "Press 'BackSpace' to go back", 0, l_screenY * .95);
	}
}

void SimonApp::DrawTimer()
{
	if (playerTimer > 0)
	{
		//Draws the timer which the colour and size is based on how much time is left...
		int fulltime = 32 * toBePlayed.size();
		if (playerTimer >= fulltime - 2)
			m_2dRenderer->setRenderColour(0, 1, 0);
		else
			m_2dRenderer->setRenderColour(1, 0, 0);
		//... represented by a rectangle
		m_2dRenderer->drawBox(640, 700, 1280 / (fulltime / playerTimer), 10);
		//Resets the Colors to the original white
		m_2dRenderer->setRenderColour(1, 1, 1);
	}
}