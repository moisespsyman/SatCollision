#pragma once

#include "Polygon.h"

class Player2 : public Polygon
{private:
	void initVariables();

public:

	Player2();

	Color fillColor;

	float speed;

	void UpdatePlayer(float dt);

};

