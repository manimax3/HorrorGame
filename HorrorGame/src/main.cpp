#include <iostream>

#include "SFML/Graphics.hpp"

int main()
{

	sf::RenderWindow window(sf::VideoMode(720, 720), "Horror Game");
	sf::Texture monitor_texture, button_texture;
	monitor_texture.loadFromFile("./res/Monitor.png");
	button_texture.loadFromFile("./res/Button.png");

	sf::Sprite monitor, button;
	monitor.setTexture(monitor_texture);
	monitor.setPosition(0.f, 0.f);

	button.setTexture(button_texture);
	button.setOrigin(sf::Vector2f(0.f, button.getLocalBounds().height));
	button.setPosition(20.f, window.getSize().y - 20);

	bool button_pressed = false;

	while (window.isOpen())
	{
		window.clear(sf::Color(6.f, 6.f, 6.f));

		window.draw(monitor);
		window.draw(button);

		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				const auto mouse_pos = sf::Mouse::getPosition() - window.getPosition();
			}
		}

	}

	return 0;
}