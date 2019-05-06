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

	void SetTimer(int t);

protected:

	Button*				m_btn1;
	Button*				m_btn2;
	Button*				m_btn3;
	Button*				m_btn4;

	int timer = 0;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};