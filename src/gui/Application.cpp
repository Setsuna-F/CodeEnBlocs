#include "Application.hpp"
#include "Utility.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "SplashScreenState.hpp"
#include "TitleState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "SettingsState.hpp"
#include "TutorialState.hpp"
#include "LevelManagerState.hpp"
#include "LoseState.hpp"
#include "WinState.hpp"
#include "ResourcePath.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(1280, 720), "CodeEnBlocs", sf::Style::Close)
, mTextures()
, mFonts()
, mMusic()
, mSounds()
, mKeyBinding()
, mTutorial(false)
, mNumLevel(0)
, mStateStack(State::Context(mWindow, mTextures, mFonts, mMusic, mSounds, mKeyBinding, mTutorial, mNumLevel))
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
	mWindow.setKeyRepeatEnabled(false);
	mWindow.setVerticalSyncEnabled(true);

	// Load musics in MusicPlayer

	// Load sounds in SoundPlayer

	// Load fonts
	mFonts.load(Fonts::Main, "res/font/Charlatan.otf");
	mFonts.load(Fonts::Normal, "res/font/Sansation.ttf");

	// Load textures
	mTextures.load(Textures::Background, "res/img/background.png");
	mTextures.load(Textures::TitleScreen, "res/img/title-screen.png");
	mTextures.load(Textures::GameBackgroud, "res/img/Background2.png");
	mTextures.load(Textures::MenuSettingsBackgroud, "res/img/Background6.png");
	//mTextures.load(Textures::LevelManagerBackgroud, "res/img/Background7.png");
	mTextures.load(Textures::LevelManagerBackgroud, "res/img/level-selection-background.png");

	mTextures.load(Textures::Buttons,			"res/img/Buttons.png");
	mTextures.load(Textures::ExitButton,		"res/img/button-exit-bi-1.png");
	mTextures.load(Textures::ExecuteButton,		"res/img/button-execute-bi.png");
	mTextures.load(Textures::ResetButton,		"res/img/button-reset-bi.png");
	mTextures.load(Textures::LoopButton,		"res/img/button-loop-bi.png");
	mTextures.load(Textures::HelpButton,		"res/img/button-help-bi.png");
	mTextures.load(Textures::DescriptionButton, "res/img/button-description-bi.png");
	mTextures.load(Textures::LevelManagerButtonLock, "res/img/level-menu-background-lock.png");
	mTextures.load(Textures::LevelManagerButtonZeroStar, "res/img/level-menu-background-score-0.png");
	mTextures.load(Textures::LevelManagerButtonOneStar, "res/img/level-menu-background-score-1.png");
	mTextures.load(Textures::LevelManagerButtonTwoStars, "res/img/level-menu-background-score-2.png");
	mTextures.load(Textures::LevelManagerButtonThreeStars, "res/img/level-menu-background-score-3.png");

	mTextures.load(Textures::AddSpawner,		"res/img/block-add.png");
	mTextures.load(Textures::AssignmentSpawner, "res/img/block-assignment.png");	
	mTextures.load(Textures::InputSpawner,		"res/img/block-input.png");	
	mTextures.load(Textures::OutputSpawner,		"res/img/block-output.png");	
	mTextures.load(Textures::ValueSpawner,		"res/img/block-value.png");	
	mTextures.load(Textures::VariableSpawner,	"res/img/block-variable.png");	

	mTextures.load(Textures::CurseurSprite,		"res/img/curseur.png");

	mTextures.load(Textures::Tutorial0, "res/img/tuto/tuto-0.png");
	mTextures.load(Textures::Tutorial1, "res/img/tuto/tuto-1.png");
	mTextures.load(Textures::Tutorial2, "res/img/tuto/tuto-2.png");
	mTextures.load(Textures::Tutorial3, "res/img/tuto/tuto-3.png");
	mTextures.load(Textures::Tutorial4, "res/img/tuto/tuto-4.png");
	mTextures.load(Textures::Tutorial5, "res/img/tuto/tuto-5.png");
	mTextures.load(Textures::Tutorial6, "res/img/tuto/tuto-6.png");
	mTextures.load(Textures::Tutorial7, "res/img/tuto/tuto-7.png");
	mTextures.load(Textures::Tutorial8, "res/img/tuto/tuto-8.png");
	mTextures.load(Textures::Tutorial9, "res/img/tuto/tuto-9.png");

	mTextures.load(Textures::Lose, "res/img/lose.png");
	mTextures.load(Textures::Win, "res/img/win.png");


	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10u);

	registerStates();
	mStateStack.pushState(States::SplashSreen);

	mMusic.setVolume(20.f);
	mSounds.setVolume(50.f);
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);

			// Check inside this loop, because stack might be empty before update() call
			if (mStateStack.isEmpty())
				mWindow.close();
		}

		updateStatistics(dt);
		render();
	}
}

void Application::processInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mStateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void Application::render()
{
	mWindow.clear();

	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
	mStatisticsUpdateTime += dt;
	mStatisticsNumFrames += 1;
	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Application::registerStates()
{
	mStateStack.registerState<SplashScreenState>(States::SplashSreen);
	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<MenuState>(States::Menu);
	mStateStack.registerState<GameState>(States::Game);
	mStateStack.registerState<SettingsState>(States::Settings);
	mStateStack.registerState<TutorialState>(States::Tutorial);
	mStateStack.registerState<LevelManagerState>(States::LevelManager);
	mStateStack.registerState<LoseState>(States::Lose);
	mStateStack.registerState<WinState>(States::Win);
}
