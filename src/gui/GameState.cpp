#ifdef __APPLESOKA__
#include "GameState.hpp"
#include "Button.hpp"
#include "GameButton.hpp"
#include "SpawnerButton.hpp"
#include "Bloc.hpp"
#include "variableBloc.hpp"
#include "addBloc.hpp"
#include "inputBloc.hpp"
#include "outputBloc.hpp"
#include "assignmentBloc.hpp"
#include "Utility.hpp"
#include "MusicPlayer.hpp"
#include "ResourceHolder.hpp"
#include "gamemodel.hpp"
#else
#include "gui/GameState.hpp"
#include "gui/Button.hpp"
#include "gui/GameButton.hpp"
#include "gui/SpawnerButton.hpp"
#include "gui/Container.hpp"
#include "gui/KeyBinding.hpp"
#include "blocs/Bloc.hpp"
#include "blocs/variableBloc.hpp"
#include "blocs/addBloc.hpp"
#include "blocs/inputBloc.hpp"
#include "blocs/outputBloc.hpp"
#include "blocs/assignmentBloc.hpp"
#include "gui/Utility.hpp"
#include "gui/MusicPlayer.hpp"
#include "gui/ResourceHolder.hpp"
#include "model/gamemodel.hpp"
#include "model/addmodel.hpp"
#endif
#include "score.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

