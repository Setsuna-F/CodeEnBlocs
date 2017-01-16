#ifdef __APPLESOKA__
#include "Bloc.hpp"
#include "Utility.hpp"
#include "SoundPlayer.hpp"
#include "ResourceHolder.hpp"
#else
#include "gui/blocs/Bloc.hpp"
#include "gui/Utility.hpp"
#include "gui/SoundPlayer.hpp"
#include "gui/ResourceHolder.hpp"
#endif


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


namespace satap
{

	Bloc::Bloc(State::Context context, typeBloc typebloc)
		: mCallback()
		, mSprite(context.textures->get(Textures::Buttons))
		, mText("", context.fonts->get(Fonts::Main), 24)
		, mIsToggle(false)
		, mSounds(*context.sounds)
		, mTypeBlock(typebloc)
	{
		changeTexture(Normal);

		sf::FloatRect bounds = mSprite.getLocalBounds();
		mText.setFillColor(sf::Color::Black);
		mText.setPosition(bounds.width * 0.7f, bounds.height * 0.5f);
	}

	void Bloc::setCallback(Callback callback) {
		mCallback = std::move(callback);
	}

	void Bloc::setText(const std::string& text) {
		mText.setString(text);
		centerOrigin(mText);
	}

	void Bloc::setToggle(bool flag) {
		mIsToggle = flag;
	}

	bool Bloc::isSelectable() const {
		return false;
	}

	void Bloc::select() {}

	void Bloc::deselect() {}

	void Bloc::activate() {}

	void Bloc::deactivate() {}

	void Bloc::handleEvent(const sf::Event&) {}

	void Bloc::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(mSprite, states);
		target.draw(mText, states);
	}

	void Bloc::changeTexture(Type buttonType) {
		sf::IntRect textureRect(0, 0, 81, 31);
		mSprite.setTextureRect(textureRect);
	}

	void Bloc::setSprite(State::Context c, Textures::ID id) {
		mSprite = sf::Sprite(c.textures->get(id));
		changeTexture(Normal);
	}
}
