#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define ROW 9
#define COL 11
char map[ROW][COL+1]={
{"*#*********"},
{"***###*###*"},
{"###**#****#"},
{"*#**###**#*"},
{"***********"},
{"#####*##*##"},
{"**##****#*E"},
{"***#*###**#"},
{"*#*********"},
};


void print_map()
{
	int i;
	for(i=0;i<ROW;i++)
	{
		puts(map[i]);
	}
}


void show_cursor(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int curX,curY;
int main()
{
	printf("你能走出这个迷宫吗？来试一试吧！");
	while(1)
	{
		char t=getch();
		system("cls");
		print_map();
		show_cursor(curX,curY);
	    if(t=='w')
		{
			if((curY-1)>=0 && map[curY-1][curX]=='*' || map[curY-1][curX]=='E') curY--;
		}
		else if(t=='s')
		{
			if((curY+1)<ROW && map[curY+1][curX]=='*' || map[curY+1][curX]=='E') curY++;
		}
		else if(t=='a')
		{
			if((curX-1)>=0 && map[curY][curX-1]=='*' || map[curY][curX-1]=='E') curX--;
		}
		else if(t=='d')
		{
			if((curX+1)<COL && map[curY][curX+1]=='*' || map[curY][curX+1]=='E') curX++;
		}
		if(map[curY][curX]=='E')
		{
			printf("走出来了，你真棒！");
			break;
		}
	}
	return 0;
}