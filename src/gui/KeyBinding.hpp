#ifndef BOOK_KEYBINDING_HPP
#define BOOK_KEYBINDING_HPP

#include <SFML/Window/Keyboard.hpp>

#include <map>
#include <vector>


namespace PlayerAction
{
	enum Type
	{
		RunCode,
		// TODO autres actions comme par exemple des raccourcis pour ouvrir les différents onglets
		Count
	};
}

class KeyBinding
{
	public:
		typedef PlayerAction::Type Action;


	public:
		explicit				KeyBinding();

		void					assignKey(Action action, sf::Keyboard::Key key);
		sf::Keyboard::Key		getAssignedKey(Action action) const;

		bool					checkAction(sf::Keyboard::Key key, Action& out) const;
		std::vector<Action>		getRealtimeActions() const;


	private:
		void					initializeActions();


	private:
		std::map<sf::Keyboard::Key, Action>		mKeyMap;
};

bool					isRealtimeAction(PlayerAction::Type action);

#endif // BOOK_KEYBINDING_HPP
