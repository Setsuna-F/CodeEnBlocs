#include "MenuState.hpp"
#include "Button.hpp"
#include "Utility.hpp"
#include "MusicPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(100, 300);
	playButton->setText("Play");
	playButton->setCallback([this] ()
	{
		requestStackPush(States::Game);
	});

	//auto hostPlayButton = std::make_shared<GUI::Button>(context);
	//hostPlayButton->setPosition(100, 350);
	//hostPlayButton->setText("Host");
	//hostPlayButton->setCallback([this] ()
	//{
	//	requestStackPop();
	//	requestStackPush(States::HostGame);
	//});

	//auto joinPlayButton = std::make_shared<GUI::Button>(context);
	//joinPlayButton->setPosition(100, 400);
	//joinPlayButton->setText("Join");
	//joinPlayButton->setCallback([this] ()
	//{
	//	requestStackPop();
	//	requestStackPush(States::JoinGame);
	//});

	auto settingsButton = std::make_shared<GUI::Button>(context);
	settingsButton->setPosition(100, 400);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this] ()
	{
		requestStackPush(States::Settings);
	});

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(100, 500);
	exitButton->setText("Exit");
	exitButton->setCallback([this] ()
	{
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	//mGUIContainer.pack(hostPlayButton);
	//mGUIContainer.pack(joinPlayButton);
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
