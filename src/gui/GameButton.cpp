#include "GameButton.hpp"
#include "Utility.hpp"
#include "SoundPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>

using namespace GUI;

GameButton::GameButton(State::Context context)
	: mCallback()
	, mSprite(context.textures->get(Textures::Buttons))
	, mText("", context.fonts->get(Fonts::Main), 16)
	, mIsToggle(false)
	, mSounds(*context.sounds)
	, mContext(context)
{
	changeTexture(Normal);

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void GameButton::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void GameButton::setText(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}

void GameButton::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool GameButton::isSelectable() const
{
    return true;
}

void GameButton::select()
{
	Component::select();

	changeTexture(Selected);
}

void GameButton::deselect()
{
	Component::deselect();

	changeTexture(Normal);
}

void GameButton::activate()
{
	Component::activate();

    // If we are toggle then we should show that the button is pressed and thus "toggled".
	if (mIsToggle)
		changeTexture(Pressed);

	if (mCallback)
		mCallback();

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
	if (!mIsToggle)
		deactivate();

	mSounds.play(SoundEffect::Button);
}

void GameButton::deactivate()
{
	Component::deactivate();

	if (mIsToggle)
	{
        // Reset texture to right one depending on if we are selected or not.
		if (isSelected())
			changeTexture(Selected);
		else
			changeTexture(Normal);
	}
	else
		changeTexture(Selected);
}

void GameButton::handleEvent(const sf::Event& event)
{
	sf::IntRect r(getPosition().x, getPosition().y, 56, 56);
	if (event.type == sf::Event::MouseMoved)
	{
		if (r.contains(event.mouseMove.x, event.mouseMove.y) && !isSelected()) {
			select();
		}			
	}
	else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && r.contains(event.mouseButton.x, event.mouseButton.y))
	{
		changeTexture(Pressed);
	}
	else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
	{
		changeTexture(Selected);
		if (r.contains(event.mouseButton.x, event.mouseButton.y))
			activate();
	}
	else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
	{
		changeTexture(Pressed);
	}
}

void GameButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
	target.draw(mText, states);
}

void GameButton::changeTexture(Type buttonType)
{
	if (buttonType == Normal) {
		sf::IntRect textureRect(0, 0, 56, 56);
		mSprite.setTextureRect(textureRect);
	} else if (buttonType == Pressed || buttonType == Selected) {
		sf::IntRect textureRect(0, 56, 56, 56);
		mSprite.setTextureRect(textureRect);
	} else {
		sf::IntRect textureRect(0, 0, 56, 56);
		mSprite.setTextureRect(textureRect);
	}
}

void GameButton::scale(float scaleX, float scaleY)
{
	mSprite.scale(scaleX, scaleY);
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(mSprite.getScale().x * bounds.width / 2.f, mSprite.getScale().y * bounds.height / 2.f);
}

void GameButton::setSprite(State::Context c, Textures::ID id) {
	mSprite = sf::Sprite(c.textures->get(id));
	changeTexture(Normal);
}


