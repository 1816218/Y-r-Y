#pragma once
#include "BaseScene.h"

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

	bool SysInit(void);		//¼½ÃÑˆ—

	unique_Base _activeScene;	// “®ì‚µ‚Ä‚¢‚é¼°İ

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

