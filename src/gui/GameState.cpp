
#include "gui/Button.hpp"
#include "gui/Utility.hpp"
#include "gui/GameState.hpp"
#include "gui/Container.hpp"
#include "gui/GameButton.hpp"
#include "gui/KeyBinding.hpp"
#include "gui/MusicPlayer.hpp"
#include "gui/SpawnerButton.hpp"
#include "gui/ResourceHolder.hpp"

#include "blocs/Bloc.hpp"
#include "blocs/addBloc.hpp"
#include "blocs/subBloc.hpp"
#include "blocs/divBloc.hpp"
#include "blocs/multBloc.hpp"
#include "blocs/inputBloc.hpp"
#include "blocs/outputBloc.hpp"
#include "blocs/variableBloc.hpp"
#include "blocs/assignmentBloc.hpp"

#include "model/addmodel.hpp"
#include "model/gamemodel.hpp"

#include "score.hpp"
#include "SoundPlayer.hpp"

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace satap;

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mContext(context)
	, mButtonsContainer()
	, mBlocsContainer()
	, mCurseur(context)
	, mLi(0)
	, mCol(0)
	, mShowConfirmationExit(false)
	, mExiting(false)
	, showInstructions(true)
	, mButtonsContainerConfirmationExit()
	, mDelayExit(sf::Time::Zero)
	, mBlocVarA(mContext)
	, mBlocVarB(mContext)
	, mBlocVarC(mContext)
	, mBlocVarD(mContext)
	, mBlocVarSelected(mContext)
{
	for (int i = 0; i < 12; i++)
		mBlocsContainer.push_back(std::make_shared<GUI::Container>());

	mBackgroundSprite.setTexture(context.textures->get(Textures::GameBackgroud));

	// TODO déplacer ça dans panel de choix de niveau
	GameModel game;
	game.loadLevel(*context.numLevel);

	mCurrentLevel = game.getCurrentLevel();


	// Fenetre confirmation quitter level (avec fond grisé, boutons yes/no,...)
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u window_size = window.getSize();

	////// Inputs //////

	mInputString.setFont(context.fonts->get(Fonts::Main));
	mInputString.setString(mCurrentLevel->getWorkspace()->getInputList()->toString());
	mInputString.setFillColor(sf::Color::Black);
	mInputString.setPosition(sf::Vector2f(window_size.x*0.06, window_size.y*0.23));

	// Débug
	/*std::cout << "Inputs" << std::endl;
	std::cout << mCurrentLevel->getWorkspace()->getInputList()->toString() << std::endl;
	std::cout << "Fin Inputs" << std::endl;*/

	mVariablesString.setFont(context.fonts->get(Fonts::Main));
	mVariablesString.setString(variablesToString());
	mVariablesString.setFillColor(sf::Color::Black);
	mVariablesString.setPosition(sf::Vector2f(window_size.x*0.17, window_size.y*0.23));

	mOutputString.setFont(context.fonts->get(Fonts::Main));
	mOutputString.setString(mCurrentLevel->getWorkspace()->getOutputList()->toString());
	mOutputString.setFillColor(sf::Color::Black);
	mOutputString.setPosition(sf::Vector2f(window_size.x*0.32, window_size.y*0.23));

	////// Instructions //////

	mInstructionSprite.setTexture(context.textures->get(Textures::Background));
	mInstructionSprite.setPosition(window_size.x*0.1, window_size.y*0.1);
	mInstructionSprite.setScale(0.8, 0.8);

	mInstructionsAlphaBackgroung.setSize(sf::Vector2f(window_size.x, window_size.y));
	mInstructionsAlphaBackgroung.setPosition(0, 0);
	mInstructionsAlphaBackgroung.setFillColor(sf::Color(0,0,0,120));

	mLevelTitle.setFont(context.fonts->get(Fonts::Main));
	mLevelTitle.setString(mCurrentLevel->getName());
	mLevelTitle.setFillColor(sf::Color::Black);
	centerOrigin(mLevelTitle);
	mLevelTitle.setPosition(sf::Vector2f(window_size.x*0.5, window_size.y*0.2));

	mLevelDescription.setFont(context.fonts->get(Fonts::Main));
	mLevelDescription.setString(mCurrentLevel->getDescription());
	mLevelDescription.setFillColor(sf::Color::Black);
	centerOrigin(mLevelDescription);
	mLevelDescription.setPosition(sf::Vector2f(window_size.x*0.5, window_size.y*0.4));

	mLevelTip.setFont(context.fonts->get(Fonts::Main));
	mLevelTip.setString(mCurrentLevel->getHelp());
	mLevelTip.setFillColor(sf::Color::Black);
	centerOrigin(mLevelTip);
	mLevelTip.setPosition(sf::Vector2f(window_size.x*0.5, window_size.y*0.6));


	mSpriteConfirmationExit.setTexture(context.textures->get(Textures::Background));
	centerOrigin(mSpriteConfirmationExit);
	mSpriteConfirmationExit.setPosition(window_size.x*0.5, window_size.y*0.5);
	mSpriteConfirmationExit.setScale(0.5, 0.5);

	mRectAlphaBackground.setSize(sf::Vector2f(window_size.x, window_size.y));
	mRectAlphaBackground.setPosition(0, 0);
	mRectAlphaBackground.setFillColor(sf::Color(0, 0, 0, 120));

	mTextConfirmationExit.setFont(context.fonts->get(Fonts::Main));
	mTextConfirmationExit.setString("Are you sure to exit ?");
	mTextConfirmationExit.setFillColor(sf::Color::Black);
	centerOrigin(mTextConfirmationExit);
	mTextConfirmationExit.setPosition(sf::Vector2f(window_size.x*0.5, window_size.y*0.4));

	auto yesConfirmationExitButton = std::make_shared<GUI::Button>(context);
	yesConfirmationExitButton->setSound(SoundEffect::WrinkledPaper);
	yesConfirmationExitButton->setText("Yes");
	yesConfirmationExitButton->setPosition(sf::Vector2f(window_size.x*0.30, window_size.y*0.55));
	yesConfirmationExitButton->setCallback([this]() {
		mExiting = true;
	});
	mButtonsContainerConfirmationExit.pack(yesConfirmationExitButton);

	auto noConfirmationExitButton = std::make_shared<GUI::Button>(context);
	noConfirmationExitButton->setText("No");
	noConfirmationExitButton->setPosition(sf::Vector2f(window_size.x*0.55, window_size.y*0.55));
	noConfirmationExitButton->setCallback([this]() {
		mShowConfirmationExit = false;
	});
	mButtonsContainerConfirmationExit.pack(noConfirmationExitButton);

	/////////// States Buttons ///////////

	auto exitButton = std::make_shared<GUI::GameButton>(context);
	exitButton->setPosition(10, 10);
	exitButton->setSprite(context, Textures::ExitButton);
	exitButton->setCallback([this]() {
		mShowConfirmationExit = true;
	});
	mButtonsContainer.pack(exitButton);

	auto settingsButton = std::make_shared<GUI::GameButton>(context);
	settingsButton->setPosition(70, 10);
	settingsButton->setSprite(context, Textures::DescriptionButton);
	settingsButton->setCallback([this]() {
		requestStackPush(States::Settings);
	});
	mButtonsContainer.pack(settingsButton);

	auto ennonceButton = std::make_shared<GUI::GameButton>(context);
	ennonceButton->setPosition(130, 10);
	ennonceButton->setSprite(context, Textures::HelpButton);
	ennonceButton->setCallback([this]() {
		showInstructions = true;
	});
	mButtonsContainer.pack(ennonceButton);

	/////////// Actions Buttons ///////////

	auto resetAction = std::make_shared<GUI::GameButton>(context);
	resetAction->setPosition(250, 10);
	resetAction->setSprite(context, Textures::ResetButton);
	resetAction->setSound(SoundEffect::Eraser1);
	resetAction->setCallback([this]() {
		resetCode();
	});
	mButtonsContainer.pack(resetAction);

	auto loopAction = std::make_shared<GUI::GameButton>(context);
	loopAction->setPosition(310, 10);
	loopAction->setSprite(context, Textures::LoopButton);
	loopAction->setCallback([this]() {
		toggleLoop();
	});
	mButtonsContainer.pack(loopAction);

	auto startAction = std::make_shared<GUI::GameButton>(context);
	startAction->setPosition(370, 10);
	startAction->setSprite(context, Textures::ExecuteButton);
	startAction->setCallback([this]() {
		startExecute();
	});
	mButtonsContainer.pack(startAction);

	/////////// Spawners Buttons ///////////

	auto inputSpawner = std::make_shared<GUI::SpawnerButton>(context);
	inputSpawner->setPosition(1020, 100);
	inputSpawner->setSprite(context, Textures::InputSpawner);
	inputSpawner->setCallback([this]() {
		//addBloc(InputBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, InputBlocType);
	});
	mButtonsContainer.pack(inputSpawner);

	auto outputSpawner = std::make_shared<GUI::SpawnerButton>(context);
	outputSpawner->setPosition(1120, 100);
	outputSpawner->setSprite(context, Textures::OutputSpawner);
	outputSpawner->setCallback([this]() {
		//addBloc(OutputBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, OutputBlocType);
	});
	mButtonsContainer.pack(outputSpawner);

	auto varSpawnerA = std::make_shared<GUI::SpawnerButton>(context);
	varSpawnerA->setPosition(1020, 150);
	varSpawnerA->setSprite(context, Textures::VariableSpawner);
	varSpawnerA->setText("a");
	mBlocVarA.setName("a");
	varSpawnerA->setCallback([this]() {
		//addBloc(VariableBlocType);
		setVarible(1);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, VariableBlocType);
	});
	mButtonsContainer.pack(varSpawnerA);

	auto varSpawnerB = std::make_shared<GUI::SpawnerButton>(context);
	varSpawnerB->setPosition(1120, 150);
	varSpawnerB->setSprite(context, Textures::VariableSpawner);
	varSpawnerB->setText("b");
	mBlocVarB.setName("b");
	varSpawnerB->setCallback([this]() {
		//addBloc(VariableBlocType);
		setVarible(2);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, VariableBlocType);
	});
	mButtonsContainer.pack(varSpawnerB);

	auto varSpawnerC = std::make_shared<GUI::SpawnerButton>(context);
	varSpawnerC->setPosition(1020, 200);
	varSpawnerC->setSprite(context, Textures::VariableSpawner);
	varSpawnerC->setText("c");
	mBlocVarC.setName("c");
	varSpawnerC->setCallback([this]() {
		//addBloc(VariableBlocType);
		setVarible(3);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, VariableBlocType);
	});
	mButtonsContainer.pack(varSpawnerC);

	auto varSpawnerD = std::make_shared<GUI::SpawnerButton>(context);
	varSpawnerD->setPosition(1120, 200);
	varSpawnerD->setSprite(context, Textures::VariableSpawner);
	varSpawnerD->setText("d");
	mBlocVarD.setName("d");
	varSpawnerD->setCallback([this]() {
		//addBloc(VariableBlocType);
		setVarible(4);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, VariableBlocType);
	});
	mButtonsContainer.pack(varSpawnerD);

	auto affectationSpawner = std::make_shared<GUI::SpawnerButton>(context);
	affectationSpawner->setPosition(1020, 250);
	affectationSpawner->setSprite(context, Textures::AssignmentSpawner);
	affectationSpawner->setCallback([this]() {
		//addBloc(AssignementBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, AssignementBlocType);

	});
	mButtonsContainer.pack(affectationSpawner);

	auto addSpawner = std::make_shared<GUI::SpawnerButton>(context);
	addSpawner->setPosition(1020, 300);
	addSpawner->setSprite(context, Textures::AddSpawner);
	addSpawner->setCallback([this]() {
		//addBloc(AddBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, AddBlocType);

	});
	mButtonsContainer.pack(addSpawner);

	auto subSpawner = std::make_shared<GUI::SpawnerButton>(context);
	subSpawner->setPosition(1120, 300);
	subSpawner->setSprite(context, Textures::SubSpawner);
	subSpawner->setCallback([this]() {
		//addBloc(AddBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, SubBlocType);

	});
	mButtonsContainer.pack(subSpawner);

	auto multSpawner = std::make_shared<GUI::SpawnerButton>(context);
	multSpawner->setPosition(1020, 350);
	multSpawner->setSprite(context, Textures::MultSpawner);
	multSpawner->setCallback([this]() {
		//addBloc(AddBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, MultBlocType);

	});
	mButtonsContainer.pack(multSpawner);

	auto divSpawner = std::make_shared<GUI::SpawnerButton>(context);
	divSpawner->setPosition(1120, 350);
	divSpawner->setSprite(context, Textures::DivSpawner);
	divSpawner->setCallback([this]() {
		//addBloc(AddBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, DivBlocType);

	});
	mButtonsContainer.pack(divSpawner);

	//mCurseur.setSprite(context, Textures::CurseurSprite);
	reloadPositionCurseur();

	for(size_t i = 0; i<12; i++)
		mBlocsContainerDeleted[i]=1;

	// Test
	//OutputBloc* out = ((OutputBloc*)addBloc(OutputBlocType));
	//AssignmentBloc* assign = ((AssignmentBloc*) addBloc(AssignementBlocType));
	//InputBloc* in = ((InputBloc*)addBloc(InputBlocType));

	//assign->setFirstOperand(out);
	//assign->setSecondOperand(in);

	//mCurrentLevel->getCodePage()->addBlock(assign);
}

