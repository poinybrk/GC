/*
Input :- 

100 100
50
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

void drawCircle(int x, int y, int xc, int yc)
{
    putpixel(xc+x, yc+y, 3);
    putpixel(xc-x, yc+y, 3);
    putpixel(xc+x, yc-y, 3);
    putpixel(xc-x, yc-y, 3);
    putpixel(xc+y, yc+x, 3);
    putpixel(xc-y, yc+x, 3);
    putpixel(xc+y, yc-x, 3);
    putpixel(xc-y, yc-x, 3);
}

int main()
{
	initwindow(800,800);
	int r, xc, yc, pk, x, y;
	cout<<"\nEnter the center co-ordinates : ";
	cin>>xc>>yc;
	cout<<"\nEnter the radius of circle : ";
	cin>>r;
	pk = 3-2*r;
	x = 0;
	y = r;
	while(x<=y)
	{
		drawCircle(x,y,xc,yc);
		x++;
		if(pk<=0) pk = pk + (4*x) + 6;
		else
		{
			y--;
			pk = pk + (4*(x-y)) + 10;
		}
		delay(50);
	}
	getch();
	return 0;
}
