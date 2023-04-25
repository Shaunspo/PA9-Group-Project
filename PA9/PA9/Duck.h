#pragma once
#include "Entity.h"

class Duck : public Entity
{
private:

public:
	Duck();

	//Core
	void initSprite() override;
};

