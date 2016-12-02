//
//  outputmodel.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef OUTPUTLISTMODEL_HPP
#define OUTPUTLISTMODEL_HPP

#include <vector>
#include <string>

namespace satap {
	/**
	 * \class OutputModel
	 *
	 * \brief Classe contenant une liste de valeur.
	 */
	class OutputListModel{
		private:
			std::vector<std::string> _output;

	public:
		OutputListModel();
		OutputListModel(std::vector<std::string> out);

		void		clear();
		void		push(std::string val);
		std::string getValByIndex(unsigned int i);
		size_t		size();
	};
}

#endif /* OUTPUTLISTMODEL_HPP */
