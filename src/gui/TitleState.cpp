#include "TitleState.hpp"
#include "Utility.hpp"
#include "MusicPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


TitleState::TitleState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mShowText(true)
, mTextEffectTime(sf::Time::Zero)
, mDelayDisplay(sf::Time::Zero)
, mColorTransparency(sf::Color::Black)
, mDarkenedScreen()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Press any key to start");
	mText.setColor(sf::Color::Black);
	centerOrigin(mText);
	mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));

	context.music->play(Music::MenuTheme);
	
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u window_size = window.getSize();
	mDarkenedScreen.setSize(sf::Vector2f(window_size.x, window_size.y));
	mDarkenedScreen.setPosition(0, 0);
	mDarkenedScreen.setFillColor(mColorTransparency);
}

void TitleState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
		window.draw(mText);

	mDarkenedScreen.setFillColor(mColorTransparency);
	window.draw(mDarkenedScreen);
}

bool TitleState::update(sf::Time dt)
{
	mTextEffectTime += dt;
	mDelayDisplay += dt;

	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}

	if (mDelayDisplay < sf::seconds(2.0f))
	{
		if (mColorTransparency.a > 6)
		{
			mColorTransparency.a -= 6;
		}
		else
		{
			mColorTransparency.a = 0;
		}
	}

	return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseButtonReleased)
	{
		requestStackPop();
		requestStackPush(States::Menu);
	}

	return true;
}
