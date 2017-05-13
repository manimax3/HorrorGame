#include <iostream>

#include "SFML/Graphics.hpp"

int main()
{

	sf::RenderWindow window(sf::VideoMode(720, 720), "Horror Game");

	while (window.isOpen())
	{
		window.clear(sf::Color::Cyan);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

	}

	return 0;
}