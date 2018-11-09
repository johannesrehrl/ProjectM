#include "Event.h"

Event::Event()
{
	this->flagDependencies = std::make_shared<std::vector<std::string>>();
	this->dateDependencies = std::make_shared<sf::Vector2i>();
}
Event::~Event()
{

}