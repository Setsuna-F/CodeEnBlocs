#ifndef BOOK_MENUSTATE_HPP
#define BOOK_MENUSTATE_HPP

#include "State.hpp"
#include "Container.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class MenuState : public State
{
	public:
								MenuState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);


	private:
		sf::Sprite				mBackgroundSprite;
		GUI::Container			mGUIContainer;

		sf::RectangleShape		mRectAlphaBackground;
		GUI::Container			mButtonsContainerConfirmationExit;
		sf::Sprite				mSpriteConfirmationExit;
		sf::Text				mTextConfirmationExit;
		bool					mShowConfirmationExit;
		bool					mExiting;
		sf::Time				mDelayExit;
};

#endif // BOOK_MENUSTATE_HPP