void GameState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.clear();

	window.draw(mBackgroundSprite);

	window.draw(mButtonsContainer);
	for (int i = 0; i < 12; i++) {
		window.draw(*mBlocsContainer[i]);
	}

	window.draw(mCurseur);

	window.draw(mInputString);
	window.draw(mVariablesString);
	window.draw(mOutputString);

	if (showInstructions) {
		window.draw(mInstructionsAlphaBackgroung);
		window.draw(mInstructionSprite);
		window.draw(mLevelTitle);
		window.draw(mLevelDescription);
		window.draw(mLevelTip);
	}
	if (mShowConfirmationExit) {
		window.draw(mRectAlphaBackground);
		window.draw(mSpriteConfirmationExit);
		window.draw(mTextConfirmationExit);
		window.draw(mButtonsContainerConfirmationExit);
	}


	if (mExiting)
	{
		mRectAlphaBackground.setFillColor(mRectAlphaBackground.getFillColor()+sf::Color(0,0,0,1));
		window.draw(mRectAlphaBackground);
	}
}

bool GameState::update(sf::Time dt)
{
	if (mExiting)
	{
		mDelayExit += dt;
		if (mDelayExit > sf::seconds(4.75f))
		{
			requestStackPop();
		}
	}

	mInputString.setString(mCurrentLevel->getWorkspace()->getInputList()->toString());
	mVariablesString.setString(variablesToString());
	mOutputString.setString(mCurrentLevel->getWorkspace()->getOutputList()->toString());
	return true;
}

