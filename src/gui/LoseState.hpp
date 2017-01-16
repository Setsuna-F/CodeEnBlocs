#ifndef BOOK_LOSESTATE_HPP
#define BOOK_LOSESTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class LoseState : public State
{
	public:
							LoseState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite, mStarsSprite;
		sf::Text			mText, mBravoText, mLevelText, mBlocsText;

		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // BOOK_LOSESTATE_HPP
