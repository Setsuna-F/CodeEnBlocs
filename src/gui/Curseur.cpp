#include "Curseur.hpp"
#include "Utility.hpp"
#include "SoundPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>

namespace GUI
{

Curseur::Curseur(State::Context context)
: mCallback()
, mSprite(context.textures->get(Textures::CurseurSprite))
, mText("", context.fonts->get(Fonts::Main), 16)
, mIsToggle(false)
, mSounds(*context.sounds)
, mContext(context)
{
	changeTexture(Normal);

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void Curseur::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void Curseur::setText(const std::string& text)
{
	mText.setString(text);
	centerOrigin(mText);
}

void Curseur::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool Curseur::isSelectable() const
{
    return false;
}

void Curseur::select()
{
}

void Curseur::deselect()
{
}

void Curseur::activate()
{
}

void Curseur::deactivate()
{
}

void Curseur::handleEvent(const sf::Event& event)
{
}

void Curseur::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
	target.draw(mText, states);
}

void Curseur::changeTexture(Type buttonType)
{
	sf::IntRect textureRect(0, 0, 40, 40);
	mSprite.setTextureRect(textureRect);
}

void Curseur::scale(float scaleX, float scaleY)
{
	mSprite.scale(scaleX, scaleY);
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(mSprite.getScale().x * bounds.width / 2.f, mSprite.getScale().y * bounds.height / 2.f);
}

}
