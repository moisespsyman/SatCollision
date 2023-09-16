#include "SatCollision.h"

bool Sat_Overlap(Polygon& r1, Polygon& r2)
{
	Polygon* poly1 = &r1;
	Polygon* poly2 = &r2;

	for (int shape = 0; shape < 2; shape++)
	{
		if (shape == 1)
		{
			poly1 = &r2;
			poly2 = &r1;
		}

		for (int a = 0; a < poly1->p.size(); a++)
		{
			int b = (a + 1) % poly1->p.size();
			Vector2f axisProj = Vector2f(-(poly1->p[b].y - poly1->p[a].y), poly1->p[b].x - poly1->p[a].x);
	
			float min_r1 = INFINITY, max_r1 = -INFINITY;
			for (int p = 0; p < poly1->p.size(); p++)
			{
				float q = (poly1->p[p].x * axisProj.x + poly1->p[p].y * axisProj.y);
				min_r1 = std::min(min_r1, q);
				max_r1 = std::max(max_r1, q);
			}

			float min_r2 = INFINITY, max_r2 = -INFINITY;
			for (int p = 0; p < poly2->p.size(); p++)
			{
				float q = (poly2->p[p].x * axisProj.x + poly2->p[p].y * axisProj.y);
				min_r2 = std::min(min_r2, q);
				max_r2 = std::max(max_r2, q);
			}

			if (!(max_r2 >= min_r1 && max_r1 >= min_r2))
				return false;

		}
	}

	return true;

}

bool Sat_Overlap_STATIC(Polygon& r1, Polygon& r2)
{
	Polygon* poly1 = &r1;
	Polygon* poly2 = &r2;

	float overlap = INFINITY;

	for (int shape = 0; shape < 2; shape++)
	{
		if (shape == 1)
		{
			poly1 = &r2;
			poly2 = &r1;
		}

		for (int a = 0; a < poly1->p.size(); a++)
		{
			int b = (a + 1) % poly1->p.size();
			Vector2f axisProj = Vector2f(-(poly1->p[b].y - poly1->p[a].y), poly1->p[b].x - poly1->p[a].x);
	
			float min_r1 = INFINITY, max_r1 = -INFINITY;
			for (int p = 0; p < poly1->p.size(); p++)
			{
				float q = (poly1->p[p].x * axisProj.x + poly1->p[p].y * axisProj.y);
				min_r1 = std::min(min_r1, q);
				max_r1 = std::max(max_r1, q);
			}

			float min_r2 = INFINITY, max_r2 = -INFINITY;
			for (int p = 0; p < poly2->p.size(); p++)
			{
				float q = (poly2->p[p].x * axisProj.x + poly2->p[p].y * axisProj.y);
				min_r2 = std::min(min_r2, q);
				max_r2 = std::max(max_r2, q);
			}

			// Caluclate OverLap
			overlap = std::min(std::min(max_r1, max_r2) - std::max(min_r1, min_r2), overlap);

			if (!(max_r2 >= min_r1 && max_r1 >= min_r2))
				return false;

		}
	}

	Vector2f d = r2.pos - r1.pos;
	float s = sqrtf(d.x * d.x + d.y * d.y);
	r1.pos -= overlap * (d / s);

	return false;

}