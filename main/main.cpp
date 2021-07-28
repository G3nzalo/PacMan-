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

	//sf::RectangleShape shape;
	//shape.setSize(sf::Vector2f(900.0f, 30.0f));

	//sf::RectangleShape shape3;
	//shape3.setSize(sf::Vector2f(500.0f, 30.0f));
	//shape3.setFillColor(sf::Color::Red);
	//shape3.setPosition(0.0f, 100.0f);
	//shape.setOrigin(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2);

	//shape.setFillColor(sf::Color::Red);
	//shape.setPosition(0.0f, 0.0f);

	//sf::CircleShape shape2(10.0f);
	//shape2.setFillColor(sf::Color::Red);
	//shape2.setPosition(500.0f, 300.0f);

	/*
	sf::Texture textureImg;
	sf::IntRect rectSourceSprite(0, 0, 220, 210);
	textureImg.loadFromFile("pacmanAnim.png");
	sf::Sprite sprite(textureImg, rectSourceSprite);
	*/

	//sprite.setTexture(textureImg);
	//sprite.setOrigin(110.0f, 105.0f);
	//sprite.setScale(0.3f, 0.3f);
	//sprite.setPosition(450, 300);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("pacmanAnim.png");

	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);

	Plattaform plattaform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Plattaform plattaform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));


	sf::Clock deltaClock;
	float velocidad = 100.0f;

	int vida = 1;
	int vida2 = 1;
	bool col = false;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time deltaTime;

		//tiempo = clock.getElapsedTime();        

		while (window.pollEvent(event))
		{

			deltaTime = deltaClock.restart();
			/*
						if (sprite.getGlobalBounds().intersects(shape.getGlobalBounds()))
						{
							col = true;
							//shape.~CircleShape();
							//vida = 0;
						}

						if (sprite.getGlobalBounds().intersects(shape2.getGlobalBounds()))
						{
							shape2.~CircleShape();
							vida2 = 0;
						}

						if (event.type == sf::Event::Closed)
							window.close();

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
								!sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
								!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
							{
								sprite.setRotation(0);
								sprite.move(velocidad * deltaTime.asSeconds(), 0.0f);
								rectSourceSprite.left += 220.0f;
							}

						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						{
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&
								!sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&
									!sf::Keyboard::isKeyPressed(sf::Keyboard::S))

							{
								sprite.setRotation(180);
									sprite.move(velocidad * deltaTime.asSeconds() * -1.0f, 0.0f);
									rectSourceSprite.left += 220.0f;
							}

						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sprite.getGlobalBounds().intersects(shape.getGlobalBounds()))
						{
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
								!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
								!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
							{
								sprite.setRotation(270);
								sprite.move(0.0f, velocidad * deltaTime.asSeconds() * -1.0f);
								rectSourceSprite.left += 220.0f;
							}
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
								!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
								!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							{


								sprite.setRotation(90);
								sprite.move(0.0f, velocidad * deltaTime.asSeconds());
								rectSourceSprite.left += 220.0f;
							}

						}
						if (rectSourceSprite.left == 660)
						{
							rectSourceSprite.left = 0;
						}
						//else
						//{
							//	rectSourceSprite.left += 220.0f;
						//}

						sprite.setTextureRect(rectSourceSprite);

					}
					

					if(vida != 0)
					{

					}
					if (vida2 != 0)
					{
						window.draw(shape2);
					}*/
					//window.draw(shape);
					//window.draw(shape3);

					//window.draw(sprite);
			player.Update(deltaTime.asSeconds());
			Collider playerCollider = player.GetCollider();
			plattaform1.GetCollider().CheckCollision(playerCollider, 1.0f);
			//plattaform2.GetCollider().CheckCollision(playerCollider, 1.0f);
			window.clear();

			//window.clear(sf::Color(150, 150, 150));
			player.Draw(window);
			plattaform1.Draw(window);
			plattaform1.Draw(window);
			window.display();

		}
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
