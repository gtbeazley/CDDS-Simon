#include "Button.h"
#include <Renderer2D.h>
#include <string>
#include <Input.h>
Button::Button(int id) : m_id(id), m_isPlaying(false)
{
	m_size = glm::vec2(150, 150);
}

Button::~Button()
{

}

void Button::Draw(aie::Renderer2D* r, aie::Font* f)
{
	SetPos();
	
	SetColour(r);

	r->drawBox(m_pos.x, m_pos.y, m_size.x, m_size.y);


	r->setRenderColour(1, 1, 1, 1);
	if (IsPlaying())
	{
		r->drawBox(m_pos.x, m_pos.y, m_size.x, m_size.y);
		SetColour(r);
	}
	else
		r->setRenderColour(1, 1, 1, 1);
	r->drawBox(m_pos.x, m_pos.y, 40, 40, .775);
		
	SetBtnDisplay(r);


	r->setRenderColour(1, 1, 1);
}

void Button::Update(float dt)
{

}

void Button::SetFont(aie::Font* f)
{
	m_font = f;
} 

void Button::SetScreen(float x, float y)
{
	screenX = x;
	screenY = y;
}

void Button::SetIsPlaying(bool playingStatus)
{
	m_isPlaying = playingStatus;
}

glm::vec2 Button::GetPos()
{
	return m_pos;
}

bool Button::WasClicked()
{
	return (m_input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT)
		&& Hovering());
}

bool Button::Hovering()
{
	return (
		m_input->getMouseX() > (m_pos.x - (m_size.x / 2)) &&
		m_input->getMouseX() < (m_pos.x + (m_size.x / 2)) &&
		m_input->getMouseY() > (m_pos.y - (m_size.y / 2)) &&
		m_input->getMouseY() < (m_pos.y + (m_size.y / 2))
		);
}

void Button::SetPos()
{
	if (m_id == 1)
	{
		m_pos.x = screenX / 2;
		m_pos.y = screenY / 4 * 3;
	}
	else if (m_id == 2)
	{
		m_pos.x = screenX / 4;
		m_pos.y = screenY / 2;
	} 
	else if (m_id == 3)
	{
		m_pos.x = screenX / 4 * 3;
		m_pos.y = screenY / 2;
	}
	else if (m_id == 4)
	{
		m_pos.x = screenX / 2;
		m_pos.y = screenY / 4;
	}
}
	
bool Button::IsPlaying()
{
	return m_isPlaying;
}

void Button::SetColour(aie::Renderer2D* r)
{
//red up
	if (m_id == 1)
	{
	
		if(!Hovering())
			r->setRenderColour(1, 0, 0);
	}
	//green left
	else if (m_id == 2)
	{ 
		if(!Hovering())
			r->setRenderColour(0, 1, 0);
	} 
	//blue right
	else if (m_id == 3)
	{ 
		if(!Hovering())
			r->setRenderColour(0, 0, 1);
	}
	//yellow down
	else if (m_id == 4)
	{ 
		if(!Hovering())
			r->setRenderColour(1, .9, .5);
	}
}

void Button::SetBtnDisplay(aie::Renderer2D* r)
{
	float offSet = 25;
	SetColour(r);
	//red up
	if (m_id == 1)
	{
		if (BtnPressed(aie::INPUT_KEY_UP)
			&& )
		{
			r->setRenderColour(1, 1, 1, 1);
		}
		r->drawBox(m_pos.x, m_pos.y - offSet, 50, 50);
	}
	//green left
	else if (m_id == 2)
	{ 
		if (BtnPressed(aie::INPUT_KEY_LEFT))
		{
			r->setRenderColour(1, 1, 1, 1);
		}
		r->drawBox(m_pos.x + offSet, m_pos.y, 50, 50);
	}
	//blue right
	else if (m_id == 3)
	{
		if (BtnPressed(aie::INPUT_KEY_RIGHT))
		{
			r->setRenderColour(1, 1, 1, 1);
		}
		r->drawBox(m_pos.x - offSet, m_pos.y, 50, 50);
	}
	//yellow down
	else if (m_id == 4)
	{
		if (BtnPressed(aie::INPUT_KEY_DOWN))
		{
			r->setRenderColour(1, 1, 1, 1);
		}
		r->drawBox(m_pos.x, m_pos.y + offSet, 50, 50);
	}
}


bool Button::BtnPressed(aie::EInputCodes e)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(e))
		return true;
	else 
		return false;
		
}


void Button::SetBtnPressable(bool bPressable)
{
	btnPressable = bPressable;
}