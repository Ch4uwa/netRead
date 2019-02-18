#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "defines.hpp"
#include "HttpRequest.h"
#include <time.h>


constexpr int HEIGTH = 1200;
constexpr int WIDTH = 738;

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(HEIGTH, WIDTH), "Stuff From Server", sf::Style::Default);
	window.setFramerateLimit(60);
	sf::Font font;
	sf::Text text, text2, responseText;
	sf::View view;
	unsigned short data1 = (rand() % 100), data2 = (rand() % 200);


	// Load fonts
	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Failed to load font\n";
	}


	text.setFont(font);
	text2.setFont(font);
	responseText.setFont(font);

	text.setCharacterSize(16);
	text2.setCharacterSize(16);
	responseText.setCharacterSize(16);

	text.setFillColor(sf::Color::Red);
	text2.setFillColor(sf::Color::Blue);
	responseText.setFillColor(sf::Color::Blue);
	text.setPosition(sf::Vector2f(100.f, 0.f));
	text2.setPosition(sf::Vector2f(0.f, 0.f));
	responseText.setPosition(sf::Vector2f(0.f, 20.f));



	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(1.f);
	rect.setOutlineColor(sf::Color::Yellow);

	sf::String temp, responseString, temp3;


	HttpRequest req;
	std::string a = "";
	view.reset(sf::FloatRect(0, 0, HEIGTH, WIDTH));
	view.setCenter(HEIGTH / 2, WIDTH / 2);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::Enter:

					temp3 = req.postToServer(temp, data1, data2);
					responseString = req.readFromServer(temp);
					responseText.setString(responseString);
					temp = "URL Response: " + temp3;
					break;

				case sf::Keyboard::Up:

					view.move(sf::Vector2f(0, 16.f));
					break;

				case sf::Keyboard::Down:
					view.move(sf::Vector2f(0, -16.f));
					break;

				default:
					break;
				}
				break;
			}
			case sf::Event::TextEntered:
			{
				if (event.text.unicode <= 128)
				{
					if (event.text.unicode == '\b' && temp.getSize() > 0)
					{
						temp.erase(temp.getSize() - 1, 2);
					}
					else if (event.text.unicode != '\b')
					{
						temp += static_cast<char>(event.text.unicode);
					}
				}
			}
			break;
			default:
				break;
			}
		}
		text2.setPosition(sf::Vector2f(rect.getGlobalBounds().width + 1, 0));

		sf::Vector2f txtbound(responseText.getGlobalBounds().width + 1, responseText.getGlobalBounds().height);
		rect.setSize(txtbound);
		rect.setPosition(sf::Vector2f(responseText.getPosition()));

		text2.setString(temp);
		window.setView(view);

		window.clear(sf::Color::Black);

		// draw
		window.draw(text2);
		window.draw(responseText);

		window.draw(rect);

		if (responseText.getPosition().y + responseText.getGlobalBounds().height > window.getSize().y)
		{

			std::cout << "X: " << responseText.getPosition().x << " Y: " << responseText.getPosition().y << "\n";
			responseText.move(sf::Vector2f(0, -4.f));
		}
		/*if (text3.getPosition().y + text3.getGlobalBounds().height <= 0)
		{
			LOG(text3.getPosition().y << text3.getPosition().x);
			text3.setPosition(sf::Vector2f(0, window.getSize().y));
		}*/

		window.display();
	}
}



