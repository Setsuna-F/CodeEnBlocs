#include "GameExitButton.hpp"
#include "Utility.hpp"
#include "SoundPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

using namespace GUI;

GameExitButton::GameExitButton(State::Context context)
	: GameButton(context)
{}


void GameExitButton::activate()
{
	Component::activate();

	mSounds.play(SoundEffect::WrinkledPaper);
	sf::Clock clock; // démarre le chrono
	//while (clock.getElapsedTime() < sf::seconds(4.75f))
	//{}
    // If we are toggle then we should show that the button is pressed and thus "toggled".
	if (mIsToggle)
		changeTexture(Pressed);

	if (mCallback)
		mCallback();

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
	if (!mIsToggle)
		deactivate();
}


