#include <iostream>
#include <ctime>
#include <random>

#include "SFML/Graphics.hpp"



int RGBGenerator()
{

	std::uniform_int_distribution<> d(1, 14620);
	std::mt19937 gen;

	int Zahl = (rand() % 255);

	std::cout << Zahl << std::endl;

	return Zahl;

}


int main()
{

	sf::RenderWindow window(sf::VideoMode(720, 720), "Horror Game");

	while (window.isOpen())
	{
		window.clear(sf::Color(RGBGenerator(), RGBGenerator(), RGBGenerator(), 255));
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


