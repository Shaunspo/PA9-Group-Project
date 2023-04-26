#pragma once

#include "Platform.h"

class Level {
public:

	Level();

	~Level();
	
	void buildLevel();

	void renderLevel(RenderTarget& target);

	float getGroundXpos(int i);

	float getGroundYpos(int i);

	float getGroundWidth(int i);

	float getGroundHeight(int i);

	float getThinXpos(int i);

	float getThinYpos(int i);

	float getThinWidth(int i);

	float getThinHeight(int i);
	
	float getThinRot(int i);

private:
	GroundPlatform ground[50];
	ThinPlatform thin[50];
	ThinPlatform balcony[50];
	Background background[50];
};
