#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <vector>

#include "levelmodel.hpp"

namespace satap {
	
	class GameModel{
		
		public:
			GameModel();
			std::vector<LevelModel*> getLevelList();
			LevelModel* getLevel(int i);
			LevelModel* getCurrentLevel();
			void loadLevel(int i);
			//TODO loadLevel(string name)

		private:
			std::vector<LevelModel*> _levelList;
			LevelModel* _currentLevel;
			
	};
}

#endif
