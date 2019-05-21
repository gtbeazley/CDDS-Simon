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
	void SetColour(aie::Renderer2D* r);
	void SetBtnDisplay(aie::Renderer2D* r);
	void SetScreen(float x, float y);
	void SetPos();
	void SetIsPlaying(bool playingStatus);
	void SetBtnPressable(bool bPressed);

	glm::vec2 GetPos(); 

	bool BtnPressed(aie::EInputCodes e);
	bool WasClicked();
	bool Hovering();
	bool IsPlaying();
protected:
private:
	
	aie::Font* m_font;
	aie::Input* m_input = aie::Input::getInstance();

	bool m_isPlaying;
	bool btnPressable;
	int m_id, screenX, screenY;
	
	vec2 m_pos, m_size;
};