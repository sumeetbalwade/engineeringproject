#include<iostream>
#include<graphics.h>

using namespace std;
void dda(int x1,int x2,int y1,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int step;
    step= abs(dx)>abs(dy)?abs(dx):abs(dy);

    float xi=dx/step;
    float yi=dy/step;
	float x=x1;
	float y=y1;
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
    for (int i = 0; i < step; i++)
    {
        putpixel(x,y,WHITE);
        x+=xi;
        y+=yi;
    }
    getch();
    closegraph();
    
}

void bresenhams(int x1,int x2,int y1,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;
    float dp=2*dy+dx;
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
    int x=x1,y=y1;
    while (x<x2)
    {
        x++;
        if (dp<=0)
        {
            dp=dp+2*dy;
        }
        else
        {
            y++;
            dp=dp+2*dy-2*dx;
        }

        putpixel(x,y,WHITE);
    }
    getch();
    closegraph();
    
}


int main(int argc, char const *argv[])
{
    bresenhams(50,300,50,150);
    return 0;
}
