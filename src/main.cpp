#include <iostream>
#include "./model/gamemodel.hpp"

using namespace satap;

int main(int argc, char**argv){

	std::cout << "CodeEnBlocs" << std::endl;
	
	GameModel game;
	game.loadLevel(0);
	std::cout << game.getCurrentLevel()->getName() << std::endl;
	
	return 0;
}

