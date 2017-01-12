//
//  tools.h
//  CodeEnBlocs
//
//  Created by sofien benharchache on 06/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef tools_h
#define tools_h

#include <sstream>

/**
 * \brief servira a donner un type au retour des fonction et aux variables.
 *
 */
struct sct_type{
	int		*int_type;
	double	*double_type;
	bool	*bool_type;
};


/**
 * \brief fonction generique de convertion n'importe quels types en string
 *
 */
template<typename T>
std::string typeToString(T i) {
	std::ostringstream oss;
	oss << i;
	return oss.str();
}
#endif /* tools_h */
