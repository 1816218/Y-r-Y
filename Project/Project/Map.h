#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Scene/SceneMng.h"
#include "VECTOR2.h"

#define lpMap Map::GetInstance()
//�A�C�e���J�E���g
extern int ItemCount;

//�}�b�v�`�b�v�̏��
enum class CHIP_STATE
{
	HIT,		//������
	NOT_HIT,	//������Ȃ�
	NOT_DRAW,	//�`�悵�Ȃ�
	GOAL,
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
	bool Collision(const Vector2F& pos, const Vector2F& size = {});

	//�X�N���[���l�擾
	const Vector2F& GetScrooll(void) const;
	//�X�N���[���l�̉��Z
	void AddScroll(const Vector2F& move = {});
	//�}�b�v�`�b�v�̑����擾
	const Vector2& GetMapChipMax(void) const;
	//�}�b�v�`�b�v�T�C�X�擾
	const Vector2& GetMapChipSize(void) const;
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
	void DrawScreen(const VecMap& mapData, int localZorder, DrawQueT drawQue);

	int						_ghFrontScreen;	//�O���
	int						_ghBackScreen;	//����
	std::vector<PairMap>	_mapData;		//�}�b�v�f�[�^(�`�悷���ʂ�ID�A�}�b�v�f�[�^)
	Vector2					_mapChip;		//�}�b�v�`�b�v�̍ő吔
	Vector2					_mapChipSize;	//�}�b�v�`�b�v�̃T�C�Y
	Vector2F				_scroll;		//�X�N���[��������ړ���
	static Map*				s_Instance;
};

