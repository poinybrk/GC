/*
Input :-

50 200
50 100
150 100
200 200
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

int main()
{
    int x[4], y[4];
    double t, xt, yt;
    initwindow(800,800);
    setcolor(YELLOW);
    
    cout<<"Enter the x and y coordinates of the four control points :- \n";
    for (int i=0; i<4; i++)
    {
    	cout<<"Point "<<i+1<<" : ";
    	cin>>x[i]>>y[i];
	}
	
    for (int i=0; i<3; i++) line(x[i], y[i], x[i+1], y[i+1]);
    
    for (t=0.0; t<1.0; t += 0.001)
    {
		xt = (1-t)*(1-t)*(1-t)*x[0] + 3*t*(1-t)*(1-t)*x[1] + 3*t*t*(1-t)*x[2] + t*t*t*x[3];
		yt = (1-t)*(1-t)*(1-t)*y[0] + 3*t*(1-t)*(1-t)*y[1] + 3*t*t*(1-t)*y[2] + t*t*t*y[3];
		putpixel(xt, yt, RED);
		delay(1);
    }
    getch();
    return 0;
}
