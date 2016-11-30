//
//  outputmodel.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef OUTPUTMODEL_HPP
#define OUTPUTMODEL_HPP

#include <vector>
#include <string>

namespace satap {
	/**
	 * \class OutputModel
	 *
	 * \brief Classe contenant une liste de valeur.
	 */
	class OutputModel{
		private:
			std::vector<std::string> _output;
	
	public:
		OutputModel();
		OutputModel(std::vector<std::string> out);
	
		void		clear();
		void		push(std::string val);
		std::string getValByIndex(unsigned int i);
		size_t		size();
	};
}

#endif /* OUTPUTMODEL_HPP */
