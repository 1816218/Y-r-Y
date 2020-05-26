#pragma once
#include "Obj.h"
#include "VECTOR2.h"

class Enemy : public Obj
{
public:
	Enemy();
	Enemy(const Vector2F& pos, const Vector2F& size);
	~Enemy();

	bool Init(void);
	void Update(void) override;

	//•`‰æ
	void Draw(void) override;

	const Vector2F& GetPos(void);
	void SetPos(const Vector2F& pos);

	const Vector2F& GetSize(void);
	void SetSize(const Vector2F& size);

	const double GetAngle(void);
	void SetAngle(const double angle);

	const double GetExRate(void);
	void SetExRate(const double exRate);
private:

};

