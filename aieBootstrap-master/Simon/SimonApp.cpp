#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Button.h"
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

SimonApp::SimonApp() {

}

SimonApp::~SimonApp() {

}

bool SimonApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	 
	m_btn1 = new Button(1);
	m_btn2 = new Button(2);
	m_btn3 = new Button(3);
	m_btn4 = new Button(4);

	buttons.push_back(m_btn1);
	buttons.push_back(m_btn2);
	buttons.push_back(m_btn3);
	buttons.push_back(m_btn4);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

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


	if (gameOn)
	{	
		if (nextLevel)
		{
			
			//Generate random number from 0-3
			srand(time(NULL));
			int RGN = rand() % 4;

			//Push the buttons that are going to be checked for the game
			toBePlayed.push_back(buttons[RGN]);
			toBePressed.push_back(1 + RGN);

			//Set timers for sequence to be played
			SetGameTimer();
			SetPlayerTimer();
			keysPressed.clear();
			nextLevel = false;

		}

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
			btnIntervalTimer--;
			btnPressable = false; 
		}
		else
		{
			btnIntervalTimer = 0;
			btnPressable = true;
		}
	}	
	else if ( input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
 		gameOn = true;
		nextLevel = true;
	}

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
	 
	if (playerTimer > 0)
	{
		int fulltime = 32 * toBePlayed.size();
		if (playerTimer >= fulltime - 2)
			m_2dRenderer->setRenderColour(0, 1, 0);
		else
			m_2dRenderer->setRenderColour(1, 0, 0);
	
		m_2dRenderer->drawBox(640, 700, 1280 / (fulltime / playerTimer), 10);
		m_2dRenderer->setRenderColour(1, 1, 1);
	}

	//draw the buttons according to the screen
	for (int i = 0; i < 4; i++)
	{
		buttons[i]->SetScreen(getWindowWidth(), getWindowHeight());
		buttons[i]->Draw(m_2dRenderer, m_font);
	} 
	


	if (!gameOn)
	{
		m_2dRenderer->drawText(m_font, "Press SPACE to start", 100, 600);
		//m_2dRenderer->drawText(m_font, score, 100, 550);
	}
	else
	{
		if (gameTimer > 0)
		{
			m_2dRenderer->drawText(m_font, "Playing Sequence", 100, 600); 
		}
		else if (playerTimer > 0)
		{
			m_2dRenderer->drawText(m_font, "GOOOOOOO!!!!!", 100, 600);
		}

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

		
		for (int i = 0; i < toBePressed.size(); i++)
		{
			m_2dRenderer->setRenderColour(1, 0, 0);
			m_2dRenderer->drawCircle(15 + (15 * i), 660, 5);

		}
		for (int i = 0; i < keysPressed.size(); i++)
		{
			if (keysPressed[i] == toBePressed[i])	
				m_2dRenderer->setRenderColour(0, 1, 0);
			m_2dRenderer->drawCircle(15 + (15 * i), 660, 5);
		}
	}

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
		gameTimer -= (1 - dt);
	else
		gameTimer = 0;
}

void SimonApp::CheckPlayerTimer(float dt)
{
	if (playerTimer > 0)
		playerTimer -= (1 - dt);
	else
		playerTimer = 0;
}

void SimonApp::CheckBtnPressed(aie::Input* input)
{	
	if (btnPressable)
	{
		if (input->isKeyDown(aie::INPUT_KEY_UP))
		{
			keyPressed = 1;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		{
			keyPressed = 2;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		{
			keyPressed = 3;
		}
		else if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		{
			keyPressed = 4;
		}
		else
			btnPressable = true;
	}

	if (keyPressed != 0)
	{
		keysPressed.push_back(keyPressed);
		btnIntervalTimer = 10;
		btnPressable = false;
	}

	keyPressed = 0;
}

void SimonApp::Fail()
{
	gameOn = false;
	btnIntervalTimer = 0;
	btnPressable = true;
	keyPressed = 0; 
	toBePressed.clear(); 
	toBePlayed.clear();
	keysPressed.clear();

}

bool SimonApp::CheckPlayerMatched()
{
	if (keysPressed.size() == 1)
		int t = 1;
	if (keysPressed.size() == 2)
		int t = 1;
	int i = 0;
	for (i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] != toBePressed[i])
			return false;

	}
	score = i + 1;
	return true;
}

