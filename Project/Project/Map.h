#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Scene/SceneMng.h"
#include "VECTOR2.h"

#define lpMap Map::GetInstance()

//�}�b�v�`�b�v�̏��
enum class CHIP_STATE
{
	HIT,		//������
	NOT_HIT,	//������Ȃ�
	NOT_DRAW,	//�`�悵�Ȃ�
	MAX
};
//�`��Ώۂɂ�����
enum class DRAW_SCREEN
{
	FRONT,	//�O���
	BACK,	//�����
	MAX
};
//�`�b�v�̃f�[�^
struct MapChip
{
	int			id;			//�摜�ԍ�
	Vector2		chipPos;	//�}�b�v�`�b�v���W
	CHIP_STATE	state;		//�}�b�v�`�b�v�̏��
};

using VecMap = std::vector<MapChip>;
using PairMap = std::pair<DRAW_SCREEN, VecMap>;

class Map
{
public:
	static Map& GetInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new Map();
		}
		return *s_Instance;
	}
	~Map();

	//�`�揈��
	void Draw(void);

	//�Փ˔���
	//@param pos ���W
	//@param size �T�C�Y
	bool Collision(Vector2F pos, Vector2F size);
private:
	Map();

	//����������
	void Init(void);

	//�t�@�C���̓ǂݍ���
	//@param screen �`��Ώۂɂ����ʂ�ID
	//@param fileName �t�@�C����
	bool ReadFile(DRAW_SCREEN screen, const std::string& fileName);

	//����̕����ŋ�؂����������Ԃ�
	//@param input �ǂݍ��񂾈�s���̕�����
	//@param delimiter ��؂镶��
	std::vector<std::string> Split(std::string& input, char delimiter);

	//��ʂɕ`��
	//@param mapData �}�b�v�f�[�^
	//@param localZorder �`�揇(����)
	//@param drawQue �`�悷����(���̨������فA���A��)
	void DrawScreen(VecMap& mapData, int localZorder, DrawQueT drawQue);

	int						_ghFrontScreen;	//�O���
	int						_ghBackScreen;	//����
	std::vector<PairMap>	_mapData;		//�}�b�v�f�[�^(�`�悷���ʂ�ID�A�}�b�v�f�[�^)
	Vector2					_mapChip;		//�}�b�v�`�b�v�̍ő吔
	Vector2					_mapChipSize;	//�}�b�v�`�b�v�̃T�C�Y
	static Map*				s_Instance;
};

