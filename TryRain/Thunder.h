#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Thunder {
public:
	Thunder();
	Sprite getSprite();
	void setPosition(float x, float y);
	void update();
private:
	Texture m_texture;
	Sprite m_sprite;
	IntRect m_tile;
	Clock m_clock;
};