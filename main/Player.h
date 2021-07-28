#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"



class Player
{
public:
	Player (sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition();
	Collider GetCollider();



private:
	sf::RectangleShape body;
	
	unsigned int row;
	float speed;
	bool faceRight;	
};

