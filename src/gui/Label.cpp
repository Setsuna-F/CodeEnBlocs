#include "Label.hpp"
#include "Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


namespace GUI
{

Label::Label(const std::string& text, const FontHolder& fonts)
: mText(text, fonts.get(Fonts::Main), 16)
{
	mText.setColor(sf::Color::Black);
}

bool Label::isSelectable() const
{
    return false;
}

void Label::handleEvent(const sf::Event&)
{
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mText, states);
}

void Label::setText(const std::string& text)
{
	mText.setString(text);
}

}
