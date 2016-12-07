//
//  uppermodel.hpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 06/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef uppermodel_hpp
#define uppermodel_hpp

#include "binarymodel.hpp"
#include "tools.h"

namespace satap {
	
	class UpperModel : public BinaryModel {
		
	public:
		UpperModel();
		UpperModel(BlockCompositeModel* firstOperand, BlockCompositeModel* secondOperand);
		UpperModel(const BinaryModel & binaryModel);
		~UpperModel();
		sct_type execute();
		std::string getCategory();
	};
}

#endif /* uppermodel_hpp */
