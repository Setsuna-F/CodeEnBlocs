#include "LoseState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


LoseState::LoseState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite(context.textures->get(Textures::Lose))
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::WinBackground));
	centerOrigin(mBackgroundSprite);
	mBackgroundSprite.setPosition(context.window->getSize().x / 2, context.window->getSize().y / 2);

	mStarsSprite.setTexture(context.textures->get(Textures::Lose));
	centerOrigin(mStarsSprite);
	mStarsSprite.setPosition(context.window->getSize().x / 2, context.window->getSize().y / 2);

	mBravoText.setFont(context.fonts->get(Fonts::Main));
	mBravoText.setString("Dommage !");
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

void LoseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	window.draw(mStarsSprite);
	window.draw(mBravoText);
	window.draw(mLevelText);
	window.draw(mBlocsText);
}

bool LoseState::update(sf::Time dt)
{
	return true;
}

bool LoseState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseButtonReleased)
	{
		requestStackPop();
	}

	return false;
}

