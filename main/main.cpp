// main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Plattaform.h"
#include "Player.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 600), "SFML works!");
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("pacmanAnim.png");
	Player player(&playerTexture, sf::Vector2u(3, 1),0.003f,15000.0f);

	 Plattaform plattaform1(nullptr, sf::Vector2f(900.0f, 40.0f), sf::Vector2f(450.0f, 0.0f));
	 Plattaform plattaform2(nullptr, sf::Vector2f(40.0f, 600.0f), sf::Vector2f(900.0f, 300.0f));
	 Plattaform plattaform3(nullptr, sf::Vector2f(40.0f, 600.0f), sf::Vector2f(0.0f, 300.0f));
	 Plattaform plattaform4(nullptr, sf::Vector2f(900.0f, 40.0f), sf::Vector2f(450.0f, 600));

	 //Plattaform plattaform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Event event;
		float deltaTime = 0.0f;
		sf::Clock clock;

		//tiempo = clock.getElapsedTime();        

		while (window.pollEvent(event))
		{

			deltaTime = clock.restart().asSeconds();
			
			player.Update(deltaTime);
			Collider playerCollider = player.GetCollider();
			plattaform1.GetCollider().CheckCollision(playerCollider, 1.0f);
			plattaform2.GetCollider().CheckCollision(playerCollider, 1.0f);
			plattaform3.GetCollider().CheckCollision(playerCollider, 1.0f);
			plattaform4.GetCollider().CheckCollision(playerCollider, 1.0f);


			//plattaform2.GetCollider().CheckCollision(playerCollider, 1.0f);
			window.clear();

			//window.clear(sf::Color(150, 150, 150));
			player.Draw(window);
			plattaform1.Draw(window);
			plattaform2.Draw(window);
			plattaform3.Draw(window);
			plattaform4.Draw(window);



			window.display();

		}
	}
}
