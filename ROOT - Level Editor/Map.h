#pragma once
#include<vector>

class Map
{
public:
	Map(int, int);
	
	~Map();

private:
	std::vector<int> xMatriz;
	std::vector<int> yMatriz;
};