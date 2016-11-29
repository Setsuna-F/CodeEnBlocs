#ifndef TEMPLATETEMPLATE_HPP
#define TEMPLATETEMPLATE_HPP

/*!
 * \file TemplateTemplateModel.hpp
 * \brief Lecteur de musique de base
 * \author appleFanBoy
 * \version 0.1
 */


#include <iostream>
#include "templatemodel.hpp"

/**
 * \namespace satap
 */
namespace satap{


	/**
	 *
	 * \class TemplateTemplateModel
	 * \brief Explication de la classe en anglais.
	 *
	 * La suite de l'explication .................
	 * ...................................... .
	 *
	 */
	class TemplateTemplateModel : public TemplateModel {

		public:
		    /*!
		     *
		     *  \brief Constructeur
		     *
		     *  Constructeur de la classe TemplateTemplateModel
		     *
		     */
			TemplateTemplateModel();

			/*!
		     *
		     *  \brief Constructeur
		     *
		     *  Constructeur de la classe TemplateTemplateModel
		     *
	         *  \param foo : un nombre foo
	         *
		     */
			TemplateTemplateModel(int foo);

			/*!
		     *  \brief retour de valeur
		     *
		     *  Methode qui permet de recuperer un morceau a liste de
		     *  lecture
		     *
		     *  \return un autre nombre si morceau deja present dans la liste,
		     *  -1 sinon
		     */
			int getFoo();

			/*!
		     *  \brief Ajout d'un morceau
		     *
		     *  Methode qui permet d'ajouter un morceau a liste de
		     *  lecture
		     *
		     *  \param foo : le morceau a ajouter
		     *  \param fooBar : un nombre de foobar
		     *  \return un autre nombre si morceau deja present dans la liste,
		     *  -1 sinon
		     */
			int doThings(int foo, int fooBar);
		
		protected:
		
		
		private:
			int _foo; 		/*!< Liste des morceaux*/
			int _bar; 		/*!< Liste des morceaux*/
			int _fooBar; 	/*!< Liste des morceaux*/

	};
	
}

#endif
