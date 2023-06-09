#include "Level.h"

Level::Level() {

}

Level::~Level() {

}



float Level::getGroundXpos(int i) {
	return ground[i].getXpos();
}

float Level::getGroundYpos(int i) {
	return ground[i].getYpos();
}

float Level::getGroundWidth(int i) {
	return ground[i].getWidth();
}

float Level::getGroundHeight(int i) {
	return ground[i].getHeight();
}

float Level::getThinXpos(int i) {
	return thin[i].getXpos();
}

float Level::getThinYpos(int i) {
	return thin[i].getYpos();
}

float Level::getThinWidth(int i) {
	return thin[i].getWidth();
}

float Level::getThinHeight(int i) {
	return thin[i].getHeight();
}

float Level::getThinRot(int i) {
	return thin[i].getRot();
}

void Level::buildLevel() {
	
	// Test Case 4
	// ground[0].setHeight(10.f);
	// ground[0].setWidth(10.f);
	// ground[0].setXpos(0.f);
	// ground[0].setYpos(500.f);
	// ground[0].placePlatform();

	// Test Case 5
	// thin[0].setHeight(10.f);
	// thin[0].setWidth(10.f);
	// thin[0].setXpos(0.f);
	// thin[0].setYpos(500.f);
	// thin[0.setRot(36.f);
	// ground[0].placePlatform();
	
	
	
	
	
	srand(time(NULL));
	int platDecider;
	int balconyDecider;
	int angleDecider;
	int prevPlatType; // 0 for GroundPlatform, 1 for ThinPlatform
	for (int i = 0; i < 50; i++) {
		if (i == 0) {
			ground[i].setHeight(10.f);
			ground[i].setWidth(10.f);
			ground[i].setXpos(0.f);
			ground[i].setYpos(500.f);
			ground[i].placePlatform();
			prevPlatType = 0;
		}
		if (i == 49) {
			if (prevPlatType == 0) {
				ground[i].setHeight(20.f);
				ground[i].setWidth(20.f);
				ground[i].setXpos(ground[i - 1].getXpos() + (ground[i - 1].getWidth() * 64) + rand() % 200 + 100);
				ground[i].setYpos(500.f);
				ground[i].placePlatform();
				prevPlatType = 0;
			}
			else {
				ground[i].setHeight(20.f);
				ground[i].setWidth(20.f);
				ground[i].setXpos(thin[i - 1].getXpos() + (thin[i - 1].getWidth() * 64) + rand() % 200 + 100);
				ground[i].setYpos(500.f);
				ground[i].placePlatform();
				prevPlatType = 0;
			}
		}
		else {
			platDecider = rand() % 4;
			if (platDecider == 3) {
				if (prevPlatType == 0) {
					thin[i].setXpos(ground[i - 1].getXpos() + (ground[i - 1].getWidth() * 64) + rand() % 200 + 100);
					thin[i].setWidth(rand() % 10 + 5);
					thin[i].setYpos(rand() % 500 + 300);
					angleDecider = rand() % 2 + 1;
					if (angleDecider == 1) {
						thin[i].setRot(15);
					}
					else {
						thin[i].setRot(345);
					}
					thin[i].placePlatform();
					prevPlatType = 1;
				}
				else {
					thin[i].setXpos(thin[i - 1].getXpos() + (thin[i - 1].getWidth() * 64) + rand() % 200 + 100);
					thin[i].setWidth(rand() % 10 + 5);
					thin[i].setYpos(rand() % 500 + 300);
					angleDecider = rand() % 2 + 1;
					if (angleDecider == 1) {
						thin[i].setRot(15);
					}
					else {
						thin[i].setRot(345);
					}
					thin[i].placePlatform();
					prevPlatType = 1;
				}
			}
			else {
				if (prevPlatType == 0) {
					ground[i].setHeight(20.f);
					ground[i].setWidth(rand() % 15 + 5);
					ground[i].setXpos(ground[i - 1].getXpos() + (ground[i - 1].getWidth() * 64) + rand() % 200 + 100);
					ground[i].setYpos(rand() % 500 + 300);
					ground[i].placePlatform();
					prevPlatType = 0;
				}
				else {
					ground[i].setHeight(20.f);
					ground[i].setWidth(rand() % 15 + 5);
					ground[i].setXpos(thin[i - 1].getXpos() + (thin[i - 1].getWidth() * 64) + rand() % 200 + 100);
					ground[i].setYpos(rand() % 500 + 300);
					ground[i].placePlatform();
					prevPlatType = 0;
				}
			}
		}
	}
}

void Level::renderLevel(RenderTarget& target) {
	for (int i = 0; i < 50; i++) {
		target.draw(this->ground[i].getRect());
	}
	for (int j = 0; j < 50; j++) {
		target.draw(this->thin[j].getRect());
	}
}

const RectangleShape Level::getGroundShape(int i)
{
	return ground[i].getRect();
}

const RectangleShape Level::getThinShape(int i)
{
	return thin[i].getRect();
}