bool GameState::handleEvent(const sf::Event& event) {
	if (mShowConfirmationExit)
	{
		mButtonsContainerConfirmationExit.handleEvent(event);
		return false;
	}



	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == getContext().keys->getAssignedKey(PlayerAction::Up)) {
			mLi--;
			if (mLi < 0)
				mLi = 0;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}
		else if (event.key.code == getContext().keys->getAssignedKey(PlayerAction::Down)) {
			mLi++;
			if (mLi > 11)
				mLi = 11;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}
		else if (event.key.code == getContext().keys->getAssignedKey(PlayerAction::EraseLine)) {
			getContext().sounds->play(SoundEffect::Eraser1);
			effacerLigne(mLi);
			mCol = 0;
		}
		else if (event.key.code == getContext().keys->getAssignedKey(PlayerAction::RunCode))
		{
			startExecute();
		}
		else if (event.key.code == getContext().keys->getAssignedKey(PlayerAction::NewLine))
		{
			newLine(mLi);
		}
	} else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseMoved) {
		if (showInstructions && event.type == sf::Event::MouseButtonReleased) {
			showInstructions = false;
		}

		else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.x > 505 && event.mouseButton.x < 995 && event.mouseButton.y > 70 && event.mouseButton.y < 70 + 50*12)
		{
			int ligne = 0;
			while (50 * ligne + 70 < event.mouseButton.y)
			{
				ligne++;
			}
			mLi = ligne-1;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}


		mButtonsContainer.handleEvent(event);
	}
	else if (event.type == sf::Event::KeyReleased)
	{

	}
	return false;
}


