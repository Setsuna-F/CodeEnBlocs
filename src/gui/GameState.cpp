#include "GameState.hpp"
#include <gui/Button.hpp>
#include <gui/blocs/Bloc.hpp>
#include <gui/blocs/variableBloc.hpp>
#include <gui/blocs/addBloc.hpp>
#include <gui/blocs/inputBloc.hpp>
#include <gui/blocs/outputBloc.hpp>
#include <gui/Utility.hpp>
#include <gui/MusicPlayer.hpp>
#include <gui/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
	, mGUIBlocsContainer()
{
	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(10, 10);
	exitButton->setText("Exit");
	exitButton->setCallback([this]()
	{
		requestStackPop();
	});

	auto inputBloc = std::make_shared<satap::InputBloc>(context);
	inputBloc->setPosition(100, 300);
	inputBloc->setText("Input");
	inputBloc->setCallback([this]() {});

	auto bloc1 = std::make_shared<satap::VariableBloc>(context);
	bloc1->setPosition(340, 300);
	bloc1->setText("V1");
	bloc1->setCallback([this]() { });

	auto bloc2 = std::make_shared<satap::AddBloc>(context);
	bloc2->setPosition(580, 300);
	bloc2->setText("Add");
	bloc2->setCallback([this]() { });

	auto bloc3 = std::make_shared<satap::VariableBloc>(context);
	bloc3->setPosition(820, 300);
	bloc3->setText("V2");
	bloc3->setCallback([this]() { });

	auto outputBloc = std::make_shared<satap::OutputBloc>(context);
	outputBloc->setPosition(1060, 300);
	outputBloc->setText("Input");
	outputBloc->setCallback([this]() {});

	mGUIContainer.pack(exitButton);

	mGUIBlocsContainer.pack(inputBloc);
	mGUIBlocsContainer.pack(bloc1);
	mGUIBlocsContainer.pack(bloc2);
	mGUIBlocsContainer.pack(bloc3);
	mGUIBlocsContainer.pack(outputBloc);

	// Play menu theme
	//context.music->play(Music::MenuTheme);
}

void GameState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mGUIContainer);
	window.draw(mGUIBlocsContainer);
}

bool GameState::update(sf::Time)
{
	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;
}
