#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class pagaia
{
public:
	pagaia();
	void draw(sf::RenderWindow& window);
	void Prawo();
	void Lewo();
	float dx, dy;
	int Ruch();
	int odbijanie();
	void zabijanieKwadratow(int z);
	void pisanie();
	int p;

private:

	sf::Texture teksturaPaletki;
	sf::Sprite paletka;

	sf::Texture teksturaPilki;
	sf::Sprite pilka;

	sf::Texture teksturaKwadratow;
	sf::Sprite kwadrat[68];

	sf::Font ksztaltLiter;
	sf::Text punkty;

	sf::Text help;
};