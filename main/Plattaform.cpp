#include "Plattaform.h"

 Plattaform:: Plattaform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	 body.setTexture(texture);
	 body.setSize(size);
	 body.setOrigin(size / 2.0f);
	 body.setPosition(position);

}

Plattaform::~Plattaform()
{
}

void Plattaform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
