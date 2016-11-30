#ifndef IFMODEL_HPP
#define IFMODEL_HPP
#include "blocksimplemodel.hpp"

/*
 *
 * Description : 
 *
 *
*/

namespace satap {

	class IfModel : public BlockSimpleModel {
	
		public:
			IfModel();
			~IfModel();
			std::string execute();
	};
}

#endif	// IFMODEL_HPP
