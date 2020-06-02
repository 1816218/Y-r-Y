#pragma once
#include <memory>
#include <vector>
#include <tuple>
#include "BaseScene.h"
#include "../VECTOR2.h"

#define lpSceneMng SceneMng::GetInstance()

using DrawQueT = std::tuple<int, int, int>;	//���̨������فAx�Ay

enum class DRAW_QUE
{
	IMAGE,	//���̨�������
	X,		//X���W
	Y,		//Y���W
	MAX
};

class SceneMng
{
public:
	static SceneMng& GetInstance()
	{
		return (*s_Instance);
	}

	//���C�����[�v����
	void Run(void);

	bool SetScreen(int ghScreen);
	bool RevScreen(void);

	void Draw(void);

	bool AddDrawQue(const int localZorder, DrawQueT que);
	bool DeleteDrawQue(void);

	const Vector2Dbl screenSize;		// ��ʂ̑傫��
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

	int _ghBefor;	//�O�̉��
	std::vector<std::pair<int, DrawQueT>> _drawList;	//�`�悷�����

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

