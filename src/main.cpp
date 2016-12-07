#include <iostream>
#include "./model/gamemodel.hpp"

using namespace satap;

int main(int argc, char**argv){

	std::cout << "CodeEnBlocs" << std::endl;
	
	GameModel game;
	game.loadLevel(1);
	
	return 0;
}

