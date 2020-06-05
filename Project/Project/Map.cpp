#include <DxLib.h>
#include <fstream>
#include <sstream>
#include "Map.h"
#include "ImageMng.h"
#include "Scene/SceneMng.h"

Map* Map::s_Instance = nullptr;

//-----�`�揈��
void Map::Draw(void)
{
	lpSceneMng.SetScreen(_ghMapScreen);
	ClearDrawScreen();

	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			if ((_mapData[y][x].id != 3) && (_mapData[y][x].id != 4))
			{
				DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, IMAGE_ID("map")[_mapData[y][x].id], true);
			}
		}
	}

	lpSceneMng.AddDrawQue(0, { _ghMapScreen, 0, 0 });
	lpSceneMng.RevScreen();

	lpSceneMng.SetScreen(_ghFrool);
	ClearDrawScreen();

	for (int y = 0; y < MAP_CHIP_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_X; x++)
		{
			if ((_mapData[y][x].id == 3) || (_mapData[y][x].id == 4))
			{
				DrawGraph(x * _mapChipSize.x, y * _mapChipSize.y, IMAGE_ID("map")[_mapData[y][x].id], true);
			}
		}
	}

	lpSceneMng.AddDrawQue(10, { _ghFrool, 0, 0 });
	lpSceneMng.RevScreen();
}
//-----�����蔻��
bool Map::Collision(Vector2F pos, Vector2F size)
{
	//���W���}�b�v�`�b�v�ɕϊ�
	Vector2 chip = { (int)(pos.x + size.x ) / _mapChipSize.x, (int)(pos.y + size.y) / _mapChipSize.y };

	//�ǂɓ������Ă����瓖���������Ƃɂ���
	if (_mapData[chip.y][chip.x].type == CHIP_TYPE::WALL)
	{
		return true;	//�������Ă���
	}
	return false;	//�������Ă��Ȃ�
}

Map::Map() : _mapChipSize(32, 32)
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
	ReadFile("Data/stage1map.csv");

	//�`��Ώۂɂ����ʂ̍쐬
	_ghMapScreen = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
	_ghFrool = MakeScreen(lpSceneMng.GetScreenSize().x, lpSceneMng.GetScreenSize().y, true);
}
//-----�t�@�C���̓ǂݍ���
void Map::ReadFile(const std::string fileName)
{
	std::ifstream ifs;
	std::string line;
	int y = 0;

	//�t�@�C�����J��
	ifs.open(fileName);
	//�t�@�C�����J���̂Ɏ��s�����珈�������Ȃ�
	if (ifs.fail())
	{
		return;
	}
	//�t�@�C���̏I�[�܂ň�s���ǂݍ���
	while (std::getline(ifs, line))
	{
		//�J���}��؂�̕�������i�[����
		std::vector<std::string> strVec = Split(line, ',');

		for (int x = 0; x < strVec.size(); x++)
		{
			//char��int�֕ϊ��������l����
			_mapData[y][x].id = atoi(strVec.at(x).c_str());

			//�ǂƂ��ēo�^
			if ((_mapData[y][x].id != 17) && (_mapData[y][x].id != 3) && (_mapData[y][x].id != 4))
			{
				_mapData[y][x].type = CHIP_TYPE::WALL;
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
