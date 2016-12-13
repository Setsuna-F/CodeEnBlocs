#ifndef BOOK_TUTORIALSTATE_HPP
#define BOOK_TUTORIALSTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class TutorialState : public State
{
	public:
							TutorialState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;

		sf::Time			mTextEffectTime;

		int					mIdTutoImg;

		void				nextImg();
		void				previousImg();
};

#endif // BOOK_TUTORIALSTATE_HPP
