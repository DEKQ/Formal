#pragma once

#include <SFML\Graphics.hpp>

namespace dekq
{
	namespace formal
	{
		class Control : public sf::Drawable
		{
		public:
			void setWidth(int width);
			int getWidth();
			void setHeight(int height);
			int getHeight();
			void setX(int x);
			int getX();
			void setY(int y);
			int getY();

		protected:
			virtual void updateComponents() = 0;

			virtual void processEvent(const sf::Event& args, int parentX, int parentY) = 0;

		private:
			struct Properties
			{
				int width = 0;
				int height = 0;
				int x = 0;
				int y = 0;
			} properties;
		};
	}
}
