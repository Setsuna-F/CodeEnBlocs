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
#include <SFML/Graphics/Text.hpp>

namespace satap{

	/**
	 * \class InputListModel
	 * 
	 * \brief Classe contenant une liste de valeur.
	 */
	class InputListModel{
	private:
		std::vector<sct_type> _input;
		std::vector<sct_type> _saveinput;
	
	public:
		InputListModel();
		InputListModel(std::vector<sct_type> in);
	
		void		push(sct_type val);
		sct_type	pop();

		std::string	toString();

		bool	isEmpty();
		size_t	size();
		void clear();
		void reload();
	};

}

#endif /* inputlistmodel_hpp */
