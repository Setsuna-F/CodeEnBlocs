#include "gui/Application.hpp"
#include "model/gamemodel.hpp"

#include <stdexcept>
#include <iostream>

using namespace satap;

int console();
int gui();


int main(int argc, char**argv){
	return gui();
}

int console(){
	std::cout << "CodeEnBlocs" << std::endl;

	GameModel game;
	game.loadLevel(1);

	LevelModel* currentLevel = game.getCurrentLevel();
	std::cout << currentLevel->getName() << std::endl;
	std::cout << currentLevel->getOptimalBlocCount() << std::endl;
	std::cout << currentLevel->getDescription() << std::endl;
	std::cout << currentLevel->getHelp() << std::endl;

	//What we need to do here :
	//a = input //variable affectation input
	//b = input
	//c = a + b
	//output c

	CodePageModel* codePage = currentLevel->getCodePage();
	//codePage->addBlock( ... );
	std::cout <<"validate: "<< currentLevel->validate() << std::endl;

	return 0;
}

int gui(){
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
	return 0;
}