std::pair<int, int> GameState::getCoordonnees(int ligne, int colonne) {
	int posX = 540, posY = 85;
	int espaceX = 90, espaceY = 50;
	return (std::pair<int, int>(posX + colonne * espaceX, posY + ligne * espaceY));
}

std::pair<int, int> GameState::getCoordonneesCurseur(int ligne) {
	int posX = 500, posY = 85, espaceY = 50;
	return (std::pair<int, int>(posX, posY + ligne * espaceY));
}

void GameState::resetCode() {
	for (int i = 0; i < 12; i++) {
		effacerLigne(i);
	}
	mLi = 0;
	mCol = 0;
}

void GameState::toggleLoop() {

}

void GameState::startExecute() {
	if(mLi == 0 && mCol == 0)
		return ;
	int score = mCurrentLevel->validate();

	mInputString.setString(mCurrentLevel->getWorkspace()->getInputList()->toString());
	mVariablesString.setString(variablesToString());
	mOutputString.setString(mCurrentLevel->getWorkspace()->getOutputList()->toString());

	*mContext.nbBlocsUsed = getNbBlocs();
	if(score != 0){
		score=1;
		if(*mContext.nbBlocsUsed<2*mCurrentLevel->getOptimalBlocCount()+1)
			score++;
		if(*mContext.nbBlocsUsed<mCurrentLevel->getOptimalBlocCount()+1)
			score++;
	}
	*mContext.score = score;
	*mContext.nameLevel = mCurrentLevel->getName();

	if (score > 0){
		requestStackPush(States::Win);
		if(mContext.scores->at(*getContext().numLevel) < score)
			mContext.scores->at(*getContext().numLevel) = score;
		if (mContext.scores->at(*getContext().numLevel+1) == -1)
			mContext.scores->at(*getContext().numLevel+1) = 0;
		//saveLevel(score, mCurrentLevel->getName());
		saveAllScore(*getContext().scores);
	}
	else
	{
		requestStackPush(States::Lose);
		mCurrentLevel->reset();
		mBlocVarA.setValuePtr(new sct_type());
		mBlocVarB.setValuePtr(new sct_type());
		mBlocVarC.setValuePtr(new sct_type());
		mBlocVarD.setValuePtr(new sct_type());
	}
}

