#ifndef ADDITIONLEVELMODEL_HPP
#define ADDITIONLEVELMODEL_HPP

#include "levelmodel.hpp"

namespace satap {
	
	class AdditionLevelModel : public LevelModel{
		
		public:
			AdditionLevelModel();
			//LevelModel(std::string name);
			//std::string getName();
			//OutputListModel getOutputListExpected();
			
			void init();
			//bool isCompleted(WorkspaceModel workspace);
			//bool isCompleted(OutputListModel outputList);
		
		/*protected:
			OutputListModel _outputListExpected;

		private:
			std::string _name;*/
			
	};
}

#endif
