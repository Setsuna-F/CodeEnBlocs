#include "LoseState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


LoseState::LoseState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite(context.textures->get(Textures::Lose))
{
	centerOrigin(mBackgroundSprite);
	mBackgroundSprite.setPosition(context.window->getSize().x / 2, context.window->getSize().y / 2);
}
void LoseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
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
