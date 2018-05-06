/*
Input :-

3

100 100 0
100 150 0
150 150 0

45
*/

#include<iostream>
#include<math.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

class matrix
{
    int nodes[10][4];
    float T[4][4];
    float rr[10][4];
    int size;
    
    public:
    
    void input()
    {
    	cout << "\nEnter number of points (2-10) : ";
    	cin>>size;
        cout << endl;
        
        for(int i=0;i<size;++i)
        {
            cout << "Enter P" << i+1 <<" : ";
            for(int j=0;j<3;++j)
                cin >> nodes[i][j];
            nodes[i][3] = 1;
        }
    }
    
    void rotation()
    {
    	cout << "\nBefore Transformation :-\n";
        for(int i=0;i<size;++i)
        {
            for(int j=0;j<4;++j)
                cout << nodes[i][j] << " ";
            cout << endl;
        }
        cout<<endl;
        
        for(int i=0;i<size;++i)
            line(nodes[i%size][0], nodes[i%size][1], nodes[(i+1)%size][0], nodes[(i+1)%size][1]);
            
    	//This code only works for rotation along x-axis
        setcolor(RED);
		int angle;
        cout << "Enter angle along x axis : ";
        cin >> angle;
        float r = angle*(3.14/180);
        T[0][0] = T[3][3] = 1;
        T[1][1] = T[2][2] = cos(r);
        T[1][2] = T[2][1] = sin(r);
        T[2][1] *= -1; 
		for(int i=1;i<=3;++i) 
			T[0][i] = T[i][0] = T[3][i-1] = T[i-1][3] = 0;
		        
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
                cout << T[i][j] << " ";
            cout << endl;
        }
        cout<<endl;
        
        
        for(int i=0;i<size;i++)
            for(int j=0;j<4;j++)
            {
                rr[i][j] = 0;
                for(int k=0;k<4;k++)
                    rr[i][j] += nodes[i][k]*T[k][j];
                rr[i][j] = round(rr[i][j]);
            }
        
        cout << "\nAfter Transformation :-\n";
        for(int i=0;i<size;++i)    
        {
            for(int j=0;j<4;++j)
                cout << rr[i][j] << " ";
            cout << endl;
        }
        
        for(int i=0;i<size;++i)
            line(rr[i%size][0], rr[i%size][1], rr[(i+1)%size][0], rr[(i+1)%size][1]);
    }
};

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    matrix m;
    m.input();
    m.rotation();
    getch();
    return 0;
}
