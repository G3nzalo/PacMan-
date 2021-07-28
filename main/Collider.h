#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:

	Collider(sf:: RectangleShape& body);
	~Collider();

	bool CheckCollision(Collider& other , float push);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();
	
	void Move(float dx, float dy);

private:
	sf::RectangleShape& body;


};