/*void GameState::effacerLigne(int ligne)
{
	if (getNbElementsOnLine(ligne) > 0) {
		if(mCurrentLevel->getCodePage()->getNbBlock(ligne) > 0)
			mCurrentLevel->getCodePage()->deleteLigne(ligne);
		mBlocsContainer[ligne]->flush();
	}
}*/


void GameState::effacerLigne(int ligne) {
	size_t countDel=0;
	//Calcul du nombre delement supprimé avant la ligne 'ligne'.
	for(size_t i=0; i<12; i++){
		if(i <= ligne) //Pour toutes les lignes en dessous de la ligne elle meme
		if(mBlocsContainerDeleted[i]==0)
			countDel++;
	}

	// Si ça n'efface pas la ligne, c'est que geNbElementsOnLine retourne 0, et que donc, les éléments de la ligne ne sont pas correctement linkés.
	std::cout << "effacer line " << ligne << std::endl;
	if (getNbElementsOnLine(ligne) > 0) {
		if(mBlocsContainerDeleted[ligne]==0)
			std::cout<< "la ligne est deja supprmé" <<std::endl;
		//mCurrentLevel->getCodePage()->deleteLigne(ligne);
		mBlocsContainer[ligne]->flush();
		mCurrentLevel->getCodePage()->deleteLigne(ligne-countDel);
		mBlocsContainerDeleted[ligne]=0;
	}
}



void GameState::newLine(int line)
{
	// TODO insérer ligne dans le model -> décaler lignes dessous
	std::cout << "TODO insérer ligne dans model" << std::endl;
	if (getNbElementsOnLine(11) == 0)
	{
		for (int l = line; l<11; l++)
		{
			for (int i = 0; i < mBlocsContainer[l]->getNbChildren(); i++)
				mBlocsContainer[l]->getComponent(i)->setPosition(mBlocsContainer[l]->getComponent(i)->getPosition().x, mBlocsContainer[l]->getComponent(i)->getPosition().y + 50);
		}
		mCol = 0;
		std::vector<GUI::Container::Ptr>::iterator it = mBlocsContainer.begin() + line;
		mBlocsContainer.insert(it, std::make_shared<GUI::Container>());
		mBlocsContainer.pop_back();
	}
}



int GameState::getNbElementsOnLine(int ligne) {
	int nbElements = mBlocsContainer[ligne]->getNbChildren();
	//std::cout << "ligne " << ligne << " : " << nbElements << std::endl;
	return nbElements;
}

int GameState::getNbBlocs() {
	int nbElements = 0;

	for (int i = 0; i < 12; i++) {
		int n = mBlocsContainer[i]->getNbChildren();
		nbElements += n;
	}

	return nbElements;
}

void GameState::reloadPositionCurseur() {
	std::pair<int, int> coordCurseur = getCoordonneesCurseur(mLi);
	mCurseur.setPosition(coordCurseur.first, coordCurseur.second);
}
/*-------------------------------------------------*/

/**
 * \brief fonction qui va ajouter un bloc a un lieu precis
 *
 * \param bloc represente une des ligne de la codePage.
 * \param t est le type de bloc a ajouter a la ligne donnée.
 */
