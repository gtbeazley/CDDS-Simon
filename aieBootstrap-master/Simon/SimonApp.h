#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"

class SimonApp : public aie::Application {
public:

	SimonApp();
	virtual ~SimonApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void SetGameTimer();
	void SetPlayerTimer();
	void CheckGameTimer(float dt);
	void CheckPlayerTimer(float dt);

	void CheckBtnPressed(aie::Input* input);

	void Fail();

	bool CheckPlayerMatched();
protected:
	 
	float gameTimer = 0; 
	float playerTimer = 0;  
	float btnIntervalTimer = 0;
	float keyPressed = 0;
	bool btnPressable = true;
	bool gameOn = false;
	bool nextLevel = false;
	int score = 0;


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