#ifndef TEMPLATETEMPLATE_HPP
#define TEMPLATETEMPLATE_HPP

#include<iostream>
#include "templatemodel.hpp"

namespace satap{

	class TemplateTemplateModel : public TemplateModel {

		public:
			TemplateTemplateModel();
			TemplateTemplateModel(int foo);
			int getFoo();
			int doThings(int foo, int fooBar);
		
		protected:
		
		
		private:
			int _foo;
			int _bar;
			int _fooBar;

	};
	
}

#endif
