#include <string>
#include "pagaia.h"

pagaia::pagaia() {

	teksturaPaletki.loadFromFile("aaa.png");
	paletka.setTexture(teksturaPaletki);
	paletka.setTextureRect(sf::IntRect(0, 0, 120, 45));
	paletka.setPosition(400, 700);

	teksturaPilki.loadFromFile("bbb.png");
	pilka.setTexture(teksturaPilki);
	pilka.setTextureRect(sf::IntRect(0, 0, 20, 20));
	pilka.setPosition(400, 500);


	teksturaKwadratow.loadFromFile("ccc.png");
	for (int i = 0; i < 68; i++) {
		kwadrat[i].setTexture(teksturaKwadratow);
		kwadrat[i].setTextureRect(sf::IntRect(0, 0, 50, 50));
	}
	for (int i = 0; i < 17; i++) {
		kwadrat[i].setPosition(i * 70+15, 50);
	}
	for (int i = 17; i < 34; i++) {
		kwadrat[i].setPosition((i - 17) * 70+15, 120);
	}
	for (int i = 34; i < 51; i++) {
		kwadrat[i].setPosition((i - 34) * 70+15, 190);
	}
	for (int i = 51; i < 68; i++) {
		kwadrat[i].setPosition((i - 51) * 70+15, 260);
	}

	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {//pamietac zeby zmienic nazwe liter
		std::cout << "literki sie popsuly\n";
	}

	punkty.setFont(ksztaltLiter);
	punkty.setFillColor(sf::Color::Magenta);
	punkty.setCharacterSize(45);
	punkty.setPosition(1000, 730);
	p = 0;

	help.setFont(ksztaltLiter);
	help.setFillColor(sf::Color::White);
	help.setCharacterSize(15);
	help.setPosition(5, 15);
	help.setString("Space - Aiuto     Escape - Pauza/Menu");
}

void pagaia::draw(sf::RenderWindow& window) {
	window.draw(paletka);
	window.draw(pilka);
	window.draw(punkty);
	window.draw(help);
	for (int i = 0; i < 68; i++) {
		window.draw(kwadrat[i]);
	}
}

void pagaia::Prawo() {
	if (paletka.getPosition().x < 1100) {
		paletka.move(1, 0);
	}
}

void pagaia::Lewo() {
	if (paletka.getPosition().x > 0) {
		paletka.move(-1, 0);
	}
}

int pagaia::Ruch() {
	pilka.move(dx, dy);
	if (pilka.getPosition().x >= 1180) {
		dx = -dx;
	}
	if (pilka.getPosition().x <= 0) {
		dx = -dx;
	}
	if (pilka.getPosition().y <= 20) {
		dy = -dy;
	}
	if (pilka.getPosition().y >= 900) {
		pilka.setPosition(400, 500);
		return 9;
	}
	return 0;
}

int pagaia::odbijanie() {
	/*sf::IntRect niewidzialnaPilka(pilka.getPosition().x, pilka.getPosition().y, 20, 20);
	sf::IntRect niewidzialnaPaletka(paletka.getPosition().x, paletka.getPosition().y, 120, 45);
	if (niewidzialnaPilka.intersects(niewidzialnaPaletka)) {
		dy = -dy;
	}*/

	sf::IntRect niewidzialnaPilka(pilka.getPosition().x, pilka.getPosition().y, 20, 20);
	sf::IntRect niewidzialnaPaletka(paletka.getPosition().x, paletka.getPosition().y, 120, 45);
	if (niewidzialnaPilka.intersects(niewidzialnaPaletka)) {
		if (pilka.getPosition().y>680 && pilka.getPosition().y<682) {
			dy = -dy;
		}
		else {
			dx = -dx;
		}
	}


	sf::IntRect niewidzialnaTablica[68];
	for (int i = 0; i < 68; i++) {
		niewidzialnaTablica[i].left = kwadrat[i].getPosition().x;
		niewidzialnaTablica[i].top = kwadrat[i].getPosition().y;
		niewidzialnaTablica[i].height = 50;
		niewidzialnaTablica[i].width = 50;
		/*niewidzialnaTablica[i].setPosition(kwadrat[i].getPosition().x, kwadrat[i].getPosition().y);
		niewidzialnaTablica[i].setSize(sf::Vector2f(50, 50));*/
	}
	for (int j = 0; j < 68; j++) {
		if (niewidzialnaTablica[j].intersects(niewidzialnaPilka)) {
			std::cout << "\n zderzenie z kwadrat" << j;
			p = p + 1;
			return j;
		}
	}
	return -1;
}

void pagaia::zabijanieKwadratow(int z) {
	if (z != -1) {
		kwadrat[z].setPosition(2000, 2000);
		if (pilka.getPosition().y > 270 && pilka.getPosition().y < 300) {
			dx = -dx;
			std::cout << "x";
		}
		else if (pilka.getPosition().y > 200 && pilka.getPosition().y < 230) {
			dx = -dx;
			std::cout << "x";
		}

		else if (pilka.getPosition().y > 130 && pilka.getPosition().y < 160) {
			dx = -dx;
			std::cout << "x";
		}
		else if (pilka.getPosition().y > 60 && pilka.getPosition().y < 90) {
			dx = -dx;
			std::cout << "x";
		}
		else {
			dy = -dy;
		}
	}
}

void pagaia::pisanie() {
	punkty.setString("Punti: " + std::to_string(p));
}