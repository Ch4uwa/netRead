#ifndef RESOURCEMANAGER_H
#define RESOURCE MANAGER_H

#include <SFML/Graphics.hpp>

#include <string>
#include <map>


class resourceManager
{
private:

	std::map<std::string, sf::Texture> texture;
	std::map<std::string, sf::Font> fonts;

public:
	void loadTexture(const std::string& name, const std::string& filename);
	void loadFont(const std::string& name, const std::string& filename);

	sf::Texture& texRef(const std::string& texture);
	sf::Font& fonRef(const std::string& font);
	

	resourceManager();
	~resourceManager();
};

#endif // !RESOURCEMANAGER_H
