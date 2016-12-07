#ifndef INPUTMODEL_HPP
#define INPUTMODEL_HPP

#include <string>
#include "blockcompositemodel.hpp"
#include "inputlistmodel.hpp"
#include "tools.h"

namespace satap{

	class InputModel : public BlockCompositeModel{
	
		public:
			InputModel();
			InputModel(InputListModel inputList);
			
			void setInputList(InputListModel inputList);
			
			std::string getCategory();
			sct_type execute();
			
		private:
			InputListModel _inputList; //TODO not inputlist but Game : then, game.getInputList().pop();
	
	};

}

#endif
