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
	numLevel++;

	auto levelButto10 = std::make_shared<GUI::LevelButton>(context);
	levelButto10->setPosition(760, 150);
	//levelButton8->setText(mGameModel.getLevel(numLevel)->getName());
	levelButto10->setText("???");
	levelButto10->setCallback([this, numLevel]()
	{
		//*getContext().numLevel = numLevel;
		//requestStackPush(States::Game);
	});
	mGUIContainer.pack(levelButto10);
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
	//TODO
	for (int i = 0; i<mGUIContainer.getNbChildren(); i++)
	{
		//allez voir dans les scores et changer texture bouton en fonction
		//		* si -1 -> lock
		//		* si 0 -> zero star
		//		* si 1 -> one star
		//		* si 2 -> two stars
		//		* si 3 -> three stars
	//	if()

	//	else if()

	//	else if()

	//	else if()

	//	else if()
	}
}


