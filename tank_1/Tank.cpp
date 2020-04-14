#include "Tank.h"

Tank::Tank(int x, int y, Direection dir, int live) {
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->live = live;
}
void Tank::setxy(int x, int y, Direection dir) {
	this->x = x;
	this->y = y;
	this->dir = dir;
}
Tank::Tank(int live)
{
	this->live = live;
}
Tank::~Tank() {
}
void Tank::setx(int x) {
	this->x = x;
}
void Tank::sety(int y) {
	this->y = y;
}
int Tank::getx() {
	return this->x;
}
int Tank::gety() {
	return this->y;
}
void Tank::setDir(Direection dir) {
	this->dir = dir;
}
Direection Tank::getDir() {
	return this->dir;
}