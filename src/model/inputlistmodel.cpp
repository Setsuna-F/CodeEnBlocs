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
InputListModel::InputListModel(std::vector<sct_type> in):_input(in), _saveinput()
{
	for (int i = 0; i < _input.size(); i++)
		_saveinput.push_back(sct_type(_input.at(i)));
}

void InputListModel::push(sct_type val)
{
	_input.push_back(val);
	_saveinput.push_back(sct_type(val));
}

sct_type InputListModel::pop(){
	sct_type res;			 /* On initialise le resultat a nullptr */
	res.int_type	=nullptr;
	res.double_type	=nullptr;
	res.bool_type	=nullptr;
	
	if(_input.size()==0)	 /* Si on a pas d'element dans notre input alors */
		return res;			 /* On retourne une valeur nulle */
	res = _input.back();	 /* Sinon on retourne le premiere element de la pile */
	_input.pop_back();		 /* Puis on retir cette element de la pile */
	return res;				 /* Pour finir on retourne le premiere element de la pile qui a ete retiré. */
}

std::string satap::InputListModel::toString() {
	std::string s = "";
	for (auto &i : _input) {
		if (i.int_type) {
			int t = *i.int_type;
			s += "" + std::to_string(t) + "\n";
		}
		else if (i.double_type) {
			//s += "" + std::to_string(*i.double_type) + "\n";
			s += "" + typeToString(*i.double_type) + "\n";
		}
		else if (i.bool_type) {
			s += "" + std::to_string(*i.bool_type) + "\n";
		}
		else {
			s += "?\n";
		}
	}
	return s;
}

bool	InputListModel::isEmpty	()	{return _input.empty();}
size_t	InputListModel::size	()	{return _input.size();}

void satap::InputListModel::clear()
{
	_input.clear();
	_saveinput.clear();
}

void satap::InputListModel::reload()
{
	_input.clear();
	for (int i = 0; i < _saveinput.size(); i++)
		_input.push_back(sct_type(_saveinput.at(i)));
}

