#include "Thunder.h"

Thunder::Thunder(): m_tile(0,0,32,32) {
	m_texture.loadFromFile("Image/thunder.png");
	m_sprite.setTextureRect(m_tile);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(16, 16);
	m_sprite.setScale(3, 3);
}
void Thunder::update() {
	if (m_clock.getElapsedTime().asMilliseconds() > 200.0f) {
		if (m_tile.left == 64) {//change row
			m_tile.left = 0;
			m_tile.top += 32;
		}
		else {//go left
			m_tile.left += 32;
		}
		if (m_tile.left == 32 && m_tile.top == 64) {//if we reach the last image->reset-loop
			m_tile.left = 0;
			m_tile.top = 0;
		}
		m_sprite.setTextureRect(m_tile);
		m_clock.restart();
	}
}
Sprite Thunder::getSprite() {
	return m_sprite;
}

void Thunder::setPosition(float x,float y) {
	m_sprite.setPosition(x,y);
}
