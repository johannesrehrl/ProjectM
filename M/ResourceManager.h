#pragma once
#include <iostream>
#include "InfluenceResource.h"
#include "NationalStability.h"

class ResourceManager
{
private:
	std::shared_ptr<InfluenceResource> influenceResource;
	std::shared_ptr<NationalStability> nationalStability;

public:
	ResourceManager(std::shared_ptr<InfluenceResource> influenceResource, std::shared_ptr<NationalStability> nationalStability);
	~ResourceManager();
	void updateEndTurn();

	std::shared_ptr<InfluenceResource> getInfluenceResource() { return influenceResource; }
	std::shared_ptr<NationalStability> getNationalStability() { return nationalStability; }
};