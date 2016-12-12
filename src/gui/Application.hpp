#ifndef BOOK_APPLICATION_HPP
#define BOOK_APPLICATION_HPP

#include <gui/ResourceHolder.hpp>
#include <gui/ResourceIdentifiers.hpp>
#include <gui/KeyBinding.hpp>
#include <gui/StateStack.hpp>
#include <gui/MusicPlayer.hpp>
#include <gui/SoundPlayer.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
	public:
								Application();
		void					run();
		

	private:
		void					processInput();
		void					update(sf::Time dt);
		void					render();

		void					updateStatistics(sf::Time dt);
		void					registerStates();


	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		TextureHolder			mTextures;
	  	FontHolder				mFonts;
		MusicPlayer				mMusic;
		SoundPlayer				mSounds;

		KeyBinding				mKeyBinding;
		StateStack				mStateStack;

		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif // BOOK_APPLICATION_HPP