void GameState::addBlocks(BlockModel *bloc, satap::typeBloc t){
	std::shared_ptr<Bloc> bloc_ptr;
	std::cerr << "1- " << __FUNCTION__ <<std::endl;
	if(mCurrentLevel->getCodePage()->getNbBlock(mLi) == 0 || (mBlocsContainerDeleted[mLi]==0)){ //Si la ligne est vide alors
		std::cerr << "2- " << __FUNCTION__ <<std::endl;
		if(isValideBlock(t) || t == VariableBlocType){
			std::cerr << "3- " << __FUNCTION__ <<std::endl;
			Bloc * bloc_tmp = factoryBlock(t);

			std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
			bloc_tmp->setPosition(coordBloc.first, coordBloc.second);
			bloc_ptr = std::shared_ptr<Bloc>(bloc_tmp);
			mBlocsContainer[mLi]->pack(bloc_ptr);
			mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
			// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

			if(t == OutputBlocType || t == VariableBlocType){
				std::cerr << "4- " << __FUNCTION__ <<std::endl;
				//std::cerr << "ERROR: OUT OU VARIABLE " << __FUNCTION__ <<std::endl;
				Bloc * bloc_assign_tmp= factoryBlock(AssignementBlocType);
				std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
				bloc_assign_tmp->setPosition(coordBloc.first, coordBloc.second);
				bloc_ptr = std::shared_ptr<Bloc>(bloc_assign_tmp);
				mBlocsContainer[mLi]->pack(bloc_ptr);
				mCol++; // TODO Trouver un autre moyen de mettre à jour mCol

				BlockModel* compofirstop = dynamic_cast<BlockModel*>(bloc_tmp);
				if(compofirstop == nullptr)
					std::cout << "ERREUR: "<< __FUNCTION__ <<std::endl;
				else{
					compofirstop->setWorspace(*mCurrentLevel->getWorkspace());
					compofirstop->setType(t);
					dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setFirstOperand(compofirstop);
					dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setSecondOperand(nullptr);
					mCurrentLevel->getCodePage()->addBlock(dynamic_cast<BlockModel*>(bloc_assign_tmp), AssignementBlocType, mLi);
					mBlocsContainerDeleted[mLi]=1;
				}
			}
			else{
				std::cerr << "5- " << __FUNCTION__ <<std::endl;
				mCurrentLevel->getCodePage()->addBlock(dynamic_cast<BlockModel*>(bloc_tmp), t, mLi);
				mBlocsContainerDeleted[mLi]=1;
			}
		}
		else{
			std::cerr << "ERROR: " << __FUNCTION__ <<" Le type n'est pas conforme. "<<std::endl;
		}
	}else{
		if(mCurrentLevel->getCodePage()->getBlockByIndex(mLi)->getType() == AssignementBlocType){
			std::cerr << "7- " << __FUNCTION__ <<std::endl;
			AssignmentModel* assignBlock = dynamic_cast<AssignmentModel*>(mCurrentLevel->getCodePage()->getBlockByIndex(mLi));
			if(assignBlock->getSecondOperand()==nullptr){
				std::cerr << "8- " << __FUNCTION__ <<std::endl;
			 	if(!isBooleanBlock(t)){
					std::cerr << "9- " << __FUNCTION__ <<std::endl;
					if(!isValideBlock(t) && !isFunctionBlock(t)){
						std::cerr << "10- " << __FUNCTION__ <<std::endl;
						Bloc * bloc_assign_tmp= factoryBlock(t);

						std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
						bloc_assign_tmp->setPosition(coordBloc.first, coordBloc.second);
						bloc_ptr = std::shared_ptr<Bloc>(bloc_assign_tmp);
						mBlocsContainer[mLi]->pack(bloc_ptr);
						mCol++;

						BlockCompositeModel* compoblock = dynamic_cast<BlockCompositeModel*>(bloc_assign_tmp);
						compoblock->setType(t);
						assignBlock->setSecondOperand(compoblock);
						if(assignBlock->getSecondOperand()==nullptr) //Je verifi que la nouvelle valeur n'est plus egale a null si elle est toujours alors elle renvera un message.
							std::cerr << "Second operand est toujours nullptr " << __FUNCTION__ <<std::endl;
					}
				}
			}
			else if (assignBlock->getSecondOperand() != nullptr){
				if (t != AssignementBlocType){
					std::cerr << "12- " << __FUNCTION__ <<std::endl;
					BlockCompositeModel * blockmodel_tmp = assignBlock->getSecondOperand();
					assignBlock->setSecondOperand(recusiveAdd(blockmodel_tmp, t));
				}
			}
		}
		else if(mCurrentLevel->getCodePage()->getBlockByIndex(mLi)->getType() == IfBlocType){
			//std::cerr << "14- " << __FUNCTION__ <<std::endl;
			std::cerr << "Type IfBlocType " << __FUNCTION__ <<std::endl;
		}
	}
}

