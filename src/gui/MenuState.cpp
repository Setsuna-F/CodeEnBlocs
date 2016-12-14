#include "MenuState.hpp"
#include "Button.hpp"
#include "Utility.hpp"
#include "MusicPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>


MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(Textures::MenuSettingsBackgroud);
	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(150, 250);
	playButton->setText("Play");
	playButton->setCallback([this] ()
	{
		if (*getContext().tutorial)
		{
			// TODO chargement de l'arbre des niveaux
			std::cout << "TODO dans MenuState push LevelManagerState à la place de GameState" << std::endl;
			requestStackPush(States::LevelManager);
		}
		else
			requestStackPush(States::Tutorial);
	});

	auto settingsButton = std::make_shared<GUI::Button>(context);
	settingsButton->setPosition(150, 350);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this] ()
	{
		requestStackPush(States::Settings);
	});

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(150, 450);
	exitButton->setText("Exit");
	exitButton->setCallback([this] ()
	{
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);

	// Play menu theme
	context.music->play(Music::MenuTheme);
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.clear();
	//window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;
}
