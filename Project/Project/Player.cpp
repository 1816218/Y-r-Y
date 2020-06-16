#include <DxLib.h>
#include "Player.h"
#include "Scene/SceneMng.h"
#include "ImageMng.h"
#include "Map.h"

Player::Player()
{
	Init();
}

Player::Player(const Vector2F& pos, const Vector2F& size)
{
	_pos = pos;
	_size = size;
	Init();
}

Player::~Player()
{
}

bool Player::Init(void)
{
	_angle = 0.0;
	_exRate = 1.0;
	_alive = true;
	_death = false;

	_animCnt = 0;
	_moveFlag = false;
	_direction = CHARA_DIR::DOWN;
	_edg = { Vector2F(-_size.x / 2, -_size.y / 4),
			 Vector2F(_size.x / 2, -_size.y / 4),
			 Vector2F(-_size.x / 2, _size.y / 2),
			 Vector2F(_size.x / 2, _size.y / 2)};
	_speed = 1.5f;
	return true;
}

void Player::Update(void)
{
	_moveFlag = false;

	Move();
}
//-----�`��
void Player::Draw(void)
{
	//-----�A�j���[�V����
	//�����Ă����Ԃ̂Ƃ���
	//�A�j���[�V�����J�E���g�𑝂₷
	_moveFlag != false ? _animCnt++ : _animCnt = 0;

	DrawRotaGraphF(_pos.x, _pos.y, _exRate, _angle, IMAGE_ID("player")[(static_cast<int>(_direction) * 4) + (_animCnt / 20 % 4)], true);
}
//-----�ړ�����
void Player::Move(void)
{
	_moveFlag = false;

	//�Փ˂��Ă��Ȃ�������ړ�����
	AddMove(_1P_UP,		CHARA_DIR::UP,		{       0, -_speed });
	AddMove(_1P_RIGHT,	CHARA_DIR::RIGHT,	{  _speed,       0 });
	AddMove(_1P_LEFT,	CHARA_DIR::LEFT,	{ -_speed,       0 });
	AddMove(_1P_DOWN,	CHARA_DIR::DOWN,	{       0,  _speed });
}

//-----Get�ESet
//���W
const Vector2F& Player::GetPos(void)
{
	return _pos;
}

void Player::SetPos(const Vector2F& pos)
{
	_pos = pos;
}
//�T�C�Y
const Vector2F& Player::GetSize(void)
{
	return _size;
}

void Player::SetSize(const Vector2F& size)
{
	_size = size;
}
//�p�x
const double Player::GetAngle(void)
{
	return _angle;
}

void Player::SetAngle(const double angle)
{
	_angle = angle;
}
//�g�嗦
const double Player::GetExRate(void)
{
	return _exRate;
}

void Player::SetExRate(const double exRate)
{
	_exRate = exRate;
}
//-----�ړ��ʂ̉��Z
void Player::AddMove(const KEY_CODE& key, const CHARA_DIR& dir, const Vector2F& add)
{
	Vector2F movePos = _pos;

	//�Փ˔��肷��ӏ�����ł��������Ă����ꍇ�͐^��Ԃ�
	auto hitFlag = [&](const Vector2F& move)
	{
		for (auto edg : _edg)
		{
			if (lpMap.Collision(move, edg))
			{
				return true;
			}
		}
		return false;
	};

	if (lpInputKey.newKey[key])
	{
		_moveFlag = true;
		_direction = dir;
		movePos += add;

		if (hitFlag(movePos))
		{
			_pos = movePos - add;	//�߂荞�񂾕��߂�
		}
		else
		{
			_pos = movePos;	//�ړ�
		}
	}
}

