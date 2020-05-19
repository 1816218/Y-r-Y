#pragma once
#include <memory>
#include <vector>
class Map
{
public:
	static Map& GetInstance()
	{
		return *s_Instance;
	}

	bool Init();
	void Draw(void);

private:
	struct MapDeleter
	{
		void operator()(Map* map) const
		{
			delete map;
		}
	};
	Map();
	~Map();

	std::vector<int> _mapData;

	static std::unique_ptr<Map, MapDeleter> s_Instance;
};

