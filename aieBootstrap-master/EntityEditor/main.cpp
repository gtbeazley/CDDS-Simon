#include "EntityEditorApp.h"

int main() {
	
	// allocation
	auto app = new EntityEditorApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}