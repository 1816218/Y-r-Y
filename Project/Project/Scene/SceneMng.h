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

	//���C�����[�v����
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

	//�V�X�e������������
	bool SysInit(void);

	unique_Base SelectScene(void);

	unique_Base _activeScene;	//���삵�Ă���V�[��
	SCN_ID _sceneID;
	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

