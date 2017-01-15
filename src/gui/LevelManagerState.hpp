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
#include "LevelButton.hpp"
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
		virtual void			onActivate();


	private:
		sf::Sprite				mBackgroundSprite;
		GUI::Container			mGUIContainer;
		satap::GameModel		mGameModel;
		sf::Text				mText;
		std::vector<GUI::LevelButton::Ptr> mLevelButtons;
};

#endif // BOOK_LEVELMANAGERSTATE_HPP
