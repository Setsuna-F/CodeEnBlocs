#ifndef SPAWNER_BUTTON_HPP
#define SPAWNER_BUTTON_HPP

#include "Component.hpp"
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

class SpawnerButton : public Component
{
    public:
        typedef std::shared_ptr<SpawnerButton>		Ptr;
        typedef std::function<void()>		Callback;

		enum Type
		{
			Normal,
			Selected,
			Pressed,
			ButtonCount
		};


	public:
		SpawnerButton(State::Context context);

        void					setCallback(Callback callback);
        void					setText(const std::string& text);
        void					setToggle(bool flag);
		void					scale(float scaleX, float scaleY);

        virtual bool			isSelectable() const;
        virtual void			select();
        virtual void			deselect();

        virtual void			activate();
        virtual void			deactivate();

        virtual void			handleEvent(const sf::Event& event);

		void					setSprite(State::Context c, Textures::ID id);


    private:
        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void					changeTexture(Type buttonType);


    private:
        Callback				mCallback;
        sf::Sprite				mSprite;
        sf::Text				mText;
        bool					mIsToggle;
		SoundPlayer&			mSounds;
		State::Context			mContext;
};

}

#endif // BOOK_BUTTON_HPP
