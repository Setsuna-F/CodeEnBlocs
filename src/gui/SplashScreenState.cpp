#include "SplashScreenState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


#include <iostream>

SplashScreenState::SplashScreenState(StateStack& stack, Context context)
: State(stack, context)
, mAppName()
, mDescription()
, mEditor()
, mAuthors()
, mDelayDisplay(sf::Time::Zero)
, mColorTransparency(sf::Color::Black)
, mDarkenedScreen()
{
	//mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	mAppName.setFont(context.fonts->get(Fonts::Main));
	mAppName.setCharacterSize(100);
	mAppName.setString("CodeEnBlocks");
	mAppName.setColor(sf::Color::White);
	centerOrigin(mAppName);
	mAppName.setPosition(sf::Vector2f(context.window->getSize().x * 0.5f, context.window->getSize().y * 0.3f));
	
	mDescription.setFont(context.fonts->get(Fonts::Main));
	mDescription.setCharacterSize(31);
	mDescription.setString("Educational game to the initiation of the algorithmic thanks to the programming in blocks.\nThis game is dedicated to the pupils of about 16 years.");
	mDescription.setColor(sf::Color::White);
	centerOrigin(mDescription);
	mDescription.setPosition(sf::Vector2f(context.window->getSize().x * 0.5f, context.window->getSize().y * 0.5f));

	mEditor.setFont(context.fonts->get(Fonts::Main));
	mEditor.setCharacterSize(15);
	mEditor.setString("Alexandre Faucher, Sofien Benharchache, Ali Chouenyib, Thomas Bonnin et Pascal Wagner in SATAP!! Edition \u00A9");
	mEditor.setColor(sf::Color::White);
	centerOrigin(mEditor);
	mEditor.setPosition(sf::Vector2f(context.window->getSize().x * 0.5f, context.window->getSize().y * 0.95f));

	//mDescription.setFont(context.fonts->get(Fonts::Main));
	//mDescription.setCharacterSize(30);
	//mDescription.setString("Educational game to the initiation éof the algorithmic thanks to the programming in blocks.\nThis game is dedicated to the pupils of about 16 years");
	//mDescription.setColor(sf::Color::White);
	//centerOrigin(mDescription);
	//std::cout << context.window->getSize().x << " " << context.window->getSize().x << std::endl;
	//std::cout << context.window->getSize().x * 0.5f << " " << context.window->getSize().x * 0.7f << std::endl;
	//mDescription.setPosition(sf::Vector2f(context.window->getSize().x * 0.5f, context.window->getSize().y * 0.7f));

	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u window_size = window.getSize();
	mDarkenedScreen.setSize(sf::Vector2f(window_size.x, window_size.y));
	mDarkenedScreen.setPosition(0, 0);
	mDarkenedScreen.setFillColor(mColorTransparency);
}

void SplashScreenState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mAppName);
	window.draw(mDescription);
	window.draw(mEditor);
	mDarkenedScreen.setFillColor(mColorTransparency);
	window.draw(mDarkenedScreen);
}

bool SplashScreenState::update(sf::Time dt)
{
	mDelayDisplay += dt;

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
	else if (mDelayDisplay < sf::seconds(4.5f))
	{
		// On attend, on affiche juste le texte
	}
	else if (mDelayDisplay < sf::seconds(6.0f))
	{

		if (mColorTransparency.a < 250)
		{
			mColorTransparency.a += 6;
		}
		else
		{
			mColorTransparency.a = 255;
		}
	}
	else
	{
		requestStackPop();
		requestStackPush(States::Title);
	}

	return true;
}

bool SplashScreenState::handleEvent(const sf::Event& event)
{
	return true;
}
