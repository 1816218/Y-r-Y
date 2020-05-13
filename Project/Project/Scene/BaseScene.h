#pragma once
#include <memory>

// ÉVÅ[ÉìÇÃID
enum class SCN_ID
{
	GAME,	// πﬁ∞—“≤›
	MAX
};

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual unique_Base UpDate(unique_Base own) = 0;
	virtual SCN_ID GetSceneID(void) = 0;
};