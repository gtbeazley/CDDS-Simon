#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Button.h"

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

	// input example
	aie::Input* input = aie::Input::getInstance();


	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
		SetTimer(1000);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SimonApp::draw() {


	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here! 
	m_btn1->SetScreen(getWindowWidth(), getWindowHeight());
	m_btn1->Draw(m_2dRenderer, m_font);
	

	m_btn2->SetScreen(getWindowWidth(), getWindowHeight());
	m_btn2->Draw(m_2dRenderer, m_font);
	

	m_btn3->SetScreen(getWindowWidth(), getWindowHeight());
	m_btn3->Draw(m_2dRenderer, m_font);


	m_btn4->SetScreen(getWindowWidth(), getWindowHeight());
	m_btn4->Draw(m_2dRenderer, m_font);


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	if (timer > 0)
		timer--;
	if (timer != 0)
		m_2dRenderer->drawText(m_font, "GetReady!!", 200, 200);

	// done drawing sprites
	m_2dRenderer->end();
}

void SimonApp::SetTimer(int t)
{
	timer = t;
}
