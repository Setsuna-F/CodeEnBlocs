#ifndef TEMPLATETEMPLATE_HPP
#define TEMPLATETEMPLATE_HPP

#include<iostream>
#include "template.hpp"

class TemplateTemplate : public Template{

	public:
		TemplateTemplate();
		TemplateTemplate(int foo);
		int getFoo();
		int doThings(int foo, int fooBar);
		
	protected:
		
		
	private:
		int _foo;
		int _bar;
		int _fooBar;

};

#endif
