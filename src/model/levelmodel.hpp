#ifndef LEVELMODEL_HPP
#define LEVELMODEL_HPP

#include <vector>
#include <string>

#include "outputlistmodel.hpp"
#include "workspacemodel.hpp"
#include "codepagemodel.hpp"
#include "blockmodel.hpp"

namespace satap {
	
	class LevelModel{
		
		public:
			LevelModel();
			LevelModel(std::string name);
			LevelModel(std::string name, std::string description);
			LevelModel(std::string name, std::string description, std::vector<BlockModel*> availableBlocks);
			std::string getName();
			std::string getDescription();
			std::vector<BlockModel*> getAvailableBlocks();
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
			std::vector<BlockModel*> _availableBlocks; //TODO by default, all the block
			OutputListModel _outputListExpected;
			WorkspaceModel* _workspace;
			CodePageModel* _codePage;
			
	};
}

#endif
