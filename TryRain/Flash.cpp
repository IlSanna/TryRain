#include "Flash.h"

Flash::Flash(int screenX, int screenY) {
	m_shape.setSize(Vector2f(screenX , screenY ));
	m_shape.setOrigin(m_shape.getSize().x/2, m_shape.getSize().y / 2);
	m_shape.setPosition(screenX/2, screenY/2);
	m_color.a = 75.0f;
	m_shape.setFillColor(m_color);
	m_buffer.loadFromFile("Audio/thunder.wav");
	m_sound.setBuffer(m_buffer);
}
void Flash::Update(Time &timeTotal) {
	if (timeTotal.asMilliseconds() > m_flashTimer ) {
		m_flashTimer = randomRange(300, 1600);
		if (!m_isActive) {
			if (m_sound.getStatus() != Sound::Playing) {
				m_sound.play();
			}
			m_isActive = true;
			timeTotal = Time::Zero;
		}
		else {
			m_isActive = false;
			timeTotal = Time::Zero;
		}
	}
}
int Flash::randomRange(int min, int max) {
	return rand() % (max - min + 1) + min;
}
RectangleShape Flash::getShape() {
	return m_shape;
}

void Flash::setActive(bool value) {
	m_isActive = value;
}

bool Flash::getActive() {
	return m_isActive;
}

