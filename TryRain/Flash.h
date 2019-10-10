#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Flash {
public:
	Flash(int screenX,int screenY);
	RectangleShape getShape();
	void setActive(bool value);
	bool getActive();
private:
	RectangleShape m_shape;
	Color m_color = Color::White;
	bool m_isActive = false;
};