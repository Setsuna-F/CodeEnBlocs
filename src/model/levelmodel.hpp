#ifndef LEVELMODEL_HPP
#define LEVELMODEL_HPP

#include <vector>
#include <string>

#include "outputlistmodel.hpp"
#include "workspacemodel.hpp"
#include "codepagemodel.hpp"

namespace satap {
	
	class LevelModel{
		
		public:
			LevelModel();
			LevelModel(std::string name);
			LevelModel(std::string name, std::string description);
			std::string getName();
			std::string getDescription();
			OutputListModel getOutputListExpected();
			WorkspaceModel* getWorkspace();
			CodePageModel* getCodePage();
			
			void setCodePage(CodePageModel* codePage);
			
			virtual void reset() = 0; //generates random input and computes expected output
			bool validate();
		
		protected:
			std::string _name;
			std::string _description;
			//TODO help
			OutputListModel _outputListExpected;
			WorkspaceModel* _workspace;
			CodePageModel* _codePage;
	};
}

#endif
