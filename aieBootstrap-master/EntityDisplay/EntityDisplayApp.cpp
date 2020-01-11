#include "EntityDisplayApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h" 

EntityDisplayApp::EntityDisplayApp() {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::startup() {

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	setBackgroundColour(1, 1, 1);


	return true;
}

void EntityDisplayApp::shutdown() {

	CloseHandle(entityFileHandle);
	CloseHandle(infoFileHandle);
	delete m_font;
	delete m_2dRenderer;
}

void EntityDisplayApp::update(float deltaTime) { 
	// input example
	aie::Input* input = aie::Input::getInstance(); 
	frame++;
	
	if (frame < 6)
	{
		infoFileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"infoFiie");
		if (infoFileHandle)
		{
			m_copiedInfo = (InfoData*)MapViewOfFile(infoFileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(InfoData));

			if (m_copiedInfo)
				m_info = *m_copiedInfo;
		}
	}
	UnmapViewOfFile(infoFileHandle);

	entityFileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");
	m_copiedEntities = (Entity*)MapViewOfFile(entityFileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity));

	for (int i = 0; i < m_info.arraySize; i++)
		if (m_entities.size() < m_info.arraySize)
			m_entities.push_back(m_copiedEntities[i]);
		else
			m_entities[i] = m_copiedEntities[i];

	UnmapViewOfFile(entityFileHandle);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void EntityDisplayApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw entities
	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}

	// output some text, uses the last used colour
	m_2dRenderer->setRenderColour(0, 0, 0);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}