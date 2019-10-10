#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Rain {
public:
	Rain();
	void Update(float enlapsedTime, float screenY, float screenX, int seed);
	void Init( float screenX,int seed);
	void setPosition(Vector2f position);
	void setSpeed(float speed);
	void setShapeColor(Color color);
	RectangleShape getShape();
	Vector2f getPosition();
	float getSpeed();

private:
	Vector2f m_position;
	RectangleShape m_shape;
	float m_speed = 0;
	const float m_dropLenght = 40.0f;
};