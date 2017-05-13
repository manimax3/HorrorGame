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
	sf::Texture monitor_texture, button_texture, message1_texture, message2_texture, message3_texture, message4_texture;
	monitor_texture.loadFromFile("./res/Monitor.png");
	button_texture.loadFromFile("./res/Button.png");
	message1_texture.loadFromFile("./res/Message_1.png");
	message2_texture.loadFromFile("./res/Message_2.png");
	message3_texture.loadFromFile("./res/Message_3.png");
	message4_texture.loadFromFile("./res/Message_4.png");

	sf::Sprite monitor, button, message1, message2, message3, message4;
	monitor.setTexture(monitor_texture);
	monitor.setPosition(0.f, 0.f);

	button.setTexture(button_texture);
	button.setOrigin(sf::Vector2f(0.f, button.getLocalBounds().height));
	button.setPosition(20.f, window.getSize().y - 20);

	message1.setTexture(message1_texture);
	message1.setPosition(0, 0);

	message2.setTexture(message2_texture);
	message3.setTexture(message3_texture);
	message4.setTexture(message4_texture);

	bool button_pressed = false;
	int menu_status = 0;

	while (window.isOpen())
	{
		if (menu_status <= 3)
			window.clear(sf::Color(25, 25, 25));
		else
			window.clear(sf::Color(RGBGenerator(), RGBGenerator(), RGBGenerator(), 255));

		window.draw(monitor);

		if (menu_status == 0)
			window.draw(message1);

		else if (menu_status == 1)
			window.draw(message2);

		else if (menu_status == 2)
			window.draw(message3);

		else if (menu_status == 3)
			window.draw(message4);

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

				if (menu_status <= 3)
					menu_status++;
				else
				{
					const auto mouse_pos = sf::Mouse::getPosition() - window.getPosition();
					button_pressed = button.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y);
					if (button_pressed)
						std::cout << "Pressed" << std::endl; // Stop the flickering
				}
			}
		}

	}

	return 0;
}


