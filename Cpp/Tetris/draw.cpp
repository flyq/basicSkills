#include "ctime"
#include "cmath"
#include "cstdlib"
#include "fig.h"
#include "ccc_win.h"

#define PI 3.141592653
void mclock(void );
void tuxing(void );

int ccc_win_main(int menuId)
{
                 switch (menuId )
                {
                 case IDM_FIG1 :
                                mclock(); // 绘制时钟
                                 break;
                 case IDM_FIG2 :
                                tuxing(); // 其它绘图程序
                                 break;
                }

                 return 0;
}

void mclock()
{
                 Shape *pShape;

                cwin << Message(Point (-1, 7), "会动时钟");

                 /* 画表盘 */
                 int radius = 6;
                 Point org(0, 0);

                pShape = &org;
                pShape->SetColor( RGB(255, 255, 255)); // 白色
                cwin << org;

                 Circle clkPlate(org, radius);
                pShape = &clkPlate;
                pShape->SetColor( RGB(0, 0, 255));   // 蓝色
                cwin << clkPlate;

                 double x, y, x_s, y_s, x_m, y_m, x_h, y_h;
                 int i;
                 for (i = 0; i<12; i++)
                {
                                x = 0.9*radius*sin( PI*i / 6);
                                y = 0.9*radius*cos( PI*i / 6);

                                 Point mPoint(x, y);
                                pShape = &mPoint;
                                pShape->SetColor(( RGB(255, 255, 255)));
                                cwin << mPoint;
                }

                 /* 画表针 */
                 struct tm local;
                 time_t t;

                 // 获取系统日历时间
                t = time( NULL);

                 // 将日历时间转化为本地时间
                localtime_s(&local, &t);

                x_s = 0.89*radius*sin( PI*(local.tm_sec) / 30);
                y_s = 0.89*radius*cos( PI*(local.tm_sec) / 30);

                x_m = 0.7*radius*sin( PI*(local.tm_min) / 30);
                y_m = 0.7*radius*cos( PI*(local.tm_min) / 30);

                x_h = 0.5*radius*sin( PI*(local.tm_hour) / 6);
                y_h = 0.5*radius*cos( PI*(local.tm_hour) / 6);

                 Point hEnd(x_h, y_h), mEnd(x_m, y_m), sEnd(x_s, y_s);
                 Line hLine(org, hEnd), mLine(org, mEnd), sLine(org, sEnd);

                hLine.SetColor(( RGB(255, 0, 0)));                       // 红色
                mLine.SetColor(( RGB(0, 255, 0)));                       // 绿色
                sLine.SetColor(( RGB(255, 255, 0)));   // 黄色
                cwin << hLine << mLine << sLine << org;
}
void tuxing()
{
                 Shape *pShape;

                cwin << Message(Point (-2, 7), "地球绕着太阳转");

                 /* 画日 */
                 int radius = 3;
                 Point org(0, 0);
    pShape = &org;
                pShape->SetColor( RGB(255, 255, 255)); // 白色
                cwin << org;

                 Circle clkPlate2(org, 1);
                pShape = &clkPlate2;
                pShape->SetColor( RGB(66, 66, 66)); // 蓝色
                cwin << clkPlate2;

                 double x, y, x_s, y_s, x_m, y_m, x_h, y_h;

                 /* 画轨道半径 */
                 struct tm local;
                 time_t t;
                t = time( NULL);
                localtime_s(&local, &t);
                x_s = 2*radius*sin( PI*(local.tm_sec) / 10);
                y_s = 2*radius*cos( PI*(local.tm_sec) / 10);
                 Point
                                sEnd(x_s, y_s);
                 Circle
                                sLine(sEnd, 0.5);
                sLine.SetColor(( RGB(255, 255, 0)));   // 黄色
                cwin << sLine << org;
}
