#ifndef BOOK_WINSTATE_HPP
#define BOOK_WINSTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class WinState : public State
{
	public:
		WinState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite, mStarsSprite;
		sf::Text			mText, mBravoText, mLevelText, mBlocsText;

		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // BOOK_WINSTATE_HPP
