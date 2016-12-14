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
	mIdTutoImg = Textures::TutorialBegin + 1;
	mBackgroundSprite.setTexture(context.textures->get(static_cast<Textures::ID>(mIdTutoImg)));
}

void TutorialState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
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

	if (mIdTutoImg == Textures::TutorialEnd)
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

	return false;
}

void TutorialState::nextImg()
{
	if (mIdTutoImg < Textures::TutorialEnd)
		mIdTutoImg++;
}

void TutorialState::previousImg()
{
	if (mIdTutoImg > Textures::TutorialBegin + 1)
		mIdTutoImg--;
}
