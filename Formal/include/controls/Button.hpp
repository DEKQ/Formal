#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>
#include <memory>
#include "Control.hpp"

namespace dekq
{
	namespace formal
	{
		namespace controls
		{
			class Button : public Control
			{
			public:
				Button();

				virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
				
				virtual void processEvent(sf::Event & args) override;

				

				/* START Property accessors */
				void setDisplayText(std::string displayText);

				std::string getDisplayText();
				/* END Property accessors */

				/* START Style accessors */
				void style_setBorderWidth(int borderWidth);
				void style_setBorderColor(sf::Color borderColor);
				void style_setBackgroundColor(sf::Color backgroundColor);
				void style_setColor(sf::Color color);
				void style_setFontSize(unsigned int fontSize);
				void style_setFont(std::shared_ptr<sf::Font> font);

				int							style_getBorderWidth();
				sf::Color					style_getBorderColor();
				sf::Color					style_getBackgroundColor();
				sf::Color					style_getColor();
				unsigned int				style_getFontSize();
				std::shared_ptr<sf::Font>	style_getFont();
				/* END Style accessors */

			private:
				virtual void updateComponents() override;

				struct Components
				{
					sf::RectangleShape background;
					/*sf::RectangleShape textBound;*/
					sf::Text displayText;
				} components;

				struct Style
				{
					int							borderWidth		= -1;
					sf::Color					borderColor		= sf::Color::Green;
					sf::Color					backgroundColor	= sf::Color::Black;
					sf::Color					color			= sf::Color::White;
					unsigned int				fontSize		= 16;
					std::shared_ptr<sf::Font>	font;
				} style;

				struct Properties
				{
					std::string displayText = "Undefined displayText";
				} properties;

			};
		}
	}
}