BlockCompositeModel* GameState::recusiveAdd(BlockCompositeModel* &block, satap::typeBloc t){
	std::shared_ptr<Bloc> bloc_ptr;
	if(isUnaryBlock(block->getType())){
		if(isBaseFunctionBlock(block->getType())){ //Si la fonction est composable et donc peut avoir 1 parametre
			std::cout << " " << t <<std::endl;
			//BinaryModel* btmp = dynamic_cast<BinaryModel*>(block);

			/*if(btmp->getOperand()==nullptr){//Si notre operateur n'a pas d'elements a l'interrieur alors
				if(isUnaryBlock(t)){ //Si t est soit un input soit un NOT(n) soit un ...

					//BlockCompositeModel* btmp = dynamic_cast<UnaryModel*>(block); //On copie l'objet du bloc principal
					Bloc * binary_block= factoryBlock(t); // On crée le nouveau type

					std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
					binary_block->setPosition(coordBloc.first, coordBloc.second);
					bloc_ptr = std::shared_ptr<Bloc>(binary_block);
					mBlocsContainer[mLi].pack(bloc_ptr);
					mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
					// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

					UnaryModel* binblock = dynamic_cast<UnaryModel*>(unary_block);
					unary_block->setType(block->getType());
					unary_block->setOperand(btmp);//Je met le precedent bloc dans le nouveau bloc
					block = unary_block;//Et je remplace le bloc par le nouveau
				}
				else{
					std::cout << "ERROR" <<std::endl;
				}
			}*/
		}
		else{//Si on a un input par exemple
			if(isOperatorFunctionBlock(t)){//Si on a une fonction binaire
				BlockCompositeModel* btmp = block;
				Bloc * binary_block= factoryBlock(t); // On crée le nouveau type

				std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
				binary_block->setPosition(coordBloc.first, coordBloc.second);
				bloc_ptr = std::shared_ptr<Bloc>(binary_block);
				mBlocsContainer[mLi]->pack(bloc_ptr);
				mCol++; // TODO Trouver un autre moyen de mettre à jour mCol

				BinaryModel* binblock = dynamic_cast<BinaryModel*>(binary_block);
				binblock->setType(t);
				binblock->setFirstOperand(btmp);//Je met le precedent bloc dans le nouveau bloc
				binblock->setSecondOperand(nullptr);//Je met le precedent bloc dans le nouveau bloc
				block = binblock;//Et je remplace le bloc par le nouveau

			}
		}
	}
	else{ //Sinon si on a un bloc de type AddModel(a, b) par exemple
		if(isOperatorFunctionBlock(block->getType())){ //Si notre bloc courant est un operateur binaire alors
			BinaryModel* binblock = dynamic_cast<BinaryModel*>(block);
			if(binblock->getSecondOperand()==nullptr){
				if(!isOperatorFunctionBlock(t) && !isValideBlock(t)){
					Bloc * binary_block= factoryBlock(t); // On crée le nouveau type

					std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
					binary_block->setPosition(coordBloc.first, coordBloc.second);
					bloc_ptr = std::shared_ptr<Bloc>(binary_block);
					mBlocsContainer[mLi]->pack(bloc_ptr);
					mCol++; // TODO Trouver un autre moyen de mettre à jour mCol

					BlockCompositeModel* compoblock = dynamic_cast<BlockCompositeModel*>(binary_block);
					compoblock->setType(t);
					binblock->setSecondOperand(compoblock);
				}
			}
		}
	}
	return block;
}

bool GameState::isValideBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case BlocType:
		case IfBlocType:
		case ForBlocType:
		case WhileBlocType:
		case OutputBlocType:
		case FonctionBlocType:
			isValide=true;
		break;
		default:
			break;
	}
	return isValide;
}


bool GameState::isBinaryBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case AddBlocType:
		case AssignementBlocType:
		case MultBlocType:
		case DivBlocType:
		case SubBlocType:
		case MaxBlocType:
		case EqualBlocType:
		//>= <= > < !=
			isValide=true;
		break;
		default:
			break;
	}

	return isValide;
}

/*
	bloc unaire comme Factoriel(n), input, not(n), ...
*/
bool GameState::isUnaryBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case InputBlocType:
		case VariableBlocType:
		case NotBlocType:
			isValide=true;
		break;
		default:
			break;
	}
	return isValide;
}

bool GameState::isBooleanBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case EqualBlocType:
		//>= <= > < !=
			isValide=true;
		break;
		default:
			break;
	}
	return isValide;
}

bool GameState::isFunctionBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case EqualBlocType:
		case AssignementBlocType:
		case AddBlocType:
		case SubBlocType:
		case MultBlocType:
		case DivBlocType:
		case MaxBlocType:
		//>= <= > < !=
			isValide=true;
		break;
		default:
			break;
	}
	return isValide;
}
bool GameState::isBaseFunctionBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case MaxBlocType:
		case MinBlocType:
		case NotBlocType:
			isValide=true;
		break;
		default:
			break;
	}
	return isValide;
}
bool GameState::isOperatorFunctionBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case EqualBlocType:
		case AssignementBlocType:
		case AddBlocType:
		case SubBlocType:
		case MultBlocType:
		case DivBlocType:
		//>= <= > < !=
			isValide=true;
		break;
		default:
			break;
	}
	return isValide;
}


bool GameState::isUnaryFunctionBlock(satap::typeBloc t){
	bool isValide=false;
	switch (t) {
		case NotBlocType:
		//++ -- ...
			isValide=true;
		break;
		default:
  			break;
	}
	return isValide;
}



