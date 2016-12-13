#include <gui/Blocs/Bloc.hpp>
#include <gui/Utility.hpp>
#include <gui/SoundPlayer.hpp>
#include <gui/ResourceHolder.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


namespace satap
{

	Bloc::Bloc(State::Context context)
		: mCallback()
		, mSprite(context.textures->get(Textures::Buttons))
		, mText("", context.fonts->get(Fonts::Main), 16)
		, mIsToggle(false)
		, mSounds(*context.sounds)
	{
		changeTexture(Normal);

		sf::FloatRect bounds = mSprite.getLocalBounds();
		mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
	}

	void Bloc::setCallback(Callback callback)
	{
		mCallback = std::move(callback);
	}

	void Bloc::setText(const std::string& text)
	{
		mText.setString(text);
		centerOrigin(mText);
	}

	void Bloc::setToggle(bool flag)
	{
		mIsToggle = flag;
	}

	bool Bloc::isSelectable() const
	{
		return true;
	}

	void Bloc::select()
	{
		Component::select();

		changeTexture(Selected);
	}

	void Bloc::deselect()
	{
		Component::deselect();

		changeTexture(Normal);
	}

	void Bloc::activate()
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

	void Bloc::deactivate()
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
	}

	void Bloc::handleEvent(const sf::Event&)
	{
	}

	void Bloc::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(mSprite, states);
		target.draw(mText, states);
	}

	void Bloc::changeTexture(Type buttonType)
	{
		sf::IntRect textureRect(0, 50 * buttonType, 200, 50);
		mSprite.setTextureRect(textureRect);
	}

}
