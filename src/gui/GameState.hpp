#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <gui/State.hpp>
#include <gui/Container.hpp>
#include <model/levelmodel.hpp>
#include <model/additionlevelmodel.hpp>
#include "blocs/Bloc.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace satap;

class GameState : public State
{
	public:
		GameState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);
		
		satap::Bloc* addBloc(satap::typeBloc t);

		void resetCode();
		void toggleLoop();
		void startExecute();

	private:
		Context					mContext;
		sf::Sprite				mBackgroundSprite;
		GUI::Container			mButtonsContainer;
		GUI::Container			mBlocsContainer;
		satap::LevelModel*		mCurrentLevel;
};

#endif // BOOK_MENUSTATE_HPP
