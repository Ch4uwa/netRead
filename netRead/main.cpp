#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "defines.hpp"
#include "HttpRequest.h"
#include <time.h>




int main()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1200, 738), "SFML window with OpenGL", sf::Style::Default);

	window.setFramerateLimit(60);

	HttpRequest req;

	int die1 = (1 + rand() % 6);
	int die2 = (1 + rand() % 6);

	req.postToServer(die1, die2);
	
	sf::Texture texture;
	if (texture.loadFromFile("img/jonathansSkiss.jpg"))
	{
		std::cerr << "Failed to load texture";
	}
	
	sf::Sprite tex;
	tex.setTexture(texture);
	
	//window.setSize(sf::Vector2u(texture.getSize().x, texture.getSize().y));

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Failed to load font\n";
	}
	sf::Text text, uInput;
	text.setFont(font);
	uInput.setFont(font);
	text.setCharacterSize(12);
	uInput.setCharacterSize(12);

	sf::RectangleShape rect(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	rect.setOutlineThickness(4.f);
	rect.setOutlineColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(0.f, 0.f));
	rect.setFillColor(sf::Color::Transparent);

	text.setFillColor(sf::Color::Red);
	text.setString(req.readFromServer());
	uInput.setFillColor(sf::Color::Black);
	uInput.setPosition(rect.getGlobalBounds().left, rect.getGlobalBounds().top);

	sf::String temp;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					temp += event.text.unicode;
					uInput.setString(temp);
				}
			}
		}

		window.clear();
		window.draw(tex);
		window.draw(rect);

		window.draw(uInput);
		window.draw(text);


		window.display();
	}
}



