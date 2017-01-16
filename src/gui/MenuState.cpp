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
, mShowConfirmationExit(false)
, mExiting(false)
, mButtonsContainerConfirmationExit()
, mDelayExit(sf::Time::Zero)
{
	sf::Texture& texture = context.textures->get(Textures::MenuSettingsBackgroud);
	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(150, 250);
	playButton->setText("Play");
	playButton->setSound(SoundEffect::Pages);
	playButton->setCallback([this] ()
	{
		if (*getContext().tutorial || getContext().scores->at(0) != -1)
		{
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
	exitButton->setSound(SoundEffect::Pages);
	exitButton->setCallback([this] ()
	{
		mShowConfirmationExit = true;
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);

	// Play menu theme
	//context.music->play(Music::MenuTheme);

	// Confirmation exit game
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u window_size = window.getSize();

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
	yesConfirmationExitButton->setSound(SoundEffect::ClosingBook);
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
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.clear();
	//window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);

	if (mShowConfirmationExit) {
		window.draw(mRectAlphaBackground);
		window.draw(mSpriteConfirmationExit);
		window.draw(mTextConfirmationExit);
		window.draw(mButtonsContainerConfirmationExit);
	}

	if (mExiting)
	{
		mRectAlphaBackground.setFillColor(mRectAlphaBackground.getFillColor() + sf::Color(0, 0, 0, 2));
		window.draw(mRectAlphaBackground);
	}
}

bool MenuState::update(sf::Time dt)
{
	if (mExiting)
	{
		getContext().music->setVolume(getContext().music->getVolume()*0.97f);
		mDelayExit += dt;
		if (mDelayExit > sf::seconds(3.0f))
		{
			requestStackPop();
		}
	}
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	if (mShowConfirmationExit)
	{
		mButtonsContainerConfirmationExit.handleEvent(event);
		return false;
	}
	mGUIContainer.handleEvent(event);
	return false;
}
