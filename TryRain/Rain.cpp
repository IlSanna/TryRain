#include "Rain.h"
//constructor, give a value to position and size
Rain::Rain() : m_position(Vector2f(-100,-100)) {//costruire con random speed
	m_shape.setSize(Vector2f(3, m_dropLenght));
}
/*initialize each drops with randon:
-position x;
-size;
-speed;
*/
void Rain::Init( float screenX, int seed) {
	srand((int)time(0) * seed);
	m_speed = (rand() % 300)+150;//between 150 and 450
	srand((int)time(0) * seed * 2);
	m_shape.setSize(Vector2f( 3 , m_dropLenght - (rand() % 25)) );//different shapes
	srand((int)time(0) * seed * 10);//random num
	//m_shape.setPosition((rand() % (int)screenX), this->getPosition().y);
	m_shape.setPosition((rand() % (int)screenX), -(rand() % 100) );//choose which version is better
}
/*update drops positions in time, if the reach the end of the
screen, reinitialize the drops and set the position on the top of the screen*/
void Rain::Update(float enlapsedTime, float screenY,float screenX, int seed) {
	m_shape.setPosition(this->getPosition().x, this->getPosition().y + m_speed * enlapsedTime);
	if (this->getPosition().y > screenY) {
		Init(screenX, seed);
		m_shape.setPosition(this->getPosition().x, -m_dropLenght);
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
