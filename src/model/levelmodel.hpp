#ifndef LEVELMODEL_HPP
#define LEVELMODEL_HPP

#include <vector>
#include <string>

#include "outputlistmodel.hpp"
#include "workspacemodel.hpp"

namespace satap {
	
	class LevelModel{
		
		public:
			LevelModel();
			LevelModel(std::string name);
			std::string getName();
			OutputListModel getOutputListExpected();
			
			bool isCompleted(WorkspaceModel workspace);
			bool isCompleted(OutputListModel outputList);
		
		protected:
			OutputListModel _outputListExpected;

		private:
			std::string _name;
			
	};
}

#endif
