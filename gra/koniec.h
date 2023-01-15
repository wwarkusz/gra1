#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class koniec
{
public:
	koniec();
	void draw(sf::RenderWindow& window);
private:
	sf::Font ksztaltLiter;
	sf::Text end;
	sf::Text END;
};

