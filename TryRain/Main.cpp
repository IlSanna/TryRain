#include <SFML/Graphics.hpp>
#include "Rain.h"
#include "Flash.h"

using namespace sf;

const int SCREEN_X = 800;
const int SCREEN_Y = 400;
const int dropsNumber = 50;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), "Rain",Style::None);

	//create storm
	Rain *storm = new Rain[dropsNumber];
	for (int i = 0; i != dropsNumber; ++i) {
		storm[i].Init(SCREEN_X, i);
	}
	Flash flash(SCREEN_X,SCREEN_Y);

	Clock clock;
	Time totalTime;
	float timer = 300;

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
		totalTime += deltaTime;
		
		//update Flash
		if (totalTime.asMilliseconds() > timer ) {
			srand((int)time(0) * totalTime.asMilliseconds());
			timer = (rand() % 1500) + 300;
			if (!flash.getActive()) {
				flash.setActive(true);
				totalTime = Time::Zero;
			}
			else {
				flash.setActive(false);
				totalTime = Time::Zero;
			}
		}
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
		if (flash.getActive()) {
			window.draw(flash.getShape());
		}
		window.display();
	}

	delete[] storm;
	return 0;
}