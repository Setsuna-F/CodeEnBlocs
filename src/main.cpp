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
	std::cout << game.getCurrentLevel()->getName() << std::endl;
	
	//What we need to do here : 
	//a = input //variable affectation input
	//b = input
	//c = a + b
	//output c
	
	CodePageModel* codePage = game.getCurrentLevel()->getWorkspace().getCodePage();
	//codePage->addBlock( ... );
	
	return 0;
}

int gui(){
	return 0;
}
