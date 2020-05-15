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

	bool SysInit(void);		//ｼｽﾃﾑ処理

	unique_Base _activeScene;	// 動作しているｼｰﾝ

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

