#ifndef BOOK_LEVELMANAGERSTATE_HPP
#define BOOK_LEVELMANAGERSTATE_HPP


#ifdef __APPLESOKA__
#include "State.hpp"
#include "Container.hpp"
#include "gamemodel.hpp"
#else
#include "State.hpp"
#include "Container.hpp"
#include "model/gamemodel.hpp"
#endif


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class LevelManagerState : public State
{
	public:
								LevelManagerState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);


	private:
		sf::Sprite				mBackgroundSprite;
		GUI::Container			mGUIContainer;
		satap::GameModel				mGameModel;
};

#endif // BOOK_LEVELMANAGERSTATE_HPP
