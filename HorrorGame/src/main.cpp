#include <iostream>
#include <ctime>
#include <random>

#include "SFML/Graphics.hpp"



std::uniform_int_distribution<> d(0, 255);
std::mt19937 gen;
int RGBGenerator()
{
	return d(gen);
}


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
		window.clear(sf::Color(RGBGenerator(), RGBGenerator(), RGBGenerator(), 255));

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
				button_pressed = button.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y);
				if (button_pressed)
					std::cout << "Pressed" << std::endl; // Stop the flickering
			}
		}

	}

	return 0;
}


