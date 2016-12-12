//
//  inputlistmodel.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef inputlistmodel_hpp
#define inputlistmodel_hpp

#include <stdlib.h>
#include <stack>
#include <string>
#include "tools.h"

namespace satap{

	/**
	 * \class InputListModel
	 * 
	 * \brief Classe contenant une liste de valeur.
	 */
	class InputListModel{
	private:
		std::stack<sct_type> _input;
	
	public:
		InputListModel();
		InputListModel(std::stack<sct_type> in);
	
		void		push(sct_type val);
		sct_type	pop();

		bool	isEmpty();
		size_t	size();
	};

}

#endif /* inputlistmodel_hpp */
