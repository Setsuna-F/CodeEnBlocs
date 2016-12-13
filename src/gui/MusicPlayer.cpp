#include "MusicPlayer.hpp"
#include "ResourcePath.hpp"

#include <iostream>


MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(20.f)
{
	//mFilenames[Music::MenuTheme]    = "res/sound/MenuTheme.ogg";
	mFilenames[Music::MenuTheme]    = "/Users/S-Setsuna-F/Documents/Master2/Jeux serieux/CodeEnBlocs/res/sound/MenuTheme.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
	std::string filename = mFilenames[theme];

	if (!mMusic.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded.");

	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();
}

void MusicPlayer::stop()
{
	mMusic.stop();
}

void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;

	if (mVolume <= 0.f)
		mVolume = 0.f;

	if (mVolume >= 100.f)
		mVolume = 100.f;

	mMusic.setVolume(mVolume);
}

float MusicPlayer::getVolume() const
{
	return mVolume;
}

void MusicPlayer::setPaused(bool paused)
{
	if (paused)
		mMusic.pause();
	else
		mMusic.play();
}
