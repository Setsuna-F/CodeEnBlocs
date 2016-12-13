//
//  UniqueObject.hpp
//  CodeEnBlocs
//
//  Created by sofien benharchache on 11/12/2016.
//  Copyright © 2016 sofien benharchache. All rights reserved.
//

#ifndef UniqueObject_hpp
#define UniqueObject_hpp

#include <stdio.h>

namespace satap{
	class UniqueObject{
	private:
		// Constructeur/destructeur
		UniqueObject (): _value (0) {  }
		~UniqueObject () { }
		
	public:
		// Interface publique
		void setValue (int val) { _value = val; }
		int getValue () { return _value; }
		
		// Fonctions de création et destruction du singleton
		static UniqueObject *getInstance (){
			if (!_singleton)
				_singleton =  new UniqueObject;
			
			return _singleton;
		}
		
		static void kill (){
			if (_singleton){
				delete _singleton;
				_singleton = NULL;
			}
		}
		
	private:
		// Variables membres
		int _value=0;
		static UniqueObject *_singleton;
	};
}


#endif /* UniqueObject_hpp */
