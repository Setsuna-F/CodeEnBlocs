#include "GameState.hpp"
#include <gui/Button.hpp>
#include <gui/Utility.hpp>
#include <gui/MusicPlayer.hpp>
#include <gui/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
{
	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(100, 300);
	playButton->setText("GAME");
	playButton->setCallback([this]()
	{

	});

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(100, 500);
	exitButton->setText("Exit");
	exitButton->setCallback([this]()
	{
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(exitButton);

	// Play menu theme
	context.music->play(Music::MenuTheme);
}

void GameState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mGUIContainer);
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