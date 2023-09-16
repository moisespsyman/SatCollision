#include "Polygon.h"
	

void Polygon::update()
{
	for (int i = 0; i < o.size(); i++)
	{

		
		p[i] =
		{	// 2D Rotation Transform + 2D Translation
			(o[i].x * cosf(angle)) - (o[i].y * sinf(angle)) + pos.x,
			(o[i].x * sinf(angle)) + (o[i].y * cosf(angle)) + pos.y,
		};

		this->shapesVertext[i].position = p[i];

	}

}

void Polygon::render(RenderTarget* target)
{
	target->draw(this->shapesVertext);
}

