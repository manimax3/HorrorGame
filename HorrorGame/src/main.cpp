#include <iostream>
#include <ctime>
#include <random>
#include <array>

#include "SFML/Graphics.hpp"



std::uniform_int_distribution<> d(0, 255);
std::mt19937 gen;
int RGBGenerator()
{
	return d(gen);
}


constexpr unsigned int NUMBER_MENUES = 4;


int main()
{

	sf::RenderWindow window(sf::VideoMode(720, 720), "Horror Game");

	sf::Texture monitor_texture, button_texture;
	std::array<sf::Texture, NUMBER_MENUES> message_textures;


	monitor_texture.loadFromFile("./res/Monitor.png");
	button_texture.loadFromFile("./res/Button.png");

	for (int i = 0; i < message_textures.size(); ++i)
		message_textures[i].loadFromFile(std::string("./res/Message_") + std::to_string(i + 1) + ".png");

	sf::Sprite monitor, button;

	monitor.setTexture(monitor_texture);
	monitor.setPosition(0.f, 0.f);

	button.setTexture(button_texture);
	button.setOrigin(sf::Vector2f(0.f, button.getLocalBounds().height));
	button.setPosition(20.f, window.getSize().y - 20);

	std::array<sf::Sprite, NUMBER_MENUES> messages;

	for (int i = 0; i < messages.size(); ++i)
		messages[i].setTexture(message_textures[i]);

	bool button_pressed = false;
	int menu_status = 0;

	while (window.isOpen())
	{
		if (menu_status <= NUMBER_MENUES - 1)
			window.clear(sf::Color(25, 25, 25));
		else
			window.clear(sf::Color(RGBGenerator(), RGBGenerator(), RGBGenerator(), 255));

		window.draw(monitor);

		if (menu_status <= NUMBER_MENUES - 1)
			window.draw(messages[menu_status]);

		else
		{
			window.clear(sf::Color(RGBGenerator(), RGBGenerator(), RGBGenerator(), 255));
			window.draw(monitor);
			window.draw(button);
		}

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
				if (menu_status <= NUMBER_MENUES - 1)
					menu_status++;
				else
				{
					const auto mouse_pos = sf::Mouse::getPosition() - window.getPosition();
					button_pressed = button.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y);
					if (button_pressed)
					{
						window.close();
					}
				}
			}
		}

	}

	return 0;
}


