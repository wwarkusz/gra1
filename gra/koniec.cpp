#include "koniec.h"

koniec::koniec() {
	if (!ksztaltLiter.loadFromFile("czcionka.otf")) {
		std::cout << "literki sie popsuly\n";
	}

	end.setFont(ksztaltLiter);
	end.setFillColor(sf::Color::Magenta);
	end.setCharacterSize(80);
	end.setString("Mamma mia");
	end.setPosition(350, 200);

	END.setFont(ksztaltLiter);
	END.setFillColor(sf::Color::White);
	END.setCharacterSize(30);
	END.setString("Space - Menu");
	END.setPosition(490, 300);
}

void koniec::draw(sf::RenderWindow& window) {
	window.draw(end);
	window.draw(END);
}