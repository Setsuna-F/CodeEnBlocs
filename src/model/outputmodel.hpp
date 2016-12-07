#ifndef OUTPUTMODEL_HPP
#define OUTPUTMODEL_HPP
#include "blocksimplemodel.hpp"
#include "tools.h"

/*
 *
 * Description : 
 *
 *
*/

namespace satap {


	class OutputModel : public BlockSimpleModel {
	
		public:
			OutputModel();
			~OutputModel();
			sct_type execute();
			std::string getCategory();
	};
}

#endif	// OUTPUTMODEL_HPP
