#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <gui/Component.hpp>
#include <gui/ResourceIdentifiers.hpp>
#include <gui/State.hpp>
#include <gui/ResourceHolder.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


class SoundPlayer;

namespace satap
{

	class Bloc : public GUI::Component
	{
	public:
		typedef std::shared_ptr<Bloc>		Ptr;
		typedef std::function<void()>		Callback;

		enum Type
		{
			Normal,
			Selected,
			Pressed,
			ButtonCount
		};


	public:
		Bloc(State::Context context);

		void					setCallback(Callback callback);
		void					setText(const std::string& text);
		void					setToggle(bool flag);

		virtual bool			isSelectable() const;
		virtual void			select();
		virtual void			deselect();

		virtual void			activate();
		virtual void			deactivate();

		virtual void			handleEvent(const sf::Event& event);


	private:
		virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void					changeTexture(Type buttonType);


	private:
		Callback				mCallback;
		sf::Sprite				mSprite;
		sf::Text				mText;
		bool					mIsToggle;
		SoundPlayer&			mSounds;
	};

}

#endif // BOOK_BUTTON_HPP