Bloc * GameState::factoryBlock(satap::typeBloc t){
	Bloc* b=NULL;
	if (t == VariableBlocType) {
		VariableBloc * b1 = new VariableBloc(mContext);
		b1->setName(mBlocVarSelected.getName());
		b1->setText(mBlocVarSelected.getName());
		b1->setValuePtr(mBlocVarSelected.getValuePtr());
		b1->setSprite(mContext, Textures::VariableSpawner);
		b = b1;
		std::cout << "Ajout d'un bloc de type var" << std::endl;
	}
	else if (t == AssignementBlocType) {
		b = new AssignmentBloc(mContext);
		b->setSprite(mContext, Textures::AssignmentSpawner);
		std::cout << "Ajout d'un bloc de type <-" << std::endl;
	}
	else if (t == InputBlocType) {
		b = new InputBloc(mContext, mCurrentLevel->getWorkspace()->getInputList());
		b->setSprite(mContext, Textures::InputSpawner);
		std::cout << "Ajout d'un bloc de type In" << std::endl;
	}
	else if (t == OutputBlocType) {
		b = new OutputBloc(mContext, mCurrentLevel->getWorkspace()->getOutputList());
		b->setSprite(mContext, Textures::OutputSpawner);
		std::cout << "Ajout d'un bloc de type Out" << std::endl;
	}
	else if (t == AddBlocType) {
		b = new AddBloc(mContext);
		b->setSprite(mContext, Textures::AddSpawner);
		std::cout << "Ajout d'un bloc de type +" << std::endl;
	}
	else if (t == SubBlocType) {
		b = new SubBloc(mContext);
		b->setSprite(mContext, Textures::SubSpawner);
		std::cout << "Ajout d'un bloc de type -" << std::endl;
	}
	else if (t == DivBlocType) {
		b = new DivBloc(mContext);
		b->setSprite(mContext, Textures::DivSpawner);
		std::cout << "Ajout d'un bloc de type /" << std::endl;
	}
	else if (t == MultBlocType) {
		b = new MultBloc(mContext);
		b->setSprite(mContext, Textures::MultSpawner);
		std::cout << "Ajout d'un bloc de type *" << std::endl;
	}

	return b;
}

void GameState::setVarible(int var)
{
	switch (var)
	{
		case 1:
			mBlocVarSelected.setName(mBlocVarA.getName());
			mBlocVarSelected.setValuePtr(mBlocVarA.getValuePtr());

			break;
		case 2:
			mBlocVarSelected.setName(mBlocVarB.getName());
			mBlocVarSelected.setValuePtr(mBlocVarB.getValuePtr());

			break;
		case 3:
			mBlocVarSelected.setName(mBlocVarC.getName());
			mBlocVarSelected.setValuePtr(mBlocVarC.getValuePtr());

			break;
		case 4:
			mBlocVarSelected.setName(mBlocVarD.getName());
			mBlocVarSelected.setValuePtr(mBlocVarD.getValuePtr());

			break;
	}

}


std::string GameState::variablesToString() {
	std::string s = "";

	// Var A
	bool notSet = false;
	sct_type var = mBlocVarA.getValue();
	std::string name = "a";

	std::string value;
	if (var.bool_type) {
		value = std::to_string(*var.bool_type);
	} else if (var.double_type) {
		value = std::to_string(*var.double_type);
	} else if (var.int_type) {
		value = std::to_string(*var.int_type);
	} else {
		notSet = true;
		value = "?";
	}

	if (!notSet) {
		s += name + "=" + value + "\n";
	}

	// Var B
	notSet = false;
	var = mBlocVarB.getValue();
	name = "b";

	if (var.bool_type) {
		value = std::to_string(*var.bool_type);
	}
	else if (var.double_type) {
		value = std::to_string(*var.double_type);
	}
	else if (var.int_type) {
		value = std::to_string(*var.int_type);
	}
	else {
		notSet = true;
		value = "?";
	}

	if (!notSet) {
		s += name + "=" + value + "\n";
	}

	// Var C
	notSet = false;
	var = mBlocVarC.getValue();
	name = "c";

	if (var.bool_type) {
		value = std::to_string(*var.bool_type);
	}
	else if (var.double_type) {
		value = std::to_string(*var.double_type);
	}
	else if (var.int_type) {
		value = std::to_string(*var.int_type);
	}
	else {
		notSet = true;
		value = "?";
	}

	if (!notSet) {
		s += name + "=" + value + "\n";
	}

	// Var D
	notSet = false;
	var = mBlocVarD.getValue();
	name = "d";

	if (var.bool_type) {
		value = std::to_string(*var.bool_type);
	}
	else if (var.double_type) {
		value = std::to_string(*var.double_type);
	}
	else if (var.int_type) {
		value = std::to_string(*var.int_type);
	}
	else {
		notSet = true;
		value = "?";
	}

	if (!notSet) {
		s += name + "=" + value + "\n";
	}

	return s;
}
