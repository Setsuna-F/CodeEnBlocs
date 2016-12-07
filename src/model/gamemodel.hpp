#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <vector>

#include "levelmodel.hpp"
#include "workspacemodel.hpp"

namespace satap {
	
	class GameModel{
		
		public:
			GameModel();
			std::vector<LevelModel> getLevelList();
			LevelModel getLevel(int i);
			void loadLevel(int i);
			WorkspaceModel getWorkspace();

		private:
			std::vector<LevelModel> _levelList;
			WorkspaceModel _workspace;
			LevelModel _currentLevel;
			
	};
}

#endif
