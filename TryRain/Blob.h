#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Blob {
public:
	Blob();
	Sprite getSprite();
	void setPosition(float x, float y);
	void update(float deltaTime);
private:
	Texture m_texture;
	Sprite m_sprite;
	IntRect m_tile;
	bool m_active = false;
};