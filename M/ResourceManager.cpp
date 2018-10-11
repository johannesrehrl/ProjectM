#include "ResourceManager.h"

ResourceManager::ResourceManager(std::shared_ptr<InfluenceResource> influenceResource, std::shared_ptr<NationalStability> nationalStability)
{
	this->influenceResource = influenceResource;
	this->nationalStability = nationalStability;
}

void ResourceManager::updateEndTurn()
{
	this->influenceResource->updateEndTurn();
	this->nationalStability->updateEndTurn();
}

ResourceManager::~ResourceManager()
{

}