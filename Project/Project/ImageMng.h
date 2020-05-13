#pragma once
#include <memory>

class ImageMng
{
public:
	static ImageMng& GetInstance()
	{
		return *s_Instance;
	}


private:
	ImageMng() {}
	~ImageMng() {}

	static ImageMng s_Instance;
};

