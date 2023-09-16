#pragma once

#include "Polygon.h"

#define PI 3.14159

class Player1 : public Polygon
{
private:
	void initVariables();

public:

	Player1();

	Color fillColor;

	float speed;

	void UpdatePlayer(float dt);
};

