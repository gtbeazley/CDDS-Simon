#pragma once
#include <Renderer2D.h>
#include <glm/vec2.hpp>
#include <Input.h>

using namespace glm;

class Button
{
public:
	Button(int id);
	~Button();

	void Draw(aie::Renderer2D* r, aie::Font* f);
	void Update(float deltaTime);

	void SetFont(aie::Font* f);
	void SetScreen(float x, float y);
	void SetPos();

	glm::vec2 GetPos(); 

	bool WasClicked();
	bool Hovering();
protected:
private:
	vec2 m_pos, m_size;
	aie::Font* m_font;
	int m_id, screenX, screenY;
	
	aie::Input* m_input = aie::Input::getInstance();

};