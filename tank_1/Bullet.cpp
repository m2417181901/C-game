#include "Bullet.h"

void Bullet::setxy(int x, int y, Direection dir,bool status , int num){
	this->setx(x);
	this->sety(y);
	this->setDir(dir);
	this->status = status;
	this->num = num;
}
int Bullet::getn() {
	return this->num;
}
bool Bullet::gets() {
	return this->status;
}
void Bullet::setn(int num) {
	this->num = num;
}
void Bullet::sets(bool status) {
	this->status = status;
}