#include <iostream>
#include "./model/gamemodel.hpp"

using namespace satap;

int console();
int gui();


int main(int argc, char**argv){
	return console();
}

int console(){
	std::cout << "CodeEnBlocs" << std::endl;
	
	GameModel game;
	game.loadLevel(0);
	
	LevelModel* currentLevel = game.getCurrentLevel();
	std::cout << currentLevel->getName() << std::endl;
	std::cout << currentLevel->getDescription() << std::endl;
	
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
	return 0;
}
