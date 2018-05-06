/*
Input :- 

200 20
220 70
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;

int main()
{
	initwindow(800,800);
	int x1,y1,x2,y2;
	float m,x,y,yprev,xprev;
	cout<<"\nEnter first point : ";
	cin>>x1>>y1;
	cout<<"\nEnter second point : ";
	cin>>x2>>y2;
	
	if (x1==x2)
	{
		for(y=y1;y<=y2;y++) putpixel(x1,y,3);
	}
	else if(y1==y2)
	{
		for(x=x1;x<=x2;x++) putpixel(x,y1,3);
	}
	else if(abs(x1-x2)>=abs(y1-y2))
	{
		if(x1>x2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		else if(x1==x2)
		{
			if(y1>y2) swap(y1,y2);
		}
		
		m = 1.0*(y2-y1)/(x2-x1);
		y = y1;
		for(int x=x1;x<=x2;x++)
		{
			yprev = y;
			putpixel(x,round(y),3);
			y = yprev + m;	
		}
	}
	else
	{
		if(y1>y2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		else if(y1==y2)
		{
			if(x1>x2) swap(x1,x2);
		}
		
		m = 1.0*(y2-y1)/(x2-x1);
		x = x1;
		for(int y=y1;y<=y2;y++)
		{
			xprev = x;
			putpixel(round(x),y,3);
			x = xprev + (1.0/m);
		}
	}	
	getch();
	return 0;
}
