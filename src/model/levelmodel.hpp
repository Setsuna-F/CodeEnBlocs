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
			WorkspaceModel getWorkspace();
			
			virtual void init() = 0; //generates random input and computes expected output
			bool isCompleted(WorkspaceModel workspace);
			bool isCompleted(OutputListModel outputList);
		
		protected:
			std::string _name;
			OutputListModel _outputListExpected;
			WorkspaceModel _workspace;
			
	};
}

#endif
