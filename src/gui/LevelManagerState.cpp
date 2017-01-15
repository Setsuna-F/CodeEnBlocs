#include "LevelManagerState.hpp"
#include "Button.hpp"
#include "LevelButton.hpp"
#include "Utility.hpp"
#include "MusicPlayer.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>


LevelManagerState::LevelManagerState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
, mGameModel()
, mText("", context.fonts->get(Fonts::Main), 50)
, mLevelButtons()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::LevelManagerBackgroud));

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(10, 10);
	exitButton->setText("Back to main menu");
	exitButton->setCallback([this]() {
		requestStackPop();
	});
	mGUIContainer.pack(exitButton);

	// TODO plus essayer de faire une création de l'arbre en dynamique
	// Pour le moment à chaque ajout de level il faudra ajouter un bouton à la main dans l'abre

	mText.setString("Choix du niveau");
	centerOrigin(mText);
	mText.setPosition(640, 670);

	// Racine tuto
	auto tutoButton = std::make_shared<GUI::LevelButton>(context);
	tutoButton->setPosition(640, 570);
	tutoButton->setText("Tutorial");
	tutoButton->setTexture(Textures::LevelManagerButtonThreeStars);
	tutoButton->setCallback([this] ()
	{
		requestStackPush(States::Tutorial);
	});
	mGUIContainer.pack(tutoButton);

	// Puis les levels
	int numLevel = 0;
	auto levelButton0 = std::make_shared<GUI::LevelButton>(context);
	levelButton0->setPosition(400, 430);
	levelButton0->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton0->setCallback([this, numLevel]()
	{
		*getContext().numLevel = numLevel;
		requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton0);
	mLevelButtons.push_back(levelButton0);
	numLevel++;

	auto levelButton1 = std::make_shared<GUI::LevelButton>(context);
	levelButton1->setPosition(640, 430);
	levelButton1->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton1->setCallback([this, numLevel]()
	{
		*getContext().numLevel = numLevel;
		requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton1);
	mLevelButtons.push_back(levelButton1);
	numLevel++;

	auto levelButton2 = std::make_shared<GUI::LevelButton>(context);
	levelButton2->setPosition(880, 430);
	levelButton2->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton2->setCallback([this, numLevel]()
	{
		*getContext().numLevel = numLevel;
		requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton2);
	mLevelButtons.push_back(levelButton2);
	numLevel++;

	auto levelButton3 = std::make_shared<GUI::LevelButton>(context);
	levelButton3->setPosition(160, 290);
	//levelButton3->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton3->setText("???");
	levelButton3->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton3);
	mLevelButtons.push_back(levelButton3);
	numLevel++;

	auto levelButton4 = std::make_shared<GUI::LevelButton>(context);
	levelButton4->setPosition(400, 290);
	//levelButton4->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton4->setText("???");
	levelButton4->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton4);
	mLevelButtons.push_back(levelButton4);
	numLevel++;

	auto levelButton5 = std::make_shared<GUI::LevelButton>(context);
	levelButton5->setPosition(640, 290);
	//levelButton5->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton5->setText("???");
	levelButton5->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton5);
	mLevelButtons.push_back(levelButton5);
	numLevel++;

	auto levelButton6 = std::make_shared<GUI::LevelButton>(context);
	levelButton6->setPosition(880, 290);
	//levelButton6->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton6->setText("???");
	levelButton6->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton6);
	mLevelButtons.push_back(levelButton6);
	numLevel++;

	auto levelButton7 = std::make_shared<GUI::LevelButton>(context);
	levelButton7->setPosition(1120, 290);
	//levelButton7->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton7->setText("???");
	levelButton7->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton7);
	mLevelButtons.push_back(levelButton7);
	numLevel++;

	auto levelButton8 = std::make_shared<GUI::LevelButton>(context);
	levelButton8->setPosition(280, 150);
	//levelButton8->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton8->setText("???");
	levelButton8->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton8);
	mLevelButtons.push_back(levelButton8);
	numLevel++;

	auto levelButton9 = std::make_shared<GUI::LevelButton>(context);
	levelButton9->setPosition(520, 150);
	//levelButton8->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton9->setText("???");
	levelButton9->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton9);
	mLevelButtons.push_back(levelButton9);
	numLevel++;

	auto levelButton10 = std::make_shared<GUI::LevelButton>(context);
	levelButton10->setPosition(760, 150);
	//levelButton8->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton10->setText("???");
	levelButton10->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton10);
	mLevelButtons.push_back(levelButton10);
	numLevel++;

	auto levelButton11 = std::make_shared<GUI::LevelButton>(context);
	levelButton11->setPosition(1000, 150);
	//levelButton8->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton11->setText("???");
	levelButton11->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButton11);
	mLevelButtons.push_back(levelButton11);
	numLevel++;

	// Play menu theme
	//context.music->play(Music::MenuTheme);
}

void LevelManagerState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.clear();
	//window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
	window.draw(mText);
}

bool LevelManagerState::update(sf::Time)
{
	return true;
}

bool LevelManagerState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.KeyReleased == sf::Keyboard::Escape)
		requestStackPop();
	mGUIContainer.handleEvent(event);
	return false;
}

void LevelManagerState::onActivate()
{
	for (int i = 0; i<getContext().scores->size(); i++)
	{

		if (getContext().scores->at(i) == -1)
			mLevelButtons[i]->setTexture(Textures::LevelManagerButtonLock);
		else if (getContext().scores->at(i) == 0)
			mLevelButtons[i]->setTexture(Textures::LevelManagerButtonZeroStar);
		else if(getContext().scores->at(i) == 1)
			mLevelButtons[i]->setTexture(Textures::LevelManagerButtonOneStar);
		else if(getContext().scores->at(i) == 2)
			mLevelButtons[i]->setTexture(Textures::LevelManagerButtonTwoStars);
		else if(getContext().scores->at(i) == 3)
			mLevelButtons[i]->setTexture(Textures::LevelManagerButtonThreeStars);
	}
}


