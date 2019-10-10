#include "Rain.h"
//constructor, give a value to position and size
Rain::Rain() : m_position(Vector2f(-100,-100)) {//costruire con random speed
	m_shape.setSize(Vector2f(1.5f, m_dropLenght));
}
/*initialize each drops with randon:
-position x;
-size;
-speed;
*/
void Rain::Init( int screenX, int seed) {
	srand((int)time(0) * seed);
	m_speed = (rand() % 300)+450;//between 450 and 750
	srand((int)time(0) * seed * 2);
	m_shape.setSize(Vector2f( 3 , m_dropLenght - (rand() % 25)) );//different shapes
	srand((int)time(0) * seed * 3);//random num
	m_shape.setPosition((rand() % screenX), -(rand() % 100) );
}
/*update drops positions in time, if the reach the end of the
screen, reinitialize the drops */
void Rain::Update(float enlapsedTime, float screenY,float screenX, int seed) {
	m_shape.setPosition(this->getPosition().x, this->getPosition().y + m_speed * enlapsedTime);
	if (this->getPosition().y > screenY) {
		Init(screenX, seed );
	}
}

void Rain::setPosition(Vector2f position) {
	m_shape.setPosition(position);
}
void Rain::setSpeed(float speed) {
	m_speed = speed;
}
void Rain::setShapeColor(Color color) {
	m_shape.setFillColor(color);
}
RectangleShape Rain::getShape() {
	return m_shape;
}
Vector2f Rain::getPosition() {
	return m_shape.getPosition();
}
float Rain::getSpeed() {
	return m_speed;
}
