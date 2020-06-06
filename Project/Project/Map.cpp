#include <DxLib.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Map.h"
#include "ImageMng.h"
#include "Scene/SceneMng.h"

Map* Map::s_Instance = nullptr;

//-----�`�揈��
void Map::Draw(void)
{
	DrawScreen(_mapFront, 100, { _ghFrontScreen, 0, 0 });
	DrawScreen(_mapBack, 0, { _ghBackScreen, 0, 0 });
}
//-----�����蔻��
bool Map::Collision(Vector2F pos, Vector2F size)
{
	//���W���}�b�v�`�b�v�ɕϊ�
	Vector2 chip = { (int)(pos.x + size.x ) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	//�ǂɓ������Ă����瓖���������Ƃɂ���
	if(_mapBack.at(chip.y * MAP_CHIP_X + chip.x).state == CHIP_STATE::HIT)
	{
		return true;	//�������Ă���
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
	ReadFile("Data/stage1_front.csv", { 50, 20 }, true);
	ReadFile("Data/stage1_back.csv", { 50, 20 }, false);

	//�`��Ώۂɂ����ʂ̍쐬
	_ghFrontScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	_ghBackScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
}
//-----�t�@�C���̓ǂݍ���
//@param fileName �t�@�C����
//@param chip �}�b�v�`�b�v��
//@param flag �`��Ώ�(true�F�O�ʁAfalse�F���)
void Map::ReadFile(const std::string fileName, const Vector2& chip, bool flag)
{
	std::ifstream ifs;
	std::string line;
	MapChip data;
	int y = 0;

	//�`�b�v�̍ő吔��ݒ�
	_mapChip = chip;

	//�t�@�C�����J��
	ifs.open(fileName);
	//�t�@�C�����J���̂Ɏ��s�����珈�������Ȃ�
	if (ifs.fail())
	{
		return;
	}

	//�������̊m��(�}�b�v�`�b�v�̑���)
	if (flag)
	{
		_mapFront.reserve(_mapChip.x * _mapChip.y);
	}
	else
	{
		_mapBack.reserve(_mapChip.x * _mapChip.y);
	}

	//�t�@�C���̏I�[�܂ň�s���ǂݍ���
	while (std::getline(ifs, line))
	{
		//�J���}��؂�̕�������i�[����
		std::vector<std::string> strVec = Split(line, ',');

		for (int x = 0; x < strVec.size(); x++)
		{
			//char��int�֕ϊ��������l����
			data.id = atoi(strVec.at(x).c_str());
			data.chipPos = { x, y };

			//�����蔻��p��ID�̓o�^
			if (flag)
			{
				data.state = CHIP_STATE::FRONT;
				_mapFront.push_back(data);
			}
			else
			{
				if (data.id >= 0)
				{
					data.state = CHIP_STATE::HIT;	//������
				}
				else
				{
					data.state = CHIP_STATE::NOT_HIT;	//������Ȃ�
				}
				_mapBack.push_back(data);
			}
		}
		y++;
	}
	ifs.close();	//�t�@�C�������
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
void Map::DrawScreen(std::vector<MapChip>& mapData, int localZorder, DrawQueT que)
{
	//�O�ʂɕ`��
	lpSceneMng.SetScreen(std::get<static_cast<int>(DRAW_QUE::IMAGE)>(que));
	ClearDrawScreen();
	for (auto map : mapData)
	{
		if (map.state == CHIP_STATE::FRONT)
		{
			if (map.id >= 0)
			{
				DrawGraph(map.chipPos.x * _mapChipSize.x, map.chipPos.y * _mapChipSize.y, IMAGE_ID("map")[map.id], true);
			}
		}
		else
		{
			DrawGraph(map.chipPos.x * _mapChipSize.x, map.chipPos.y * _mapChipSize.y, IMAGE_ID("map")[abs(map.id)], true);
		}
	}
	lpSceneMng.AddDrawQue(localZorder, que);
	lpSceneMng.RevScreen();
}
