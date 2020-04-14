#pragma once
#include "Tank.h"
class Bullet:public Tank
{
private:
	bool status;
	int num;
public:
	//Bullet(int x, int y, Direection dir,int live, bool status = false, int num = 1);
	void setxy(int x, int y, Direection dir,bool status = false, int num = 1);
	void sets(bool status);
	void setn(int num);
	bool gets();
	int getn();
};

