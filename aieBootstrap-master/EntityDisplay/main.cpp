#include "EntityDisplayApp.h"

int main() {
	
	// allocation
	auto app = new EntityDisplayApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}