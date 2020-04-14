#pragma once
#include "Bullet.h"
enum Direection {
	UP,LEFT,DOWN,RIGHT
};
class Tank:public Bullet
{
private:
	int x, y;//坦克在地图中的所在列和行
	Direection dir;
	int live;//生命 
public:
	Tank(int x, int y, Direection dir, int live);
	Tank(int live=1);
	void setxy(int x, int y, Direection dir);
	void setDir(Direection dir);
	Direection getDir();
	virtual~Tank();
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
};

