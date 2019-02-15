#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "defines.hpp"
#include "HttpRequest.h"
#include <time.h>




int main()
{
	srand(time(NULL));
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML window with OpenGL", sf::Style::Default);
	// Make it the active window for OpenGL calls
	window.setActive();

	HttpRequest req;

	int die1 = (1+rand() % 6);
	int die2 = (1+rand() % 6);

	req.postToServer(die1,die2);

	

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Failed to load font\n";
	}

	sf::Text text,text2;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(12);
	text.setString(req.readFromServer());

	text2.setFont(font);
	text2.setFillColor(sf::Color::Blue);
	text2.setCharacterSize(12);
	text2.setString("HEJ!");
	text2.setPosition(sf::Vector2f(300.f, 0.f));



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
		}

	window.clear(sf::Color::Black);
	
	window.draw(text2);
	window.draw(text);
	

	window.display();
	}
}



