#ifndef GAME_EXIT_BUTTON_HPP
#define GAME_EXIT_BUTTON_HPP

#include "GameButton.hpp"
#include "ResourceIdentifiers.hpp"
#include "State.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


class SoundPlayer;

namespace GUI
{

class GameExitButton : public GameButton
{
	public:
		GameExitButton(State::Context context);

        virtual void			activate();
};

}

#endif // BOOK_BUTTON_HPP
