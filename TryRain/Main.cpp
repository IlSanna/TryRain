#include <SFML/Graphics.hpp>
#include "Rain.h"

using namespace sf;

const int SCREEN_X = 400;
const int SCREEN_Y = 400;
const int dropsNumber = 20;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), "Rain",Style::None);

	//create storm
	Rain *storm = new Rain[dropsNumber];
	for (int i = 0; i != dropsNumber; ++i) {
		storm[i].Init(SCREEN_X, i);
	}

	Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == Keyboard::Escape) {
				window.close();
			}
		}
		//Update
		Time deltaTime = clock.restart();
		//update storm
		for (int i = 0; i != dropsNumber; ++i) {
			storm[i].Update(deltaTime.asSeconds(), SCREEN_Y,SCREEN_X,i);
		}
		//endUpdate
		//Draw
		window.clear(Color::Blue);
		//draw the storm
		for (int i = 0; i != dropsNumber; ++i) {
			window.draw(storm[i].getShape());
		}
		window.display();
	}

	delete[] storm;
	return 0;
}