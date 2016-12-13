#include "gui/GameState.hpp"
#include "gui/Button.hpp"
#include "gui/GameButton.hpp"
#include "gui/SpawnerButton.hpp"
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
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::GameBackgroud));

	// TODO déplacer ça dans panel de choix de niveau
	GameModel game;
	game.loadLevel(0);

	mCurrentLevel = game.getCurrentLevel();
	std::cout << mCurrentLevel->getName() << std::endl;
	std::cout << mCurrentLevel->getDescription() << std::endl;

	/////////// States Buttons ///////////

	auto exitButton = std::make_shared<GUI::GameButton>(context);
	exitButton->setPosition(10, 10);
	exitButton->setSprite(context, Textures::ExitButton);
	exitButton->setCallback([this]() {
		requestStackPush(States::Menu);
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

	// Test
	InputBloc* in = ((InputBloc*) addBloc(InputBlocType));
	OutputBloc* out = ((OutputBloc*) addBloc(OutputBlocType));
	//VariableBloc* var = ((VariableBloc*) addBloc(VariableBlocType));
	AssignmentBloc* assign = ((AssignmentBloc*) addBloc(AssignementBlocType));
	//AssignmentBloc* assignOutVar = ((AssignmentBloc*) addBloc(AssignementBlocType));

	//assignVarIn->setFirstOperand(var);
	assign->setFirstOperand(out);

	//assignOutVar->setFirstOperand(out);
	assign->setSecondOperand(in);

	mCurrentLevel->getCodePage()->addBlock(assign);
	//mCurrentLevel->getCodePage()->addBlock(assignOutVar);
}

void GameState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.clear();

	window.draw(mBackgroundSprite);

	window.draw(mButtonsContainer);
	window.draw(mBlocsContainer);
}

bool GameState::update(sf::Time)
{
	return true;
}

bool GameState::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		
	} else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseMoved) {
		mButtonsContainer.handleEvent(event);
	}
	return false;
}

Bloc * GameState::addBloc(satap::typeBloc t)
{
	int posX = 540, posY = 70;

	Bloc* b;
	std::shared_ptr<Bloc> bl;

	if (t == VariableBlocType) {
		b = new VariableBloc(mContext);
		std::cout << "Ajout d'un bloc de type var" << std::endl;
	}
	else if (t == AssignementBlocType) {
		b = new AssignmentBloc(mContext);
		std::cout << "Ajout d'un bloc de type <-" << std::endl;
	}
	else if (t == InputBlocType) {
		b = new InputBloc(mContext, mCurrentLevel->getWorkspace()->getInputList());
		std::cout << "Ajout d'un bloc de type In" << std::endl;
	}
	else if (t == OutputBlocType) {
		b = new OutputBloc(mContext, mCurrentLevel->getWorkspace()->getOutputList());
		std::cout << "Ajout d'un bloc de type Out" << std::endl;
	}
	else if (t == AddBlocType) {
		b = new AddBloc(mContext);
		std::cout << "Ajout d'un bloc de type +" << std::endl;
	}

	b->setPosition(posX, posY);
	bl = std::shared_ptr<Bloc>(b);
	mBlocsContainer.pack(bl);
	return b;
}

void GameState::resetCode() {
	mCurrentLevel->getCodePage()->flush();
	mBlocsContainer.flush();
}

void GameState::toggleLoop() {

}

void GameState::startExecute() {
	std::cout << mCurrentLevel->validate() << std::endl;
}

