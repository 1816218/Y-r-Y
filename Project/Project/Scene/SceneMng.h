#pragma once
#include "BaseSceneh.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	static SceneMng& GetInstance()
	{
		return (*s_Instance);
	}

	void Run(void);
private:
	struct SceneMngDeleter
	{
		void operator()(SceneMng* sceneMng) const
		{
			delete sceneMng;
		}
	};
	SceneMng();
	~SceneMng();

	bool SysInit(void);		//ºΩ√—èàóù

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

