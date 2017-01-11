﻿#ifdef __APPLESOKA__
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
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::GameBackgroud));

	// TODO déplacer ça dans panel de choix de niveau
	GameModel game;
	game.loadLevel(*context.numLevel);

	mCurrentLevel = game.getCurrentLevel();
	std::cout << mCurrentLevel->getName() << std::endl;
	std::cout << mCurrentLevel->getDescription() << std::endl;

	/////////// States Buttons ///////////

	auto exitButton = std::make_shared<GUI::GameButton>(context);
	exitButton->setPosition(10, 10);
	exitButton->setSprite(context, Textures::ExitButton);
	exitButton->setCallback([this]() {
		requestStackPop();
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
		// TODO ajouter un State Enoncé
	});
	mButtonsContainer.pack(ennonceButton);

	/////////// Actions Buttons ///////////

	auto resetAction = std::make_shared<GUI::GameButton>(context);
	resetAction->setPosition(250, 10);
	resetAction->setSprite(context, Textures::ResetButton);
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
}

bool GameState::update(sf::Time)
{
	return true;
}

bool GameState::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up) {
			mLi--;
			if (mLi < 0)
				mLi = 0;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}
		else if (event.key.code == sf::Keyboard::Down) {
			mLi++;
			if (mLi > 12)
				mLi = 12;
			mCol = getNbElementsOnLine(mLi);
			reloadPositionCurseur();
		}
		else if (event.key.code == sf::Keyboard::BackSpace) {
			effacerLigne(mLi);
			mCol = 0;
		}

	} else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseMoved) {
		mButtonsContainer.handleEvent(event);
	}
	else if (event.type == sf::Event::KeyReleased)
	{

	}
	return false;
}

