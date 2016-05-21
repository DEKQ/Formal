#include <iostream>

#include "Controls\Button.hpp"
#include <memory>

#include "events\Event.hpp"

struct SampleEvent
{
	int x;
	int y;
};

int main()
{
	dekq::formal::events::Event<SampleEvent> sampleEvent;

	auto pos = sampleEvent += [](SampleEvent args) { std::cout << args.x << " " << args.y << std::endl; };
	auto pos2 = sampleEvent += [](SampleEvent args) { std::cout << args.x*2 << " " << args.y*2 << std::endl; };

	SampleEvent sampleArgs;
	sampleArgs.x = 10;
	sampleArgs.y = 15;

	sampleEvent.raise(sampleArgs);
	sampleEvent.raise(sampleArgs);

	sampleEvent -= pos;
	sampleEvent.raise(sampleArgs);
	sampleEvent -= pos2;
	sampleEvent.raise(sampleArgs);
	//sampleEvent -= pos2;
	sampleEvent.raise(sampleArgs);



	auto font = std::make_shared<sf::Font>();
	sf::RenderWindow window(sf::VideoMode(400, 200), "SFML works!");

	dekq::formal::controls::Button myButton;

	font->loadFromFile("arial.ttf");

	myButton.setHeight(20);
	myButton.setWidth(300);

	myButton.style_setFont(font);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			myButton.processEvent(event, 0, 0);

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(myButton);
		window.display();
	}

	return EXIT_SUCCESS;
}
