#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

struct point{
    int x;
    int y;
};
void createfood(point &food){
    food.x=(rand()%32)*20;
    food.y=(rand()%24)*20;
}
bool judege(vector<point> &snake){
    for(int i=1;i<snake.size();i++){
        if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y){
            return true;
        }
    }
    return false;
}


int main()
{   srand((unsigned)time(NULL));
    //设置窗口大小为640*480和一个动态的蛇的身体 
    vector<point> snake;  
     point food;
     createfood(food);
     bool gameover=false;

    snake.push_back({100, 100});
    snake.push_back({80, 100});
    snake.push_back({60, 100});
    int dx=20,dy=0;
    int direction=1;
    initgraph(640,480);


    while(!gameover){
    if(GetAsyncKeyState('W')&&direction!=2){
            dx=0;
            dy=-20;
            direction=4;
        }
    if(GetAsyncKeyState('S')&&direction!=4){
            dx=0;
            dy=20;
            direction=2;
        }
    if(GetAsyncKeyState('A')&&direction!=1){
            dx=-20;
            dy=0;
            direction=3;
        }
    if(GetAsyncKeyState('D')&&direction!=3){
            dx=20;
            dy=0;
            direction=1;
        }
        int m=snake[snake.size()-1].x;
        int n=snake[snake.size()-1].y;
        for(int i=snake.size()-1;i>0;i--){
            snake[i].x=snake[i-1].x;
            snake[i].y=snake[i-1].y;
        }
        snake[0].x+=dx;
        snake[0].y+=dy;
        //判断撞墙,撞自己身上；
        if(snake[0].x<0||snake[0].x>=640||snake[0].y<0||snake[0].y>=480||judege(snake)==true){
            gameover=true;
        }
        if(snake[0].x==food.x&&snake[0].y==food.y){
            snake.push_back({m,n});
            createfood(food);
            
        }
        cleardevice();
        //给蛇填充为红色
        setfillcolor(GREEN);
        for(int i=0;i<snake.size();i++){
        fillrectangle(snake[i].x,snake[i].y,snake[i].x+20,snake[i].y+20);
        }
        //给食物填充颜色
        setfillcolor(RED);
        fillrectangle(food.x,food.y,food.x+20,food.y+20);
        
        Sleep(200);
    }
    cleardevice();
    settextstyle(30,0,"宋体");
    outtextxyA(250,200,"Game Over");
    _getch();
    closegraph();
    return 0;
    
}