#include "LevelManagerState.hpp"
#include "Button.hpp"
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

	// Racine tuto
	auto tutoButton = std::make_shared<GUI::Button>(context);
	tutoButton->setPosition(590, 600);
	tutoButton->setText("Tutorial");
	tutoButton->setCallback([this] ()
	{
		requestStackPush(States::Tutorial);
	});

	// Puis les levels
	int numLevel = 0;
	auto levelButton0 = std::make_shared<GUI::Button>(context);
	levelButton0->setPosition(350, 500);
	levelButton0->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton0->setCallback([this, numLevel]()
	{
		*getContext().numLevel = numLevel;
		requestStackPush(States::Game);
	});

	numLevel++;
	auto levelButton1 = std::make_shared<GUI::Button>(context);
	levelButton1->setPosition(590, 500);
	levelButton1->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton1->setCallback([this, numLevel]()
	{
		*getContext().numLevel = numLevel;
		requestStackPush(States::Game);
	});

	numLevel++;
	auto levelButton2 = std::make_shared<GUI::Button>(context);
	levelButton2->setPosition(830, 500);
	levelButton2->setText(mGameModel.getLevel(numLevel)->getName());
	levelButton2->setCallback([this, numLevel]()
	{
		*getContext().numLevel = numLevel;
		requestStackPush(States::Game);
	});

	mGUIContainer.pack(tutoButton);
	mGUIContainer.pack(levelButton0);
	mGUIContainer.pack(levelButton1);
	mGUIContainer.pack(levelButton2);

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
