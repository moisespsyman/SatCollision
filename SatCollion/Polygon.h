#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Polygon
{
public:

	std::vector<Vector2f> p;
	Vector2f pos;

	float angle;

	std::vector<Vector2f> o;
	
	VertexArray shapesVertext;

	void update();
	void render(RenderTarget* target);
};

