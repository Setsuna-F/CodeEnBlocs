#include "templatetemplatemodel.hpp"
#include "templatemodel.hpp"


/*

	La tabulation sera une tabulation de 4 espaces (Mais ca reste une tabulation) !

*/


using namespace satap;

TemplateTemplateModel::TemplateTemplateModel() :
	TemplateModel() {
	//do nothing because life is empty and you are part of it
}

TemplateTemplateModel::TemplateTemplateModel(int foo) {
	_foo 	= foo; 
	_bar 	= 23;
	_fooBar = 42;
}

int TemplateTemplateModel::getFoo() {
	if (true) /* Si ma condition est vrai alors */
		std::cout<<"je suis dans le getfoo"<<std::endl; /* On affiche une message qui ne sert a rien */
	else
		std::cout<<"vive Apple !!!"<<std::endl; /* Sinon on affiche un super message pour les ignorants ! */
	return 0; 
}

int TemplateTemplateModel::doThings(int foo, int fooBar) {
	return foo;
}
