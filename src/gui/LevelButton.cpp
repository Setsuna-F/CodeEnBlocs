#include "LevelButton.hpp"
#include "Utility.hpp"
#include "SoundPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>
#include <cmath>

namespace GUI
{

LevelButton::LevelButton(State::Context context)
: mCallback()
, mSprite(context.textures->get(Textures::LevelManagerButtonLock))
, mText("", context.fonts->get(Fonts::Main), 40)
, mIsToggle(false)
, mSounds(*context.sounds)
, mContext(context)
, mSoundPlayed(SoundEffect::Button)
, mTexture(Textures::LevelManagerButtonLock)
{
	changeTexture(Normal);
	mText.setFillColor(sf::Color::Black);
	scale(0.55f, 0.5f);
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width * 0.5f, bounds.height * 0.7f);

	srand(time(NULL));
	mSoundPlayed = static_cast<SoundEffect::ID>(rand() % 9 + SoundEffect::Pencil1);


	setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void LevelButton::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void LevelButton::setText(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}

void LevelButton::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool LevelButton::isSelectable() const
{
    return true;
}

void LevelButton::select()
{
	Component::select();

	changeTexture(Selected);
}

void LevelButton::deselect()
{
	Component::deselect();

	changeTexture(Normal);
}

void LevelButton::activate()
{
	Component::activate();

	if(mSoundPlayed != SoundEffect::NoSound && mTexture != Textures::LevelManagerButtonLock)
		mSounds.play(mSoundPlayed);

    // If we are toggle then we should show that the button is pressed and thus "toggled".
	if (mIsToggle)
		changeTexture(Pressed);

	if (mCallback && mTexture != Textures::LevelManagerButtonLock)
		mCallback();

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
	if (!mIsToggle)
		deactivate();
}

void LevelButton::deactivate()
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

void LevelButton::handleEvent(const sf::Event& event)
{
	sf::IntRect bounds = mSprite.getTextureRect();
	sf::IntRect r(getPosition().x - bounds.width * getScale().x / 2.f, getPosition().y - bounds.height * getScale().y / 2.f, bounds.width*getScale().x, bounds.height*getScale().y);
	if (event.type == sf::Event::MouseMoved && r.contains(event.mouseMove.x, event.mouseMove.y) && !isSelected())
	{
		select();
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
	else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space))
	{
		changeTexture(Pressed);
	}
}

void LevelButton::setSound(SoundEffect::ID s)
{
	mSoundPlayed = s;
}

void LevelButton::setTexture(Textures::ID t)
{
	mTexture = t;
	mSprite.setTexture(mContext.textures->get(t), true);
	//sf::FloatRect bounds = mSprite.getLocalBounds();
	//mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void LevelButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
	if(mTexture != Textures::LevelManagerButtonLock)
		target.draw(mText, states);
}

void LevelButton::changeTexture(Type buttonType)
{
	//sf::IntRect textureRect(0, 50*buttonType, 200, 50);
	//mSprite.setTextureRect(textureRect);
}

}
