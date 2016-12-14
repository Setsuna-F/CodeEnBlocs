#include "TutorialState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>


TutorialState::TutorialState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mTextEffectTime(sf::Time::Zero)
{
	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Félicitation ! Tu as fini le didacticiel !\n C'est parti pour le premier niveau.");
	mText.setColor(sf::Color::Black);
	centerOrigin(mText);
	mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));

	mIdTutoImg = Textures::TutorialBegin + 1;
	mBackgroundSprite.setTexture(context.textures->get(static_cast<Textures::ID>(mIdTutoImg)));
}

void TutorialState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	
	if (mIdTutoImg >= Textures::TutorialEnd)
		window.draw(mText);
}

bool TutorialState::update(sf::Time dt)
{
	return true;
}

bool TutorialState::handleEvent(const sf::Event& event)
{
	int saveMIdTutoImg = mIdTutoImg;
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Left)
			previousImg();
		else if (event.key.code == sf::Keyboard::Right)
			nextImg();
	}
	else if (event.type == sf::Event::MouseButtonReleased)
		nextImg();

	if (mIdTutoImg > Textures::TutorialEnd)
	{
		if (*getContext().tutorial)
			// TODO pop and push levelmanagerstate
			requestStackPop();
		else
		{
			// TODO Charger Level 0
			bool& tutorial = *getContext().tutorial;
			tutorial = true;
			*getContext().numLevel = 0;
			requestStackPop();
			requestStackPush(States::LevelManager);
			requestStackPush(States::Game);
		}
	}

	if (saveMIdTutoImg != mIdTutoImg && mIdTutoImg != Textures::TutorialEnd)
		mBackgroundSprite.setTexture(getContext().textures->get(static_cast<Textures::ID>(mIdTutoImg)));
	else if (saveMIdTutoImg != mIdTutoImg && mIdTutoImg >= Textures::TutorialEnd)
		mBackgroundSprite.setTexture(getContext().textures->get(Textures::Background));

	return false;
}

void TutorialState::nextImg()
{
	mIdTutoImg++;
}

void TutorialState::previousImg()
{
	if (mIdTutoImg > Textures::TutorialBegin + 1)
		mIdTutoImg--;
}
