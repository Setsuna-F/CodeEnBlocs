#ifndef BLOCK_HPP
#define BLOCK_HPP


#ifdef __APPLESOKA__
#include "Component.hpp"
#include "ResourceIdentifiers.hpp"
#include "State.hpp"
#include "ResourceHolder.hpp"
#else
#include "gui/Component.hpp"
#include "gui/ResourceIdentifiers.hpp"
#include "gui/State.hpp"
#include "gui/ResourceHolder.hpp"
#include "model/BlockModel.hpp"
#endif


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


class SoundPlayer;

namespace satap
{

	class Bloc : public GUI::Component
	{
	public:
		typedef std::shared_ptr<Bloc>		Ptr;
		typedef std::function<void()>		Callback;

		enum Type
		{
			Normal,
			Selected,
			Pressed,
			ButtonCount
		};


	public:
		Bloc(State::Context context, typeBloc);

		void					setCallback(Callback callback);
		void					setText(const std::string& text);
		void					setToggle(bool flag);

		virtual bool			isSelectable() const;
		virtual void			select();
		virtual void			deselect();

		virtual void			activate();
		virtual void			deactivate();

		virtual void			handleEvent(const sf::Event& event);

		void					setSprite(State::Context c, Textures::ID id);

		typeBloc				getType(){return mTypeBlock;}

	private:
		virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void					changeTexture(Type buttonType);


	private:
		Callback				mCallback;
		sf::Sprite				mSprite;
		sf::Text				mText;
		bool					mIsToggle;
		SoundPlayer&			mSounds;
		typeBloc				mTypeBlock;
	};

}

#endif // BOOK_BUTTON_HPP
