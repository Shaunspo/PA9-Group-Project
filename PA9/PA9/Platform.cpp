#include "Platform.h"

// Constructors and destructors
Platform::Platform() {
	posX = 0.f;
	posY = 0.f;
	width = 0.f;
	height = 0.f;
	rotation = 0.f;
	bricks.loadFromFile("images/building1.png");
	bricks.setRepeated(true);
}

Platform::~Platform() {

}

Platform::Platform(float xPos, float yPos, float w, float h, float rot) {
	posX = xPos;
	posY = yPos;
	width = w;
	height = h;
	rotation = rot;
}

// Setters and getters

float Platform::getXpos() {
	return this->posX;
}

float Platform::getYpos() {
	return this->posY;
}

float Platform::getWidth() {
	return this->width;
}

float Platform::getHeight() {
	return this->height;
}

float Platform::getRot() {
	return rotation;
}

RectangleShape Platform::getRect() {
	return rect;
}

void Platform::setXpos(float xPos) {
	posX = xPos;
}

void Platform::setYpos(float yPos) {
	posY = yPos;
}

void Platform::setWidth(float w) {
	width = w;
}

void Platform::setHeight(float h) {
	height = h;
}

void Platform::setRot(float rot) {
	rotation = rot;
}

void Platform::setRect(RectangleShape newRect) {
	rect = newRect;
}

// places a platform (unrendered. rendering happens in the level class).

void Platform::placePlatform() {
	rect.setFillColor(sf::Color::Magenta);
	rect.setSize(Vector2f(width, height));
	rect.setPosition(posX, posY);
	rect.setRotation(rotation);
}

void Platform::placePlatform(float xPos, float yPos, float w, float h, float rot) {
	rect.setFillColor(sf::Color::Magenta);
	rect.setSize(Vector2f(w, h));
	rect.setPosition(xPos, yPos);
	rect.setRotation(rot);
}

void Platform::renderPlatform(RenderTarget& target) {
	target.draw(this->rect);
}

// Overloaded methods for GroundPlatform and ThinPlatform classes

void GroundPlatform::placePlatform() {
	rect.setFillColor(sf::Color::White);
	rect.setSize(Vector2f(getWidth() * 64, getHeight() * 64));
	rect.setPosition(getXpos(), getYpos());
	rect.setRotation(0.f);
	rect.setTexture(&bricks);
	rect.setTextureRect(sf::IntRect(0, 0, 320, 320));
}

void GroundPlatform::placePlatform(float xPos, float yPos, float w, float h, float rot) {
	rect.setFillColor(sf::Color::Green);
	rect.setSize(Vector2f(w * 64, h * 64));
	rect.setPosition(xPos, yPos);
	rect.setRotation(0.f);
}

void ThinPlatform::placePlatform() {
	rect.setFillColor(sf::Color::Red);
	rect.setSize(Vector2f(getWidth() * 64, 10.f));
	rect.setPosition(getXpos(), getYpos());
	rect.setRotation(getRot());
}

void ThinPlatform::placePlatform(float xPos, float yPos, float w, float h, float rot) {
	rect.setFillColor(sf::Color::Red);
	rect.setSize(Vector2f(w * 64, 10.f));
	rect.setPosition(xPos, yPos);
	rect.setRotation(rot);
}

void Background::placePlatform() {
	rect.setFillColor(sf::Color::Magenta);
	rect.setSize(Vector2f(getWidth() * 64, getHeight() * 64));
	rect.setPosition(getXpos(), getYpos());
	rect.setRotation(0.f);
}

void Background::placePlatform(float xPos, float yPos, float w, float h, float rot) {
	rect.setFillColor(sf::Color::Magenta);
	rect.setSize(Vector2f(w * 64, h * 64));
	rect.setPosition(xPos, yPos);
	rect.setRotation(0.f);
}