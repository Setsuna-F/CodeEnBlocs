#ifndef WORKSPACEMODEL_HPP
#define WORKSPACEMODEL_HPP

#include "outputlistmodel.hpp"
#include "variablelistmodel.hpp"

namespace satap {
	class InputListModel;

	class WorkspaceModel{
		
		public:
			WorkspaceModel();
			WorkspaceModel(InputListModel* inputList, OutputListModel* outputList, VariableListModel* variableList);
			InputListModel* getInputList();
			OutputListModel* getOutputList();
			VariableListModel* getVariableList();
			
			void setInputList(InputListModel* inputList);
			void setOutputList(OutputListModel* outputList);
			void setVariableList(VariableListModel* variableList);
			void flush();
			void reload();

		private:
			InputListModel* _inputList;
			OutputListModel* _outputList;
			VariableListModel* _variableList;
	};
}

#endif
