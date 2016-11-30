//
//  inputmodel.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef inputmodel_hpp
#define inputmodel_hpp

#include <stdlib.h>
#include <stack>
#include <string>

namespace satap{

	/**
	 * \class InputModel
	 * 
	 * \brief Classe contenant une liste de valeur.
	 */
	class InputModel{
	private:
		std::stack<std::string> _input;
	
	public:
		InputModel();
		InputModel(std::stack<std::string> in);
	
		void		push(std::string val);
		std::string pop();

		bool	isEmpty();
		size_t	size();
	};

}

#endif /* inputmodel_hpp */
