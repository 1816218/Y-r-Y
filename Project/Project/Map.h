#pragma once
#include <memory>
#include <vector>
#include <string>
#include "VECTOR2.h"

#define lpMap Map::GetInstance()
#define MAP_CHIP_X 25
#define MAP_CHIP_Y 20

enum class CHIP_TYPE
{
	WALL,	//��
	FLOOR	//��
};

struct MapChip
{
	CHIP_TYPE type;	//�`�b�v���
	int id;			//�`�b�v�ԍ�
};

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
	//@param fileName �t�@�C����
	void ReadFile(const std::string fileName);

	//����̕����ŋ�؂����������Ԃ�
	//@param input �ǂݍ��񂾈�s���̕�����
	//@param delimiter ��؂镶��
	std::vector<std::string> Split(std::string& input, char delimiter);

	MapChip _mapData[MAP_CHIP_Y][MAP_CHIP_X];

	Vector2 _mapChipSize;	//�}�b�v�`�b�v�̃T�C�X
	
	int _ghMapScreen;
	int _ghFrool;

	static Map* s_Instance;
};