Bloc * GameState::addBloc(satap::typeBloc t)
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
	// TODO à retirer
	std::cout << score << std::endl;
	if (score > 0)
		requestStackPush(States::Win);
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
	int nbElements = mCurrentLevel->getCodePage()->getNbBlock(ligne);
	std::cout << "ligne " << ligne << " : " << nbElements << std::endl;
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
//return ;
	// mCurrentLevel->getCodePage()->addBlock(assign);
	std::shared_ptr<Bloc> bloc_ptr;




	std::cerr << "1- " << __FUNCTION__ <<std::endl;
	if(mCurrentLevel->getCodePage()->getNbBlock(0) == 0){ //Si la ligne est vide alors
		std::cerr << "2- " << __FUNCTION__ <<std::endl;
		if(isValideBlock(t)){
			std::cerr << "3- " << __FUNCTION__ <<std::endl;
			//std::cerr << "ERROR: INTERNE " << __FUNCTION__ <<std::endl;
			Bloc * bloc_tmp = factoryBlock(t);
			//bloc_tmp->setType(t);
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

				dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setFirstOperand(dynamic_cast<BlockModel*>(bloc_tmp));
				dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setSecondOperand(nullptr);
				//dynamic_cast<AssignmentBloc*>(bloc_assign_tmp)->setSecondOperand(nullptr);
				mCurrentLevel->getCodePage()->addBlock(dynamic_cast<BlockModel*>(bloc_assign_tmp), AssignementBlocType);
			}
			else{
				std::cerr << "5- " << __FUNCTION__ <<std::endl;
				mCurrentLevel->getCodePage()->addBlock(dynamic_cast<BlockModel*>(bloc_tmp), t);
			}
		}
		else{
			std::cerr << "6- " << __FUNCTION__ <<std::endl;
			std::cerr << "ERROR: " << __FUNCTION__ <<" Le type n'est pas conforme. "<<std::endl;
		}
	}else{
		if(mCurrentLevel->getCodePage()->getBlockByIndex(0)->getType() == AssignementBlocType){
			std::cerr << "7- " << __FUNCTION__ <<std::endl;
			AssignmentModel* assignBlock = dynamic_cast<AssignmentModel*>(mCurrentLevel->getCodePage()->getBlockByIndex(0));
			if(assignBlock->getSecondOperand()==nullptr){
				std::cerr << "8- " << __FUNCTION__ <<std::endl;
			 	if(!isBooleanBlock(t)){
					std::cerr << "9- " << __FUNCTION__ <<std::endl;
					if(!isValideBlock(t) && !isFunctionBlock(t)){
						std::cerr << "10- " << __FUNCTION__ <<std::endl;
						std::cerr << "TRUE IF " << __FUNCTION__ <<std::endl;
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
				std::cout << "11- [ getType- "<< assignBlock->getType() << " ] -11" << __FUNCTION__ <<std::endl;
				std::cout << "11- [ getType- "<< t << " ] -11" << __FUNCTION__ <<std::endl;
				std::cout << "11- [ getType- "<< mCurrentLevel->getCodePage()->getBlockByIndex(0)->getType() << " ] -11" << __FUNCTION__ <<std::endl;

			//	if(( (isBinaryBlock(assignBlock->getSecondOperand()->getType()) && !isBinaryBlock(t))
			//	  || (!isBinaryBlock(assignBlock->getSecondOperand()->getType()) && isBinaryBlock(t)))
			//	  && (assignBlock->getSecondOperand()->getType()!=t) && (t != AssignementBlocType))
				  {
					std::cerr << "12- " << __FUNCTION__ <<std::endl;

					std::cerr << "FALSE IF "<< t << __FUNCTION__ <<std::endl;
					BlockCompositeModel * blockmodel_tmp = assignBlock->getSecondOperand();
/*					std::cout << "Type int (avant recusive)" << blockmodel_tmp->getType() <<std::endl;
					recusiveAdd(blockmodel_tmp, t);
					std::cout << "Type int (apres recusive)" << blockmodel_tmp->getType() <<std::endl;
*/
					std::cout << "Type int (avant recusive)" << blockmodel_tmp->getType() <<std::endl;
					assignBlock->setSecondOperand(recusiveAdd(blockmodel_tmp, t));
					std::cout << "Type int (apres recusive)" << blockmodel_tmp->getType() <<std::endl;

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
		else if(mCurrentLevel->getCodePage()->getBlockByIndex(0)->getType() == IfBlocType){
			std::cerr << "14- " << __FUNCTION__ <<std::endl;
			std::cerr << "Type IfBlocType " << __FUNCTION__ <<std::endl;
		}
		//std::cerr << "LIGNE NON VIDE : " << __FUNCTION__ <<mCurrentLevel->getCodePage()->getBlockByIndex(0)->getId()<<std::endl;
	}
}

BlockCompositeModel* GameState::recusiveAdd(BlockCompositeModel* &block, satap::typeBloc t){

	std::cout << "Type int " << block->getType() <<std::endl;
	std::cout << "Type add " << t <<std::endl;
	std::shared_ptr<Bloc> bloc_ptr;

	if(isUnaryBlock(block->getType())){
		std::cout << "___________" << t <<std::endl;
		if(isBaseFunctionBlock(block->getType())){ //Si la fonction est composable et donc peut avoir 1 parametre
			std::cout << "___________" << t <<std::endl;
			BinaryModel* btmp = dynamic_cast<BinaryModel*>(block);

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
			std::cout << "TYPE INPUT PAR EXEMPLE" <<std::endl;
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

				std::cout << "Type + " << block->getType() <<std::endl;
				//std::cout << "Type ++ " << binblock->getSecondOperand()->getType() <<std::endl;

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
					std::cout << "Type ++ " << binblock->getSecondOperand()->getType() <<std::endl;

					//compoblock->setOperand(btmp);//Je met le precedent bloc dans le nouveau bloc
					//block = compoblock;//Et je remplace le bloc par le nouveau
				}
			}
		}
	}








/*
	std::shared_ptr<Bloc> bloc_ptr;
	std::cerr << "AvantIF " << __FUNCTION__ <<std::endl;
	if(( (isBinaryBlock(block->getType()) && !isBinaryBlock(t))
	  || (!isBinaryBlock(block->getType()) && isBinaryBlock(t)))){
	//if(/ *!(isFunctionBlock(t) &&* / (block->getType() != t) / *&& isUnaryBlock(block->getType())* /){ //Si le bloc courant n'est pas un bloc de fonction et donc s'il n'a aucun element a integrer.
		std::cerr << "PremierIF " << __FUNCTION__ <<std::endl;
		BlockCompositeModel* btmp = block; //On copie l'objet du bloc principal
		Bloc * binary_block= factoryBlock(t); // On crée le nouveau type
		if(isBinaryBlock(t)){ //Si le type a ajouter est binaire alors
			std::pair<int, int> coordBloc = getCoordonnees(mLi, mCol);
			binary_block->setPosition(coordBloc.first, coordBloc.second);
			bloc_ptr = std::shared_ptr<Bloc>(binary_block);
			mBlocsContainer[mLi].pack(bloc_ptr);
			mCol++; // TODO Trouver un autre moyen de mettre à jour mCol
			// TODO linker correctement le bloc créé avec les blocs existant de la même ligne. Mettre à jour (dans certains cas), le bloc à exécuter en premier (dans le blockList de mCurrentLevel->getCodePage()->...)

			BinaryModel* binblock = dynamic_cast<BinaryModel*>(binary_block);
			binblock->setType(block->getType());
			binblock->setFirstOperand(btmp);//Je met le precedent bloc dans le nouveau bloc
			block = binblock;//Et je remplace le bloc par le nouveau
		}
	}*/
	return block;
}

bool GameState::isValideBlock(satap::typeBloc t){
	bool isValide=false;
	//std::cerr << "Avant VALIDE "<< t << " isVal="<<(isValide?"true":"false") << __FUNCTION__ <<std::endl;
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
	//std::cerr << "Apres VALIDE "<< t << " isVal="<<(isValide?"true ":"false ") << __FUNCTION__ <<std::endl;
	return isValide;
}


bool GameState::isBinaryBlock(satap::typeBloc t){
	bool isValide=false;
	//std::cerr << "Avant VALIDE "<< t << " isVal="<<(isValide?"true ":"false ") << __FUNCTION__ <<std::endl;
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
	//std::cerr << "Apres VALIDE "<< t << " isVal="<<(isValide?"true ":"false ") << __FUNCTION__ <<std::endl;

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
