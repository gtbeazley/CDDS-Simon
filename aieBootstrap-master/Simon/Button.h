#pragma once
#include <Renderer2D.h>
#include <glm/vec2.hpp>
#include <Input.h>

using namespace glm;

class Button
{
public:
	//Constructor gives an id to detemine buttons
	Button(int id);
	//Destructor
	~Button();

	//Draw funtion called every frame
	//r is the bootstraps 2d renderer used to draw the game 
	void Draw(aie::Renderer2D* r);
	//Update is the logic function ran every frame 
	//deltatime is the time between each frame
	void Update(float deltaTime); 
	// sets the colour of the current button
	void SetColour(aie::Renderer2D* r);
	//Sets the display of the button showing what directional button it corressponds to
	void SetBtnDisplay(aie::Renderer2D* r);
	// sets the screen size for scaling
	void SetScreen(float x, float y);
	//sets the position of tthe button acording to the screen
	void SetPos();
	//Sets the playing status to playingStatus
	void SetIsPlaying(bool playingStatus);
	//Sets the pressable state of the button
	void SetBtnPressable(bool bPressed);

	//Returns the position in glm::vec2
	glm::vec2 GetPos(); 

	// returns true if e was pressed
	bool BtnPressed(aie::EInputCodes e);
	//Returns true if hovering was true and the lmb was clicked
	bool WasClicked();
	//RReturns true if the moiuse is  hovering over the button
	bool Hovering();
	// returns m_isplaying
	bool IsPlaying();
protected:
private:
	
	aie::Input* m_input = aie::Input::getInstance();

	bool m_isPlaying;
	bool btnPressable;
	int m_id, screenX, screenY;
	
	vec2 m_pos, m_size;
};