#include "Controls\Button.hpp"

//TODO create multiple constructors for passing default values
dekq::formal::controls::Button::Button()
{
	this->setWidth(80); //TODO make this more efficient(cause every set in here will trigger updateComponents)
	this->setHeight(18);
	this->setX(10);
	this->setY(10);

	listeners.mouse_enter = events.MouseEnter.operator+=([this](int i)
	{
		std::cout << "mouse enter" << std::endl;
		this->states.hover = true;
	});
	listeners.mouse_leave = events.MouseLeave.operator+=([this](int i)
	{
		std::cout << "mouse leave" << std::endl;
		this->states.hover = false;
	});
	listeners.pressed = events.Pressed.operator+=([this](int i)
	{
		std::cout << "pressed" << std::endl;
		this->states.pressed = true;
	});
	listeners.released = events.Released.operator+=([this](int i)
	{
		std::cout << "released" << std::endl;
		this->states.pressed = false;
	});

	updateComponents();
}

void dekq::formal::controls::Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(components.background, states);
	/*target.draw(components.textBound, states);*/
	target.draw(components.displayText, states);
}

void dekq::formal::controls::Button::setDisplayText(std::string displayText)
{
	properties.displayText = displayText;
	updateComponents();
}

std::string dekq::formal::controls::Button::getDisplayText()
{
	return properties.displayText;
}

void dekq::formal::controls::Button::style_setBorderWidth(int borderWidth)
{
	style.borderWidth = borderWidth;
	updateComponents();
}

void dekq::formal::controls::Button::style_setBorderColor(sf::Color borderColor)
{
	style.borderColor = borderColor;
	updateComponents();
}

void dekq::formal::controls::Button::style_setBackgroundColor(sf::Color backgroundColor)
{
	style.backgroundColor = backgroundColor;
	updateComponents();
}

void dekq::formal::controls::Button::style_setColor(sf::Color color)
{
	style.color = color;
	updateComponents();
}

void dekq::formal::controls::Button::style_setFontSize(unsigned int fontSize)
{
	style.fontSize = fontSize;
	updateComponents();
}

std::shared_ptr<sf::Font> dekq::formal::controls::Button::style_getFont()
{
	return style.font;
}

void dekq::formal::controls::Button::updateComponents()
{
	//update components.background
	components.background.setSize(sf::Vector2f((float)getWidth(), (float)getHeight()));
	components.background.setPosition(sf::Vector2f((float)getX(), (float)getY()));
	components.background.setOutlineThickness((float)style.borderWidth);
	components.background.setOutlineColor(style.borderColor);
	components.background.setFillColor(style.backgroundColor);

	//update comonents.displayText
	if (style.font.get() != nullptr)
	{
		components.displayText.setColor(style.color);
		components.displayText.setString(properties.displayText);
		auto tmp = components.displayText.getGlobalBounds();
		//components.displayText.setOrigin(sf::Vector2f(floor(tmp.width / 2.0f + 0.5f), floor(tmp.height / 2.0f + 0.5f)));
		components.displayText.setPosition(sf::Vector2f((float)getX(), (float)getY()));
		components.displayText.setFont(*style.font);
		components.displayText.setCharacterSize(style.fontSize);
		//components.textBound.setPosition(sf::Vector2f((float)getX() + (getWidth() / 2), (float)getY() + (getHeight() / 2)));
		//components.textBound.setOrigin(sf::Vector2f(floor(tmp.width / 2.0f + 0.5f), floor(tmp.height / 2.0f + 0.5f)));
		//components.textBound.setSize(sf::Vector2f(tmp.width, tmp.height));
		//components.textBound.setOutlineColor(sf::Color::Red);
		//components.textBound.setOutlineThickness(-1.0f);
		//components.textBound.setFillColor(sf::Color::Transparent);
	}
}

void dekq::formal::controls::Button::processEvent(const sf::Event & args, int parentX, int parentY)
{
	switch (args.type)
	{
	case sf::Event::MouseMoved:
	{
		//hover detection
		int mouseX = args.mouseMove.x + parentX;
		int mouseY = args.mouseMove.y + parentY;

		int x = getX();
		int y = getY();
		int width = getWidth();
		int height = getHeight();

		if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
		{
			if (!states.hover)
			{
				events.MouseEnter.raise(0); //TODO
			}
		}
		else
		{
			if (states.hover)
			{
				events.MouseLeave.raise(0); //TODO
			}
		}
	}
	break;
	case sf::Event::MouseButtonPressed:
	{
		//pressed detection
		if (args.mouseButton.button == sf::Mouse::Left)
		{
			if (states.hover)
			{
				events.Pressed.raise(0); //TODO
			}
		}
		break;
	}
	case sf::Event::MouseButtonReleased:
	{
		//click detection
		if (args.mouseButton.button == sf::Mouse::Left)
		{
			if (states.pressed)
			{
				if (states.hover)
				{
					events.Clicked.raise(0);
				}
				events.Released.raise(0);
			}
		}
	}
	break;
	}
}

void dekq::formal::controls::Button::style_setFont(std::shared_ptr<sf::Font> font)
{
	style.font = font;
	updateComponents();
}

int dekq::formal::controls::Button::style_getBorderWidth()
{
	return style.borderWidth;
}

sf::Color dekq::formal::controls::Button::style_getBorderColor()
{
	return style.borderColor;
}

sf::Color dekq::formal::controls::Button::style_getBackgroundColor()
{
	return style.backgroundColor;
}

sf::Color dekq::formal::controls::Button::style_getColor()
{
	return style.color;
}

unsigned int dekq::formal::controls::Button::style_getFontSize()
{
	return style.fontSize;
}
