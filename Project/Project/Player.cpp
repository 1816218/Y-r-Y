#include <DxLib.h>
#include "Player.h"
#include"ImageMng.h"
#include "Map.h"

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

	_moveFlag = false;
	_direction = CHARA_DIR::DOWN;
	_animCnt = 0;
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
	auto move = [&](bool flag, const CHARA_DIR& dir, const Vector2F& speed)
	{
		if (!flag)
		{
			_moveFlag = true;
		}

		if (_direction != dir)
		{
			_direction = dir;
		}
		_pos += speed;
	};

	//�L�[���͂ɂ��ړ�
	if (lpInputKey.newKey[KEY_CODE::KEY_UP])
	{
		if (!lpMap.Collision(_pos, { 0, 0 }))
		{
			move(_moveFlag, CHARA_DIR::UP, { 0, -1 });
		}
	}
	if (lpInputKey.newKey[KEY_CODE::KEY_RIGHT])
	{
		if (!lpMap.Collision(_pos, { 16, 0 }))
		{
			move(_moveFlag, CHARA_DIR::RIGHT, { 1, 0 });
		}
	}
	if (lpInputKey.newKey[KEY_CODE::KEY_LEFT])
	{
		if (!lpMap.Collision(_pos, { -16, 0 }))
		{
			move(_moveFlag, CHARA_DIR::LEFT, { -1, 0 });
		}
	}
	if (lpInputKey.newKey[KEY_CODE::KEY_DOWN])
	{
		if (!lpMap.Collision(_pos, { 0, 16 }))
		{
			move(_moveFlag, CHARA_DIR::DOWN, { 0, 1 });
		}
	}
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


