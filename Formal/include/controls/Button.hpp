#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>
#include <memory>
#include "Control.hpp"
#include "events\Event.hpp"

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
				
				virtual void processEvent(const sf::Event & args, int parentX, int parentY) override;

				

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

				struct Events
				{
					events::Event<int> MouseEnter; //done
					events::Event<int> MouseLeave; //done
					events::Event<int> Pressed; //done
					events::Event<int> Released; //done
					events::Event<int> Clicked; //done
				} events;

			private:
				virtual void updateComponents() override;

				struct States
				{
					bool hover = false;
					bool pressed = false;
					bool focus = false;
				} states;

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

				struct Listeners
				{
					std::list<std::function<void(int)> >::iterator mouse_enter;
					std::list<std::function<void(int)> >::iterator mouse_leave;
					std::list<std::function<void(int)> >::iterator pressed;
					std::list<std::function<void(int)> >::iterator released;
				} listeners;

			};
		}
	}
}
