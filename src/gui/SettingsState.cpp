#include "SettingsState.hpp"
#include "Utility.hpp"
#include "ResourceHolder.hpp"
#include "MusicPlayer.hpp"
#include "SoundPlayer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>


SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	
	// Build key binding buttons and labels
	//for (std::size_t x = 0; x < 2; ++x)
	//{
	//	addButtonLabel(PlayerAction::MoveLeft,		x, 0, "Move Left", context);
	//	addButtonLabel(PlayerAction::MoveRight,		x, 1, "Move Right", context);
	//	addButtonLabel(PlayerAction::MoveUp,		x, 2, "Move Up", context);
	//	addButtonLabel(PlayerAction::MoveDown,		x, 3, "Move Down", context);
	//	addButtonLabel(PlayerAction::Fire,			x, 4, "Fire", context);
	//	addButtonLabel(PlayerAction::LaunchMissile,	x, 5, "Missile", context);
	//}

	int col = 0;
	int ligne = 0;

	// Build key binding buttons and labels
	addButtonLabel(PlayerAction::RunCode, col, ligne, "Run code ", context);

	ligne++;

	// TODO autres binding

	// Settings : music volume, effect sound volume, ...
	// Bouttons pour le volume de la musique
	col++;
	ligne = 0;
	auto downMusicVolumeButton = std::make_shared<GUI::Button>(context);
	downMusicVolumeButton->setPosition(500.f*col + 80.f, 50.f*ligne + 300.f);
	downMusicVolumeButton->setText(" - ");
	downMusicVolumeButton->scale(0.25, 1);
	downMusicVolumeButton->setCallback([this]()
	{
		MusicPlayer& music = *getContext().music;
		music.setVolume(music.getVolume() - 5.f);
	});

	auto musicVolumeLabbel = std::make_shared<GUI::Label>("Volume musique", *context.fonts);
	musicVolumeLabbel->setPosition(500.f*col + 150.f, 50.f*ligne + 315.f);

	auto upMusicVolumeButton = std::make_shared<GUI::Button>(context);
	upMusicVolumeButton->setPosition(500.f*col + 300.f, 50.f*ligne + 300.f);
	upMusicVolumeButton->setText(" + ");
	upMusicVolumeButton->scale(0.25, 1);
	upMusicVolumeButton->setCallback([this]()
	{
		MusicPlayer& music = *getContext().music;
		music.setVolume(music.getVolume() + 5.f);
	});

	// Bouttons pour le volume des sons
	ligne++;
	auto downSoundsVolumeButton = std::make_shared<GUI::Button>(context);
	downSoundsVolumeButton->setPosition(500.f*col + 80.f, 50.f*ligne + 300.f);
	downSoundsVolumeButton->setText(" - ");
	downSoundsVolumeButton->scale(0.25, 1);
	downSoundsVolumeButton->setCallback([this]()
	{
		SoundPlayer& sounds = *getContext().sounds;
		sounds.setVolume(sounds.getVolume() - 5.f);
	});

	auto soundsVolumeLabbel = std::make_shared<GUI::Label>("Volume bruitage", *context.fonts);
	soundsVolumeLabbel->setPosition(500.f*col + 150.f, 50.f*ligne + 315.f);

	auto upSoundsVolumeButton = std::make_shared<GUI::Button>(context);
	upSoundsVolumeButton->setPosition(500.f*col + 300.f, 50.f*ligne + 300.f);
	upSoundsVolumeButton->setText(" + ");
	upSoundsVolumeButton->scale(0.25, 1);
	upSoundsVolumeButton->setCallback([this]()
	{
		SoundPlayer& sounds = *getContext().sounds;
		sounds.setVolume(sounds.getVolume() + 5.f);
	});


	mGUIContainer.pack(downMusicVolumeButton);
	mGUIContainer.pack(musicVolumeLabbel);
	mGUIContainer.pack(upMusicVolumeButton);

	mGUIContainer.pack(downSoundsVolumeButton);
	mGUIContainer.pack(soundsVolumeLabbel);
	mGUIContainer.pack(upSoundsVolumeButton);

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(80.f, 620.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&SettingsState::requestStackPop, this));

	mGUIContainer.pack(backButton);
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	// window.clear(); Si commenté, crée un effet de "pause" de la vue précédente au panneau de settings.

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time)
{
	return true;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
	bool isKeyBinding = false;

	// Iterate through all key binding buttons to see if they are being pressed, waiting for the user to enter a key
	for (std::size_t i = 0; i < PlayerAction::Count; ++i)
	{
		if (mBindingButtons[i]->isActive())
		{
			isKeyBinding = true;
			if (event.type == sf::Event::KeyReleased)
			{
				getContext().keys->assignKey(static_cast<PlayerAction::Type>(i), event.key.code);

				mBindingButtons[i]->deactivate();
			}
			break;
		}
	}

	// If pressed button changed key bindings, update labels; otherwise consider other buttons in container
	if (isKeyBinding)
		updateLabels();
	else
		mGUIContainer.handleEvent(event);

	return false;
}

void SettingsState::updateLabels()
{
	for (std::size_t i = 0; i < PlayerAction::Count; ++i)
	{
		auto action = static_cast<PlayerAction::Type>(i);

		// Get keys of both players
		sf::Keyboard::Key key = getContext().keys->getAssignedKey(action);

		// Assign both key strings to labels
		mBindingLabels[i]->setText(toString(key));
	}
}

void SettingsState::addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context)
{
	// For x==0, start at index 0, otherwise start at half of array
	index += PlayerAction::Count * x;

	mBindingButtons[index] = std::make_shared<GUI::Button>(context);
	mBindingButtons[index]->setPosition(400.f*x + 80.f, 50.f*y + 300.f);
	mBindingButtons[index]->setText(text);
	mBindingButtons[index]->setToggle(true);

	mBindingLabels[index] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[index]->setPosition(400.f*x + 300.f, 50.f*y + 315.f);

	mGUIContainer.pack(mBindingButtons[index]);
	mGUIContainer.pack(mBindingLabels[index]);
}
