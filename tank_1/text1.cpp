#include "text1.h"
#include"Bullet.h"
#include"GameSettings.h"
#include"Tank.h"
#include<easyx.h>
#include<graphics.h>
#include<iostream>
#include<conio.h>//键盘输入库
void menu();
void initMap();
void Tank_player();
void Tank_CP(Tank tank);
void CP_come(int);

/*****
定义坦克
*****/
Tank player(8, 24, UP, 3);
Tank CP[10];
int CP_num = 0;
IMAGE P1_tank[4][2];
IMAGE CP_tank[4][2];
void capcher(Tank &tank,int key);
void change(int **map, int x, int y, int value) {
	*((int*)map + x * map_col + y) = value;
	*((int*)map + x * map_col + y + 1) = value;
	*((int*)map + (x + 1) * map_col + y) = value;
	*((int*)map + (x + 1) * map_col + y + 1) = value;
}
void change_dir(Tank &tank, Direection dir,bool flag=true);
/**********
定义子弹
***********/
Bullet P1_bullet;
Bullet CP_bullet[10];
int main()
{

		// 初始化绘图窗口
		initgraph(960, 1024);
		//开始场景
		menu();
		//初始化地图
		initMap();
		//坦克
	Tank_player();
		int key;
		CP_come(2);
		while (1) {
		//	CP_come(2);
			if (_kbhit()) {
			 	key = _getch();
				capcher(player,key);
			}
			Sleep(10);
		}
		system("pause");
	return 0;
}
/****
鼠标事件管理 与 菜单
***/

void menu() {
	IMAGE logo_img;
	IMAGE teach_img;
	loadimage(&teach_img, _T("Image\\menu\\illustrate.jpg"), 300, 300);
	loadimage(&logo_img, _T("Image\\menu\\tank_logo.png"), 960, 512);
	putimage(0, 0, &logo_img);
	//实现导航按钮
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(230, 220, 310, 240);
	fillrectangle(330, 220, 410, 240);
	settextstyle(25, 0, _T("宋体"));
	outtextxy(240, 210, _T("说 明"));
	outtextxy(340, 210, _T("开 始"));
	int finished = 0;
	MOUSEMSG mouse;
	while (!finished)
	{
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_MOUSEMOVE:
			if ((mouse.x > 230) && (mouse.x < 310) && (mouse.y > 220) && (mouse.y < 240)) {
				putimage(330, 520, &teach_img);
			}
			else {
				solidrectangle(330, 520, 630, 820);
			}
			break;
		case WM_LBUTTONDOWN:
			if ((mouse.x > 350) && (mouse.x < 430) && (mouse.y > 200) && (mouse.y < 240)) {
				cleardevice();
				finished = 1;
				break;
			}
		default:
			break;
		}
	}
}
/*****
初始化地图
****/
void initMap() {
	IMAGE img_home, img_wall_1, img_wall_2;
	loadimage(&img_home, _T("Image\\commander0.png"), 50, 50);
	loadimage(&img_wall_1, _T("Image\\map\\wall.png"), 25, 25);
	loadimage(&img_wall_2, _T("Image\\map\\iron.png"), 25, 25);
	for(int i=0;i<map_row;i++)
		for (int j = 0; j < map_col; j++) {
			switch (map[i][j]) {
			case 1: 
				putimage(25 * j, 25 * i, &img_wall_1);
				break;
			case 2:
				putimage(25 * j, 25 * i, &img_wall_2);
				break;   
			case 3:
				putimage(25 * j, 25 * i, &img_home);
				change((int**)map, i, j, 4);
				break;
			}
		}
}
void Tank_player() {
	std::cout << player.getx() << ' ' << player.gety() << std::endl;
	change((int**)map, player.gety(), player.getx(), 200);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
		{
			loadimage(&P1_tank[i][j], P1_FileName[0][i][j], 50, 50);
			loadimage(&CP_tank[i][j], CP_FileName[0][i][j], 50, 50);
		}
	putimage(player.getx() * 25, player.gety() * 25, &P1_tank[0][0]);
}
void Tank_CP(Tank tank) {
	change((int**)map, tank.gety(), tank.getx(), 100);
	putimage(tank.getx() * 25, tank.gety() * 25, &CP_tank[tank.getDir()][0]);
}
void CP_come(int key) {
	for (int i = CP_num;(i < CP_NUM)&&(i<=CP_num+3-key); i++)
	{
		switch (i % 3)
		{
		case 0:
			CP[i].setxy(0, 0, DOWN);
			Tank_CP(CP[i]);
			break;
		case 1:
			CP[i].setxy(3, 0, DOWN);
			Tank_CP(CP[i]);
			break;
		case 2:
			CP[i].setxy(6, 0, DOWN);
			Tank_CP(CP[i]);
			break;
		default:
			break;
		}
	}
}
/****
捕获键盘响应
***/

void capcher(Tank &tank,int key) {
	switch (key)
	{
	case 'a'://LEFT
		change_dir(tank, LEFT, false);
		if ((map[tank.gety()][tank.getx() - 1] == 0) && (map[tank.gety() + 1][tank.getx() - 1]==0)&&(tank.getx()>0)&&((tank.getx()+1) < map_col)) 
			change_dir(tank, LEFT);
		break;
	case 'w':
		change_dir(tank, UP,false);
		if ((map[tank.gety() - 1][tank.getx()] == 0) && (map[tank.gety()  - 1][tank.getx() + 1] == 0) && (tank.gety() > 0) && ((tank.gety()+1) < map_row))
			change_dir(tank, UP);
		break;
	case 's':
		change_dir(tank, DOWN,false);
		if ((map[tank.gety() + 2][tank.getx()] == 0) && (map[tank.gety() +2][tank.getx() + 1] == 0) && (tank.gety() >= 0) && ((tank.gety()+2) < map_row))
			change_dir(tank, DOWN);
		break;
	case 'd':
		change_dir(tank, RIGHT,false);
		if ((map[tank.gety()][tank.getx() + 2] == 0) && (map[tank.gety() + 1][tank.getx() + 2] == 0) && (tank.getx() >= 0) && ((tank.getx()+2) < map_col))
			change_dir(tank, RIGHT);
		break;
	case 'j':
		if (!P1_bullet.gets())
		{

		}
		break; 
	case 'k':
		system("PAUSE");
		break;
	default:
		break;
	}
}
void change_dir(Tank &tank,Direection dir,bool flag) {
	setfillcolor(BLACK);
	solidrectangle(tank.getx() * 25, tank.gety() * 25, tank.getx() * 25 + 50, tank.gety() * 25 + 50);
	if (flag)
	{
		change((int**)map, tank.gety(), tank.getx(), 0);
		switch (dir)
		{
		case UP:
			tank.sety(tank.gety() - 1);
			break;
		case LEFT:
			tank.setx(tank.getx() - 1);
			break;
		case DOWN:
			tank.sety(tank.gety() + 1);
			break;
		case RIGHT:
			tank.setx(tank.getx() + 1);
			break;
		default:
			break;
		}
		change((int**)map, tank.gety(), tank.getx(), 200);
	}
	tank.setDir(dir);
	putimage(tank.getx() * 25, tank.gety() * 25, &P1_tank[dir][0]);
}
/*******
发射子弹方法 
*******/
void Bullet_move(Bullet bullet) {
	switch (bullet.getDir())
	{
	case 0:
		
		break;
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	default:
		break;
	}
}
/****

判断主角坦克方向 设置子弹出场方向
****/
void bullet_fire(Tank tank)




/*******
*1 敌人坦克出场
*2 选路实现
*3 炮击实现
******/






