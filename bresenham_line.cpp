/*
Input :- 

200 20
220 70
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

int main()
{
	int dx,dy,x,y,p,x1,y1,x2,y2;
	initwindow(800,800);
	cout<<"\n\nEnter first point : ";
	cin>>x1>>y1;
	cout<<"\n\nEnter second point : ";
	cin>>x2>>y2;
	
	if(abs(x1-x2)>=abs(y1-y2))
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
		
		dx = x2-x1;
		dy = y2-y1;
		p = 2*dy-dx;
		for(x=x1,y=y1; x<=x2; x++)
		{
			putpixel(x,y,3);
			if(p<0) p = p + 2*dy;
			else
			{
				y++;
				p = p + 2*(dy-dx);
			}
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
		
		dx = x2-x1;
		dy = y2-y1;
		p = 2*dx-dy;
		for(x=x1,y=y1; y<=y2; y++)
		{
			putpixel(x,y,3);
			if(p<0) p = p + 2*dx;
			else
			{
				x++;
				p = p + 2*(dx-dy);
			}
		}
	}
	getch();
	return 0;
}
