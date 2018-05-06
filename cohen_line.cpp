/*
Input :- 

200 200
400 400

150 150 450 450

Press Enter in graphics window after output to obtain clipped line.
*/

// C++ program to implement Cohen Sutherland algorithm for line clipping.
#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Defining x_max, y_max and x_min, y_min for clipping rectangle. 
// Since diagonal points are enough to define a rectangle.
int x_max,y_max,x_min,y_min;

// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    // initialized as being inside 
    int code = INSIDE;

    if (x < x_min)  code |= LEFT;         // to the left of rectangle
    else if (x > x_max)  code |= RIGHT;   // to the right of rectangle
        
    if (y < y_min)  code |= BOTTOM;       // below the rectangle
    else if (y > y_max)  code |= TOP;     // above the rectangle

    return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle, in same region
            break;
        }
        else
        {
            // Some segment of line lies within the rectangle
            int code_out;
            double x, y;

            // At least one endpoint is outside the rectangle, pick it.
            if (code1 != 0)  code_out = code1;
            else  code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
    	line(x1,y1,x2,y2);
        cout<<"\nLine accepted from ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<").\n";
    }
    else cout << "\nLine rejected.\n";
}

int main()
{
	initwindow(800,800);
	int x1,x2,y1,y2;
	cout<<"Enter diagonal points of Clipping Rectangle :-\n";
	cin>>x_min>>y_min>>x_max>>y_max;
	cout<<"\nClipping Rectangle is : ("<<x_min<<","<<y_min<<"), ("<<x_min<<","<<y_max
		<<"), ("<<x_max<<","<<y_min<<"), ("<<x_max<<","<<y_max<<")\n\n";
	
	setcolor(YELLOW);
	line(x_min,y_min,x_max,y_min);
	line(x_min,y_min,x_min,y_max);
	line(x_min,y_max,x_max,y_max);
	line(x_max,y_max,x_max,y_min);
	
	cout<<"Enter line coordinates : ";
	cin>>x1>>y1>>x2>>y2;
	setcolor(RED);
	line(x1, y1, x2, y2);
	
	
	getch();
	cleardevice();
	setcolor(YELLOW);
	line(x_min,y_min,x_max,y_min);
	line(x_min,y_min,x_min,y_max);
	line(x_min,y_max,x_max,y_max);
	line(x_max,y_max,x_max,y_min);
	
	setcolor(RED);
    cohenSutherlandClip(x1, y1, x2, y2);
	getch();
    return 0;
}
