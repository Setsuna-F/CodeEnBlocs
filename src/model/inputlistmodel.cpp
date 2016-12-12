//
//  inputlistmodel.cpp
//  SeriousGame
//
//  Created by sofien benharchache on 30/10/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#include "inputlistmodel.hpp"
#include <iostream>
#include <string>

using namespace satap;

InputListModel::InputListModel(){}
InputListModel::InputListModel(std::stack<sct_type> in):_input(in) {}

void InputListModel::push(sct_type val){_input.push(val);}

sct_type InputListModel::pop(){
	sct_type res;		 /* On initialise le resultat a nullptr */
	res.int_type	=nullptr;
	res.double_type	=nullptr;
	res.bool_type	=nullptr;
	
	if(_input.size()==0) /* Si on a pas d'element dans notre input alors */
		return res;		 /* On retourne une valeur nulle */
	res = _input.top();	 /* Sinon on retourne le premiere element de la pile */
	_input.pop();		 /* Puis on retir cette element de la pile */
	return res;			 /* Pour finir on retourne le premiere element de la pile qui a ete retiré. */
}

bool	InputListModel::isEmpty	()	{return _input.empty();}
size_t	InputListModel::size	()	{return _input.size();}

