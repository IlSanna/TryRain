#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

using namespace sf;

class Flash {
public:
	Flash(int screenX,int screenY);
	void Update(Time &timeTotal);
	int randomRange(int min, int max);
	RectangleShape getShape();
	void setActive(bool value);
	bool getActive();
private:
	RectangleShape m_shape;
	Color m_color = Color::White;
	bool m_isActive = false;
	float m_flashTimer = 300;
	SoundBuffer m_buffer;
	Sound m_sound;
};