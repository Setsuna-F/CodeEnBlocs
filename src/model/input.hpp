//
//  input.hpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef input_hpp
#define input_hpp


#include <stdlib.h>
#include <stack>
#include <string>

/**
 * \class Input
 * 
 * \brief Classe contenant une liste de valeur.
 */
class Input{
private:
	std::stack<std::string> input;
	
public:
	Input();
	Input(std::stack<std::string> in);
	
	void		push(std::string val);
	std::string pop();

	bool	isEmpty();
	size_t	size();
};


#endif /* input_hpp */
