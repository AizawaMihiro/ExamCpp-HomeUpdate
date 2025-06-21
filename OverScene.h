#pragma once
#include "GameObject.h"
#include "globals.h"

class OverScene :
	public GameObject
{
public:
	OverScene();
	~OverScene();
	void Update();
	void Draw();
	bool GetOver();
	void SetOver(bool nowState);
private:
	bool nowOver;
};

