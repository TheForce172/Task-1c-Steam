#include "Application.h"
#include "MainMenu.h"

// TODO: Remove from global scope once menu system is integrated

void main()
{
	// TODO: Remove call to dummy data, instead use Load and Save
	//createHardcodedTestData();

	Application app;
	app.Load();
	MainMenu("MAIN MENU", &app);
	app.Save();
}