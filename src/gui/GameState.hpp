#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <gui/State.hpp>
#include <gui/Container.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
public:
	GameState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);


private:
	sf::Sprite				mBackgroundSprite;
	GUI::Container			mGUIContainer;
	GUI::Container			mGUIBlocsContainer;
};

#endif // BOOK_MENUSTATE_HPP
