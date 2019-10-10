#include "Flash.h"

Flash::Flash(int screenX, int screenY) {
	m_shape.setSize(Vector2f(screenX , screenY ));
	m_shape.setOrigin(m_shape.getSize().x/2, m_shape.getSize().y / 2);
	m_shape.setPosition(screenX/2, screenY/2);
	m_color.a = 75.0f;
	m_shape.setFillColor(m_color);
}
void Flash::Update(Time &timeTotal) {
	if (timeTotal.asMilliseconds() > m_flashTimer ) {
		srand((int)time(0) * timeTotal.asMilliseconds());
		m_flashTimer = (rand() % 1500) + 300;
		if (!m_isActive) {
			m_isActive = true;
			timeTotal = Time::Zero;
		}
		else {
			m_isActive = false;
			timeTotal = Time::Zero;
		}
	}
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

