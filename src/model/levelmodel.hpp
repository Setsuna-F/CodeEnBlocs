#ifndef LEVELMODEL_HPP
#define LEVELMODEL_HPP

#include <vector>
#include <string>
#include <exception>

#include "outputlistmodel.hpp"
#include "workspacemodel.hpp"
#include "codepagemodel.hpp"
#include "blockmodel.hpp"
#include "InstructionBlocks.hpp"
namespace satap {

	class LevelModel{

		public:
			LevelModel();
			LevelModel(std::string name, int optimalBlockCount);
			LevelModel(std::string name, int optimalBlockCount, std::string description);
			LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help);
			LevelModel(std::string name, int optimalBlockCount, std::string description, InstructionBlockModel availableBlocks);
			LevelModel(std::string name, int optimalBlockCount, std::string description, std::string help, InstructionBlockModel availableBlocks);
			std::string getName();
			std::string getDescription();
			int			getOptimalBlocCount();
			InstructionBlockModel	getAvailableBlocks();
			std::string				getHelp();
			OutputListModel getOutputListExpected();
			WorkspaceModel* getWorkspace();
			CodePageModel*	getCodePage();

			void setCodePage(CodePageModel* codePage);

			virtual void reset() = 0; //generates random input and computes expected output
			int validate();

			

		protected:
			std::string		_name;
			std::string		_description;
			std::string		_help;
			int				_optimalBlocCount;
			InstructionBlockModel _availableBlocks; //TODO by default, all the block
			OutputListModel		  _outputListExpected;
			WorkspaceModel*		  _workspace;
			CodePageModel*		  _codePage;

	};
}

#endif
