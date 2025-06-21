#pragma once
#include "GameObject.h"
#include "globals.h"

class TitleScene :
	public GameObject
{
public:
	TitleScene();
	~TitleScene();
	void Update();
	void Draw();
	bool GetTitle();
	void SetTitle(bool nowState);
private:
	bool nowTitle;
};

