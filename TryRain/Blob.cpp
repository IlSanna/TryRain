#include "Blob.h"

Blob::Blob(): m_tile(0,0,32,32) {
	m_texture.loadFromFile("thunder.png");
	m_sprite.setTextureRect(m_tile);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(16, 16);
	m_sprite.setScale(3, 3);
}
void Blob::update(float deltaTime) {
	if (Keyboard::isKeyPressed(Keyboard::A) && !m_active) {
		m_active = true;
		//think for 96x96
		if (m_tile.left == 96) {
			m_tile.left = 0;
			m_tile.top += 32;
		}
		else {
			m_tile.left += 32;
		}
		m_sprite.setTextureRect(m_tile);
	}
	else if (!Keyboard::isKeyPressed(Keyboard::A)) {
		m_active = false;
	}
}
Sprite Blob::getSprite() {
	return m_sprite;
}

void Blob::setPosition(float x,float y) {
	m_sprite.setPosition(x,y);
}
