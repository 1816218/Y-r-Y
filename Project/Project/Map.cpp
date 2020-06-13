#include <DxLib.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Map.h"
#include "ImageMng.h"

Map* Map::s_Instance = nullptr;

//-----�`�揈��
void Map::Draw(void)
{
	for (auto map : _mapData)
	{
		if (map.first == DRAW_SCREEN::FRONT)
		{
			DrawScreen(map.second, 100, { _ghFrontScreen, 0, 0 });
		}
		else
		{
			DrawScreen(map.second, 0, { _ghBackScreen, 0, 0 });
		}
	}
}
//-----�����蔻��
bool Map::Collision(Vector2F pos, Vector2F size)
{
	//���W���}�b�v�`�b�v�ɕϊ�
	Vector2 chip = { (int)(pos.x + size.x ) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	//�ǂɓ������Ă����瓖���������Ƃɂ���
	for (auto map : _mapData)
	{
		for (auto data : map.second)
		{
			if (data.chipPos.x == chip.x && data.chipPos.y == chip.y)
			{
				if (data.state == CHIP_STATE::HIT)
				{
					return true;	//�������Ă���
				}
			}
		}
	}
	return false;	//�������Ă��Ȃ�
}

Map::Map() : _mapChip(0,0), _mapChipSize(32, 32)
{
	Init();
}

Map::~Map()
{
}
//-----����������
void Map::Init(void)
{
	//�t�@�C���̓ǂݍ���
	ReadFile(DRAW_SCREEN::FRONT, "Data/stage1_front.csv");
	ReadFile(DRAW_SCREEN::BACK, "Data/stage1_back.csv");

	//�`��Ώۂɂ����ʂ̍쐬
	_ghFrontScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	_ghBackScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
}
//-----�t�@�C���̓ǂݍ���
bool Map::ReadFile(DRAW_SCREEN screen, const std::string& fileName)
{
	std::ifstream ifs;
	std::string line;
	MapChip data;
	VecMap map;

	//�t�@�C�����J��
	ifs.open(fileName);

	//�t�@�C�����J���̂Ɏ��s�����珈�������Ȃ�
	if (ifs.fail())
	{
		return false;
	}

	{//�}�b�v�`�b�v�̍ő吔��ݒ�
		//�J���}��؂�ŕ�������i�[����
		std::getline(ifs, line);
		std::vector<std::string> strVec = Split(line, ',');
		_mapChip = { atoi(strVec.at(0).c_str()), atoi(strVec.at(1).c_str()) };
	}

	//�������̊m��(�}�b�v�`�b�v�̑���)
	map.reserve(_mapChip.y * _mapChip.x);

	for(int y = 0; y<_mapChip.y; y++)
	{
		//�J���}��؂�ŕ�������i�[����
		std::getline(ifs, line);
		std::vector<std::string> strVec = Split(line, ',');

		for (int x = 0; x < strVec.size(); x++)
		{
			//char��int�֕ϊ��������l����
			int num = atoi(strVec.at(x).c_str());

			data.id = num / 10;
			data.chipPos = { x, y };

			//�`�b�v�̏�Ԃ�o�^
			if (num % 10 == 0)
			{
				data.state = CHIP_STATE::HIT;
			}
			else if (num % 10 == 1)
			{
				data.state = CHIP_STATE::NOT_HIT;
			}
			else
			{
				data.state = CHIP_STATE::NOT_DRAW;
			}
			map.push_back(data);
		}
	}
	ifs.close();	//�t�@�C�������

	_mapData.push_back(std::make_pair(screen, map));

	return true;
}
//-----��������i�[
std::vector<std::string> Map::Split(std::string& input, char delimiter)
{
	std::istringstream			stream(input);	//�ǂݍ��񂾈�s���̕���
	std::string					charString;		//������
	std::vector<std::string>	result;			//��s���̕�����

	//�w�肵�������ŋ�؂�����������i�[����
	while (std::getline(stream, charString, delimiter))
	{
		result.push_back(charString);
	}
	return result;	//�������Ԃ�
}
//----��ʂɕ`��
void Map::DrawScreen(VecMap& mapData, int localZorder, DrawQueT drawQue)
{
	lpSceneMng.SetScreen(std::get<static_cast<int>(DRAW_QUE::IMAGE)>(drawQue));
	ClearDrawScreen();
	for (auto map : mapData)
	{
		if (map.state != CHIP_STATE::NOT_DRAW)
		{
 			DrawGraph(map.chipPos.x * _mapChipSize.x, map.chipPos.y * _mapChipSize.y, IMAGE_ID("map")[map.id], true);
		}
	}
	lpSceneMng.AddDrawQue(localZorder, drawQue);
	lpSceneMng.RevScreen();
}
