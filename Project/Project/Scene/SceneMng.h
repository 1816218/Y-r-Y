#pragma once
#include <memory>
#include <vector>
#include <tuple>
#include "BaseScene.h"
#include "../VECTOR2.h"

#define lpSceneMng SceneMng::GetInstance()

using DrawQueT = std::tuple<int, int, int>;	//���̨������فAx�Ay

//�`��f�[�^
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

	//�ǉ�������ʂ��܂Ƃ߂ĕ`��
	void Draw(void);

	//�`���ʂ̐ݒ�
	//@param ghScreen �`�悷����
	bool SetScreen(int ghScreen);

	//�\��������
	bool RevScreen(void);

	//�`�悷��Ώۂ�ǉ�
	//@param localZorder �`�揇�̎w��(����)
	//@param que �쐬������ʃf�[�^�ƕ`��J�n��(����)
	bool AddDrawQue(const int localZorder, DrawQueT que);

	//�`�悵����ʃf�[�^�����ׂď���
	bool DeleteAllDrawList(void);

	//��ʃT�C�X���擾����
	const Vector2F& GetScreenSize(void);

	//�V�[����ݒ�
	//@param id �ݒ肷��V�[��
	void SetSceneID(const SCN_ID id);

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
	//�V�[���؂�ւ�����
	void SelectScene(void);
	//�V�[���̉��
	bool ResetActiveScene(void);

	SCN_ID									_sceneID;		//�V�[���̏��
	unique_Base								_activeScene;	//���삵�Ă���V�[��
	const Vector2F							_screenSize;	//��ʂ̑傫��
	int										_ghBefor;		//�O�̉��
	std::vector<std::pair<int, DrawQueT>>	_drawList;		//�`�悷�����

	static std::unique_ptr<SceneMng, SceneMngDeleter> s_Instance;
};

