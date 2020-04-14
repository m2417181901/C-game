#pragma once
#include<easyx.h>
#include"Tank.h"
const int CP_NUM = 10;

const int map_row = 26;
const int map_col = 26;
static int map[map_row][map_col] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
	{ 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
const wchar_t* const P1_FileName[4][4][2] =
{
	_T("Image\\tank\\player1\\player1_0_up1.png"),_T("Image\\tank\\player1\\player1_0_up2.png"),
	_T("Image\\tank\\player1\\player1_0_left1.png"),_T("Image\\tank\\player1\\player1_0_left2.png"),
	_T("Image\\tank\\player1\\player1_0_down1.png"),_T("Image\\tank\\player1\\player1_0_down2.png"),
	_T("Image\\tank\\player1\\player1_0_right1.png"),_T("Image\\tank\\player1\\player1_0_right2.png"),

	_T("Image\\tank\\player1\\player1_1_up1.png"),_T("Image\\tank\\player1\\player1_1_up2.png"),
	_T("Image\\tank\\player1\\player1_1_left1.png"),_T("Image\\tank\\player1\\player1_1_left2.png"),
	_T("Image\\tank\\player1\\player1_1_down1.png"),_T("Image\\tank\\player1\\player1_1_down2.png"),
	_T("Image\\tank\\player1\\player1_1_right1.png"),_T("Image\\tank\\player1\\player1_1_right2.png"),

	_T("Image\\tank\\player1\\player1_2_up1.png"),_T("Image\\tank\\player1\\player1_2_up2.png"),
	_T("Image\\tank\\player1\\player1_2_left1.png"),_T("Image\\tank\\player1\\player1_2_left2.png"),
	_T("Image\\tank\\player1\\player1_2_down1.png"),_T("Image\\tank\\player1\\player1_2_down2.png"),
	_T("Image\\tank\\player1\\player1_2_right1.png"),_T("Image\\tank\\player1\\player1_2_right2.png"),

	_T("Image\\tank\\player1\\player1_3_up1.png"),_T("Image\\tank\\player1\\player1_3_up2.png"),
	_T("Image\\tank\\player1\\player1_3_left1.png"),_T("Image\\tank\\player1\\player1_3_left2.png"),
	_T("Image\\tank\\player1\\player1_3_down1.png"),_T("Image\\tank\\player1\\player1_3_down2.png"),
	_T("Image\\tank\\player1\\player1_3_right1.png"),_T("Image\\tank\\player1\\player1_3_right2.png")
};
const wchar_t* const CP_FileName[4][4][2] =
{
	_T("Image\\tank\\enemy\\enemy0_up1.png"),_T("Image\\tank\\enemy\\enemy0_up2.png"),
	_T("Image\\tank\\enemy\\enemy0_left1.png"),_T("Image\\tank\\enemy\\enemy0_left2.png"),
	_T("Image\\tank\\enemy\\enemy0_down1.png"),_T("Image\\tank\\enemy\\enemy0_down2.png"),
	_T("Image\\tank\\enemy\\enemy0_right1.png"),_T("Image\\tank\\enemy\\enemy0_right2.png"),

	_T("Image\\tank\\enemy\\enemy1_up1.png"),_T("Image\\tank\\enemy\\enemy1_up2.png"),
	_T("Image\\tank\\enemy\\enemy1_left1.png"),_T("Image\\tank\\enemy\\enemy1_left2.png"),
	_T("Image\\tank\\enemy\\enemy1_down1.png"),_T("Image\\tank\\enemy\\enemy1_down2.png"),
	_T("Image\\tank\\enemy\\enemy1_right1.png"),_T("Image\\tank\\enemy\\enemy1_right2.png"),

	_T("Image\\tank\\enemy\\enemy2_up1.png"),_T("Image\\tank\\enemy\\enemy2_up2.png"),
	_T("Image\\tank\\enemy\\enemy2_left1.png"),_T("Image\\tank\\enemy\\enemy2_left2.png"),
	_T("Image\\tank\\enemy\\enemy2_down1.png"),_T("Image\\tank\\enemy\\enemy2_down2.png"),
	_T("Image\\tank\\enemy\\enemy2_right1.png"),_T("Image\\tank\\enemy\\enemy2_right2.png"),

	_T("Image\\tank\\enemy\\enemy3_up1.png"),_T("Image\\tank\\enemy\\enemy3_up2.png"),
	_T("Image\\tank\\enemy\\enemy3_left1.png"),_T("Image\\tank\\enemy\\enemy3_left2.png"),
	_T("Image\\tank\\enemy\\enemy3_down1.png"),_T("Image\\tank\\enemy\\enemy3_down2.png"),
	_T("Image\\tank\\enemy\\enemy3_right1.png"),_T("Image\\tank\\enemy\\enemy3_right2.png")
};






