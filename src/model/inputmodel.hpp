#ifndef INPUTMODEL_HPP
#define INPUTMODEL_HPP

#include <string>
#include "blockcompositemodel.hpp"
#include "inputlistmodel.hpp"

namespace satap{

	class InputModel : public BlockCompositeModel{
	
		public:
			InputModel();
			InputModel(InputListModel inputList);
			
			void setInputList(InputListModel inputList);
			
			std::string execute();
			
		private:
			InputListModel _inputList;
	
	};

}

#endif
