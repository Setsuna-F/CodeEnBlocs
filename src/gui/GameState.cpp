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

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

using namespace satap;

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mButtonsContainer()
	, mBlocsContainer()
	, mContext(context)
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
		addBloc(InputBlocType);
	});
	mButtonsContainer.pack(inputSpawner);

	auto outputSpawner = std::make_shared<GUI::SpawnerButton>(context);
	outputSpawner->setPosition(1120, 100);
	outputSpawner->setSprite(context, Textures::OutputSpawner);
	outputSpawner->setCallback([this]() {
		addBloc(OutputBlocType);
	});
	mButtonsContainer.pack(outputSpawner);

	auto addSpawner = std::make_shared<GUI::SpawnerButton>(context);
	addSpawner->setPosition(1020, 200);
	addSpawner->setSprite(context, Textures::AddSpawner);
	addSpawner->setCallback([this]() {		
		addBloc(AddBlocType);
	});
	mButtonsContainer.pack(addSpawner);

	auto varSpawner = std::make_shared<GUI::SpawnerButton>(context);
	varSpawner->setPosition(1020, 150);
	varSpawner->setSprite(context, Textures::VariableSpawner);
	varSpawner->setCallback([this]() {
		addBloc(VariableBlocType);
	});
	mButtonsContainer.pack(varSpawner);

	auto affectationSpawner = std::make_shared<GUI::SpawnerButton>(context);
	affectationSpawner->setPosition(1120, 150);
	affectationSpawner->setSprite(context, Textures::AssignmentSpawner);
	affectationSpawner->setCallback([this]() {
		addBloc(AssignementBlocType);
	});
	mButtonsContainer.pack(affectationSpawner);

	//mCurseur.setSprite(context, Textures::CurseurSprite);
	reloadPositionCurseur();
	

	// Test
	OutputBloc* out = ((OutputBloc*)addBloc(OutputBlocType));
	AssignmentBloc* assign = ((AssignmentBloc*) addBloc(AssignementBlocType));
	InputBloc* in = ((InputBloc*)addBloc(InputBlocType));

	assign->setFirstOperand(out);
	assign->setSecondOperand(in);

	mCurrentLevel->getCodePage()->addBlock(assign);
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
	Bloc* b;
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