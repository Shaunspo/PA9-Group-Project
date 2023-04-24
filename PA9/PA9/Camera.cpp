#include "Camera.h"

Camera::Camera(double width, double height) {

	camera.setSize(width, height);

}


void Camera::update(const sf::Vector2f& playerPosition) {

	camera.setCenter(playerPosition);

}

const sf::View& Camera::getCamera() const {

	return camera;

}

void Camera::setCamera(const sf::View view)
{
	camera = view;
}



