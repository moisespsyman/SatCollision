#include "Player1.h"

void Player1::initVariables()
{
	shapesVertext = VertexArray(TriangleFan, 3);

	fillColor = Color(255, 51, 255);

	pos = Vector2f(500.f, 360.f);
	angle = 0.0f;
	speed = 325.f;

	const float theta = PI * 2.0f / 3.0f;

	for (int i = 0; i < 3; i++)
	{
		o.push_back({ 32 * std::cosf(theta * i), 32 * std::sinf(theta * i)});
		p.push_back({ 32 * std::cosf(theta * i), 32 * std::sinf(theta * i)});

		shapesVertext[i].color = fillColor;
	}

}

Player1::Player1()
{

	initVariables();

}

void Player1::UpdatePlayer(float dt)
{

	if (Keyboard::isKeyPressed(Keyboard::A)) angle -= 6 * dt;
	if (Keyboard::isKeyPressed(Keyboard::D)) angle += 6 * dt;
	
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		pos.x += std::cosf(angle) * speed * dt;
		pos.y += std::sinf(angle) * speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		pos.x -= std::cosf(angle) * speed * dt;
		pos.y -= std::sinf(angle) * speed * dt;
	}

	for (int i = 0; i < 3; i++)
	{
		shapesVertext[i].color = fillColor;
	}

}
