#include "gui/GameState.hpp"
#include "gui/Button.hpp"
#include "blocs/Bloc.hpp"
#include "blocs/variableBloc.hpp"
#include "blocs/addBloc.hpp"
#include "blocs/inputBloc.hpp"
#include "blocs/outputBloc.hpp"
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
	// TODO déplacer ça dans panel de choix de niveau
	GameModel game;
	game.loadLevel(*context.numLevel);

	mCurrentLevel = game.getCurrentLevel();
	std::cout << mCurrentLevel->getName() << std::endl;
	std::cout << mCurrentLevel->getDescription() << std::endl;

	/////////// States Buttons ///////////

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(10, 10);
	exitButton->setText("Exit");
	exitButton->setCallback([this]() {
		requestStackPop();
	});
	mButtonsContainer.pack(exitButton);

	auto settingsButton = std::make_shared<GUI::Button>(context);
	settingsButton->setPosition(170, 10);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this]() { 
		requestStackPush(States::Settings);
	});
	mButtonsContainer.pack(settingsButton);

	auto ennonceButton = std::make_shared<GUI::Button>(context);
	ennonceButton->setPosition(330, 10);
	ennonceButton->setText("Ennonce");
	ennonceButton->setCallback([this]() {
		// TODO ajouter un State Enoncé
	});
	mButtonsContainer.pack(ennonceButton);

	/////////// Actions Buttons ///////////

	auto resetAction = std::make_shared<GUI::Button>(context);
	resetAction->setPosition(200, 600);
	resetAction->setText("Reset");
	resetAction->setCallback([this]() {
		resetCode();
	});
	mButtonsContainer.pack(resetAction);

	auto loopAction = std::make_shared<GUI::Button>(context);
	loopAction->setPosition(400, 600);
	loopAction->setText("Loop");
	loopAction->setCallback([this]() {
		toggleLoop();
	});
	mButtonsContainer.pack(loopAction);

	auto startAction = std::make_shared<GUI::Button>(context);
	startAction->setPosition(600, 600);
	startAction->setText("Start");
	startAction->setCallback([this]() {
		startExecute();
	});
	mButtonsContainer.pack(startAction);

	/////////// Spawners Buttons ///////////

	auto inputSpawner = std::make_shared<GUI::Button>(context);
	inputSpawner->setPosition(1000, 100);
	inputSpawner->setText("Input");
	inputSpawner->setCallback([this]() {
		addBloc<satap::InputBloc>();
	});
	mButtonsContainer.pack(inputSpawner);

	auto outputSpawner = std::make_shared<GUI::Button>(context);
	outputSpawner->setPosition(1000, 220);
	outputSpawner->setText("Output");
	outputSpawner->setCallback([this]() {
		addBloc<satap::OutputBloc>();
	});
	mButtonsContainer.pack(outputSpawner);

	auto addSpawner = std::make_shared<GUI::Button>(context);
	addSpawner->setPosition(1000, 340);
	addSpawner->setText("+");
	addSpawner->setCallback([this]() {
		addBloc<satap::AddBloc>();
	});
	mButtonsContainer.pack(addSpawner);

	auto varSpawner = std::make_shared<GUI::Button>(context);
	varSpawner->setPosition(1000, 460);
	varSpawner->setText("Var");
	varSpawner->setCallback([this]() {
		addBloc<satap::VariableBloc>();
	});
	mButtonsContainer.pack(varSpawner);

	auto affectationSpawner = std::make_shared<GUI::Button>(context);
	affectationSpawner->setPosition(1000, 580);
	affectationSpawner->setText("<-");
	affectationSpawner->setCallback([this]() {
		std::cout << "<-" << std::endl;
		// TODO 
	});
	mButtonsContainer.pack(affectationSpawner);

	// Test

}

void GameState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.clear();

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

template<class T>
void GameState::addBloc()
{
	std::cout << "Ajout d'un bloc " << std::endl;
	auto b = std::make_shared<T>(mContext);
	b->setPosition(200, 300);
	b->setCallback([this]() { });
	mBlocsContainer.pack(b);
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
