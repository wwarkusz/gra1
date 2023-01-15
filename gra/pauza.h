#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class pauza
{
public:
	void draw(sf::RenderWindow& window);
	pauza();

private:
	sf::RectangleShape rectangle;

	sf::Font ksztaltLiter;
	sf::Text stop;
};

