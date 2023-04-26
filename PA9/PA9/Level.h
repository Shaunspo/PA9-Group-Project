#pragma once

#include "Platform.h"

class Level {
public:

	Level();

	~Level();
	
	void buildLevel();

	void renderLevel(RenderTarget& target);

private:
	GroundPlatform ground[50];
	ThinPlatform thin[50];
	ThinPlatform balcony[50];
	Background background[50];
};
