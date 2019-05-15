#include "SimonApp.h"

#include <iostream>

int main() {
	
	// allocation
	auto app = new SimonApp();

	// initialise and loop
	app->run("SIMON", 1280, 720, false);

	// deallocation
	delete app;


	

	system("pause");
	return 0;
}