using namespace satap;

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mContext(context)
	, mButtonsContainer()
	, mBlocsContainer()
	, mCurseur(context)
	, mLi(0)
	, mCol(0)
	, showInstructions(true)
	, mShowConfirmationExit(false)
	, mExiting(false)
	, mButtonsContainerConfirmationExit()
	, mDelayExit(sf::Time::Zero)
{
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
	mInputString.setColor(sf::Color::Black);
	mInputString.setPosition(sf::Vector2f(window_size.x*0.06, window_size.y*0.23));

	// Débug
	/*std::cout << "Inputs" << std::endl;
	std::cout << mCurrentLevel->getWorkspace()->getInputList()->toString() << std::endl;
	std::cout << "Fin Inputs" << std::endl;*/

	mVariablesString.setFont(context.fonts->get(Fonts::Main));
	mVariablesString.setString(mCurrentLevel->getWorkspace()->getVariableList()->toString());
	mVariablesString.setColor(sf::Color::Black);
	mVariablesString.setPosition(sf::Vector2f(window_size.x*0.17, window_size.y*0.23));

	mOutputString.setFont(context.fonts->get(Fonts::Main));
	mOutputString.setString(mCurrentLevel->getWorkspace()->getOutputList()->toString());
	mOutputString.setColor(sf::Color::Black);
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
	mLevelTitle.setColor(sf::Color::Black);
	centerOrigin(mLevelTitle);
	mLevelTitle.setPosition(sf::Vector2f(window_size.x*0.5, window_size.y*0.2));

	mLevelDescription.setFont(context.fonts->get(Fonts::Main));
	mLevelDescription.setString(mCurrentLevel->getDescription());
	mLevelDescription.setColor(sf::Color::Black);
	centerOrigin(mLevelDescription);
	mLevelDescription.setPosition(sf::Vector2f(window_size.x*0.5, window_size.y*0.4));

	mLevelTip.setFont(context.fonts->get(Fonts::Main));
	mLevelTip.setString(mCurrentLevel->getHelp());
	mLevelTip.setColor(sf::Color::Black);
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
	mTextConfirmationExit.setColor(sf::Color::Black);
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
	resetAction->setSound(SoundEffect::WrinkledPaper);
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

	auto addSpawner = std::make_shared<GUI::SpawnerButton>(context);
	addSpawner->setPosition(1020, 200);
	addSpawner->setSprite(context, Textures::AddSpawner);
	addSpawner->setCallback([this]() {
		//addBloc(AddBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, AddBlocType);

	});
	mButtonsContainer.pack(addSpawner);

	auto varSpawner = std::make_shared<GUI::SpawnerButton>(context);
	varSpawner->setPosition(1020, 150);
	varSpawner->setSprite(context, Textures::VariableSpawner);
	varSpawner->setCallback([this]() {
		//addBloc(VariableBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, VariableBlocType);
	});
	mButtonsContainer.pack(varSpawner);

	auto affectationSpawner = std::make_shared<GUI::SpawnerButton>(context);
	affectationSpawner->setPosition(1120, 150);
	affectationSpawner->setSprite(context, Textures::AssignmentSpawner);
	affectationSpawner->setCallback([this]() {
		//addBloc(AssignementBlocType);
		addBlocks(NULL/*mCurrentLevel->getCodePage()->getBlock(0)*/, AssignementBlocType);

	});
	mButtonsContainer.pack(affectationSpawner);

	//mCurseur.setSprite(context, Textures::CurseurSprite);
	reloadPositionCurseur();


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
		window.draw(mBlocsContainer[i]);
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
	mVariablesString.setString(mCurrentLevel->getWorkspace()->getVariableList()->toString());
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
		if (event.key.code == sf::Keyboard::Up) {
			mLi--;
			if (mLi < 0)
				mLi = 0;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}
		else if (event.key.code == sf::Keyboard::Down) {
			mLi++;
			if (mLi > 11)
				mLi = 11;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}
		else if (event.key.code == sf::Keyboard::BackSpace) {
			effacerLigne(mLi);
			mCol = 0;
		}
		else if (event.key.code == getContext().keys->getAssignedKey(PlayerAction::RunCode))
		{
			startExecute();
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

/*Bloc * GameState::addBloc(satap::typeBloc t)
{
	Bloc* b=NULL;
	std::shared_ptr<Bloc> bl;

	if (t == VariableBlocType) {
		b = new VariableBloc(mContext);
		b->setSprite(mContext, Textures::VariableSpawner);
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

	std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
	b->setPosition(coordBloc.first, coordBloc.second);
	bl = std::shared_ptr<Bloc>(b);
	mBlocsContainer[mLi].pack(bl);

	mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
	// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)


	return b;
}*/

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
	mCurrentLevel->getCodePage()->flush();
	for (int i = 0; i < 12; i++) {
		mBlocsContainer[i].flush();
	}
	mLi = 0;
	mCol = 0;
}

void GameState::toggleLoop() {

}

void GameState::startExecute() {
	int score = mCurrentLevel->validate();

	mInputString.setString(mCurrentLevel->getWorkspace()->getInputList()->toString());
	mVariablesString.setString(mCurrentLevel->getWorkspace()->getVariableList()->toString());
	mOutputString.setString(mCurrentLevel->getWorkspace()->getOutputList()->toString());

	*mContext.score = score;
	*mContext.nameLevel = mCurrentLevel->getName();
	*mContext.nbBlocsUsed = getNbBlocs();

	// TODO à retirer
	std::cout << score << std::endl;
	if (score > 0){
		requestStackPush(States::Win);
		saveLevel(score, mCurrentLevel->getName());
	}
	else
		requestStackPush(States::Lose);
}

void GameState::effacerLigne(int ligne) {
	// Si ça n'efface pas la ligne, c'est que geNbElementsOnLine retourne 0, et que donc, les éléments de la ligne ne sont pas correctement linkés.
	std::cout << "effacer line " << ligne << std::endl;
	if (getNbElementsOnLine(ligne) > 0) {
		mCurrentLevel->getCodePage()->deleteLigne(ligne);
		mBlocsContainer[ligne].flush();
	}
}

int GameState::getNbElementsOnLine(int ligne) {
	//int nbElements = mCurrentLevel->getCodePage()->getNbBlock(ligne);
	int nbElements = mBlocsContainer[mLi].getNbChildren();
	std::cout << "ligne " << ligne << " : " << nbElements << std::endl;
	return nbElements;
}

int GameState::getNbBlocs() {
	int nbElements = 0;

	for (int i = 0; i < 12; i++) {
		int n = mBlocsContainer[i].getNbChildren();
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
	if(mCurrentLevel->getCodePage()->getNbBlock(mLi) == 0){ //Si la ligne est vide alors
		std::cerr << "2- " << __FUNCTION__ <<std::endl;
		if(isValideBlock(t)){
			std::cerr << "3- " << __FUNCTION__ <<std::endl;
			Bloc * bloc_tmp = factoryBlock(t);

			std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
			bloc_tmp->setPosition(coordBloc.first, coordBloc.second);
			bloc_ptr = std::shared_ptr<Bloc>(bloc_tmp);
			mBlocsContainer[mLi].pack(bloc_ptr);
			mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
			// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

			if(t == OutputBlocType || t == VariableBlocType){
				std::cerr << "4- " << __FUNCTION__ <<std::endl;
				//std::cerr << "ERROR: OUT OU VARIABLE " << __FUNCTION__ <<std::endl;
				Bloc * bloc_assign_tmp= factoryBlock(AssignementBlocType);
				std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
				bloc_assign_tmp->setPosition(coordBloc.first, coordBloc.second);
				bloc_ptr = std::shared_ptr<Bloc>(bloc_assign_tmp);
				mBlocsContainer[mLi].pack(bloc_ptr);
				mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
				// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)


				//BlockCompositeModel* compofirstop = dynamic_cast<BlockCompositeModel*>(bloc_tmp);
				/*BlockModel* compo = dynamic_cast<BlockModel*>(bloc_tmp);
				std::cout << "Type int (avant setType) -> " << compo->getType() <<std::endl;
				compo->setType(t);
				std::cout << "Type int (apres setType) -> " << compo->getType() <<std::endl;*/
				//BlockCompositeModel* compofirstop = dynamic_cast<BlockCompositeModel*>(bloc_tmp);
				BlockModel* compofirstop = dynamic_cast<BlockModel*>(bloc_tmp);
				if(compofirstop == nullptr)
					std::cout << "ERREUR: "<< __FUNCTION__ <<std::endl;
				else{
					compofirstop->setWorspace(*mCurrentLevel->getWorkspace());
					compofirstop->setType(t);
					dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setFirstOperand(compofirstop);
					dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setSecondOperand(nullptr);
					mCurrentLevel->getCodePage()->addBlock(dynamic_cast<BlockModel*>(bloc_assign_tmp), AssignementBlocType);
				}
			}
			else{
				std::cerr << "5- " << __FUNCTION__ <<std::endl;
				mCurrentLevel->getCodePage()->addBlock(dynamic_cast<BlockModel*>(bloc_tmp), t);
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
						mBlocsContainer[mLi].pack(bloc_ptr);
						mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
						// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

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

					//std::cout << "Type int (avant recusive)" << blockmodel_tmp->getType() <<std::endl;
					assignBlock->setSecondOperand(recusiveAdd(blockmodel_tmp, t));
					//std::cout << "Type int (apres recusive)" << blockmodel_tmp->getType() <<std::endl;

				}
			}
			/*else{
				std::cerr << "13- " << __FUNCTION__ <<std::endl;
				std::cerr << "ERROR: " << t << " " << __FUNCTION__ <<" Le type n'est pas conforme. "<<std::endl;
				std::cerr << "getType: " << t << " " << __FUNCTION__ <<" Le type n'est pas conforme. "<<std::endl;
				std::cerr << "isBin: " << t << " " << __FUNCTION__ <<" Le type n'est pas conforme. "<<std::endl;
				std::cerr << "isUn: " << t << " " << __FUNCTION__ <<" Le type n'est pas conforme. "<<std::endl;
			}*/
		}
		else if(mCurrentLevel->getCodePage()->getBlockByIndex(mLi)->getType() == IfBlocType){
			//std::cerr << "14- " << __FUNCTION__ <<std::endl;
			std::cerr << "Type IfBlocType " << __FUNCTION__ <<std::endl;
		}
		//std::cerr << "LIGNE NON VIDE : " << __FUNCTION__ <<mCurrentLevel->getCodePage()->getBlockByIndex(0)->getId()<<std::endl;
	}
}

BlockCompositeModel* GameState::recusiveAdd(BlockCompositeModel* &block, satap::typeBloc t){

	//std::cout << "Type int " << block->getType() <<std::endl;
	//std::cout << "Type add " << t <<std::endl;
	std::shared_ptr<Bloc> bloc_ptr;

	if(isUnaryBlock(block->getType())){
		//std::cout << "___________" << t <<std::endl;
		if(isBaseFunctionBlock(block->getType())){ //Si la fonction est composable et donc peut avoir 1 parametre
			std::cout << " " << t <<std::endl;
			//BinaryModel* btmp = dynamic_cast<BinaryModel*>(block);

			/*if(btmp->getOperand()==nullptr){//Si notre operateur n'a pas d'elements a l'interrieur alors
				if(isUnaryBlock(t)){ //Si t est soit un input soit un NOT(n) soit un ...
					std::cout << "___________" << t <<std::endl;

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
				mBlocsContainer[mLi].pack(bloc_ptr);
				mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
				// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

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
					mBlocsContainer[mLi].pack(bloc_ptr);
					mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
					// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

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
		case VariableBlocType:
			isValide=true;
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
		case NotBlocType:
			isValide=true;
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
	}
	return isValide;
}



Bloc * GameState::factoryBlock(satap::typeBloc t){
	Bloc* b=NULL;
	if (t == VariableBlocType) {
		b = new VariableBloc(mContext);
		b->setSprite(mContext, Textures::VariableSpawner);
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

	return b;
}
