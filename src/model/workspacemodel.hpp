#ifndef WORKSPACEMODEL_HPP
#define WORKSPACEMODEL_HPP

#include "inputlistmodel.hpp"
#include "outputlistmodel.hpp"
#include "variablelistmodel.hpp"
#include "codepagemodel.hpp"

namespace satap {
	
	class WorkspaceModel{
		
		public:
			WorkspaceModel();
			WorkspaceModel(InputListModel inputList, OutputListModel outputList, VariableListModel variableList, CodePageModel codePage);
			InputListModel getInputList();
			OutputListModel getOutputList();
			VariableListModel getVariableList();
			CodePageModel getCodePage();
			
			void setInputList(InputListModel inputList);
			void setOutputList(OutputListModel outputList);
			void setVariableList(VariableListModel variableList);
			void setCodePage(CodePageModel codePage);

		private:
			InputListModel _inputList;
			OutputListModel _outputList;
			VariableListModel _variableList;
			CodePageModel _codePage;
	};
}

#endif
