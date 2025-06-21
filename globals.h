#pragma once

const int WIN_WIDTH = 1024;
const int WIN_HEIGHT = 768;

namespace {

	const int PLAYER_IMAGE_WIDTH = 48;
	const int PLAYER_IMAGE_HEIGHT = 48;
	const int BULLET_IMAGE_WIDTH = 13;
	const int BULLET_IMAGE_HEIGHT = 33;
	const int ENEMY_IMAGE_WIDTH = 48;
	const int ENEMY_IMAGE_HEIGHT = 48;
	const int BEAM_IMAGE_WIDTH = 11;
	const int BEAM_IMAGE_HEIGHT = 21;

	const int TITLE_POS_X = 300;
	const int TITLE_POS_Y = 200;
	const int OVER_POS_X = 410;
	const int OVER_POS_Y = 200;
	const int TITLE_FONT_SIZE = 64;

	const int KEY_POS_X = 470;
	const int KEY_POS_Y = 500;
	const int KEY_FONT_SIZE = 12;

	const float ENEMY_MOVE_SPEED = 1.0f;
	enum State
	{
		TITLE, GAME, OVER, MUX_STATE
	};
}
extern float gDeltaTime;//ÉtÉåÅ[ÉÄä‘ÇÃéûä‘ç∑

inline float GetDeltaTime() {
	return gDeltaTime;
}

struct Point {
	float x;
	float y;
};

struct Rect {
	float x;
	float y;
	float w;
	float h;

	inline Point GetCenter() const
	{
		return { x + w / 2,y + h / 2 };
	}
};