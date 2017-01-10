#ifndef BOOK_RESOURCEIDENTIFIERS_HPP
#define BOOK_RESOURCEIDENTIFIERS_HPP


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
	class Shader;
	class SoundBuffer;
}

namespace Textures
{
	enum ID
	{
		TitleScreen,
		Background,
		GameBackgroud,
		MenuSettingsBackgroud,
		LevelManagerBackgroud,
		Buttons,
		ExitButton,
		ExecuteButton,
		ResetButton,
		LoopButton,
		HelpButton,
		DescriptionButton,
		AddSpawner,
		AssignmentSpawner,
		InputSpawner,
		OutputSpawner,
		ValueSpawner,
		VariableSpawner,
		CurseurSprite,
		TutorialBegin,
		Tutorial0,
		Tutorial1,
		Tutorial2,
		Tutorial3,
		Tutorial4,
		Tutorial5,
		Tutorial6,
		Tutorial7,
		Tutorial8,
		Tutorial9,
		TutorialEnd,
		Lose,
		Win1,
		Win2,
		Win3,
		WinBackground
	};
}

namespace Shaders
{
	enum ID
	{
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,
	};
}

namespace Fonts
{
	enum ID
	{
		Main,
		Normal,
	};
}

namespace SoundEffect
{
	enum ID
	{
		Button,
		WrinkledPaper,
	};
}

namespace Music
{
	enum ID
	{
		MenuTheme,
		MissionTheme,
	};
}


// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>			TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>					FontHolder;
typedef ResourceHolder<sf::Shader, Shaders::ID>				ShaderHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>	SoundBufferHolder;

#endif // BOOK_RESOURCEIDENTIFIERS_HPP
