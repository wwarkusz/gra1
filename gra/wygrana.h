#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class wygrana
{
public:
	wygrana();
	void draw(sf::RenderWindow& window);
private:
	sf::Font ksztaltLiter;
	sf::Text win;
	sf::Text WIN;
};