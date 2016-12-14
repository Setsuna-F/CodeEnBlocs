#include "WinState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


WinState::WinState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite(context.textures->get(Textures::Win))
{
	centerOrigin(mBackgroundSprite);
	mBackgroundSprite.setPosition(context.window->getSize().x / 2, context.window->getSize().y / 2);
}

void WinState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
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
