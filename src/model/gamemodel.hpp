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
			void loadLevel(int i);

		private:
			std::vector<LevelModel*> _levelList;
			LevelModel* _currentLevel;
			
	};
}

#endif
