#include "GameState.hpp"
#include <gui/Button.hpp>
#include <gui/Blocs/Bloc.hpp>
#include <gui/blocs/variableBloc.hpp>
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

	

	auto bloc1 = std::make_shared<satap::VariableBloc>(context);
	bloc1->setPosition(100, 200);
	bloc1->setText("VariableBloc1");
	bloc1->setCallback([this]()
	{

	});
	
	auto bloc2 = std::make_shared<satap::VariableBloc>(context);
	bloc2->setPosition(350, 200);
	bloc2->setText("VariableBloc2");
	bloc2->setCallback([this]()
	{

	});
	auto bloc3 = std::make_shared<satap::VariableBloc>(context);
	bloc3->setPosition(600, 200);
	bloc3->setText("VariableBloc3");
	bloc3->setCallback([this]()
	{

	});

	mGUIContainer.pack(exitButton);

	mGUIBlocsContainer.pack(bloc1);
	mGUIBlocsContainer.pack(bloc2);
	mGUIBlocsContainer.pack(bloc3);

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