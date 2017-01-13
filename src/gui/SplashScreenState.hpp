#ifndef BOOK_SPLASHSCREENSTATE_HPP
#define BOOK_SPLASHSCREENSTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>

// nom du logiciel, le nom de l'éditeur, le logo de l'éditeur ou du logiciel, les droits d'auteur associés au logiciel, la version
class SplashScreenState : public State
{
	public:
		SplashScreenState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Text			mAppName;
		sf::Text			mDescription;
		sf::Text			mEditor;
		sf::Text			mAuthors;

		sf::Time			mDelayDisplay;

		sf::Color			mColorTransparency;
		sf::RectangleShape	mDarkenedScreen;
};

#endif // BOOK_SPLASHSCREENSTATE_HPP
