#include "WinState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>


WinState::WinState(StateStack& stack, Context context)
: State(stack, context)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::WinBackground));
	centerOrigin(mBackgroundSprite);
	mBackgroundSprite.setPosition(context.window->getSize().x / 2, context.window->getSize().y / 2);

	if (*context.score == 1) {
		mStarsSprite.setTexture(context.textures->get(Textures::Win1));
	} else if (*context.score == 2) {
		mStarsSprite.setTexture(context.textures->get(Textures::Win2));
	} else if (*context.score == 3) {
		mStarsSprite.setTexture(context.textures->get(Textures::Win3));
	}
	centerOrigin(mStarsSprite);
	mStarsSprite.setPosition(context.window->getSize().x / 2, context.window->getSize().y / 2);

	mBravoText.setFont(context.fonts->get(Fonts::Main));
	mBravoText.setString("Bravo !");
	mBravoText.setColor(sf::Color::White);
	centerOrigin(mBravoText);
	mBravoText.setPosition(sf::Vector2f(context.window->getSize().x / 2, context.window->getSize().y * 0.3));

	mLevelText.setFont(context.fonts->get(Fonts::Main));
	mLevelText.setString(*context.nameLevel);
	mLevelText.setColor(sf::Color::White);
	centerOrigin(mLevelText);
	mLevelText.setPosition(sf::Vector2f(context.window->getSize().x / 2, context.window->getSize().y * 0.55));

	mBlocsText.setFont(context.fonts->get(Fonts::Main));
	mBlocsText.setString("Blocs utilisés : " + std::to_string(*context.nbBlocsUsed));
	mBlocsText.setColor(sf::Color::White);
	centerOrigin(mBlocsText);
	mBlocsText.setPosition(sf::Vector2f(context.window->getSize().x / 2, context.window->getSize().y * 0.65));
}

void WinState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	window.draw(mStarsSprite);
	window.draw(mBravoText);
	window.draw(mLevelText);
	window.draw(mBlocsText);
}

bool WinState::update(sf::Time dt)
{
	return true;
}

bool WinState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseButtonReleased)
	{
		requestStackPop();
		requestStackPop();
	}

	return false;
}
