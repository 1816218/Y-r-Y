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

	//システム初期化処理
	bool SysInit(void);

	unique_Base SelectScene(void);

	unique_Base _activeScene;	//動作しているシーン
	SCN_ID _sceneID;
	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

