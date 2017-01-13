#include "State.hpp"
#include "StateStack.hpp"


State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts,
	MusicPlayer& music, SoundPlayer& sounds, KeyBinding& keys, bool& tutorial, int& numLevel,
	int& score, std::string& nameLevel, int& nbBlocsUsed)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, music(&music)
, sounds(&sounds)
, keys(&keys)
, tutorial(&tutorial)
, numLevel(&numLevel)
, score(&score)
, nameLevel(&nameLevel)
, nbBlocsUsed(&nbBlocsUsed)
{
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}

void State::onActivate()
{

}

void State::onDestroy()
{

}
