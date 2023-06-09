#include "Player2.h"

void Player2::initVariables()
{

	shapesVertext = VertexArray(TrianglesFan, 4);

	fillColor = Color(51, 255, 255, 255);

	pos = Vector2f(800.f, 360.f);
	angle = 0.f;
	speed = 325.f;

	for (int i = 0; i < 4; i++)
	{
		shapesVertext[i].color = fillColor;
	}

	o.push_back({-32.f, -32.f});
	o.push_back({-32.f, 32.f});
	o.push_back({32.f, 32.f});
	o.push_back({32, -32});

	p.resize(4);

}

Player2::Player2()
{
	initVariables();
}

void Player2::UpdatePlayer(float dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) angle -= 6 * dt;
	if (Keyboard::isKeyPressed(Keyboard::Right)) angle += 6 * dt;
	
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		pos.x += std::cosf(angle) * speed * dt;
		pos.y += std::sinf(angle) * speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		pos.x -= std::cosf(angle) * speed * dt;
		pos.y -= std::sinf(angle) * speed * dt;
	}
}
