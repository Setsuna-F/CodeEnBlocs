#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP


#ifdef __APPLESOKA__
#include "State.hpp"
#include "Container.hpp"
#include "levelmodel.hpp"
#include "additionlevelmodel.hpp"
#include "Curseur.hpp"
#include "blocs/Bloc.hpp"
#else
#include <gui/State.hpp>
#include <gui/Container.hpp>
#include <model/levelmodel.hpp>
#include <gui/blocs/variableBloc.hpp>
#include <model/additionlevelmodel.hpp>
#include "gui/Curseur.hpp"
#include "blocs/Bloc.hpp"
#include "model/BlockModel.hpp"
#endif


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

		//satap::Bloc* addBloc(satap::typeBloc t);
		void addBlocks(satap::BlockModel *block, satap::typeBloc t);

		void resetCode();
		void toggleLoop();
		void startExecute();

		std::pair<int, int> getCoordonnees(int ligne, int colonne);
		std::pair<int, int> getCoordonneesCurseur(int ligne);

		void effacerLigne(int ligne);
		void newLine(int);
		int getNbElementsOnLine(int ligne);
		int getNbBlocs();
		void reloadPositionCurseur();

		bool isUnaryBlock   (typeBloc t);
		bool isValideBlock  (typeBloc t);
		bool isBinaryBlock  (typeBloc t);
		bool isBooleanBlock (typeBloc t);
		bool isFunctionBlock(typeBloc t);
		bool isBaseFunctionBlock     (typeBloc t);
		bool isUnaryFunctionBlock    (typeBloc t);
		bool isOperatorFunctionBlock (typeBloc t);

		BlockCompositeModel* recusiveAdd	(BlockCompositeModel* &block, satap::typeBloc t);

		Bloc *factoryBlock(typeBloc t);

		void setVarible(int);

		std::string variablesToString();


	private:
		Context							mContext;
		sf::RectangleShape				mInstructionsAlphaBackgroung;
		sf::Sprite						mBackgroundSprite, mInstructionSprite;
		sf::Text						mLevelTitle, mLevelDescription, mLevelTip, mInputString, mOutputString, mVariablesString;
		GUI::Container					mButtonsContainer;
		std::vector<GUI::Container::Ptr>				mBlocsContainer; // Un tableau ? mBlocsContainer[0] = 1ere ligne, mBlocsContainer[1] = 2e ligne, etc...
		int								mBlocsContainerDeleted[12]; // tableau qui contiendra les lignes supprimées.
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
		satap::VariableBloc				mBlocVarA;
		satap::VariableBloc				mBlocVarB;
		satap::VariableBloc				mBlocVarC;
		satap::VariableBloc				mBlocVarD;
		satap::VariableBloc				mBlocVarSelected;
};

#endif // BOOK_MENUSTATE_HPP
