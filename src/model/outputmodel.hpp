#ifndef OUTPUTMODEL_HPP
#define OUTPUTMODEL_HPP
#include "blocksimplemodel.hpp"

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
			std::string execute();
			std::string getCategory();
	};
}

#endif	// OUTPUTMODEL_HPP
