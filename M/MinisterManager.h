#pragma once
#include <vector> 
#include <string> 
#include "Minister.h" 

class MinisterManager
{
private:
	std::vector<std::shared_ptr<Minister>> allMinisters;

public:
	MinisterManager(){}
	~MinisterManager(){}

	void addMinister(std::shared_ptr<Minister> minister) { this->allMinisters.push_back(minister); }
	void clearMinisterList() { this->allMinisters.clear(); }

	std::shared_ptr<Minister> getMinisterById(std::string id)
	{
		for (int i = 0; i < this->allMinisters.size(); i++)
		{
			if (this->allMinisters.at(i)->getId() == id)
			{
				return this->allMinisters.at(i);
			}
		}

		return nullptr;
	}

	void updateMinister(std::shared_ptr<Minister> minister)
	{
		for (int i = 0; i < this->allMinisters.size(); i++)
		{
			if (this->allMinisters.at(i)->getId() == minister->getId())
			{
				this->allMinisters.at(i).reset();
				this->allMinisters.at(i) = minister;
			}
		}
	}

	std::vector<std::shared_ptr<Minister>> getMinisterList() { return this->allMinisters; }
};