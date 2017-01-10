#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <gui/State.hpp>
#include <gui/Container.hpp>
#include <model/levelmodel.hpp>
#include <model/additionlevelmodel.hpp>
#include "gui/Curseur.hpp"
#include "blocs/Bloc.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace satap;

class GameState : public State
{
	public:
		GameState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);
		
		satap::Bloc* addBloc(satap::typeBloc t);

		void resetCode();
		void toggleLoop();
		void startExecute();

		std::pair<int, int> getCoordonnees(int ligne, int colonne);
		std::pair<int, int> getCoordonneesCurseur(int ligne);
		void effacerLigne(int ligne);
		int getNbElementsOnLine(int ligne);
		int getNbBlocs();
		void reloadPositionCurseur();



	private:
		Context							mContext;
		sf::RectangleShape				mInstructionsAlphaBackgroung;
		sf::Sprite						mBackgroundSprite, mInstructionSprite;
		sf::Text						mLevelTitle, mLevelDescription, mLevelTip, mInputString, mOutputString, mVariablesString;
		GUI::Container					mButtonsContainer;
		GUI::Container					mBlocsContainer[12]; // Un tableau ? mBlocsContainer[0] = 1ere ligne, mBlocsContainer[1] = 2e ligne, etc...
		GUI::Curseur					mCurseur;
		satap::LevelModel*				mCurrentLevel;
		int								mLi, mCol; // Coordonn�es du curseur (l� ou va �tre plac� le prochain bloc)

		sf::RectangleShape				mRectAlphaBackground;
		sf::Sprite						mSpriteConfirmationExit;
		sf::Text						mTextConfirmationExit;
		bool							mShowConfirmationExit;
		bool							mExiting;
		bool							showInstructions;
		GUI::Container					mButtonsContainerConfirmationExit;
		sf::Time						mDelayExit;
};

#endif // BOOK_MENUSTATE_HPP
