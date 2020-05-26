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

	//メインループ処理
	void Run(void);

	unique_Base SelectScene(void);
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

	bool SysInit(void);	//ｼｽﾃﾑ処理

	unique_Base _activeScene;	//動作しているシーン
	SCN_ID _sceneID;

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

