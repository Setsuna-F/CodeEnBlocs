//
//  output.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef output_hpp
#define output_hpp

#include <stdio.h>
#include <vector>

/**
 * \class Output
 *
 * \brief Classe contenant une liste de valeur.
 */
class Output{
private:
	std::vector<std::string> output;
	
public:
	Output();
	Output(std::vector<std::string> out);
	
	void		clear();
	void		push(std::string val);
	std::string getValByIndex(unsigned int i);
	size_t		size();
};

#endif /* output_hpp */
