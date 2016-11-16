#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <vector>

/**
 * \namespace satap
 */
namespace satap{

	/**
	 *
	 * \class TemplateModel
	 * \brief Explication de la classe en anglais.
	 *
	 * La suite de l'explication .................
	 * ...................................... .
	 *
	 */
	class TemplateModel {

		public:

		    /*!
		     *
		     *  \brief Constructeur
		     *
		     *  Constructeur de la classe TemplateModel
		     *
		     */
			TemplateModel();
		
		protected:
		
		private:
			std::vector<std::vector<int> > _iLoveVectors; /*!< Liste des morceaux*/

	};

}

#endif
