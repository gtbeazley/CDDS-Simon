#include "Button.h"
#include <Renderer2D.h>
#include <string>
#include <Input.h>
Button::Button(int id) : m_id(id)
{
	m_size = glm::vec2(200, 200);
}

Button::~Button()
{

}

void Button::Draw(aie::Renderer2D* r, aie::Font* f)
{
	SetPos();
	if (m_id == 1)
	{
		if(!Hovering())
			r->setRenderColour(1, 0, 0);
	}
	else if (m_id == 2)
	{
		if(!Hovering())
			r->setRenderColour(0, 1, 0);
	}
	else if (m_id == 3)
	{
		if(!Hovering())
			r->setRenderColour(0, 0, 1);
	}
	else if (m_id == 4)
	{
		if(!Hovering())
			r->setRenderColour(1, .9, .5);
	}

	r->drawBox(m_pos.x, m_pos.y, m_size.x, m_size.y);


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
	