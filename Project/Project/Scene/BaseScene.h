#pragma once
#include <memory>

//�V�[�����
enum class SCN_ID
{
	TITLE,	//�Q�[���^�C�g��
	MAIN,	//�Q�[�����C��
	OVER,	//�Q�[���I�[�o�[
	CLEAR,
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() : _sceneID(SCN_ID::MAX) {}
	virtual ~BaseScene() {}
	virtual void Update(void) = 0;
	virtual SCN_ID GetSceneID(void) = 0;
protected:
	SCN_ID _sceneID;	//�V�[��ID
};